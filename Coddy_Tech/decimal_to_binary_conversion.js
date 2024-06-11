// Link: https://coddy.tech/challenges/decimal_to_binary_conversion_js

function decimalToBinary(number) {
    // Handle the special case where the number is 0
    if (number === 0) {
        return "0";
    }

    let binary = "";
    while (number > 0) {
        let remainder = number % 2;
        binary = remainder + binary;
        number = Math.floor(number / 2);
    }

    return binary;
}
