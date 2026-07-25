class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int tobesum=0;
        int currsum=0;
        for(int i=0;i<nums.size();i++){
            currsum+=nums[i]; //for the current sum according to the current size of the array
            tobesum=n*(n+1)/2; //gives sum of all the elements from the start;classic maths formula
        }
        return tobesum-currsum; //suppose currsum=1+3+4=8 & tobesum=1+2+3+4=10,then tobesum-currsum=10-8=2,which is the missing element from the range->1,2,3,4(0 does not make any difference in case of addition)
    }
};