// Link: https://coddy.tech/challenges/natures_hidden_message_js

function decodeNatureMessage(stoneSequence, skipPattern) {
    let s = "";
    for (let i = 0; i < stoneSequence.length; i += skipPattern){
        s += stoneSequence[i];
    }
    return s;
}
