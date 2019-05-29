#include "encode.h"

using namespace std;

EncodeInfo encode::encode(string pathToModel, string input_string) {
    
    sentencepiece::SentencePieceProcessor processor;
    const auto status = processor.Load(pathToModel);

    EncodeInfo returnedObject;

    if (!status.ok()) {
        returnedObject.pieces = vector<string>();
        returnedObject.errorMessage = string("Model for tokenization could not be loaded : ").append(pathToModel);
        return returnedObject;
    }

    std::vector<std::string> pieces;
    processor.Encode(input_string, &pieces);

    returnedObject.pieces = pieces;
    returnedObject.errorMessage = "";
    return returnedObject;
}

Napi::Array encode::EncodeWrapped(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() != 2 || !info[0].IsString() || !info[1].IsString()) {
        const char * errorMessage = "Incorrect parameters. Function expects two string params for model path and input text";
        Napi::TypeError::New(env, errorMessage).ThrowAsJavaScriptException();
    }

    Napi::String pathToModel = info[0].As<Napi::String>();
    Napi::String inputString = info[1].As<Napi::String>();

    EncodeInfo encodeInfo = encode::encode(pathToModel.Utf8Value(), inputString.Utf8Value());
    
    if (encodeInfo.errorMessage.length() != 0) {
        Napi::Error::New(env, encodeInfo.errorMessage.c_str()).ThrowAsJavaScriptException();
    }

    Napi::Array napiPieces = Napi::Array::New(env);
    for (unsigned int i = 0; i < encodeInfo.pieces.size(); i++) {
        napiPieces.Set(i, Napi::String::New(env, encodeInfo.pieces[i].c_str()));
    }
    return napiPieces;
}

void encode::Init(Napi::Env env, Napi::Object exports) {
    exports.Set("encode", Napi::Function::New(env, encode::EncodeWrapped));
}