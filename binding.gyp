{
    "targets": [{
        "target_name": "sentencepiece",
        "cflags!": [ "-fno-exceptions" ],
        "cflags_cc!": [ "-fno-exceptions" ],
        "cflags": ["-fexceptions"],
        "cflags_cc": ["-fexceptions"],
        "sources": [
            "cppsrc/main.cpp",
            "cppsrc/token.cpp"
        ],
        'include_dirs': [
            "<!@(node -p \"require('node-addon-api').include\")",
            "<(module_root_dir)/sentencepiece/src"
        ],
        'libraries': ["<(module_root_dir)/bin/sentencepiece_lib.lib"],
        'dependencies': [
            "<!(node -p \"require('node-addon-api').gyp\")"
        ],
        'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ]
    }]
}