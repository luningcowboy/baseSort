function mergeSort(arr){
    var len = arr.length;
    if(len < 2) return arr;
    var mid = Math.floor(len / 2),
        left = arr.slice(0, mid),
        right = arr.slice(mid)
    return merge(mergeSort(left), mergeSort(right));

}
function merge(left, right){
    var result = [];
    while(left.length && right.length){
        if(left[0] <= right[0]) result.push(left.shift());
        else result.push(right.shift());
    }
    while(left.length) result.push(left.shift());
    while(right.length) result.push(right.shift());
    return result;
}
let arr = [1,4,3,2,6,7,9,5];
console.log("before sort:", arr);
arr = mergeSort(arr);
console.log("after sort:", arr);
