#include <napi.h>
#include "token.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
  token::Init(env, exports);
  return exports;
}

NODE_API_MODULE(testaddon, InitAll)