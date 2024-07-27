// Link: https://coddy.tech/challenges/message_encryption_js

function encryptMessage(message, key, sequence) {
    // Step 1: Reverse the message string
    let reversedMessage = message.split('').reverse().join('');

    // Step 2: Convert each character in the reversed message to its ASCII code
    let asciiCodes = [];
    for (let i = 0; i < reversedMessage.length; i++) {
        asciiCodes.push(reversedMessage.charCodeAt(i));
    }

    // Step 3: Multiply each ASCII code by the corresponding number in the sequence array
    let modifiedAsciiCodes = [];
    for (let i = 0; i < asciiCodes.length; i++) {
        let multiplier = sequence[i % sequence.length];
        modifiedAsciiCodes.push(asciiCodes[i] * multiplier);
    }

    // Step 4: Add the encryption key to each multiplied ASCII code
    for (let i = 0; i < modifiedAsciiCodes.length; i++) {
        modifiedAsciiCodes[i] += key;
    }

    // Step 5: Convert the modified ASCII codes back to characters
    let encryptedMessage = "";
    for (let i = 0; i < modifiedAsciiCodes.length; i++) {
        encryptedMessage += String.fromCharCode(modifiedAsciiCodes[i]);
    }

    // Return the encrypted message as a string
    return encryptedMessage;
}
