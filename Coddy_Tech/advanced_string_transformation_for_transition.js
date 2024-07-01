// Link: https://coddy.tech/challenges/advanced_string_transformation_for_transition_js

function transformText(text, operation) {
    // Helper function to check if a string is a palindrome
    function isPalindrome(str) {
        const cleanedStr = str.replace(/[^A-Za-z0-9]/g, '').toLowerCase();
        return cleanedStr === cleanedStr.split('').reverse().join('');
    }

    // Helper function to make a string a palindrome by minimal modification
    function makePalindrome(str) {
        let cleanedStr = str.replace(/[^A-Za-z0-9]/g, '').toLowerCase();
        let len = cleanedStr.length;
        let changes = 0;

        // Compare characters from both ends and make minimal changes to form a palindrome
        for (let i = 0; i < Math.floor(len / 2); i++) {
            if (cleanedStr[i] !== cleanedStr[len - 1 - i]) {
                cleanedStr = cleanedStr.slice(0, len - 1 - i) + cleanedStr[i] + cleanedStr.slice(len - i);
                changes++;
            }
        }

        if (changes === 0) {
            return 'Is Palindrome';
        } else {
            return cleanedStr.split('').reverse().join('');
        }
    }

    // Helper function to create the most meaningful anagram
    function meaningfulAnagram(str) {
        // Since creating a meaningful anagram is subjective and complex,
        // for simplicity, we'll just sort the letters while keeping word boundaries
        let words = str.match(/\b(\w+)\b/g);
        let sortedWords = words.map(word => word.split('').sort().join(''));
        return sortedWords.join(' ');
    }

    if (operation === 'reverse') {
        return text.split('').reverse().join('');
    } else if (operation === 'palindrome') {
        if (isPalindrome(text)) {
            return 'Is Palindrome';
        } else {
            return makePalindrome(text);
        }
    } else if (operation === 'anagram') {
        return meaningfulAnagram(text);
    } else {
        return text;
    }
}
