// Link: https://coddy.tech/challenges/palindrome_monster_detector_js

function isMonsterPalindrome(str) {
    // Remove spaces and punctuation, and convert to lowercase
    const cleanedStr = str.replace(/[^a-zA-Z0-9]/g, '').toLowerCase();
    
    // Check if the cleaned string is a palindrome
    const isPalindrome = cleanedStr === cleanedStr.split('').reverse().join('');
    
    if (isPalindrome) {
        return "Beware, a palindrome monster is near!";
    } else {
        return "You are safe from palindrome monsters... for now.";
    }
}
