// Link: https://coddy.tech/challenges/serpents_path_of_chaos_js?daily=true

function serpentPath(gardenLength, directionChanges) {
    let arr = [...Array(gardenLength)].fill(0);
    arr[0] = 1;
    let position = 0;
    if (directionChanges.length === 0) {
        arr[0] = 2;
        return arr;
    }
    for (const direction of directionChanges){
        if (direction === 'right'){
            if((position+1) === gardenLength){
                position = 0;
                arr[position]++;
            }
            else {
                position += 1;
                arr[position]++;
            }
        }
        else if (direction === 'left') {
            if((position-1) === -1){
                position = gardenLength-1;
                arr[position]++;
            }
            else {
                position -= 1;
                arr[position]++;
            }
        }
    }
    return arr;
}
