// Link: https://coddy.tech/challenges/balanced_contrast_js

function balancedContrast(arr, condition, str) {
    // Array manipulation
    let manipulatedArray = arr.map((element, index) => {
        return element > condition ? arr[arr.length - 1 - index] : element;
    });

    // String manipulation
    let reversedString = str.split('').reverse().join('');
    let manipulatedString = reversedString.split('').map((char, index) => {
        let originalChar = str[index];
        if ('a' <= originalChar && originalChar <= 'm') {
            return char.toUpperCase();
        } else if ('n' <= originalChar && originalChar <= 'z') {
            return char.toLowerCase();
        }
        return char;
    }).join('');

    // Return the manipulated array and string in an object
    return {
        array: manipulatedArray,
        string: manipulatedString
    };
}
