// Link: https://coddy.tech/challenges/interrupted_story_narration_js

function findStopWord(sentences, stopWord) {
    let result = [];
    for (let sentence of sentences) {
        result.push(sentence);
        if (sentence.includes(stopWord)) {
            break;
        }
    }
    return result;
}
