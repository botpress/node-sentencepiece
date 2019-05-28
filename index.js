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

const wrappedEncode = (language, inputText) => {
    const modelFilePath = mapLanguageToModel(language)
    return sentencepiece.encode(modelFilePath, inputText)
}

const sentencepieceWrapper = {
    encode: wrappedEncode
}

module.exports = sentencepieceWrapper