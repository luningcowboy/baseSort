/**
有5个人偷了一堆苹果，准备在第二天分赃。晚上，有一人出来，把所有菜果分成5份，但是多了一个，他顺手把这个苹果扔给树上的猴，自己先拿1/5藏了起来。结果其他四人也都是这么想的，都如第一个人一样把苹果分成5份，把多的那一个扔给了猴子，偷走了1/5。第二天，大家分赃，也是分成5份多一个扔给猴子。最后一人分了一份。问：共有多少苹果？
总数:x
每个人取走的:x/5
多1个
y1 = x - x/5 - 1
y2 = y1 - y1/5 - 1
y3 = y2 - y2/5 - 1
y4 = y3 - y3/5 - 1
y5 = y4 - y4/5 - 1
y4 = y5 + 1 + y4/5

y6 = y5 - y5/5 - 1
(y5 - 1)/5=n
y5 = 5*n + 1
y4 = (y5 + 1)/4
y3 = (y4 + 1)/4
y2 = (y3 + 1)/4
y1 = (y2 + 1)/4
x = (y1 + 1)/4

 */
(function(){

})()
(function run() {
    for (let x = 5;; ++x) {
        if (x % 5 === 1) {
            let y1 = x - Math.round(x / 5) - 1;
            if (y1 % 5 === 1) {
                let y2 = y1 - Math.round(y1 / 5) - 1;
                if (y2 % 5 == 1) {
                    let y3 = y2 - Math.round(y2 / 5) - 1;
                    if (y3 % 5 === 1) {
                        let y4 = y3 - Math.round(y3 / 5) - 1;
                        if (y4 % 5 === 1) {
                            let y5 = y4 - Math.round(y4 / 5) - 1;
                            if(y5 % 5 == 1){
                                console.log(x);
                                break;
                            }
                        }
                    }
                }

            }
        }
    }

})();
