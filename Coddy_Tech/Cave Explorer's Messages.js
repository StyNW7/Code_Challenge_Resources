// Link: https://coddy.tech/challenges/cave_explorers_messages_js

function exploreCave(message1, message2) {
    let ans = "";
    ans = message1 + " & " + message2;
    if (message1 === message2) return "Echo: " + message1;
    else return ans;
}
