// Link: https://coddy.tech/challenges/writers_royalty_calculator_js?daily=true

function calculateRoyalties(pages, royaltyRate, bonusThreshold, bonusRate) {
    // Step 1: Calculate base royalties
    let baseRoyalty = pages * royaltyRate;
    
    // Step 2: Initialize bonus royalty
    let bonusRoyalty = 0;

    // Step 3: Check if pages exceed the bonus threshold
    if (pages > bonusThreshold) {
        // Step 4: Calculate bonus pages and bonus earnings
        let bonusPages = pages - bonusThreshold;
        bonusRoyalty = bonusPages * royaltyRate * (1 + bonusRate);
    }

    // Step 5: Return total royalties (base + bonus)
    return baseRoyalty + bonusRoyalty;
}
