// Link: https://coddy.tech/challenges/bird_code_generator_js?daily=true

function birdCode(birdName) {
    let code = '';

    // Helper function to check if a number is prime
    function isPrime(num) {
        if (num <= 1) return false;
        for (let i = 2; i * i <= num; i++) {
            if (num % i === 0) return false;
        }
        return true;
    }

    // Helper function to check if a number is a perfect square
    function isPerfectSquare(num) {
        let sqrt = Math.sqrt(num);
        return sqrt === Math.floor(sqrt);
    }

    // Helper function to check if a word is a palindrome
    function isPalindrome(str) {
        let reversedStr = str.split('').reverse().join('');
        return str === reversedStr;
    }

    // Step 1: Check if the birdName has a prime number of vowels
    const vowels = 'aeiouAEIOU';
    let vowelCount = 0;
    for (let char of birdName) {
        if (vowels.includes(char)) {
            vowelCount++;
        }
    }
    if (isPrime(vowelCount)) {
        code += '1';
    }

    // Step 2: Check if the length of birdName is a perfect square
    if (isPerfectSquare(birdName.length)) {
        code += '2';
    }

    // Step 3: Check if the birdName is a palindrome
    if (isPalindrome(birdName)) {
        code += '3';
    }

    // Step 4: If none of the conditions were met, return "0"
    return code === '' ? '0' : code;
}
