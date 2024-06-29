// Link: https://coddy.tech/challenges/shepherds_path_counter_js

function countShepherdMoves(field) {
    let count = 0
    for (let i = 1; i < field.length; i++){
        if (field[i] != field[i-1]) count++
    }

    return count;
    
}
