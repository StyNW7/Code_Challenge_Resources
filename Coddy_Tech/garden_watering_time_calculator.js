// Link: https://coddy.tech/challenges/garden_watering_time_calculator_js?daily=true

function calculateWateringTime(plantTypes) {

    let time = 0;
    
    const mapping = {
        "Rose": 10,
        "Tulip": 5,
        "Sunflower": 8,
        "Daisy": 6,
        "Lily": 7
    }

    const plantArray = plantTypes.split(',');

    for (let plant of plantArray){
        plant = plant.trim()
        time += mapping[plant] || 5;
    }

    return time

}
