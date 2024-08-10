// Link: https://coddy.tech/challenges/decipher_the_ancient_code_js

function decipherAncientCode(code, shiftKey, keyPhrase) {
    // Function to check if a number is prime
    function isPrime(num) {
        if (num <= 1) return false;
        if (num <= 3) return true;
        if (num % 2 === 0 || num % 3 === 0) return false;
        for (let i = 5; i * i <= num; i += 6) {
            if (num % i === 0 || num % (i + 2) === 0) return false;
        }
        return true;
    }

    // Step 1: Shift each character in the code string
    let deciphered = "";
    for (let char of code) {
        if (/[a-z]/.test(char)) {
            let newCharCode = char.charCodeAt(0) + shiftKey;
            if (newCharCode > 'z'.charCodeAt(0)) {
                newCharCode -= 26;
            }
            deciphered += String.fromCharCode(newCharCode);
        } else {
            deciphered += char;
        }
    }

    // Step 2: Split the deciphered string into words and process each word
    let words = deciphered.split(" ").map(word => {
        if (word.includes(keyPhrase)) {
            return word.split("").reverse().join("");
        } else {
            return word.toUpperCase();
        }
    });

    // Step 3: Join the processed words back into a string
    let transformedString = words.join(" ");

    // Step 4: Modify the string based on the position of each character
    let finalString = transformedString.split("").map((char, index) => {
        if (/[A-Z]/.test(char) && !isPrime(index + 1)) {
            return "_";
        }
        return char;
    }).join("");

    return finalString;
}
