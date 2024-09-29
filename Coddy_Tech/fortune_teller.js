// Link: https://coddy.tech/challenges/fortune_teller_js?daily=true

function fortuneTeller(numbers, target) {
    let sum = 0;
    for (let number of numbers){
        if (number % 2 == 0) sum += number;
        else sum -= number;
    }
    return sum == target ? "Lucky!" : "Unlucky!"
}
