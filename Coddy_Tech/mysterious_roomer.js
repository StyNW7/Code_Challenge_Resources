// Link: https://coddy.tech/challenges/mysterious_roomer_js

function mysteriousRoomer(roomNumber, nights) {
    
    let contain = false
    for (let i of roomNumber){
        if (i === 'a' || i === 'A') {
            contain = true;
            break;
        }
    }

    let totalPrice = nights * 50

    if (contain) totalPrice += 15
    if (nights >= 7) totalPrice += 10
    else if (nights > 5) totalPrice += 20

    return totalPrice

}
