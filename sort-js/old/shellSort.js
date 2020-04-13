function shellSort(arr){
    var len = arr.length, temp, gap = 1;
    while(gap < len / 3){
        gap = gap * 3 + 1;
    }
    for(gap; gap > 0; gap = Math.floor(gap / 3)){
        for(let i = gap ; i < len; i++){
            temp = arr[i];
            let j = 0;
            for(j = i - gap; j >= 0 && arr[j] > temp; j-=gap){
                arr[j + gap] = arr[j];
            }
            arr[j + gap] = temp;
        }
    }
}
let arr = [1,4,3,2,6,7,9,5];
console.log("shell before sort:", arr);
shellSort(arr);
console.log("shell after sort:", arr);
