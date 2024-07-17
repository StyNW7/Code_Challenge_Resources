// Link: https://coddy.tech/challenges/reverse_explorers_path_and_inventory_js

function reverseExplorerPath(path, inventory) {
    // Reverse the path string
    let reversedPath = path.split('').reverse().join('');
    
    // Reverse the inventory array
    let reversedInventory = inventory.slice().reverse();
    
    // Return the results as an array
    return [reversedPath, reversedInventory];
}
