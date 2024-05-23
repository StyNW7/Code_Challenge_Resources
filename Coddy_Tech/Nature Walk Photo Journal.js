// Link: https://coddy.tech/challenges/nature_walk_photo_journal_js

function organizePhotos(tags, photos) {
    // Initialize an empty object to hold the organized photos
    const organizedPhotos = {};

    // Iterate over the tags array
    for (let i = 0; i < tags.length; i++) {
        const tag = tags[i];
        const photo = photos[i];

        // If the tag does not exist in the object, initialize it with an empty array
        if (!organizedPhotos[tag]) {
            organizedPhotos[tag] = [];
        }

        // Add the photo to the corresponding tag array
        organizedPhotos[tag].push(photo);
    }

    return organizedPhotos;
}
