// Link: https://coddy.tech/challenges/flatweed_journey_simulation_js

function flatweedJourney(steps, direction) {
    let current = 0;

    for (let i = 0; i < steps; i++){
        if (direction == "north" && (current+1) % 5 != 0) current++;
        else if (direction == "south" && (current-1) % 5 != 0) current--;
    }

    return current;

}
