## Quick Start

**Prerequisites**: Yarn, node and cmake  
note : windows users also need [Build Tools for Visual Studio package](https://visualstudio.microsoft.com/fr/downloads/?rr=https%3A%2F%2Fwww.google.com%2F)

1. Run `yarn` to fetch node packages.
2. Run `yarn build` to build google/sentencepiece and the node binding
3. step outside the directory:  
    `>> cd ..`
4. run node:  
    `>> node`
5. require node-sentencepiece package  
    `(node) var sp = require('./node-sentencepiece')`
6. use the package to get tokens (default language is english)  
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
7. to tokenize in another language you can pass the path of your own custom model  
    `(node) sp.encode('Never gonna give you up, Never gonna let you down', '/path/to/model/m.model')`

8. you can get back the original input text from token by using decode with the same model  
    `(node) var modelPath = '/path/to/model/m.model'` 

    `(node) var inputText = 'Never gonna give you up, Never gonna let you down'`  
         
    `(node) var pieces = sp.encode(inputText, modelPath)` 
        
    `(node) var outputText = sp.decode(pieces, modelPath)`

    `(node) inputText === outpuText`

    returns:  
    `true`

