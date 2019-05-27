#include "token.h"

using namespace std;

class LoadModelTokenException : public exception
{
    public:
    LoadModelTokenException(string modelFilePath) {
        errorMessage = string("Model for tokenization could not be loaded : ").append(modelFilePath);
    }

	const char * what () const throw ()
    {
    	return errorMessage.c_str();
    }

    private:
    string errorMessage;
};

vector<string> token::encode(string pathToModel, string input_string) {
    
    sentencepiece::SentencePieceProcessor processor;
    const auto status = processor.Load(pathToModel);

    if (!status.ok()) {
        throw LoadModelTokenException(pathToModel);
    }

    std::vector<std::string> pieces;
    processor.Encode(input_string, &pieces);

    return pieces;
}

Napi::Array token::EncodeWrapped(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() != 2 || !info[0].IsString() || !info[1].IsString()) {
        const char * errorMessage = "Incorrect parameters. Function expects two string params for model path and input text";
        Napi::TypeError::New(env, errorMessage).ThrowAsJavaScriptException();
    }

    Napi::String pathToModel = info[0].As<Napi::String>();
    Napi::String inputString = info[1].As<Napi::String>();

    vector<string> pieces;
    try {
        pieces = token::encode(pathToModel.Utf8Value(), inputString.Utf8Value());
    } catch (LoadModelTokenException& e) {
        Napi::Error::New(env, e.what()).ThrowAsJavaScriptException();
    }

    Napi::Array napiPieces = Napi::Array::New(env);
    for (unsigned int i = 0; i < pieces.size(); i++) {
        napiPieces.Set(i, Napi::String::New(env, pieces[i].c_str()));
    }
    return napiPieces;
}

void token::Init(Napi::Env env, Napi::Object exports) {
    exports.Set("encode", Napi::Function::New(env, token::EncodeWrapped));
}