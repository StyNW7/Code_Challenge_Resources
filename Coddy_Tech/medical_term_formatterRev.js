// Link: https://coddy.tech/challenges/medical_term_formatter_js

function formatMedicalTerm(term) {

    let word = ""

    for (let i = 1; i < term.length; i++){
        if (term[i] == ' ') break
        if (term[i] >= '0' && term[i] <= '9') {
            word += ' '
            word += term[i].toLowerCase()
            word += term[i+1]
            break
        }
        word += term[i].toLowerCase()
    }

    return term.charAt(0).toUpperCase() + word

}
