// Link: https://coddy.tech/challenges/park_path_finder_js

function navigateCrowdedPark(grid, startX, startY, endX, endY) {
    const rows = grid.length;
    const cols = grid[0].length;

    // Directions for moving up, down, left, right
    const directions = [
        [-1, 0], [1, 0], [0, -1], [0, 1]
    ];

    // Queue for BFS
    const queue = [[startX, startY, 0]];
    // Visited array to keep track of visited cells
    const visited = Array.from({ length: rows }, () => Array(cols).fill(false));
    visited[startX][startY] = true;

    while (queue.length > 0) {
        const [x, y, steps] = queue.shift();

        // If we reached the end position
        if (x === endX && y === endY) {
            return steps;
        }

        // Explore neighbors
        for (const [dx, dy] of directions) {
            const newX = x + dx;
            const newY = y + dy;

            // Check bounds and whether the cell is already visited
            if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && !visited[newX][newY]) {
                // Mark the cell as visited
                visited[newX][newY] = true;

                // Calculate new steps depending on the cell type
                if (grid[newX][newY] === 0) {
                    queue.push([newX, newY, steps + 1]);
                } else if (grid[newX][newY] === 2) {
                    queue.push([newX, newY, steps + 2]);
                }
            }
        }
    }

    // Return -1 if there is no path, though the problem guarantees there is always a path
    return -1;
}
