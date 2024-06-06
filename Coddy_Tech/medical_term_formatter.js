// Link: https://coddy.tech/challenges/medical_term_formatter_js

function formatMedicalTerm(term) {
    
    term = term.replace(/[aeiouAEIOU]/g, '');

    term = term.replace(/[_-]/g, ' ');

    term = term.replace(/(\d+)([a-zA-Z])/g, '$1 $2');
    term = term.replace(/([a-zA-Z])(\d+)/g, '$1 $2');

    term = term.split(' ').map(word => word.charAt(0).toUpperCase() + word.slice(1)).join(' ');

    return term;
}
