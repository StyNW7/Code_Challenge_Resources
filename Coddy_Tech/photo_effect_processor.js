// Link: https://coddy.tech/challenges/photo_effect_processor_js

function processPhoto(photoData, effectType, intensity) {
    if (effectType === "Reverse") {
        // Reverse the order of elements in photoData
        return photoData.reverse();
    } else if (effectType === "Amplify") {
        // Multiply each element in photoData by the intensity value
        return photoData.map(value => value * intensity);
    } else {
        // Return the original photoData array for any other effectType
        return photoData;
    }
}
