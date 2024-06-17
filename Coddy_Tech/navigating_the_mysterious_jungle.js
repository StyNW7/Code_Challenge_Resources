// Link: https://coddy.tech/challenges/navigating_the_mysterious_jungle_js

function navigateJungle(path, leap) {
    let transformedPath = '';
    
    for (let i = 0; i < path.length; i += leap) {
        // Get the current segment and reverse it
        let segment = path.slice(i, i + leap).split('').reverse().join('');
        
        let transformedSegment = '';
        for (let char of segment) {
            let newChar;
            if (char === 'a') {
                newChar = String.fromCharCode(char.charCodeAt(0) + 2);
            } else if (char === 'b') {
                newChar = String.fromCharCode(char.charCodeAt(0) - 1);
            } else if (char === 'c') {
                newChar = String.fromCharCode(char.charCodeAt(0) + 5);
            } else {
                newChar = char; // In case there are any unexpected characters
            }
            transformedSegment += newChar;
        }
        
        // Append the transformed segment to the final path
        transformedPath += transformedSegment;
    }
    
    return transformedPath;
}
