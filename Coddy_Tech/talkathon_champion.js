// Link: https://coddy.tech/challenges/talkathon_champion_js?daily=true

function talkathonChampion(participants, topic, binaryScores) {
    // Convert topic to lowercase for case-insensitive comparison
    const lowerCaseTopic = topic.toLowerCase();

    // Create an array to store participants' scores with bonuses
    let scores = participants.map((name, index) => {
        // Convert binary score to decimal
        let decimalScore = parseInt(binaryScores[index], 2);
        
        // Apply 1.5x bonus if the participant's name contains the topic (case-insensitive)
        if (name.toLowerCase().includes(lowerCaseTopic)) {
            decimalScore *= 1.5;
        }

        // Return an object with participant's name and their score
        return { name, score: decimalScore };
    });

    // Sort participants by score in descending order and by name in lexicographically ascending order
    scores.sort((a, b) => {
        if (b.score === a.score) {
            return a.name.localeCompare(b.name);
        }
        return b.score - a.score;
    });

    // Return the champion (first in the sorted array)
    return scores[0];
}
