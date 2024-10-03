// Link: https://coddy.tech/challenges/deciphering_picnic_talk_js?daily=true

function decipherPicnicTalk(picnicItems, overheardPhrases, keyword) {
    
    let result = [];

    if (picnicItems === null) return result;

    picnicItems.forEach(item => {
        overheardPhrases.forEach(phrase => {
            if (phrase.toLowerCase().includes(keyword.toLowerCase()) && 
                phrase.toLowerCase().includes(item.toLowerCase())) {
                result.push(`${item}: ${phrase}`);
            }
        });
    });

    return result;

}
