const binarySearch = (list, item)=>{
    let min = 0;
    let max = list.length - 1;
    while(min <= max){
        let mid = Math.floor((min + max)/2);
        let guess = list[mid];
        if(guess === item) return mid;
        if(guess > item) max = mid - 1;
        else min = mid + 1;
    }
    return null;
};
let list = [1,2,3,4,5,6,7];
console.log(binarySearch(list, 4));
