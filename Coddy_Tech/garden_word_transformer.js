// Link: https://coddy.tech/challenges/garden_word_transformer_js?daily=true

function gardenWordTransformer(flowerNames) {
    // Step 1: Split flowerNames into an array of flower names
    const flowersArray = flowerNames.split(' ');

    // Step 2: Reverse the order of the names
    const reversedArray = flowersArray.reverse();

    // Step 3: Join the reversed names into a string, separated by spaces
    const reversedString = reversedArray.join(' ');

    // Step 4: Check if the reversed string is a palindrome (ignoring case and non-alphabetic characters)
    const cleanedString = reversedString.replace(/[^a-zA-Z]/g, '').toLowerCase();
    const isPalindrome = cleanedString === cleanedString.split('').reverse().join('');

    // Step 5: Concatenate based on palindrome check
    const concatenatedString = isPalindrome 
        ? flowerNames + ' ' + flowerNames 
        : reversedString + ' ' + flowerNames;

    // Step 6: Calculate the length of the concatenated string
    const concatenatedLength = concatenatedString.length;

    // Step 7: Select a garden-themed word based on the length
    let gardenWord = '';
    if (concatenatedLength >= 1 && concatenatedLength <= 5) {
        gardenWord = 'seed';
    } else if (concatenatedLength >= 6 && concatenatedLength <= 10) {
        gardenWord = 'sprout';
    } else if (concatenatedLength >= 11 && concatenatedLength <= 15) {
        gardenWord = 'blossom';
    } else if (concatenatedLength >= 16 && concatenatedLength <= 20) {
        gardenWord = 'flourish';
    } else if (concatenatedLength >= 21) {
        gardenWord = 'abundance';
    }

    // Step 8: Insert the selected word in the middle of the concatenated string
    const middleIndex = Math.floor(concatenatedString.length / 2);
    const transformedString = concatenatedString.slice(0, middleIndex) + gardenWord + concatenatedString.slice(middleIndex);

    // Step 9: Return the transformed string
    return transformedString;
}
