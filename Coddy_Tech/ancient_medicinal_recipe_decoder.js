// Link: https://coddy.tech/challenges/ancient_medicinal_recipe_decoder_js

function decodeMedicinalRecipe(binaryRecipe, ingredients) {
    // Step 1: Convert the binary string to a decimal number
    const recipeIdentifier = parseInt(binaryRecipe, 2);

    // Step 2: Initialize an empty array to store the indices of required ingredients
    let requiredIngredients = [];

    // Step 3: Iterate through the ingredients array
    for (let i = 0; i < ingredients.length; i++) {
        // Step 4: Check if the recipe identifier is divisible by the (index + 1)
        if (recipeIdentifier % (i + 1) === 0) {
            // Step 5: If it is, add the (index + 1) to the result array
            requiredIngredients.push(i + 1);
        }
    }

    // Step 6: Return the array of required ingredient indices
    return requiredIngredients;
}
