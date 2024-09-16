// Link: https://coddy.tech/challenges/decoding_the_hieroglyphs_js?daily=true

function findHiddenMessage(hieroglyphs, key) {
    // Iterate through the array of hieroglyphs
    for (let hieroglyph of hieroglyphs) {
        // Check if the key is found in the current hieroglyph
        let keyIndex = hieroglyph.indexOf(key);
        
        // If the key is found
        if (keyIndex !== -1) {
            // Return the substring starting after the key until the end
            return hieroglyph.substring(keyIndex + key.length);
        }
    }
    
    // If no key is found in any hieroglyph
    return "No message found";
}
