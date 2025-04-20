// Link: https://coddy.tech/challenges/decoding_chemical_formulas_js

function decodeChemicalFormula(codedFormula) {
  const elementMap = {
    a: 'H',
    b: 'O',
    c: 'C',
    d: 'N',
    e: 'Cl'
  };

  const elements = [];

  // Step 1 & 2: Decode letters into elements or capitalized characters
  for (let char of codedFormula) {
    if (elementMap[char]) {
      elements.push(elementMap[char]);
    } else {
      elements.push(char.toUpperCase());
    }
  }

  // Step 3: Count the occurrences of each element
  const countMap = {};
  for (let el of elements) {
    countMap[el] = (countMap[el] || 0) + 1;
  }

  // Step 4: Build the final formula with subscripts
  let decodedFormula = '';
  for (let el of elements) {
    if (countMap[el] !== null) {
      decodedFormula += el + (countMap[el] > 1 ? countMap[el] : '');
      countMap[el] = null; // Mark as added
    }
  }

  return decodedFormula;
}
