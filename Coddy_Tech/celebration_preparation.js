// Link: https://coddy.tech/challenges/celebration_preparation_js

function celebrationPrep(binaryNumbers) {
    // Convert each binary number to its decimal equivalent
    const decimalNumbers = binaryNumbers.map(binary => parseInt(binary, 2));
    
    // Sort the decimal numbers in ascending order
    decimalNumbers.sort((a, b) => a - b);
    
    // Return the sorted array of decimal numbers
    return decimalNumbers;
}
