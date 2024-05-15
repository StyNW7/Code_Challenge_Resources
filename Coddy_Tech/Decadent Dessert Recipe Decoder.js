// Link: https://coddy.tech/challenges/decadent_dessert_recipe_decoder_js

function formatDessertRecipe(recipeString, ingredientCodes) {
    const ingredients = recipeString.split('|');
    const formattedIngredients = [];

    ingredients.forEach(ingredient => {
        const code = ingredient[0];
        const ingredientName = ingredientCodes[code];
        
        let quantity = '';
        let unit = '';

        if (ingredient.includes('%')) {
            const percentMatch = ingredient.match(/%(\d+)/);
            if (percentMatch) {
                quantity = percentMatch[1];
                unit = '%';
            }
        } 
        
        else if (ingredient.includes('#')) {
            const countMatch = ingredient.match(/#(\d+)/);
            if (countMatch) {
                quantity = parseInt(countMatch[1], 10);
                unit = 'count';
            }
        } 
        
        else if (ingredient.includes('@')) {
            const weightMatch = ingredient.match(/@(\d+)/);
            if (weightMatch) {
                quantity = weightMatch[1];
                unit = 'grams';
            }
        }

        let formattedIngredient = '';

        if (unit === 'count' && quantity > 1) {
            formattedIngredient = `${quantity} ${ingredientName}s`;
        } 
        
        else if (unit === 'count') {
            formattedIngredient = `${quantity} ${ingredientName}`;
        } 
        
        else {
            formattedIngredient = `${ingredientName}: ${quantity}${unit === '%' ? '%' : unit === 'grams' ? ' grams' : ''}`;
        }

        formattedIngredients.push(formattedIngredient);

    });

    return formattedIngredients.join('\n');
}
