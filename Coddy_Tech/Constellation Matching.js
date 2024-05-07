// Link: https://coddy.tech/challenges/constellation_matching_js

function analyzeStarData(constellations, targetConstellation) {
     for (let i = 0; i < constellations.length; i++) {
        const constellation = constellations[i];
        
        if (constellation.includes(targetConstellation)) {
            constellations[i] = "MATCH FOUND";
        }
    }
    
    return constellations;
}
