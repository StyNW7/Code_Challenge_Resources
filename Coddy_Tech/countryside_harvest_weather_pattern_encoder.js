// Link: https://coddy.tech/challenges/countryside_harvest_weather_pattern_encoder_js

function encodeWeatherPattern(weather, shiftAmount, modifier) {
    // Step 1: Convert weather string to ASCII values
    const asciiValues = [];
    for (let i = 0; i < weather.length; i++) {
        asciiValues.push(weather.charCodeAt(i));
    }

    // Step 2: Perform bitwise XOR with modifier
    const modifiedValues = asciiValues.map(value => value ^ modifier);

    // Step 3: Convert modified ASCII values to binary
    const binaryStrings = modifiedValues.map(value => {
        let binary = value.toString(2);
        // Ensure each binary string is 8 bits (ASCII standard)
        while (binary.length < 8) {
            binary = '0' + binary;
        }
        return binary;
    });

    // Step 4: Combine binary strings into a single binary string
    let combinedBinary = binaryStrings.join('');

    // Step 5: Perform cyclic right shift on the binary string
    const shift = shiftAmount % combinedBinary.length;
    combinedBinary = combinedBinary.slice(-shift) + combinedBinary.slice(0, -shift);

    // Step 6: Convert shifted binary string back to ASCII characters
    let encodedString = '';
    for (let i = 0; i < combinedBinary.length; i += 8) {
        const byte = combinedBinary.substr(i, 8);
        const charCode = parseInt(byte, 2);
        encodedString += String.fromCharCode(charCode);
    }

    return encodedString;
}
