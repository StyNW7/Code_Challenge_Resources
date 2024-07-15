// Link: https://coddy.tech/challenges/hobby_selector_js

function hobbySelector(hobbies, category) {
    let categoryName;

    switch (category) {
        case 1:
            categoryName = 'Outdoor hobbies';
            break;
        case 2:
            categoryName = 'Indoor hobbies';
            break;
        case 3:
            categoryName = 'Creative hobbies';
            break;
        default:
            return 'Unknown hobby category';
    }

    const reversedHobbies = hobbies.reverse().join(', ');

    return `${categoryName}: ${reversedHobbies}`;
}
