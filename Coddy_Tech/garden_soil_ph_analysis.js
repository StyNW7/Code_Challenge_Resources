// Link: https://coddy.tech/challenges/garden_soil_ph_analysis_js

function analyzeGardenSoil(soilSamples) {
    let sumPH = 0;
    let acidicCount = 0;
    let alkalineCount = 0;

    soilSamples.forEach(pH => {
        sumPH += pH;
        if (pH < 7) {
            acidicCount++;
        } else if (pH > 7) {
            alkalineCount++;
        }
    });

    let averagePH = sumPH / soilSamples.length;
    averagePH = Math.round(averagePH * 100) / 100;

    return [averagePH, acidicCount, alkalineCount];
}
