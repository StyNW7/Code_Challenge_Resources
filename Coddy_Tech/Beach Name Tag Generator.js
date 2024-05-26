// Link: https://coddy.tech/challenges/beach_name_tag_generator_js

function createBeachNameTag(fullName, dayOfMonth) {
    const [firstName, lastName] = fullName.split(' ');

    const first3Letters = firstName.slice(0, 3);

    const last3Letters = lastName.slice(-3);

    const reversedDay = dayOfMonth.toString().split('').reverse().join('');

    const nameTag = `${first3Letters}-${reversedDay}-${last3Letters}`.toUpperCase();

    return nameTag;
}
