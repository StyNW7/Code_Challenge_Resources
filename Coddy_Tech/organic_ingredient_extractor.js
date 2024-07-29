// Link: https://coddy.tech/challenges/organic_ingredient_extractor_js

function getOrganicIngredients(ingredientsList) {
    // Split the ingredients list into an array
    let ingredientsArray = ingredientsList.split(', ');

    // Filter out ingredients that start with "organic"
    let organicIngredients = ingredientsArray.filter(ingredient => ingredient.startsWith("organic"));

    // Join the organic ingredients array back into a string separated by ", "
    return organicIngredients.join(', ');
}
