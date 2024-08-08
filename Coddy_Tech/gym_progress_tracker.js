// Link: https://coddy.tech/challenges/gym_progress_tracker_js

function gymProgressTracker(day1Exercises, day2Exercises) {
    // Check if the lengths of the two arrays are the same
    if (day1Exercises.length !== day2Exercises.length) {
        return "You mixed it up today!";
    }

    // Compare the arrays element by element
    for (let i = 0; i < day1Exercises.length; i++) {
        if (day1Exercises[i] !== day2Exercises[i]) {
            return "You mixed it up today!";
        }
    }

    // If all elements are the same, return the same workout message
    return "You did the same workout on both days!";
}
