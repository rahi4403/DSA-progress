class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0; //for the 1st index
        for(int j=0;j<nums.size();j++){ //for element to element traversing and checking 
            if(nums[j]!=0){
                swap(nums[j],nums[i]);
           i++; //moves to next index to check
            }
        }
    }
};