// Link: https://coddy.tech/challenges/ancient_scripture_decoder_js?daily=true

function decodeScripture(originalLine, additionalLine) {
    return originalLine.concat(additionalLine[additionalLine.length-2]).concat(additionalLine[additionalLine.length-1])
}
