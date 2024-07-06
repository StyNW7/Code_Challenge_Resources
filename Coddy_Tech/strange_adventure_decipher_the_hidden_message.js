// Link: https://coddy.tech/challenges/strange_adventure_decipher_the_hidden_message_js

function strangeAdventure(clues, cipher) {
    const decipheredClues = [];
    const cipherSorted = cipher.split('').sort().join('');

    for (const clue of clues) {
        for (let i = 0; i <= clue.length - cipher.length; i++) {
            const substring = clue.substring(i, i + cipher.length);
            if (substring.split('').sort().join('') === cipherSorted) {
                decipheredClues.push(substring);
            }
        }
    }

    if (decipheredClues.length === 0) {
        return "No hidden message found!";
    }

    decipheredClues.sort((a, b) => {
        const sumA = a.split('').reduce((sum, char) => sum + char.charCodeAt(0), 0);
        const sumB = b.split('').reduce((sum, char) => sum + char.charCodeAt(0), 0);
        return sumA - sumB;
    });

    let hiddenMessage = decipheredClues.join('');

    hiddenMessage = hiddenMessage.replace(/[A-Z]/g, ' ').replace(/[a-z]/g, char => char.toUpperCase());

    return hiddenMessage;
}
