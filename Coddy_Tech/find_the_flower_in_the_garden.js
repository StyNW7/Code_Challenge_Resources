// Link: https://coddy.tech/challenges/find_the_flower_in_the_garden_js

function findFlower(garden, flower) {
    // let i = 0
    // for (let f in garden){
    //     if (f === flower) return i
    //     i++
    // }
    // return -1
    return garden.indexOf(flower);
}
