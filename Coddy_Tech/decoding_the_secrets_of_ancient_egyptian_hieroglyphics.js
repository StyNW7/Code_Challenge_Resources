// Link: https://coddy.tech/challenges/decoding_the_secrets_of_ancient_egyptian_hieroglyphics_js?daily=true

function decodeHieroglyphics(patternKey, encodedString) {
    // Step 1: Create a dictionary from the pattern key
    const keyPairs = patternKey.split(','); // Split into key-value pairs
    const symbolToPlaintext = {};
    
    keyPairs.forEach(pair => {
        const [symbol, value] = pair.split('=>'); // Split each pair into symbol and value
        symbolToPlaintext[symbol] = value; // Create a dictionary entry
    });

    // Step 2: Decode the encoded string
    const symbols = encodedString.split('.'); // Split the encoded string by periods
    const decodedValues = symbols.map(symbol => symbolToPlaintext[symbol]); // Map each symbol to its plaintext

    // Step 3: Join the decoded values with spaces
    const decodedMessage = decodedValues.join(' ');
    
    return decodedMessage;
}

function calculateSecretChamberLocation(decodedMessage) {
    // Step 1: Create a set of unique decoded names
    const decodedNames = decodedMessage.split(' '); // Split the decoded message into words
    const uniqueNames = [...new Set(decodedNames)]; // Remove duplicates by creating a set
    
    // Step 2: Extract the first letter of each unique name
    const firstLetters = uniqueNames.map(name => name[0]); // Get the first letter of each name
    
    // Step 3: Sort the letters alphabetically
    firstLetters.sort(); // Sort the letters
    
    // Step 4: Concatenate the sorted letters to form the secret code
    const secretCode = firstLetters.join(''); // Join the letters to form a string
    
    return secretCode;
}
