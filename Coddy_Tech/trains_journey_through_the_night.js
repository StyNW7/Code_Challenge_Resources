// Link: https://coddy.tech/challenges/trains_journey_through_the_night_js

function trainJourney(input) {
    // Step 1: Reverse the order of words
    let wordsReversed = input.split(' ').reverse().join(' ');

    // Step 2: Capitalize every third character
    let result = '';
    for (let i = 0; i < wordsReversed.length; i++) {
        // Capitalize every 3rd character (0-indexed, i.e., i % 3 === 0)
        if (i % 3 === 0) {
            result += wordsReversed[i].toUpperCase();
        } else {
            result += wordsReversed[i];
        }
    }

    // Step 3: Concatenate " choo choo!" to the end
    result += ' choo choo!';

    return result;
}
