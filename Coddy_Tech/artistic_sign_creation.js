// Link: https://coddy.tech/challenges/artistic_sign_creation_js

function createArtisticSign(text, decorations) {
    let str1 = "";
    let str2 = "";
    let index;
    for (let i = 0; i < decorations.length; i++){
        if (decorations[i] === '&') str1 += '&';
        else str2 += '*';
    }
    return str1 + text + str2;
}
