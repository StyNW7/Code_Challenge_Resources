// Link: https://coddy.tech/challenges/enchanted_string_checker_js?daily=true

function isEnchantedString(str) {
    if (str.length === 0) {
        return false; // Empty string is not considered enchanted
    }

    let hasUppercase = false;
    let hasLowercase = false;
    let hasDigit = false;
    let asciiSum = 0;

    // Iterate over each character in the string
    for (let i = 0; i < str.length; i++) {
        const char = str[i];
        const asciiValue = char.charCodeAt(0);
        asciiSum += asciiValue;

        if (char >= 'A' && char <= 'Z') {
            hasUppercase = true;
        } else if (char >= 'a' && char <= 'z') {
            hasLowercase = true;
        } else if (char >= '0' && char <= '9') {
            hasDigit = true;
        }
    }

    // Check if the ASCII sum is a prime number
    if (!isPrime(asciiSum)) {
        return false;
    }

    // Return true if all conditions are satisfied
    return hasUppercase && hasLowercase && hasDigit;
}

// Helper function to check if a number is prime
function isPrime(num) {
    if (num <= 1) return false;
    if (num <= 3) return true;

    if (num % 2 === 0 || num % 3 === 0) return false;

    for (let i = 5; i * i <= num; i += 6) {
        if (num % i === 0 || num % (i + 2) === 0) return false;
    }

    return true;
}
