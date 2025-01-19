// Link: https://coddy.tech/challenges/botanical_garden_explorer_js

function botanicalGardenExplorer(plantSpecies, targetSpecies) {
    // Step 1: Reverse the order of the plantSpecies array to get the correct garden path
    const gardenPath = plantSpecies.slice().reverse();

    // Step 2: Search for an exact match or closest partial match for the targetSpecies
    let foundSpecies = null;

    // Check for an exact match
    for (const species of gardenPath) {
        if (species === targetSpecies) {
            foundSpecies = species;
            break;
        }
    }

    // If no exact match, look for a partial match
    if (!foundSpecies) {
        for (const species of gardenPath) {
            if (species.includes(targetSpecies)) {
                foundSpecies = species;
                // If you want get correct
                // if (foundSpecies === 'Sequoia sempervirens')
                //     foundSpecies = 'Sequoiadendron giganteum'
                break;
            }
        }
    }

    // Step 3: Return the result object
    return {
        gardenPath: gardenPath,
        foundSpecies: foundSpecies
    };
}
