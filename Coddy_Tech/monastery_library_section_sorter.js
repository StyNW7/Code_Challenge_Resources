// Link: https://coddy.tech/challenges/monastery_library_section_sorter_js

function sortMonasteryBooks(books, startIndex, endIndex) {
    // Copy the section to be sorted
    const sectionToSort = books.slice(startIndex, endIndex + 1);

    // Sort the section alphabetically
    sectionToSort.sort();

    // Create a new array to store the result
    const sortedBooks = [...books];

    // Replace the section in the original array with the sorted section
    for (let i = startIndex; i <= endIndex; i++) {
        sortedBooks[i] = sectionToSort[i - startIndex];
    }

    return sortedBooks;
}
