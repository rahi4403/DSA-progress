class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int i=digits.size()-1;
        int carry=1;
        while(i>=0){
            int val=digits[i];
            int sum=val+carry;
            carry=sum/10;
            sum=sum%10;
            ans.push_back(sum);
            i--;
        }
        while(carry!=0){
            int sum=carry;
            carry=sum/10;
            sum=sum%10;
            ans.push_back(sum);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};