class Solution {
public:
    bool check(vector<int>& nums) {
        int count=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i])
            {
                count++; //for no of decreases. For a sorted array no of decreases=0.
            }
        }
        if(nums[nums.size()-1]>nums[0]){ //checks last to first element
            count++; 
        }
        return count<=1;
    }
};