// Link: https://coddy.tech/challenges/solitary_walk_in_the_woods_js

function solitary_walk(steps) {
    let sum = 0
    for (let i = 0; i < steps.length; i++){
        if (sum + steps[i] >= 0) sum += steps[i]
        else break;
    }
    return sum
}
