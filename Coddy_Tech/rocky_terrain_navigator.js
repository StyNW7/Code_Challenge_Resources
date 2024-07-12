// Link: https://coddy.tech/challenges/rocky_terrain_navigator_js

function rockyTerrainNavigator(terrain, steps) {
    let position = 0;
    let actualSteps = 0;

    while (actualSteps < steps && position < terrain.length - 1) {
        position++;
        if (terrain[position] === "Obstacle") {
            position = Math.max(0, position - 1);
        }
        actualSteps++;
    }

    return position;
}
