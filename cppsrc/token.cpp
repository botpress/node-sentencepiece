#include "token.h"

using namespace std;

tuple<vector<string>, string> token::encode(string pathToModel, string input_string) {
    
    sentencepiece::SentencePieceProcessor processor;
    const auto status = processor.Load(pathToModel);

    if (!status.ok()) {
        return make_tuple(vector<string>(), string("Model for tokenization could not be loaded : ").append(pathToModel));
    }

    std::vector<std::string> pieces;
    processor.Encode(input_string, &pieces);
    return make_tuple(pieces, "");
}

Napi::Array token::EncodeWrapped(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() != 2 || !info[0].IsString() || !info[1].IsString()) {
        const char * errorMessage = "Incorrect parameters. Function expects two string params for model path and input text";
        Napi::TypeError::New(env, errorMessage).ThrowAsJavaScriptException();
    }

    Napi::String pathToModel = info[0].As<Napi::String>();
    Napi::String inputString = info[1].As<Napi::String>();

    tuple<vector<string>, string> returnedTuple = token::encode(pathToModel.Utf8Value(), inputString.Utf8Value());
    vector<string> pieces = get<0>(returnedTuple);
    string errorMessage = get<1>(returnedTuple);
    
    if (errorMessage.length() != 0) {
        Napi::Error::New(env, errorMessage.c_str()).ThrowAsJavaScriptException();
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