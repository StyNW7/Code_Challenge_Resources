// Link: https://coddy.tech/challenges/reversing_beach_day_memories_js

function reverseBeachDay(items, phrase) {
    // Reverse the items array
    let reversedItems = items.slice().reverse(); // slice() to avoid mutating the original array

    // Reverse the phrase string
    let reversedPhrase = phrase.split('').reverse().join('');

    // Return an array with the reversed items and reversed phrase
    return [reversedItems, reversedPhrase];
}
