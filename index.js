const sentencepiece = require('./build/Release/sentencepiece.node');

const encode = (inputText, model) => {
    const modelFilePath = model ? model : `${__dirname}/models/en.model`
    return sentencepiece.encode(modelFilePath, inputText)
}

const sentencepieceWrapper = {
    encode: encode
}

module.exports = sentencepieceWrapper