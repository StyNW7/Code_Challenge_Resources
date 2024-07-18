// Link: https://coddy.tech/challenges/decipher_encrypted_message_js

function decipherMessage(encryptedMessage, cipherKey) {
    // Initialize an array to store deciphered characters
    let deciphered = new Array(encryptedMessage.length);
    
    // Fill deciphered array based on cipherKey
    for (let i = 0; i < cipherKey.length; i++) {
        // Check if cipherKey[i] is within bounds
        if (cipherKey[i] >= 0 && cipherKey[i] < encryptedMessage.length) {
            deciphered[i] = encryptedMessage[cipherKey[i]];
        } else {
            deciphered[i] = 'undefined'; // Handle out of bounds case
        }
    }
    
    // Join deciphered array into a string and return
    return deciphered.join('');
}
