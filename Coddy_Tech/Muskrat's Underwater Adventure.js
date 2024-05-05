// Link: https://coddy.tech/challenges/muskrats_underwater_adventure_js

function muskratAdventure(day) {
    let activity;

    switch (day) {
        case 1:
            activity = "Dive for clams";
            break;
        case 2:
            activity = "Swim in the seaweed forest";
            break;
        case 3:
            activity = "Explore the coral reef";
            break;
        case 4:
            activity = "Play with friendly fish";
            break;
        case 5:
            activity = "Take a nap in a sea cave";
            break;
        default:
            activity = "Float on the ocean waves";
            break;
    }

    if (day % 3 === 0) {
        activity = "Search for a new shell";
    }

    return activity;
}
