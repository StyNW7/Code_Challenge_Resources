// Link: https://coddy.tech/challenges/decode_island_map_js

function decodeIslandMap(encodedMap) {
    let count = 0
    for (let i = 0; i < encodedMap.length; i++){
        if (encodedMap[i]==='1')count++
    }
    return count
}
