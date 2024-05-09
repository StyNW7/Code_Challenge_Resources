// Link: https://coddy.tech/challenges/reservoir_word_play_js

function reservoirWordPlay(word) {

    // Function to check if a string is a palindrome
    function isPalindrome(str) {
        const reversed = str.split('').reverse().join('');
        return str === reversed;
    }

    // Function to remove vowels from a string
    function removeVowels(str) {
        return str.replace(/[aeiou]/gi, '');
    }

    // Check if the word is a palindrome
    if (isPalindrome(word)) {
        // If it's a palindrome, remove vowels
        return removeVowels(word);
    } 
    
    else {
        // If it's not a palindrome, reverse the string
        return word.split('').reverse().join('');
    }

}
