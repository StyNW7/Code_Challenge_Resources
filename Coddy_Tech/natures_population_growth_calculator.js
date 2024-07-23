// Link: https://coddy.tech/challenges/natures_population_growth_calculator_js

function countNatureGrowth(initialPopulation, growthRate, years) {
    // Calculate the projected population using the given formula
    const finalPopulation = initialPopulation * Math.pow(1 + growthRate, years);
    
    // Round down the result to the nearest whole number
    return Math.floor(finalPopulation);
}
