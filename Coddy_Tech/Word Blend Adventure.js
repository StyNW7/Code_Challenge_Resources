// Link: https://coddy.tech/challenges/word_blend_adventure_js

function blendWords(word1, word2) {
    if (!word1) return word2;
    if (!word2) return word1;
    
    if (word1[word1.length - 1] === word2[0]) {
        return word1 + word2.slice(1);
    } 
    else {
        return word1 + word2;
    }
}
