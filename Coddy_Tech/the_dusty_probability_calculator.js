// Link: https://coddy.tech/challenges/the_dusty_probability_calculator_js

function calculateDustProbability(dustParticles, airVolume, maxParticles, settlingRate) {
    let totalParticles = 0;
    let dangerousIntervals = 0;

    dustParticles.forEach(particles => {
        // Add current interval's particles to the total
        totalParticles += particles;

        // Calculate settled particles
        let settledParticles = totalParticles * (settlingRate / 100);

        // Update total particles by subtracting settled particles
        totalParticles -= settledParticles;

        // Calculate particle concentration
        let concentration = totalParticles / airVolume;

        // Check if concentration exceeds maxParticles
        if (concentration > maxParticles) {
            dangerousIntervals++;
        }
    });

    // Calculate the probability as a percentage
    let probability = (dangerousIntervals / dustParticles.length) * 100;

    // Return the probability rounded to two decimal places
    return parseFloat(probability.toFixed(2));
}
