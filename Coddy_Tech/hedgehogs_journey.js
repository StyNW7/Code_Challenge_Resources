// Link: https://coddy.tech/challenges/hedgehogs_journey_js?daily=true

function countHedgehogSteps(terrain) {
    let count = 0;
    for (const word of terrain){
        if (word === 'grass') count += 1;
        else if (word === 'rock') continue;
        else break;
    }
    return count;
}
