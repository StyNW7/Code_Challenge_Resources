// Link: https://coddy.tech/challenges/unmasking_the_mansions_secrets_js

function decodeMessage(message) {
    let str = "";
    for (let i = message.length-1; i >= 0; i--){
        str += message[i];
    }
    let final  = ""
    final = str + message;
    return final;
}
