// Code Challenge by coddy.tech

// Link: https://coddy.tech/challenges/sort_amino_acids_js

function sortProtein(aminoAcids) {
    
    const validAminoAcids = [
        "Alanine", "Arginine", "Asparagine", "Aspartic acid", "Cysteine",
        "Glutamic acid", "Glutamine", "Glycine", "Histidine", "Isoleucine",
        "Leucine", "Lysine", "Methionine", "Phenylalanine", "Proline",
        "Serine", "Threonine", "Tryptophan", "Tyrosine", "Valine"
    ];

    // Filter and sort the valid amino acids
    const sortedAminoAcids = aminoAcids.filter(acid => validAminoAcids.includes(acid)).sort();

    return sortedAminoAcids;

}
