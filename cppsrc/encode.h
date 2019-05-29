#include <napi.h>
#include <vector>
#include <string>
#include "sentencepiece_processor.h"

struct EncodeInfo {
   std::vector<std::string> pieces;
   std::string errorMessage;
};

namespace encode {
    EncodeInfo encode(std::string pathToModel, std::string input_string);
    Napi::Array EncodeWrapped(const Napi::CallbackInfo& info);
    void Init(Napi::Env env, Napi::Object exports);
}