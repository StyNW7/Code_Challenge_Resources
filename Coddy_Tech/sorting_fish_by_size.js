// Link: https://coddy.tech/challenges/sorting_fish_by_size_js

function sortFishBySize(fishList) {
    // Mapping of fish names to their sizes
    const sizeMapping = {
        "Sardine": 1,  // Small
        "Trout": 2,    // Medium
        "Salmon": 3,   // Large
        "Tuna": 4      // Extra Large
    };

    // Custom comparison function to sort the fish based on their size
    fishList.sort((a, b) => sizeMapping[a] - sizeMapping[b]);

    return fishList;
}
