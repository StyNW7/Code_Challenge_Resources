// Link: https://coddy.tech/challenges/bond_through_numbers_js

function bondThroughNumbers(decimalNumber) {
    // Convert the given decimal number to its binary representation
    let binaryRepresentation = decimalNumber.toString(2);

    // Reverse the order of the bits in the binary representation
    let reversedBinary = binaryRepresentation.split('').reverse().join('');

    // Convert the reversed binary representation back to a decimal number
    let reversedDecimal = parseInt(reversedBinary, 2);

    return reversedDecimal;
}
