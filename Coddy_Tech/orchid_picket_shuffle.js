// Link: https://coddy.tech/challenges/orchid_picket_shuffle_js

function orchidPicketShuffle(picketNumber) {
    // Convert the picketNumber to a string
    let numberStr = picketNumber.toString();

    // Reverse the order of the digits in the string
    let reversedStr = numberStr.split('').reverse().join('');

    // Increment each digit by 1, with 9 becoming 0
    let incrementedStr = '';
    for (let char of reversedStr) {
        let digit = parseInt(char);
        digit = (digit + 1) % 10;  // Increment and wrap around
        incrementedStr += digit.toString();
    }

    // Convert the resulting string back to an integer
    return parseInt(incrementedStr);
}
