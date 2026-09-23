class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int> s;
        vector<int> ans(n); //creating an answer with n positions
        for(int i=2*n-1;i>=0;i--){ //since it is a circular array 
            int index=i%n; //to access the actual array index since we are pretending the element is appearing twice
            while(!s.empty() && s.top()<=nums[index]){//similar to next greater element I
                s.pop();
            }
                if(s.empty()){
                ans[index]=-1; //if no greater element is available,store -1(dummy index)
                }
                else{
                    ans[index]=s.top();
                }
                s.push(nums[index]);
        }
        return ans;
    }
};