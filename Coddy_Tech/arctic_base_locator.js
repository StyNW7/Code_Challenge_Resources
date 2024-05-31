// Link: https://coddy.tech/challenges/arctic_base_locator_js

function arcticBaseLocator(baseNames, targetBaseName) {
    for (let i = 0; i < baseNames.length; i++){
        if (baseNames[i] === targetBaseName) return i;
    }
    return -1;
}
