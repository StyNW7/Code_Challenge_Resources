// Link: https://coddy.tech/challenges/the_kindly_substring_swap_js?daily=true

function kindlySubstringSwap(text, index1, length1, index2, length2) {
    // Extract the first and second substrings
    let substring1 = text.substr(index1, length1);
    let substring2 = text.substr(index2, length2);

    // Reverse both substrings
    let reversedSubstring1 = substring1.split('').reverse().join('');
    let reversedSubstring2 = substring2.split('').reverse().join('');

    // Form the new string by combining the parts
    let result = text.slice(0, index1) + reversedSubstring2 + text.slice(index1 + length1, index2) + reversedSubstring1 + text.slice(index2 + length2);

    // Handle case when the two indices overlap or one is within the other
    if (index1 + length1 > index2) {
        // Adjust the slices if the indices are not independent (overlap)
        result = text.slice(0, index1) + reversedSubstring2 + text.slice(index1 + length1, index2 + length2 - length1) + reversedSubstring1 + text.slice(index2 + length2);
    }

    return result;
}
