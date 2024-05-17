// Link: https://coddy.tech/challenges/decoding_the_wine_collectors_secret_js

function decodeWineCollectorSecret(text) {
    const parts = text.split(' ');
    let decodedMessage = [];

    parts.forEach(part => {
        if (part.startsWith('#')) {
            const binaryString = part.slice(1);
            const decimalValue = parseInt(binaryString, 2);
            const char = String.fromCharCode(decimalValue);
            decodedMessage.push(char);
        } 
        
        else {
            const reversedWord = part.split('').reverse().join('');
            decodedMessage.push(reversedWord);
        }
    });

    return decodedMessage.join(' ');
    
}
