const sentencepiece = require('./build/Release/sentencepiece.node');

const mapLanguageToModel = (language) => {
    let modelFilePath = `${__dirname}/models/`;
    if (language === 'en') {
        modelFilePath += 'en.wiki.bpe.vs200000.model'
    } else if (language === 'fr') {
        modelFilePath += 'fr.wiki.bpe.vs200000.model'
    } else  {
        throw `${language} is not a supported language`
    }
    return modelFilePath
}

const cleanTokens = (tokens) => {
    let tokenSentence = tokens.reduce((ac, cu) => ac + cu, "")
    return tokenSentence.split('▁').filter(x => x)
}

const wrappedEncode = (language, inputText) => {
    const modelFilePath = mapLanguageToModel(language)
    const dirtyTokens = sentencepiece.encode(modelFilePath, inputText)
    return cleanTokens(dirtyTokens)
}

const sentencepieceWrapper = {
    encode: wrappedEncode
}

module.exports = sentencepieceWrapper