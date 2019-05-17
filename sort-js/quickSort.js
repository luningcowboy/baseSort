function quickSort(arr, left, right){
    var len = arr.length,
        partitionIndex,
        left = typeof left !== 'number' ? 0 : left,
        right = typeof right !== 'number' ? len - 1 : right;
    if (left < right){
        partitionIndex = partiton(arr, left, right);
        quickSort(arr, left, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, right);
    }
    return arr;
}
function partiton(arr, left, right){
    var pivot = left,
        index = pivot + 1;
    for(var i = index; i <= right; i++){
        if(arr[i] < arr[pivot]){
            swap(arr, i, index);
            index++;
        }
    }
    swap(arr, pivot, index - 1);
    return index - 1;
}
function swap(arr, i, j){
    var tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}
let arr = [1,8,7,9,6,2,5,3];
console.log(arr);
quickSort(arr);
console.log(arr);
