// Link: https://coddy.tech/challenges/colorful_flower_garden_composer_js

function flowerGardenComposer(flowerNames, separator) {
    // Define the list of colors
    const colors = ["red", "yellow", "pink", "blue", "purple"];
    
    // Create an empty string to store the final result
    let result = "";

    // Iterate through each flower name in the flowerNames array
    for (let i = 0; i < flowerNames.length; i++) {
        // Determine the associated color by using the index modulo the number of colors
        const color = colors[i % colors.length];
        
        // Concatenate the color, a space, and the flower name to the result string
        result += color + " " + flowerNames[i];
        
        // Append the separator if it's not the last flower
        if (i < flowerNames.length - 1) {
            result += separator;
        }
    }
    
    // Return the final result string
    return result;
}
