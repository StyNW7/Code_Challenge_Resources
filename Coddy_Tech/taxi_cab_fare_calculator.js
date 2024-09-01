// Link: https://coddy.tech/challenges/taxi_cab_fare_calculator_js?daily=true

function calculateCabFare(distances, baseFare) {
    let total = baseFare;
    for (let i = 0; i < distances.length; i++){
        total += distances[i] * 10;
    }
    return total;
}
