// Link: https://coddy.tech/challenges/mystical_verse_chanter_js?daily=true

function chantVerse(rankNumber, totalDruids, verse) {
    const verseLength = verse.length;
    const basePortionSize = Math.floor(verseLength / totalDruids);
    const extraChars = verseLength % totalDruids;

    // Determine the start index for this druid's portion
    let startIndex = 0;
    
    for (let i = 1; i < rankNumber; i++) {
        startIndex += basePortionSize + (i <= extraChars ? 1 : 0);
    }
    
    // Determine the end index for this druid's portion
    let portionSize = basePortionSize + (rankNumber <= extraChars ? 1 : 0);
    let endIndex = startIndex + portionSize;

    // Return the portion of the verse for this druid
    return verse.slice(startIndex, endIndex);
}
