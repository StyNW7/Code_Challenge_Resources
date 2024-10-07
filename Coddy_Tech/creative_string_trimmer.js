// Link: https://coddy.tech/challenges/creative_string_trimmer_js?daily=true

function trimCreativeString(inputString, maxLength) {
    // Define a helper function to remove vowels except in the word "art"
    function removeVowelsExceptArt(word) {
        // If the word is "art", return it as is
        if (word.toLowerCase() === "art") return word;

        // Remove all vowels from the word
        return word.replace(/[aeiouAEIOU]/g, '');
    }

    // Split the input string into words and filter out the word "break"
    let words = inputString.split(' ').filter(word => word.toLowerCase() !== 'break');

    // Remove vowels from each word except in "art"
    let modifiedWords = words.map(removeVowelsExceptArt);

    // Now, rebuild the sentence, ensuring it doesn't exceed maxLength
    let result = '';
    
    for (let word of modifiedWords) {
        // Check if adding the next word would exceed the maxLength
        if ((result + word).length + (result ? 1 : 0) > maxLength) {
            break;
        }

        // Add the word to the result (with a space if it's not the first word)
        result += (result ? ' ' : '') + word;
    }

    return result;
}
