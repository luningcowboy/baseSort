function bubbleSort(arr){
    let len = arr.length;
    for(let i = 0; i < len - 1; ++i){
        for(let j = 0; j < len - 1 - i; ++j){
            if(arr[j] > arr[j + 1]){
                let tmp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}
let arr = [1,4,3,2,6,7,9,5];
console.log("before sort:", arr);
bubbleSort(arr);
console.log("after sort:", arr);
