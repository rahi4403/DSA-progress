class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(2*n);
        for(int i=0;i<n;i++){
            ans[i]=nums[i]; //this is for the first half
            ans[i+n]=nums[i]; //this is for the second half to access the next half and store the same elements (nums[i])
        }
        return ans;
        
    }
};