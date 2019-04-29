let Sort = {};
let _swapArrayElement = (arr, a, b)=>{
    let t = arr[a];
    arr[a] = arr[b];
    arr[b] = t;
};
let _defaultCall = (a, b)=>a>b;
let _isArray = (arr)=>Array.isArray(arr) || arr instanceof Array || Object.prototype.toString.call(arr) === '[object Array]';

Sort.bubble = (arr, call)=>{
    if(!_isArray(arr)) return;
    call = call || _defaultCall;
    let len = arr.length;
    for(let i = 0; i < len - 1; ++i){
        for(let j = 0; j < len - 1 - i; ++j){
            if(call(arr[j], arr[j + 1])) _swapArrayElement(arr, j, j + 1);
        }
    }
};

Sort.select = (arr, call)=>{
    if(!_isArray(arr)) return;
    call = call || _defaultCall;
    let sele_idx = 0;
    let len = arr.length;
    for(let i = 0; i < len - 1; ++i){
        sele_idx = i;
        for(let j = i + 1; j < len; ++j){
            if(call(arr[j], arr[sele_idx])){
                sele_idx = j;
            }
        }
        if(sele_idx !== i)_swapArrayElement(arr, i, sele_idx);
    }
};

Sort.insert = (arr, call)=>{};
module.exports = Sort;
