function sort(arr){
    for(var i = 0; i < arr.length; i++){
        for(var j = i + 1; j < arr.length; j++){
            if(arr[i] > arr[j]){
                var tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}
var arr = [1,4,2,3,5,2,6];
sort(arr);
console.log(arr);
