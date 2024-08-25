// Link: https://coddy.tech/challenges/find_the_winning_horse_js?daily=true

function findWinningHorse(raceResults) {
    // Initialize an empty object to store the count of occurrences for each horse
    const horseCounts = {};

    // Iterate through the raceResults string to count occurrences of each horse
    for (let horse of raceResults) {
        if (horseCounts[horse]) {
            horseCounts[horse]++;
        } else {
            horseCounts[horse] = 1;
        }
    }

    // Find the horse with the maximum count
    let maxCount = 0;
    let winningHorse = null;

    for (let horse in horseCounts) {
        if (horseCounts[horse] > maxCount) {
            maxCount = horseCounts[horse];
            winningHorse = horse;
        }
    }

    // Find the index of the first occurrence of the winning horse
    return raceResults.indexOf(winningHorse);
}
