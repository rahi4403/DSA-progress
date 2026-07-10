
var createCounter = function(n) {
    return function() {
let first=n;
n+=1;
return first;
    };
};
