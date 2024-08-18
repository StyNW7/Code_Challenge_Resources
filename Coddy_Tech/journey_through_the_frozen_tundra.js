// Link: https://coddy.tech/challenges/journey_through_the_frozen_tundra_js

function manageJourney(weatherCondition, suppliesLeft) {
    if (weatherCondition === 'blizzard') return 'stay'
    else if (weatherCondition === 'snowy' && suppliesLeft < 3) return 'gather supplies'
    else return 'proceed'
}
