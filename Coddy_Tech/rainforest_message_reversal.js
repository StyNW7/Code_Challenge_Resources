// Link: https://coddy.tech/challenges/rainforest_message_reversal_js?daily=true

function reverseRainforestMessage(message, words) {
    // Reverse the words array
    const reversedWords = words.reverse();
    
    // Replace each placeholder {0}, {1}, {2}, ... with the corresponding word from reversedWords
    let formattedMessage = message.replace(/{(\d+)}/g, (match, index) => {
        return reversedWords[index];
    });
    
    return formattedMessage;
}
