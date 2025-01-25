// Link: https://coddy.tech/challenges/banquet_binary_candles_js?daily=true

function banquetBinaryCandles(decimalCandles) {
    // Convert the decimal number to its binary representation
    const binaryRepresentation = decimalCandles.toString(2);
    
    // Count the number of '1's in the binary string
    const litCandles = binaryRepresentation.split('').filter(char => char === '1').length;
    
    // Return the count of lit candles
    return litCandles;
}
