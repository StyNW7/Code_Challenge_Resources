// Link: https://coddy.tech/challenges/nature_quest_log_merge_js

function mergeQuestLogs(quests, actions) {
    // Create a map for quick access to quests by their id
    const questMap = new Map();
    quests.forEach(quest => questMap.set(quest.id, quest));

    // Iterate through each action and apply the corresponding updates
    actions.forEach(action => {
        const quest = questMap.get(action.id);

        // If quest exists, apply the action
        if (quest) {
            switch (action.actionType) {
                case 'complete':
                    quest.status = 'completed';
                    break;
                case 'abandon':
                    quest.status = 'abandoned';
                    break;
                case 'updateTitle':
                    quest.title = action.info;
                    break;
            }
        }
    });

    // Return the updated array of quest objects
    return Array.from(questMap.values());
}
