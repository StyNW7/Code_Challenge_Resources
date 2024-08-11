// Link: https://coddy.tech/challenges/whimsical_tassel_base_converter_js

function tasselBaseConverter(tasselColor, number) {
    // Convert the input number string to a decimal integer
    const decimalNumber = parseInt(number, 10);

    // Determine the base to convert to based on the tasselColor
    let base;
    switch (tasselColor) {
        case "red":
            base = 2;  // Binary
            break;
        case "blue":
            base = 16; // Hexadecimal
            break;
        case "green":
            base = 8;  // Octal
            break;
        default:
            throw new Error("Invalid tassel color"); // Handle invalid colors
    }

    // Convert the decimal number to the desired base and return it as a string
    return decimalNumber.toString(base).toUpperCase();
}
