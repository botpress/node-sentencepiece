## Quick Start

**Prerequisites**: Yarn, node and cmake  
note : windows users also need [Build Tools for Visual Studio package](https://visualstudio.microsoft.com/fr/downloads/?rr=https%3A%2F%2Fwww.google.com%2F)

1. clone the repo using the `--recursive` arg to fetch [google/sentencepiece](https://github.com/google/sentencepiece) submodule
1. Run `yarn` to fetch node packages.
1. Run `yarn build` to build google/sentencepiece and the node binding
1. step outside the directory:  
    `>> cd ..`
1. run node:  
    `>> node`
1. require node-sentencepiece package  
    `(node) var sp = require('./node-sentencepiece')`
1. use the package to get tokens (default language is english)  
    `(node) sp.encode('Never gonna give you up, Never gonna let you down')`
        
    returns:  
    `[ 'Never',
    'gonna',
    'give',
    'you',
    'up,',
    'Never',
    'gonna',
    'let',
    'you',
    'down' ]`
1. to tokenize in another language you can pass the path of your own custom model  
    `(node) sp.encode('Never gonna give you up, Never gonna let you down', '/path/to/model/m.model')`

1. you can get back the original input text from token by using decode with the same model  
    `(node) var modelPath = '/path/to/model/m.model'` 

    `(node) var inputText = 'Never gonna give you up, Never gonna let you down'`  
         
    `(node) var pieces = sp.encode(inputText, modelPath)` 
        
    `(node) var outputText = sp.decode(pieces, modelPath)`

    `(node) inputText === outpuText`

    returns:  
    `true`

