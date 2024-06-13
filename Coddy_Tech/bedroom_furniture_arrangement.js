// Link: https://coddy.tech/challenges/bedroom_furniture_arrangement_js

function arrangeFurniture(furnitureList, bedroomWidth, bedroomLength) {
    // Helper function to check if a piece of furniture can be placed at the given position
    function canPlaceFurniture(grid, x, y, width, length) {
        if (x + width > bedroomWidth || y + length > bedroomLength) return false;
        for (let i = y; i < y + length; i++) {
            for (let j = x; j < x + width; j++) {
                if (grid[i][j] !== '.') return false;
            }
        }
        return true;
    }

    // Helper function to place the furniture on the grid
    function placeFurniture(grid, x, y, width, length, char) {
        for (let i = y; i < y + length; i++) {
            for (let j = x; j < x + width; j++) {
                grid[i][j] = char;
            }
        }
    }

    // Parse the furnitureList to extract furniture details
    let furnitureItems = furnitureList.map(item => {
        let [name, dimensions] = item.split(':');
        let [width, length] = dimensions.split('x').map(Number);
        return { name, width, length, char: name[0]};
    });

    // Create the bedroom grid
    let grid = Array.from({ length: bedroomLength }, () => Array(bedroomWidth).fill('.'));

    // Try to place each furniture item in the grid
    for (let { name, width, length, char } of furnitureItems) {
        let placed = false;
        for (let y = 0; y <= bedroomLength - length; y++) {
            for (let x = 0; x <= bedroomWidth - width; x++) {
                if (canPlaceFurniture(grid, x, y, width, length)) {
                    placeFurniture(grid, x, y, width, length, char);
                    placed = true;
                    break;
                }
            }
            if (placed) break;
        }
        if (!placed) return "Not enough space";
    }

    return grid.map(row => row.join('')).join('\n');
}
