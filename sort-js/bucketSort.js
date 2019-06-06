function bucketSort(arr, bucketSize){
    if(arr.length == 0) return arr;
    let i;
    let minValue = arr[0];
    let maxValue = arr[0];
    for(i = 1; i < arr.length; i++){
        if(arr[i] < minValue) minValue = arr[i];
        else if(arr[i] > maxValue) maxValue = arr[i];
    }
    var DEFAULT_BUCKET_SIZE = 5;
    bucketSize = bucketSize || DEFAULT_BUCKET_SIZE;
    let bucketCount = Math.floor((maxValue - minValue) / bucketSize) + 1;
    let buckets = new Array(bucketCount);
    for(i = 0; i < buckets.length; ++i) bucket[i] = [];
    for(i = 0; i < arr.length; i++){
        buckets[Math.floor((arr[i] - minValue)/bucketSize)].push(arr[i]);
    }
    arr.length = 0;
    for(i = 0; i < buckets.length; i++){
        insertionSort(buckets[i]);
        for(let j = 0; j < buckets[i].length; j++){
            arr.push(buckets[i][j]);
        }
    }
    return arr;
}
