#include <napi.h>
#include <vector>
#include <string>
#include "sentencepiece_processor.h"

struct DecodeInfo {
   std::string reconstructedText;
   std::string errorMessage;
};

namespace decode {
    DecodeInfo decode(std::string pathToModel, std::vector<std::string> pieces);
    Napi::String DecodeWrapped(const Napi::CallbackInfo& info);
    void Init(Napi::Env env, Napi::Object exports);
}