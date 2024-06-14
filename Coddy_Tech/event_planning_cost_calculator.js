// Link: https://coddy.tech/challenges/event_planning_cost_calculator_js

function calculateEventCost(services, attendees) {
    let totalCost = 0
    for (let i = 0; i < services.length; i++){
        if (services[i] === 'catering') totalCost += (500 + (15*attendees))
        if (services[i] === 'sound') totalCost += (300 + (5*attendees))
        if (services[i] === 'decoration') totalCost += (250 + (10*attendees))
        if (services[i] === 'photography') totalCost += (400 + (8*attendees))
    }
    return totalCost
}
