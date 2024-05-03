// Link: https://coddy.tech/challenges/binary_breath_js

function binaryBreath(n) {
    let breath = "";
    for (let i = 0; i <= n; i++){
        if (i % 2 == 0) breath += "10";
        else breath += "01";
    }
    return breath
}
