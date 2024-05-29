// Link: https://coddy.tech/challenges/craft_a_wooden_sign_js

function craftWoodSign(signText, borderWidth) {
    
    const reversedText = signText.split('').reverse().join('');
    
    const totalWidth = signText.length + 2 * borderWidth;
    
    const sideBorder = '*'.repeat(totalWidth) + ' '.repeat(borderWidth) + reversedText + ' '.repeat(borderWidth) + '*'.repeat(totalWidth);
    
    return sideBorder;
}
