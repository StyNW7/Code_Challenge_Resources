// Link: https://coddy.tech/challenges/spacecraft_compartment_reconfiguration_js

function reconfigureSpacecraft(compartmentSizes, spacerSize) {
    const reconfiguredSizes = [];

    for (let i = 0; i < compartmentSizes.length; i++) {
        // Append the current compartment size to reconfiguredSizes
        reconfiguredSizes.push(compartmentSizes[i]);

        // If it's not the last compartment, append the spacer size
        if (i < compartmentSizes.length - 1) {
            reconfiguredSizes.push(spacerSize);
        }
    }

    return reconfiguredSizes;
}
