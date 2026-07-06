class Solution {
public:
    bool isPowerOfThree(int n) {
        for(int i=0;i<=19;i++){
            int power=pow(3,i);
                if(n==power){
                    return true;
            }
        }
        return false;
    }
};