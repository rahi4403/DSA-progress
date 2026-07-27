class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=1; //since index 0 already has one unique element,no need to change it,k is for position
        for(int i=1;i<nums.size();i++){
        if(nums[i]!=nums[i-1]){
            nums[k]=nums[i];
            k++; //moves to the next empty position 
        }
        }
        return k;
    }
};