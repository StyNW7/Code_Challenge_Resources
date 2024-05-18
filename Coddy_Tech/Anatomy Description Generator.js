// Link: https://coddy.tech/challenges/anatomy_description_generator_js

function anatomyString(bodyPart, anatomicalDetails) {
    
    let result = `The ${bodyPart} is `;
    
    if (anatomicalDetails.length === 0) {
        return result.trim() + '.';
    }

    if (anatomicalDetails.length === 1) {
        result += anatomicalDetails[0];
    } 
    
    else {
        const lastDetail = anatomicalDetails.pop();
        result += anatomicalDetails.join(', ') + ' and ' + lastDetail;
    }

    return result + '.';
}
