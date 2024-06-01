// Link: https://coddy.tech/challenges/garden_label_formatter_js

function createGardenLabel(plantName, plantAge, isFlowering) {
    let valid;
    if (isFlowering)valid = "yes"
    else valid = "no"
    let ans = "Plant: " + plantName + ", " + "Age: " + plantAge + " years, Flowering: " + valid
    return ans
}
