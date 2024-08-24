// Link: https://coddy.tech/challenges/calculating_financial_mistakes_js?daily=true

function calculateFinancialMistakes(years, mistakesPerYear) {
    let total = 0;
    let cost = 100;
    
    if (years === 0) {
        return total;
    }
    
    for (let i = 0; i < mistakesPerYear.length; i++) {
        total += mistakesPerYear[i] * cost;
        cost += 100;
    }
    
    return total;
}
