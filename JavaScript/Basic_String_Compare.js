// Code Challenge by: Coddy.tech

// Link: https://coddy.tech/challenges/count_the_swans_js

function countSwans(swans) {
    
    let white = 0;
    let black = 0;

    for (let i = 0; i < swans.length; i++){
        if (swans[i] == "white") white++;
        else black++;
    }

    console.log("Today at the dike, there are %d white swans and %d black swans.", white, black);

}
