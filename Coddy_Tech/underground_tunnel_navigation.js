// Link: https://coddy.tech/challenges/underground_tunnel_navigation_js

function navigateUndergroundTunnel(tunnelMap, startPos, targetPos, obstacles) {
    // Parse the obstacles into a map for quick lookup
    const obstacleMap = new Map();
    obstacles.forEach(obstacle => {
        obstacleMap.set(obstacle.position, obstacle);
    });

    // BFS setup
    const queue = [{ pos: startPos, steps: 0, clearedObstacles: [] }];
    const visited = new Set();
    visited.add(startPos);

    while (queue.length > 0) {
        const { pos, steps, clearedObstacles } = queue.shift();

        // Check if we've reached the target position
        if (pos === targetPos) {
            return {
                reachable: true,
                steps: steps,
                clearedObstacles: clearedObstacles
            };
        }

        // Explore the next positions (left and right)
        const nextPositions = [pos - 1, pos + 1];
        for (const nextPos of nextPositions) {
            if (nextPos >= 0 && nextPos < tunnelMap.length && !visited.has(nextPos)) {
                visited.add(nextPos);

                // Check if the next position is a safe path
                if (tunnelMap[nextPos] === '0') {
                    if (obstacleMap.has(nextPos)) {
                        const obstacle = obstacleMap.get(nextPos);
                        const clearanceCode = obstacle.clearanceCode;

                        // If the obstacle can be cleared, continue
                        if (clearanceCode === 1) {  // Assuming 1 is the required code to clear the obstacle
                            queue.push({
                                pos: nextPos,
                                steps: steps + 1,
                                clearedObstacles: [...clearedObstacles, { ...obstacle, clearedAt: steps + 1 }]
                            });
                        }
                    } else {
                        // If there is no obstacle, simply move to the next position
                        queue.push({
                            pos: nextPos,
                            steps: steps + 1,
                            clearedObstacles: clearedObstacles
                        });
                    }
                }
            }
        }
    }

    // If we exhaust the queue without reaching the target position, it's not reachable
    return {
        reachable: false,
        steps: -1,
        clearedObstacles: []
    };
}
