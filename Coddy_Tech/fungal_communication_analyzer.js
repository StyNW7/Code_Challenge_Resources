https://coddy.tech/challenges/fungal_communication_analyzer_js?daily=true

function fungiCommunicationAnalyzer(ring1, ring2, ring3) {
    if (ring1 && !ring2 && !ring3) return "Spore Alert!"
    else if (!ring1 && ring2 && !ring3) return "Mycelium Network!"
    else if (ring1 && ring2 && !ring3) return "Fungal Symphony!"
    else if (!ring1 && !ring2 && ring3) return "New Discovery!"
    else return "Observing..."
}
