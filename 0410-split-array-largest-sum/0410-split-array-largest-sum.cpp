class Solution { //similar to book allocation problem of binary search
public: 
bool isPossible(vector<int>& nums,int k,int mid){
    int subs=1;
    int arrsum=0;
    for(int i=0;i<nums.size();i++){
        if(arrsum+nums[i]<=mid){
            arrsum+=nums[i];
        }
        else{
            subs++;
            if(subs>k||nums[i]>mid){
                return false;
            }
            arrsum=nums[i];
        }
    }
    return true;
}
    int splitArray(vector<int>& nums, int k) {
        int s=0;
        int sum=0;
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int e=sum;
        int mid=s+(e-s)/2;
        while(s<=e){
            if(isPossible(nums,k,mid)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return ans;
    }
};