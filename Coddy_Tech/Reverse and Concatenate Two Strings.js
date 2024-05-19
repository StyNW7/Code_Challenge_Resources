// Link: https://coddy.tech/challenges/reverse_and_concatenate_two_strings_js

function reverseAndConcatenate(str1, str2) {
    // Reverse the order of characters in both str1 and str2
    const reversedStr1 = str1.split('').reverse().join('');
    const reversedStr2 = str2.split('').reverse().join('');

    // Concatenate the reversed str1 and reversed str2 together
    const concatenatedString = reversedStr1 + reversedStr2;

    // Return the concatenated string with the message prepended
    return `The reversed and concatenated string is: ${concatenatedString}`;
}
