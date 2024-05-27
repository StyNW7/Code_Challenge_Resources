// Link: https://coddy.tech/challenges/decoding_deep_sea_messages_js

function decodeDeepSeaMessage(encodedMessage) {
    // Reverse the encoded message
    let reversedMessage = encodedMessage.split('').reverse().join('');
    let decodedMessage = '';

    // Iterate through the reversed message
    for (let char of reversedMessage) {
        if (char >= '0' && char <= '9') {
            // Check if the character is a digit
            let digit = parseInt(char, 10);
            if (digit % 2 === 0) {
                // Convert even numbers to binary
                decodedMessage += digit.toString(2);
            } else {
                // Keep odd numbers as decimal
                decodedMessage += digit;
            }
        } else {
            // Keep letters as they are
            decodedMessage += char;
        }
    }

    return decodedMessage;
}
