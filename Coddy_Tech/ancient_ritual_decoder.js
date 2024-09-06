// Link: https://coddy.tech/challenges/ancient_ritual_decoder_js?daily=true

function decodeRitual(ritualText) {
    let result = [];
    let pattern = /A[^A]*?Z/g; // Regular expression to match substrings starting with 'A' and ending with 'Z'
    
    let matches = ritualText.match(pattern); // Find all matching substrings

    if (matches) {
        for (let match of matches) {
            let reversed = match.split('').reverse().join(''); // Reverse the matched substring
            result.push(reversed);
        }
    }
    
    return result;
}
