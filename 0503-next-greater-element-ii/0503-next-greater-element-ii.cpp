class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int> s;
        vector<int> ans(n);
        for(int i=2*n-1;i>=0;i--){
            int index=i%n;
            while(!s.empty() && s.top()<=nums[index]){
                s.pop();
            }
                if(s.empty()){

ans[index]=-1;
                }
                else{
                    ans[index]=s.top();
                }
                s.push(nums[index]);
        }
        return ans;
    }
};