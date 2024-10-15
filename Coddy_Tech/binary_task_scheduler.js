// Link: https://coddy.tech/challenges/binary_task_scheduler_js?daily=true

function canScheduleTasks(task1, task2) {
    for (let i = 0; i < task1.length; i++){
        if (task1[i] === '1' && task2[i] === '1') return false;
    }
    return true;
}
