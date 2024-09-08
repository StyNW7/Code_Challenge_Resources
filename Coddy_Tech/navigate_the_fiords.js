// Link: https://coddy.tech/challenges/navigate_the_fiords_js?daily=true

function navigateFiords(directions, startingPoint) {
    let position = startingPoint;

    for (let i = 0; i < directions.length; i++) {
        switch (directions[i]) {
            case 'north':
                if (position > 0) {
                    position--;
                }
                break;
            case 'south':
                if (position < directions.length - 1) {
                    position++;
                }
                break;
            case 'east':
                // Stay at the current position.
                break;
            case 'west':
                if (position + 2 < directions.length) {
                    position += 2;
                } else {
                    return 'lost'; // Exceeded the array boundary.
                }
                break;
            default:
                // If an unrecognized direction is encountered, do nothing.
                break;
        }
    }

    // Return the final position after following all directions.
    return directions[position];
}
