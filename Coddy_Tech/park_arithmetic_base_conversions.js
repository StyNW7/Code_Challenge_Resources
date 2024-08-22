// Link: https://coddy.tech/challenges/park_arithmetic_base_conversions_js?daily=true

function parkArithmeticBaseConversions(number, convertToBase) {
    // Calculate square root and square
    const sqrtValue = Math.sqrt(number);
    const squareValue = Math.pow(number, 2);

    // Determine the base for conversion
    let base;
    switch (convertToBase.toLowerCase()) {
        case 'binary':
            base = 2;
            break;
        case 'octal':
            base = 8;
            break;
        case 'hexadecimal':
            base = 16;
            break;
        default:
            // If convertToBase is a number (like "3", "10", etc.)
            base = parseInt(convertToBase);
            if (isNaN(base) || base < 2 || base > 36) {
                throw new Error('Invalid base');
            }
    }

    // Convert the square root and square to the specified base
    const sqrtInBase = sqrtValue.toString(base);
    const squareInBase = squareValue.toString(base);

    // Return the results as an array of strings
    return [sqrtInBase, squareInBase];
}
