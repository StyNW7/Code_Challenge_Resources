// Link: https://coddy.tech/challenges/strategic_number_game_js?daily=true

function findStrategicNumbers(gameBoard, strategicNumber) {
    const primes = [];
    const fibonaccis = [];
    const squares = [];

    // Helper function to check if a number is prime
    function isPrime(num) {
        if (num <= 1) return false;
        if (num === 2) return true;
        if (num % 2 === 0) return false;
        for (let i = 3; i * i <= num; i += 2) {
            if (num % i === 0) return false;
        }
        return true;
    }

    // Helper function to generate Fibonacci numbers up to the strategicNumber
    function generateFibonacci(max) {
        const fibs = [0, 1];
        while (true) {
            const next = fibs[fibs.length - 1] + fibs[fibs.length - 2];
            if (next > max) break;
            fibs.push(next);
        }
        return new Set(fibs); // Convert to a set for quick look-up
    }

    // Helper function to check if a number is a perfect square
    function isPerfectSquare(num) {
        const sqrt = Math.sqrt(num);
        return sqrt === Math.floor(sqrt);
    }

    // Generate Fibonacci numbers up to the strategicNumber
    const fibonacciSet = generateFibonacci(strategicNumber);

    // Iterate through the gameBoard array
    for (let num of gameBoard) {
        if (num > strategicNumber) break;

        if (isPrime(num)) primes.push(num);
        if (fibonacciSet.has(num)) fibonaccis.push(num);
        if (isPerfectSquare(num)) squares.push(num);
    }

    // Return the result object
    return {
        primes,
        fibonaccis,
        squares
    };
}
