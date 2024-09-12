// Link: https://coddy.tech/challenges/celestial_message_encoder_js?daily=true

function encodeMessage(message, indices) {
    // Convert the message into an array to make reversing parts easier
    let messageArr = message.split('');
    
    // Iterate through the list of indices and reverse the relevant part of the message
    for (let i = 0; i < indices.length; i++) {
        let index = indices[i];
        
        // Reverse the segment of the array from the start to the given index (inclusive)
        let reversedSegment = messageArr.slice(0, index + 1).reverse();
        
        // Replace the initial part of the array with the reversed segment
        messageArr = [...reversedSegment, ...messageArr.slice(index + 1)];
    }
    
    // Join the array back into a string and return the final encoded message
    return messageArr.join('');
}
