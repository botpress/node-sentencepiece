const sentencepiece = require('./build/Release/sentencepiece.node');

const encode = (inputText, model) => {
    const modelFilePath = model ? model : `${__dirname}/models/en.model`
    return sentencepiece.encode(modelFilePath, inputText)
}

const decode = (pieces, model) => {
    const modelFilePath = model ? model : `${__dirname}/models/en.model`
    return sentencepiece.decode(modelFilePath, pieces)
}

const sentencepieceWrapper = {
    encode: encode,
    decode : decode
}

module.exports = sentencepieceWrapper