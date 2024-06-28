// Link: https://coddy.tech/challenges/plant_cell_health_status_tracker_js

function checkPlantCellHealth(cellIntegrity, pestPresence) {
    let healthStatus = [];
    
    for (let i = 0; i < cellIntegrity.length; i++) {
        if (cellIntegrity[i] > 75 && !pestPresence[i]) {
            healthStatus.push("Healthy");
        } else if ((cellIntegrity[i] >= 50 && cellIntegrity[i] <= 75) || pestPresence[i]) {
            healthStatus.push("At Risk");
        } else if (cellIntegrity[i] < 50) {
            healthStatus.push("Unhealthy");
        }
    }
    
    return healthStatus;
}
