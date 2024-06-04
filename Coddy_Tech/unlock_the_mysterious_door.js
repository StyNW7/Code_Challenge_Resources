// Link: https://coddy.tech/challenges/unlock_the_mysterious_door_js

function unlockDoor(doorCode, numAttempts, clue) {
    for (let i = 1; i <= numAttempts; i++){
        if (doorCode == i) return "Door unlocked! The code was " + doorCode
    }
    return clue
}
