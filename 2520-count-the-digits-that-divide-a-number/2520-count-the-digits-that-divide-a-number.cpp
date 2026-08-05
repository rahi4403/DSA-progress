class Solution {
public:
    int countDigits(int num) {
        int n=num;
        int count=0;
        while(n>0){
            int temp=n % 10;
            if(temp!=0 && num % temp==0){
                count++;
            }
        n/=10;
        }
        return count;
    }
};