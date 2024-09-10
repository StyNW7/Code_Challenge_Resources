// Link: https://coddy.tech/challenges/king_arthurs_feast_seating_arrangement_js?daily=true

function feastArrangement(numKnights) {
    let ans = []
    if (numKnights === 0) return ans
    if (numKnights === 1) {
        ans.push('knight')
        return ans
    }
    for (let i = 0; i < numKnights-1; i++){
        ans.push('knight')
        ans.push('wine')
    }
    ans.push('knight')
    return ans
}
