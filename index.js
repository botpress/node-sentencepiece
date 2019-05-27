const sentencepiece = require('./build/Release/token.node');

// const input_text = 'Reaching for something in the distance '
// + 'So close you can almost taste it '
// + 'Release your inhibitions '
// + 'Feel the rain on your skin '
// + 'No one else can feel it for you '
// + 'Only you can let it in '
// + 'No one else, no one else '
// + 'Can speak the words on your lips '
// + 'Drench yourself in words unspoken '
// + 'Live your life with arms wide open '
// + 'Today is where your book begins '
// + 'The rest is still unwritten.'

// const path_to_model = './models/en.wiki.bpe.vs200000.model'

const input_text = 'Ton arrière-arrière-grand-père, il a défriché la terre'
+ 'Ton arrière-grand-père, il a labouré la terre'
+ 'Et pis ton grand-père a rentabilisé la terre'
+ 'Pis ton père, il l’a vendue pour devenir fonctionnaire'
+ 'Et pis toi, mon p’tit gars, tu l’sais pus c’que tu vas faire'
+ 'Dans ton p’tit trois et demi bien trop cher, frette en hiver'
+ 'Il te vient des envies de devenir propriétaire'
+ 'Et tu rêves la nuit d’avoir ton petit lopin de terre'

const path_to_model = '/home/francois/Téléchargements/fr.wiki.bpe.vs200000.model'

const tokens = sentencepiece.encode(path_to_model, input_text.toLocaleLowerCase())
console.log(tokens);

module.exports = sentencepiece;