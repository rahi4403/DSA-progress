class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=2; //because 1st 2 elements are already occupied
        int n=nums.size();
        if(n<2){ //if the array has only 2 or less than that element then we return the size of the array itself,it has to be checked before the loop since otherwise it directly returns 2 from the for loop
                return n;
            }
        for(int i=2;i<n;i++){
         if(nums[i]!=nums[k-2]){ //k-2 since we are gonna check two positions before,in the part of the array which we are keeping. We are not using i-2 since i traverses the original array,k builds the final array from the original array 
                nums[k]=nums[i];
            k++;
            }
        }
        return k;
    }
};