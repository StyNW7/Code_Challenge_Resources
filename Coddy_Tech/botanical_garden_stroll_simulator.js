// Link: https://coddy.tech/challenges/botanical_garden_stroll_simulator_js?daily=true

function botanicalGardenStroll(plantsString, steps, direction) {
    
    const plants = plantsString.split(',');

    let currentIndex = direction === "forward" ? 0 : plants.length-1;

    let path = [];

    for (let i = 0; i < steps; i++){
        path.push(plants[currentIndex]);

        if (direction === "forward") currentIndex = (currentIndex+1) % plants.length;
        else currentIndex = (currentIndex - 1 + plants.length) % plants.length;
    }

    const finalPlant = plants[currentIndex];

    return `The path taken: ${path.join(' > ')}\nFinal plant reached: ${finalPlant}`;

}
