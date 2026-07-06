class Solution {
public:
    int bitwiseComplement(int n) {
        int num=n;
        int complement=0;
     if(n==0){
        return 1;
     }
     while(num!=0){
        complement=(complement<<1)|1;
        num=num>>1;
     }
     int result=(~n)&complement;
     return result;
    }
};