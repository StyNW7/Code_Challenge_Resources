// Link: https://coddy.tech/challenges/skin_damage_calculator_js?daily=true

function calculateSkinDamage(skinType, sunExposure, sunscreenSPF) {
    // Define base damage values for each skin type
    const baseDamageValues = {
        "I": 0.05,
        "II": 0.04,
        "III": 0.03,
        "IV": 0.02,
        "V": 0.01,
        "VI": 0.005
    };

    // Validate input parameters
    if (!baseDamageValues.hasOwnProperty(skinType)) {
        return { error: "Invalid skin type"};
    }
    if (typeof sunExposure !== "number" || sunExposure < 0) {
        return { error: "Invalid sun exposure" };
    }
    if (typeof sunscreenSPF !== "number" || sunscreenSPF < 0 || sunscreenSPF > 100) {
        return { error: "Invalid sunscreen SPF" };
    }

    // Get the base damage for the skin type
    const baseDamage = baseDamageValues[skinType];

    // Calculate actual damage per minute
    const actualDamagePerMinute = baseDamage * (1 - (sunscreenSPF / 100));

    // Calculate total cumulative damage
    const totalDamage = (actualDamagePerMinute * sunExposure).toFixed(2);

    // Determine damage status
    let status;
    if (totalDamage <= 2) {
        status = "Low";
    } else if (totalDamage <= 4) {
        status = "Moderate";
    } else if (totalDamage <= 6) {
        status = "High";
    } else {
        status = "Critical";
    }

    // Return the result object
    return {
        skinType,
        sunExposure,
        sunscreenSPF,
        totalDamage: parseFloat(totalDamage),
        status
    };
}
