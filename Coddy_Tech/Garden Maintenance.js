// Link: https://coddy.tech/challenges/garden_maintenance_js

function maintainGarden(gardenBed, hedge) {
    // Water all dry plants in the garden bed
    let wateredGardenBed = gardenBed.replace(/d/g, 'w');
    
    // Trim all untrimmed sections in the hedge by reversing each 'u' substring
    let trimmedHedge = hedge.replace(/u+/g, match => match.split('').reverse().join(''));
    
    // Return the results as an array
    return [wateredGardenBed, trimmedHedge];
}
