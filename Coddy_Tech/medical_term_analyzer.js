// Link: https://coddy.tech/challenges/medical_term_analyzer_js

function medicalTermAnalyzer(term) {
    // Predefined list of medical terms
    const medicalTerms = ["diagnosis", "therapy", "neural", "cardiac", "oncology"];

    // Helper function to check if a string is an anagram of any in a list
    function isAnagram(term, list) {
        const sortedTerm = term.split('').sort().join('');
        return list.some(t => sortedTerm === t.split('').sort().join(''));
    }

    // Reverse the term
    const reversed = term.split('').reverse().join('');

    // Check if the term is a palindrome
    const isPalindrome = term === reversed;

    // Format the reversed term: every second character uppercase
    let formattedReversed = reversed.split('').map((char, index) => 
        index % 2 === 0 ? char.toLowerCase() : char.toUpperCase()
    ).join('');

    // Check if the formatted reversed term is an anagram of any medical term
    const isAnagramOfMedicalTerm = isAnagram(formattedReversed.toLowerCase(), medicalTerms);

    // Return the analysis result
    return {
        original: term,
        palindrome: isPalindrome,
        reversed: formattedReversed,
        isAnagram: isAnagramOfMedicalTerm
    };
}
