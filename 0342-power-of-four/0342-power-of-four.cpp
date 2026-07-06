class Solution {
public:
    bool isPowerOfFour(int n) {
        for(int i=0;i<=15;i++){ //because a power of 4 grows much faster so if we calculate 4 to the power 30 or beyond 15 it exceeds safe integer limit which is why our code breaks//
        int power=pow(4,i);
        if(n==power){
            return true;
        }
        }
        return false;
    }
};