// Link: https://coddy.tech/challenges/starfish_finder_js

function countStarfish(text) {
    // Convert the input text to lowercase for case-insensitive matching
    const lowerCaseText = text.toLowerCase();
    
    // Split the lowercase text into an array of words
    const words = lowerCaseText.split(/\s+/);

    // Initialize counters for total and standalone occurrences of 'starfish'
    let total = 0;
    let standalone = 0;

    // Iterate through each word in the array
    words.forEach(word => {
        // Check if the word is exactly 'starfish'
        if (word === 'starfish') {
            standalone++;
            total++;
        } 
        // Check if the word contains 'starfish' as a substring
        else if (word.includes('starfish')) {
            total++;
        }
    });

    // Return an object with the total and standalone counts
    return {
        total: total,
        standalone: standalone
    };
}
