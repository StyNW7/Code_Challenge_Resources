// Link: https://coddy.tech/challenges/reverse_grain_field_js?daily=true

function reverseGrain(grainField) {
    return grainField.map(grain => {
        // Reverse the string
        let reversedGrain = grain.split('').reverse().join('');
        // Take the first half of the reversed string
        let halfLength = Math.floor(reversedGrain.length / 2);
        return reversedGrain.slice(0, halfLength);
    });
}
