// Link: https://coddy.tech/challenges/count_tiffany_bracelets_js

function countTiffanyBracelets(num) {
    let counter = 0
    while (num > 0){
        if (num % 2 == 1) {
            counter++
            num--
            num = num/2
        }
        else num = num/2
        
    }
    return counter
}
