// Link: https://coddy.tech/challenges/forest_stroll_js

function forestStroll(n) {
    
    let ans = "";

    for (let i = 1; i <= n; i++){
        if (i % 15 == 0) ans += "b";
        else if (i % 5 == 0) ans += "r";
        else if (i % 3 == 0) ans += "d";
        else ans += "*";
    }

    return ans;

}
