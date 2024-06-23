// Link: https://coddy.tech/challenges/garden_walk_counter_js

function gardenWalk(path, initialValue = 0) {
    let counter = initialValue;
    let before = false;
    for (let i = 0; i < path.length; i++){
        if (path[i] === 'R') {
            initialValue += 2
            if (path[i-1] === 'R' && path[i-2] === 'R'){
                return initialValue;
            }
        }
        else if (path[i] === 'T') initialValue *= 3;
        else if (path[i] === 'S') {
            if (initialValue % 2 == 1) {
                initialValue--;
                initialValue /= 2;
            }
            else initialValue /= 2;
        }
        else if (path[i] === 'D') {
            if (path[i-1] === 'D' && !before){
                before = true;
                continue;
            }
            before = false
            initialValue -= 1;
        }
        else if (path[i] === 'X') initialValue = counter;
    }
    return initialValue;
}
