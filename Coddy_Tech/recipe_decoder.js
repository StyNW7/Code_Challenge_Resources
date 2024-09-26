// Link: https://coddy.tech/challenges/recipe_decoder_js?daily=true

function decodeRecipe(encodedRecipe) {
    let parts = encodedRecipe.split('#')
    let decodedIngredients = []

    for (let i = 0; i < parts.length; i += 2) {
        let quantity = parts[i];
        let ingredient = parts[i + 1];
        
        // Extract the numeric part of the quantity
        let tablespoons = quantity.substring(1);
        
        decodedIngredients.push(`${tablespoons} tablespoons of ${ingredient}`);
    }
    
    // Join the ingredients into a single string separated by commas
    return decodedIngredients.join(', ');

}
