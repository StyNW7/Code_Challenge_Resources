// Link: https://coddy.tech/challenges/sort_buckets_by_string_length_js

function sortBuckets(buckets) {
    for (let i = 0; i < buckets.length - 1; i++){
        for (let j = 0; j < buckets.length - i - 1; j++){
            if (buckets[j+1].length < buckets[j].length){
                let temp = buckets[j];
                buckets[j] = buckets[j+1]
                buckets[j+1] = temp
            }
        }
    }
    return buckets;
}
