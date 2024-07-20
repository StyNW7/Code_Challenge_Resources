// Link: https://coddy.tech/challenges/beach_wave_pattern_simulation_js

function beachWavePattern(initialWave, transforms) {
    let output = [];

    // Add the initial wave to the output array
    output.push(initialWave.join(','));
    
    // Iterate through each transformation
    transforms.forEach(([position, value]) => {
        // Apply the transformation to the initialWave array
        initialWave[position] += value;
        
        // Create a string representation of the current wave heights
        let waveString = initialWave.join(',');
        
        // Add the string representation to the output array
        output.push(waveString);
    });
    
    return output;
}
