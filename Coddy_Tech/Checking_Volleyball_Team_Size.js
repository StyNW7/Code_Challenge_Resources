function checkVolleyballTeam(players, minPlayers) {
    
    let player = 0;

    for (let i = 0; i < players.length; i++){
        if (i+1 != players.length) player++;
    }

    if (player) player += 1;
    if (players.length == 1) player += 1;

    if (player >= minPlayers){
        return "Let's play volleyball on the beach!";
    }

    else return "We need more players to form a volleyball team.";

}
