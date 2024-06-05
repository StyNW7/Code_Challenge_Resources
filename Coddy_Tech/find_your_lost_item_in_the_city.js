// Link: https://coddy.tech/challenges/find_your_lost_item_in_the_city_js

function findLostItem(items, searchItem) {
    return (items.includes(searchItem)) ? "Item found!" : "Item not found!"
    if (items.includes(searchItem)) {
        return "Item found!";
    } 
    else {
        return "Item not found!";
    }
}
