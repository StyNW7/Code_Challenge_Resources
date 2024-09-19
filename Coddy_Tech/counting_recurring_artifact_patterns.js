// Link: https://coddy.tech/challenges/counting_recurring_artifact_patterns_js?daily=true

function countRecurringPatterns(patterns) {
    // Step 1: Create a frequency map to store how many times each pattern appears
    const frequencyMap = {};

    // Step 2: Count the occurrences of each pattern in the array
    for (const pattern of patterns) {
        if (frequencyMap[pattern]) {
            frequencyMap[pattern]++;
        } else {
            frequencyMap[pattern] = 1;
        }
    }

    // Step 3: Count how many patterns have a frequency greater than 1
    let recurringPatternsCount = 0;
    for (const count of Object.values(frequencyMap)) {
        if (count > 1) {
            recurringPatternsCount++;
        }
    }

    // Step 4: Return the count of recurring patterns
    return recurringPatternsCount;
}
