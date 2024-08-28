// Link: https://coddy.tech/challenges/love_journey_js?daily=true

function loveJourney(loveScore, memoryBook) {
    let total = loveScore;
    for (let i = 1; i < memoryBook.length-1; i++){
        if (memoryBook[i] % 2 === 0) total += memoryBook[i];
        else total -= memoryBook[i];
    }
    return total;
}
