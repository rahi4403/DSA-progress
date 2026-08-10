class Solution {
    public:
    void Solve(vector<int> nums,vector<int> output,int index,vector<vector<int>> &ans){
        if(index>=nums.size()){
            ans.push_back(output);
            return;
        }
        Solve(nums,output,index+1,ans);
        int element=nums[index];
        output.push_back(element);
        Solve(nums,output,index+1,ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int index=0;
        Solve(nums,output,index,ans);
        return ans;
    }
};