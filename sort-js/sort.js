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

Sort.insert = (arr, call)=>{
    if(!_isArray(arr)) return;
    call = call || _defaultCall;
    let preIdx = 0, cur = 0;
    let len = arr.length;
    for(let i = 1; i < len; ++i){
        preIdx = i - 1;
        cur = arr[i];
        while(preIdx >= 0 && call(arr[preIdx], cur)){
            arr[preIdx+1] = arr[preIdx];
            preIdx--;
        }
        arr[preIdx + 1] = cur;
    }
};

Sort.shell = (arr, call)=>{
    if(!_isArray(arr)) return;
    call = call || _defaultCall;

};

function _merge(left, right, call){
    let ret = [];
    console.log('_merge start =>', left, right);
    while(left.length && right.length){
        if(call(left[0], right[0])) {
        //if(left[0] < right[0]) {
            ret.push(left.shift());
            console.log('_merge 1');
        }
        else {
            ret.push(right.shift());
            console.log('_merge 2');
        }
    }
    while(left.length) {
        ret.push(left.shift());
        console.log('_merge 3');
    }
    while(right.length) {
        ret.push(right.shift());
        console.log('_merge 4');
    }
    console.log('_merge end =>', ret);
    return ret;
}
Sort.merge = (arr, call)=>{
    call = call || _defaultCall;
    let len = arr.length;
    if(len < 2) return arr;
    let mid = Math.floor(len / 2),
        left = arr.slice(0, mid),
        right = arr.slice(mid);
    return _merge(Sort.merge(left), Sort.merge(right), call);
};
module.exports = Sort;
