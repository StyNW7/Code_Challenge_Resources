// Link: https://coddy.tech/challenges/building_a_wall_with_minimum_bricks_js

function buildWall(brickHeights, targetHeight) {
    let minBricks = Infinity; // Variable to track the minimum number of bricks required
    
    // Sorting brickHeights in descending order
    brickHeights.sort((a, b) => b - a);
    
    const n = brickHeights.length;
    
    // Iterate through all possible combinations of bricks using nested loops
    for (let mask = 0; mask < (1 << n); mask++) {
        let currentHeight = 0;
        let currentBricks = 0;
        
        // Check each brick in the mask
        for (let i = 0; i < n; i++) {
            if (mask & (1 << i)) { // If the i-th bit is set in the mask
                currentHeight += brickHeights[i];
                currentBricks++;
                
                // If the current height matches the target height, update minBricks
                if (currentHeight === targetHeight) {
                    minBricks = Math.min(minBricks, currentBricks);
                    break; // No need to continue if we found a valid combination
                }
            }
        }
    }
    
    // Return the minimum number of bricks required or -1 if not possible
    return minBricks === Infinity ? -1 : minBricks;
}
