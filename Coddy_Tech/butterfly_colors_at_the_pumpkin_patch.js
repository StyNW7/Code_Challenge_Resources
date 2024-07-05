// Link: https://coddy.tech/challenges/butterfly_colors_at_the_pumpkin_patch_js

function countButterflyColors(colors) {
    const colorCounts = {};

    for (const color of colors) {
        if (colorCounts[color]) {
            colorCounts[color]++;
        } else {
            colorCounts[color] = 1;
        }
    }

    return colorCounts;
}
