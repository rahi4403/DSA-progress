class Solution{ //less time taking solution
    public:
    vector<int> runningSum(vector<int>& nums){
        int n=nums.size();
        int sum=0;
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            ans.push_back(sum);
        }
        return ans;
    }
};

/*class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> runningsum(n);
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=0;j<=i;j++){
                sum+=nums[j];
            }
            runningsum[i]=sum;
        }
        return runningsum;
    }
};*/ //->>my solution(takes 4ms)

