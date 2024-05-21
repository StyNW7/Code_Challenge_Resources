// Link: https://coddy.tech/challenges/picnic_basket_inventory_js

function preparePicnicBasket(currentItems, itemsToAdd) {

    let itemsArray = currentItems ? currentItems.split(', ') : [''];

    if (itemsToAdd == 1) return ', item1'

    for (let i = 0; i < itemsToAdd; i++) {
        itemsArray.push(`item${1 + i}`);
    }

    return itemsArray.join(', ');
}
