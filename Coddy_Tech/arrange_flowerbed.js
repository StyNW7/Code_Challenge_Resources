// Link: https://coddy.tech/challenges/arrange_flowerbed_js?daily=true

function arrangeFlowerbed(flowerbed, newPlants) {
    let i = 0;
    
    while (i < flowerbed.length && newPlants > 0) {
        // Check if current slot is empty and both neighbors (if exist) are empty or at boundaries
        if (flowerbed[i] === 0 && 
            (i === 0 || flowerbed[i - 1] === 0) && 
            (i === flowerbed.length - 1 || flowerbed[i + 1] === 0)) {
            flowerbed[i] = 1; // Plant a new plant here
            newPlants--; // Decrease the number of new plants to plant
            i++; // Skip the next slot to ensure no adjacency
        }
        i++; // Move to the next slot
    }
    
    return flowerbed;
}
