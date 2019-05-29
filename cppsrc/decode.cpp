#include "decode.h"

using namespace std;

DecodeInfo decode::decode(string pathToModel, vector<string> pieces) {
    
    sentencepiece::SentencePieceProcessor processor;
    const auto status = processor.Load(pathToModel);

    DecodeInfo returnedObject;
    if (!status.ok()) {
        returnedObject.reconstructedText = "";
        returnedObject.errorMessage = string("Model for de-tokenization could not be loaded : ").append(pathToModel);
        return returnedObject;
    }

    string reconstructedText;
    processor.Decode(pieces, &reconstructedText);

    returnedObject = { .reconstructedText = reconstructedText, .errorMessage = "" };
    return returnedObject;
}

Napi::String decode::DecodeWrapped(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() != 2 || !info[0].IsString() || !info[1].IsArray()) {
        const char * errorMessage = "Incorrect parameters. Function expects one string param for model path and one array param for pieces to decode";
        Napi::TypeError::New(env, errorMessage).ThrowAsJavaScriptException();
    }

    Napi::String pathToModel = info[0].As<Napi::String>();
    Napi::Array pieces = info[1].As<Napi::Array>();

    vector<string> vectorPieces = vector<string>();
    for (unsigned int i = 0; i < pieces.Length(); i++) {
        string stringPiece = pieces.Get(i).As<Napi::String>().Utf8Value();
        vectorPieces.push_back(stringPiece);
    }

    DecodeInfo decodeInfo = decode::decode(pathToModel.Utf8Value(), vectorPieces);
    
    if (decodeInfo.errorMessage.length() != 0) {
        Napi::Error::New(env, decodeInfo.errorMessage.c_str()).ThrowAsJavaScriptException();
    }

    return Napi::String::New(env, decodeInfo.reconstructedText.c_str());
}

void decode::Init(Napi::Env env, Napi::Object exports) {
    exports.Set("decode", Napi::Function::New(env, decode::DecodeWrapped));
}