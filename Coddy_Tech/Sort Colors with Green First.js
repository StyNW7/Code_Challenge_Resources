// Link: https://coddy.tech/challenges/sort_colors_with_green_first_js

function sortColors(colors) {
    const greens = colors.filter(color => color === "green");
    const otherColors = colors.filter(color => color !== "green");

    otherColors.sort();

    return [...greens, ...otherColors];
}
