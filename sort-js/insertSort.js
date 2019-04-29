function insertSort(arr){
    let len = arr.length;
    let preIdx = 0, cur = 0;
    for(var i = 1; i < len; ++i){
        preIdx = i - 1;
        cur = arr[i];
        while(preIdx >= 0 && arr[preIdx] > cur){
            arr[preIdx+1] = arr[preIdx];
            preIdx--;
        }
        arr[preIdx + 1] = cur;
    }
}
let arr = [1,4,3,2,6,7,9,5];
console.log("before sort:", arr);
insertSort(arr);
console.log("after sort:", arr);
