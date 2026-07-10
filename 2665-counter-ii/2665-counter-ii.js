
var createCounter = function(init) {
    let initial=init;
    return{
        increment:function(){
            return ++initial
        },
        reset:function(){
            initial=init;
        return initial;
        },
        decrement:function(){
return --initial;
    }
    };
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */