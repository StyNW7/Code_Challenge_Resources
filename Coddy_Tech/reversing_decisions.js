// Link: https://coddy.tech/challenges/reversing_decisions_js

function reverseDecision(decision) {
    // Split the decision string into individual words
    const words = decision.split(' ');

    // Reverse each word in the words array
    const reversedWords = words.map(word => {
        return word.split('').reverse().join('');
    });

    // Join the reversed words back together into a single string
    const reversedDecision = reversedWords.join(' ');

    return reversedDecision;
}
