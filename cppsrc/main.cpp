#include <napi.h>
#include "encode.h"
#include "decode.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
  encode::Init(env, exports);
  decode::Init(env, exports);
  return exports;
}

NODE_API_MODULE(testaddon, InitAll)