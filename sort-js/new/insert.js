function sort(arr){
    var sortMax = 0;
    var unsortMin = 0;
    var i = 0;
    var j = 0;

    for(i = 0; i < arr.length - 1; i++){
        var min = -1;
        for(j = i + 1; j < arr.length; j++){
            if(min == -1) min = j;
            else {
                if(arr[j] < arr[min]){
                    min = j;
                }
            }
        }
        if(min != -1) {
            var tmp = arr[i + 1];
            arr[i + 1]  = arr[min];
            arr[min] = tmp;
        }
        else{
            console.log("ERROR", i, j);
        }
    }
}
var arr = [1,4,2,3,5,2,6];
sort(arr);
console.log(arr);
