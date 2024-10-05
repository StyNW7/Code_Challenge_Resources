// Link: https://coddy.tech/challenges/garden_watering_schedule_optimizer_js?daily=true

function gardenPlanner(gardenZones, waterUnitsPerDay) {
    let ans = []
    for (let i = 0; i < gardenZones.length; i++){
        let sum = 0;
        for (let j = 0; j < gardenZones[i].length; j++){
            sum += gardenZones[i][j]
        }
        ans.push(sum)
    }
    return ans
}
