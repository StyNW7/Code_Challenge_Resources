// Link: https://coddy.tech/challenges/seed_packet_decoder_js

function decodeSeedPacket(seedPacket) {
    // Define the alphabet string
    const alphabet = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ';
    let decodedPlantName = ''; // Initialize the decoded plant name

    // Iterate through each character in the seedPacket string
    for (let char of seedPacket) {
        // Find the index of the character in the alphabet
        let index = alphabet.indexOf(char);
        if (index !== -1) {
            // Subtract 3 to decode
            let decodedIndex = index - 3;

            // Wrap around if the index is less than 0
            if (decodedIndex < 0) {
                decodedIndex += 26;
            }

            // Append the decoded character to the result
            decodedPlantName += alphabet[decodedIndex];
        } else {
            // If the character is not in the alphabet, append it as-is
            decodedPlantName += char;
        }
    }

    return decodedPlantName;
}
