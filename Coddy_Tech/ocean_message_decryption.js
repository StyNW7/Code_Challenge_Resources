// Link: https://coddy.tech/challenges/ocean_message_decryption_js

function decryptOceanMessage(message1, message2, decryptedMessage) {
    // Step 1: Concatenate message1 and message2 by alternating characters
    let concatenatedMessage = '';
    for (let i = 0; i < message1.length; i++) {
        concatenatedMessage += message1[i] + message2[i];
    }

    // Step 2: Reverse the concatenated string
    let reversedMessage = concatenatedMessage.split('').reverse().join('');

    // Step 3: Compare the reversed string to decryptedMessage
    return reversedMessage === decryptedMessage;
}
