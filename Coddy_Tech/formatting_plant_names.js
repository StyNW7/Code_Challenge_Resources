// Link: https://coddy.tech/challenges/formatting_plant_names_js

function formatPlantName(plantName) {
     return plantName
        .split(' ') // Split the string into an array of words
        .map(word => 
            word.charAt(0).toUpperCase() + word.slice(1).toLowerCase() // Capitalize the first letter and make the rest lowercase
        )
        .join(' '); // Join the words back into a single string with spaces
}
