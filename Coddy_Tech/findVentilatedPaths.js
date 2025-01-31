function findVentilatedPaths(altitudeGrid, minAltitudeDiff) {
    const rows = altitudeGrid.length;
    const cols = altitudeGrid[0].length;
    const memo = new Map(); // Memoization for optimized recursion

    function dfs(r, c) {
        // If reached the bottom-right corner, return a valid path (empty string for concatenation)
        if (r === rows - 1 && c === cols - 1) {
            return [""];
        }

        // Use a unique key for memoization
        const key = `${r},${c}`;
        if (memo.has(key)) {
            return memo.get(key);
        }

        const result = [];
        const currentAltitude = altitudeGrid[r][c];

        // Move Right
        if (c + 1 < cols && Math.abs(altitudeGrid[r][c + 1] - currentAltitude) >= minAltitudeDiff) {
            const rightPaths = dfs(r, c + 1);
            for (const path of rightPaths) {
                result.push("right" + (path ? "," + path : ""));
            }
        }

        // Move Down
        if (r + 1 < rows && Math.abs(altitudeGrid[r + 1][c] - currentAltitude) >= minAltitudeDiff) {
            const downPaths = dfs(r + 1, c);
            for (const path of downPaths) {
                result.push("down" + (path ? "," + path : ""));
            }
        }

        // Store result in memo before returning
        memo.set(key, result);
        return result;
    }

    return dfs(0, 0);
}
