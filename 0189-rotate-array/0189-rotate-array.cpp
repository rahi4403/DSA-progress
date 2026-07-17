class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp(nums.size()); //creating an empty array of same size because we dont want nums elements to be overwritten
        for(int i=0;i<nums.size();i++){
            temp[(i+k)%nums.size()]=nums[i]; //mod operator to bring the last elements to the front of the array via indexing
        }
        nums=temp; //storing temp into nums for the result
    }
};