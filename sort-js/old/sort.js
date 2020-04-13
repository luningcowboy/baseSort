let Sort = {};
let _swapArrayElement = (arr, a, b)=>{
    let t = arr[a];
    arr[a] = arr[b];
    arr[b] = t;
};
let _defaultCall = (a, b)=>a>b;
let _isArray = (arr)=>Array.isArray(arr) || arr instanceof Array || Object.prototype.toString.call(arr) === '[object Array]';
let _isNumber = num=> typeof num === 'number';

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
//    console.log('_merge start =>', left, right);
    while(left.length && right.length){
        //?? 直接对比两个值可以，通过函数对比有问题
        if(call(left[0], right[0])) {
        //if(left[0] < right[0]) {
            ret.push(left.shift());
  //          console.log('_merge 1');
        }
        else {
            ret.push(right.shift());
 //           console.log('_merge 2');
        }
    }
    while(left.length) {
        ret.push(left.shift());
   //     console.log('_merge 3');
    }
    while(right.length) {
        ret.push(right.shift());
    //    console.log('_merge 4');
    }
//    console.log('_merge end =>', ret);
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
function _partition(arr, left, right, call){
    let pivot = left,
        idx = pivot + 1;
    for(let i = idx; i <= right; ++i){
        if(arr[i] > arr[pivot]){
            _swapArrayElement(arr, i, idx);
            idx++;
        }
    }
    _swapArrayElement(arr, pivot, idx - 1);
    return idx - 1;

}
Sort.quick = (arr, call, left, right)=>{
    let len = arr.length;
    let parIdx = 0;
    call = call || _defaultCall;
    left = _isNumber(left) ? 0 : left;
    right = _isNumber(right) ? len - 1 : right;
    if(left < right){
        parIdx = _partition(arr, left, right, call);
        Sort.quick(arr, call, left, parIdx - 1);
        Sort.quick(arr, call, parIdx + 1, right);
    }
    return arr;
};
module.exports = Sort;
