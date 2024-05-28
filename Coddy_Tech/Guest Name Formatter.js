// Link: https://coddy.tech/challenges/guest_name_formatter_js

function formatGuestNames(guestNames) {
    // Split the input string into an array of names
    const namesArray = guestNames.split(',');

    // Get the length of the array
    const length = namesArray.length;

    // Handle the different cases based on the length
    if (length === 1) {
        // If there is only one guest name, return the name as is
        return namesArray[0];
    } else if (length === 2) {
        // If there are exactly two guest names, return the names separated by " and "
        return namesArray.join(' and ');
    } else if (length > 2) {
        // If there are more than two guest names, format them accordingly
        const allExceptLast = namesArray.slice(0, -1).join(', ');
        const last = namesArray[length - 1];
        return `${allExceptLast}, and ${last}`;
    }
}
