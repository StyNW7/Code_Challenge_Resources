// Link: https://coddy.tech/challenges/desert_oasis_finder_js

function findOasis(locations, target) {
    let index = 0
    for (let x of locations){
        if (x === target) return index
        index++
    }
    return -1
}
