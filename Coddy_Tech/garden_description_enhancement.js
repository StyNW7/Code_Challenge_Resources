// Link: https://coddy.tech/challenges/garden_description_enhancement_js

function enhanceGardenDescription(description, enhancements) {
    // Helper function to reverse the bits of a number
    function reverseBits(num) {
        let reversed = 0;
        while (num > 0) {
            reversed = (reversed << 1) | (num & 1);
            num >>= 1;
        }
        return reversed;
    }

    // Descriptive words to enhance the description
    const descriptiveWords = ["lush", "vibrant", "floral", "serene", "blooming"];
    let wordIndex = 0; // Index to cycle through descriptive words

    // Convert the description to an array of characters for easier manipulation
    let descriptionArray = description.split("");

    // Iterate through the enhancements array
    for (let i = 0; i < enhancements.length; i++) {
        let position = enhancements[i];

        // Transform the position using bit manipulation (reverse bits)
        let transformedPosition = reverseBits(position);

        // If the transformed position is out of bounds, skip it
        if (transformedPosition < 0 || transformedPosition >= descriptionArray.length) {
            continue;
        }

        // Insert the descriptive word at the transformed position
        let wordToInsert = descriptiveWords[wordIndex % descriptiveWords.length];
        wordIndex++;

        // Advanced string concatenation: Insert the word in the transformed position
        descriptionArray.splice(transformedPosition, 0, " " + wordToInsert);

        // Break if we reach a certain number of enhancements (optional condition)
        if (wordIndex >= descriptiveWords.length * 2) { // Example condition
            break;
        }
    }

    // Return the enhanced description as a string
    return descriptionArray.join("");
}
