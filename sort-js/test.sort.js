let Sort = require('./sort.js');
// bubble
let arr = [1,4,3,2,6,7,9,5];
console.log("before sort:", arr);
Sort.bubble(arr,(a,b)=>a>b);
console.log("after sort:", arr);
// select 
arr = [1,4,3,2,6,7,9,5];
console.log("before sort:", arr);
Sort.select(arr,(a, b)=>a < b);
console.log("after sort:", arr);
// insert 
arr = [1,4,3,2,6,7,9,5];
console.log("before sort:", arr);
Sort.insert(arr,(a, b)=>a > b);
console.log("after sort:", arr);
// merge
arr = [1,4,3,2,6,7,9,5];
console.log("before sort:", arr);
arr = Sort.merge(arr,(a, b)=>{
    return b < a;
}
);
console.log("after sort:", arr);

