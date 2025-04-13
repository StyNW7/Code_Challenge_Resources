// Link: https://coddy.tech/challenges/prison_break_decode_your_escape_js

function prisonBreak(encodedMessage, cellNumber) {
    // Step 1: Extract substring
  let extracted;
  if (cellNumber > encodedMessage.length) {
    extracted = encodedMessage;
  } else {
    extracted = encodedMessage.substr(cellNumber, cellNumber);
  }

  // Step 2: Create an array with the substring and cellNumber as a string
  const parts = [extracted, String(cellNumber)];

  // Step 3: Join the array elements to form the escape code
  const escapeCode = parts.join('');

  return escapeCode;
}
