## Quick Start

**Prerequisites**: Yarn, node and cmake  
note : windows users also need [Build Tools for Visual Studio package](https://visualstudio.microsoft.com/fr/downloads/?rr=https%3A%2F%2Fwww.google.com%2F)

1. Run `yarn` to fetch node packages. There might be an error caused by node-gyp, but it is temporary: continue to step 2.
2. Run `yarn build` to build google/sentencepiece and the node binding
3. step outside the directory:  
    \>> cd ..
4. run node:  
    \>> node
5. require node-sentencepiece package  
    (node) var sp = require('./node-sentencepiece')
6. use the package to get tokens  
    (node) sp.encode('en', 'Never gonna give you up, Never gonna let you down')
7. resulting output is  
    [ 'Never',
    'gonna',
    'give',
    'you',
    'up,',
    'Never',
    'gonna',
    'let',
    'you',
    'down' ]

