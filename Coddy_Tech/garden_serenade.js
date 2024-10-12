// Link: https://coddy.tech/challenges/garden_serenade_js?daily=true

function gardenSerenade(plantHeights, melodyLength) {
    let arr = []
    for (let i of plantHeights){
        if (i % 7 === 0) arr.push('C')
        else if (i % 7 === 1) arr.push('D')
        else if (i % 7 === 2) arr.push('E')
        else if (i % 7 === 3) arr.push('F')
        else if (i % 7 === 4) arr.push('G')
        else if (i % 7 === 5) arr.push('A')
        else if (i % 7 === 6) arr.push('B')
    }
    if (plantHeights.length < melodyLength){
        let diff = melodyLength - plantHeights.length;
        for (let i = 0; i < diff; i++){
            arr.push(arr[i])
        }
    }
    return arr.join(' ');
}
