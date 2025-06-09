{
  "targets": [
    {
      "target_name": "addon",
      "sources": [ 
        "./addon/addon.cc",
        "./addon/src/dbc2dbf/dbc2dbf.cc",
        "./addon/src/dbc2dbf/utils/cleanup.cc",
        "./addon/src/dbc2dbf/utils/inf.cc",
        "./addon/src/dbc2dbf/utils/outf.cc",
        "./addon/src/blast/blast.cc",
        "./addon/src/blast/utils/bits.cc",
        "./addon/src/blast/utils/construct.cc",
        "./addon/src/blast/utils/decode.cc",
        "./addon/src/blast/utils/decomp.cc"
      ],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")",
        "./addon/src/dbc2dbf",
        "./addon/src/blast"
      ],
      "dependencies": [
        "<!(node -p \"require('node-addon-api').gyp\")"
      ],
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
      "defines": [ "NAPI_DISABLE_CPP_EXCEPTIONS=0" ],
      "conditions": [
        [ 'OS=="win"', {
          "msvs_settings": {
            "VCCLCompilerTool": { "ExceptionHandling": 1 }
          }
        }]
      ]
    }
  ]
}
