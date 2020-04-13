function selectSort(arr){
    let len = arr.length;
    let minIdx = 0, tmp = 0;
    for(let i = 0; i < len - 1; ++i){
        minIdx = i;
        for(let j = i + 1; j < len; ++j){
            if(arr[j] < arr[minIdx]){
                minIdx = j;
            }
        }
        tmp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = tmp;
    }
}
let arr = [1,4,3,2,6,7,9,5];
console.log("before sort:", arr);
selectSort(arr);
console.log("after sort:", arr);
