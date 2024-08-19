// Link: https://coddy.tech/challenges/city_street_beauty_js

function calculateStreetBeauty(streetView, steps) {
    let treesCount = 0;
    let currentIndex = 0;
    const totalSegments = streetView.length;

    // Traverse through the steps
    for (let i = 0; i < steps; i++) {
        // Loop around if we reach the end of the streetView
        currentIndex = i % totalSegments;

        // Count trees ('T') in the current segment
        for (let char of streetView[currentIndex]) {
            if (char === 'T') {
                treesCount++;
            }
        }
    }

    // Determine final position after all steps
    finalPosition = currentIndex;

    // Return the result as an object
    return {
        treesCount: treesCount,
        finalPosition: finalPosition
    };
}
