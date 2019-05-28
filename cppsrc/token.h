#include <napi.h>
#include <vector>
#include <string>
#include <tuple>
#include "sentencepiece_processor.h"

namespace token {
    std::tuple<std::vector<std::string>, std::string> encode(std::string pathToModel, std::string input_string);
    Napi::Array EncodeWrapped(const Napi::CallbackInfo& info);
    void Init(Napi::Env env, Napi::Object exports);
}