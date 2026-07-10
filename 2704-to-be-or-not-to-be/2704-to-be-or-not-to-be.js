
var expect = function(val) {
    return {
    toBe: function(compare){  //creation of an object with function as the value and toBe as the property
        if(val===compare){
            return true;
        }
        throw new Error("Not Equal") //built in
        },
        notToBe: function(compare){
            if(val!==compare){
                return true;
            }
            throw new Error("Equal")
        }
    }
};

