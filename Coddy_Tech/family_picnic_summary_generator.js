// Link: https://coddy.tech/challenges/family_picnic_summary_generator_js?daily=true

function generatePicnicSummary(familyMembers, activities, foodBasket) {
    // Helper function to format list of items
    const formatList = (items) => {
        if (items.length === 1) {
            return items[0];
        } else if (items.length === 2) {
            return `${items[0]} and ${items[1]}`;
        } else if (items.length === 3) {
            return `${items[0]}, ${items[1]}, and ${items[2]}`;
        }
        else if (items.length >= 4) {
            return `${items[0]}, ${items[1]}, ${items[2]}, and ${items[3]}`;
        }
        return "";
    };

    // Format family members
    const familyPart = formatList(familyMembers);

    // Format activities if there are any
    const activitiesLength = activities.length >= 3 ? activities.length-1 : activities.length;
    const activitiesPart = activities.length > 0 ? `${activitiesLength} different activities, like ${formatList(activities)}` : "";

    // Format foodBasket or default to a generic message
    const foodPart = foodBasket.length > 0 ? formatList(foodBasket) : "a variety of delicious treats";

    // Generate final summary
    let summary = `Our family picnic in Orlando was fantastic! ${familyPart} `;
    if (activitiesPart) {
        summary += `enjoyed ${activitiesPart}. `;
    }
    summary += `We feasted on ${foodPart}. What a memorable day!`;

    return summary;
}
