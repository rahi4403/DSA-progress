class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1; //last valid element of nums1
        int j=n-1; //last valid element of nums2
        int k=m+n-1; //last position of nums1
        while(i>=0 && j>=0){
            if(nums1[i]>nums2[j]){ //we need to merge from the end and not from the front because nums1 already has some elements,and we dont want to overwrite them by merging from the front
                nums1[k]=nums1[i];
                i--;
            }
            else{
                nums1[k]=nums2[j]; //without mentioning j-- separately we can directly write nums2[j--] to make it concise
                j--;
            }
            k--;
        }
        while(j>=0){
            nums1[k]=nums2[j]; //copying the remaining already sorted elements into nums1
            j--;
            k--;
        }
    }
};