// Link: https://coddy.tech/challenges/fishing_simulator_js

function fishingDay(fishingSpot, patience) {
    
    let ans = "";

    for (let i  = 1; i <= patience; i++){
        if (i % 3 == 0 && i % 5 == 0) {
            ans += "fishberry"
            break;
        }
        else if (i % 3 == 0) ans += "trout";
        else if (i % 5 == 0) ans += "salmon";
        else ans += "old boot";
        if (i + 1 <= patience) ans += " "
    }

    let finalResult = ""

    finalResult += "I spent a peaceful day fishing at "
    finalResult += fishingSpot
    finalResult += ". I caught: "
    finalResult += ans

    return finalResult

}
