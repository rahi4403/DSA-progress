class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0; //for the 1st index
        for(int j=0;j<nums.size();j++){ //for element to element traversing and checking 
            if(nums[j]!=0){ //if it is already equal to 0 then ignore it,if not then swap it with the indexed position so 0 automatically moves after the non zero element
                swap(nums[j],nums[i]);
           i++; //moves to next index to check
            }
        }
    }
};