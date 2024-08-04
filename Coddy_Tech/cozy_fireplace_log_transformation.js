// Link: https://coddy.tech/challenges/cozy_fireplace_log_transformation_js

function cozyFireplaceTransform(logPattern, iterations) {
    // Convert the log pattern to an array for easier manipulation
    let logArray = logPattern.split('');
    const n = logArray.length;

    for (let iter = 0; iter < iterations; iter++) {
        // Create a copy of the current state to calculate the next state
        let newLogArray = [...logArray];

        for (let i = 0; i < n; i++) {
            // Rule 1: '#' turns into '-' if both sides are '-'
            if (logArray[i] === '#' && 
                (i > 0 && logArray[i - 1] === '-') && 
                (i < n - 1 && logArray[i + 1] === '-')) {
                newLogArray[i] = '-';
            }
            // Rule 2: '-' turns into '#' if followed by '#'
            if (logArray[i] === '-' && i < n - 1 && logArray[i + 1] === '#') {
                newLogArray[i] = '#';
            }
        }
        
        // Update the logArray with the new state
        logArray = newLogArray;
    }

    // Convert the array back to a string and return it
    return logArray.join('');
}
