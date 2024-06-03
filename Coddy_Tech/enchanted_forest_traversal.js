// Link: https://coddy.tech/challenges/enchanted_forest_traversal_js

function traverseEnchantedForest(path) {
    
    const sections = path.split('/');
    
    let items = [];
    
    let modifiedPath = [];
    
    for (let section of sections) {
        let modifiedSection = '';
        let rock = false
        
        for (let encounter of section) {
            if (encounter === 'T') {
                modifiedSection += encounter;
            } else if (encounter === 'R') {
                modifiedSection += encounter;
                rock = true
            } else if (encounter === 'C') {
                if (!rock) items.push(encounter);
                modifiedSection += encounter;
            } else if (encounter === 'M') {
                continue;
            }
        }
        
        modifiedPath.push(modifiedSection);

    }
    
    const finalPath = modifiedPath.join('/');
    
    return [finalPath, items];
}
