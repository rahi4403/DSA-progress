class Solution {
public:
    bool isPowerOfFour(int n) {
        for(int i=0;i<=15;i++){
        int power=pow(4,i);
        if(n==power){
            return true;
        }
        }
        return false;
    }
};