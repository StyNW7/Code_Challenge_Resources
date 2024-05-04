// Link: https://coddy.tech/challenges/soap_bar_weight_calculator_js

function soapMaker(weights) {
    
    const totalWeight = weights.reduce((sum, weight) => sum + weight, 0);

    const reversedWeights = weights.slice().reverse();

    const lastSoapWeight = reversedWeights[weights.length-1];

    const lastSoapPercentage = Math.round((lastSoapWeight / totalWeight) * 100);

    return {
        reversedWeights: reversedWeights,
        lastSoapPercentage: lastSoapPercentage
    };

}
