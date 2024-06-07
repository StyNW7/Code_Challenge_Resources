// Link: https://coddy.tech/challenges/social_etiquette_guide_generator_js

function socialEtiquetteGuide(guestList, seatingArrangement, conversationTopics) {
    
    // Check if all guests are seated
    const seatedGuests = new Set();
    for (const table in seatingArrangement) {
        seatingArrangement[table].forEach(guest => seatedGuests.add(guest));
    }
    
    for (const guest of guestList) {
        if (!seatedGuests.has(guest)) {
            return `Error: Guest ${guest} is not assigned a seat.`;
        }
    }

    // Create strings for each table
    const tableStrings = [];
    const conversationStarters = [];
    
    for (const table in seatingArrangement) {
        const guests = seatingArrangement[table];
        const tableString = `Table ${table}: ${guests.join(', ')}`;
        tableStrings.push(tableString);
        
        // Generate conversation starter key
        const key = guests.map(guest => guest[0]).join('');
        
        // Find a conversation topic
        let topic = conversationTopics.find(t => t.includes(key));
        if (!topic) {
            topic = conversationTopics[0];
        }
        
        const conversationStarter = `Table ${table} Conversation Starter: ${topic}`;
        conversationStarters.push(conversationStarter);
    }

    // Concatenate table strings and conversation starters
    const finalString = [...tableStrings, ...conversationStarters].join('\n');
    return finalString;
    
}
