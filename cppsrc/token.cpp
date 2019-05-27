#include "token.h"

using namespace std;

vector<string> token::encode(string pathToModel, string input_string) {
    
    sentencepiece::SentencePieceProcessor processor;
    const auto status = processor.Load(pathToModel);

    std::vector<std::string> pieces;
    processor.Encode(input_string, &pieces);

    return pieces;
}

Napi::Array token::EncodeWrapped(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::String pathToModel = info[0].As<Napi::String>();
    Napi::String inputString = info[1].As<Napi::String>();

    vector<string> pieces = token::encode(pathToModel.Utf8Value(), inputString.Utf8Value());

    Napi::Array napiPieces = Napi::Array::New(env);
    for (unsigned int i = 0; i < pieces.size(); i++) {
        napiPieces.Set(i, Napi::String::New(env, pieces[i].c_str()));
    }
    return napiPieces;
}

void token::Init(Napi::Env env, Napi::Object exports) {
    exports.Set("encode", Napi::Function::New(env, token::EncodeWrapped));
}