const sentencepiece = require('./build/Release/token.node');

const input_text = 'Reaching for something in the distance'
+ 'So close you can almost taste it'
+ 'Release your inhibitions'
+ 'Feel the rain on your skin'
+ 'No one else can feel it for you'
+ 'Only you can let it in'
+ 'No one else, no one else'
+ 'Can speak the words on your lips'
+ 'Drench yourself in words unspoken'
+ 'Live your life with arms wide open'
+ 'Today is where your book begins'
+ 'The rest is still unwritten'

const path_to_model = '/home/francois/Documents/botpress-root/Setence-piece-test/sentencepiece/m.model'

const tokens = sentencepiece.encode(path_to_model, input_text)
console.log(tokens);

module.exports = sentencepiece;