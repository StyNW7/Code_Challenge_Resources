// Link: https://coddy.tech/challenges/visionary_pyramid_exploration_js?daily=true

function visionaryPyramid(maxLevels) {
    if (maxLevels < 1 || maxLevels > 10) {
        return "Error: maxLevels should be between 1 and 10.";
    }

    let pyramid = [];
    let currentOdd = 1;

    // Determine the width of the bottom row for proper alignment
    const maxWidth = maxLevels * 2 - 1;

    // Outer loop for each level
    for (let level = 1; level <= maxLevels; level++) {
        let levelNumbers = [];
        let oddCount = 0;  // Tracks how many odd numbers are in the current level

        // Inner loop for odd numbers in the current level
        while (oddCount < level) {
            if (currentOdd % 5 === 0) {
                currentOdd += 2;  // Skip the next odd number if current is divisible by 5
                continue;
            }
            levelNumbers.push(currentOdd);  // Add the odd number to the current level
            currentOdd += 2;  // Move to the next odd number
            oddCount++;
        }

        // Format the level as a centered string
        const levelString = levelNumbers.join(' ');
        const padding = ' '.repeat((maxWidth - levelString.length) / 2);
        pyramid.push(padding + levelString + padding);
    }

    return pyramid;
}
