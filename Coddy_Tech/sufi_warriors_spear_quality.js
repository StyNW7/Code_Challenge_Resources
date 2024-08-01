// Link: https://coddy.tech/challenges/sufi_warriors_spear_quality_js

function sufiWarriorSpear(material, length) {
    let quality = '';

    // Determine initial quality based on material
    switch (material.toLowerCase()) {
        case 'bronze':
            quality = 'low';
            break;
        case 'iron':
            quality = 'medium';
            break;
        case 'steel':
            quality = 'high';
            break;
        default:
            quality = 'unknown';
            return `The spear is of ${quality} quality.`;
    }

    // Adjust quality based on length
    if (length < 50) {
        if (quality === 'medium') {
            quality = 'low';
        } else if (quality === 'high') {
            quality = 'medium';
        }
    } else if (length > 100) {
        if (quality === 'medium') {
            quality = 'high';
        } else if (quality === 'low') {
            quality = 'medium';
        }
    }

    return `The spear is of ${quality} quality.`;
}
