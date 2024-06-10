// Link: https://coddy.tech/challenges/family_gathering_meal_cost_calculator_js

function calculateMealCost(guestCount, mealType) {
    return mealType === 'vegetarian' ? guestCount * 10 : guestCount * 15
}
