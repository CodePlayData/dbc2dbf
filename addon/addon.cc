// addon.cc
#include <napi.h>
#include "dbc2dbf.h"

Napi::Value CreateObject(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (!info[0].IsObject()) {
    Napi::TypeError::New(env, "Argument should be an object").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Object obj = info[0].As<Napi::Object>();

  if (!obj.Has("input") || !obj.Has("output")) {
    Napi::TypeError::New(env, "Object should have 'input' and 'output'").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Value inputVal = obj.Get("input");
  Napi::Value outputVal = obj.Get("output");

  if (!inputVal.IsString() || !outputVal.IsString()) {
    Napi::TypeError::New(env, "'input' and 'output' should be strings").ThrowAsJavaScriptException();
    return env.Null();
  }

  std::string inputPath = inputVal.As<Napi::String>();
  std::string outputPath = outputVal.As<Napi::String>();

  // Convert to char* for legacy C function
  char* inputPathC = const_cast<char*>(inputPath.c_str());
  char* outputPathC = const_cast<char*>(outputPath.c_str());

  dbc2dbf(&inputPathC, &outputPathC);

  return obj;
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set("dbc2dbf", Napi::Function::New(env, CreateObject));
  return exports;
}

NODE_API_MODULE(addon, Init)