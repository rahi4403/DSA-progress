class Solution {
public:
vector<int> reverse(vector<int>& v){
    int s=0;
    int e=v.size()-1;
    while(s<e){
        swap(v[s++],v[e--]);
    }
    return v;
}
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        int i=num.size()-1; //we start adding from last since we need to carry 
        int carry=0;
        while(i>=0){
            int val=num[i];
            int digit=k%10; //because k is a entire number so we need to add digit by digit
            int sum=val+digit+carry;
            carry=sum/10;
            sum=sum%10;
            k=k/10;
            ans.push_back(sum);
            i--;
        }
        while(k>0){
            int digit=k%10;
            int sum=digit+carry;
            k=k/10;
            carry=sum/10;
            sum=sum%10;
            ans.push_back(sum);
        }
        while(carry!=0){ //in case carry is still left
            int sum=carry;
            carry=sum/10;
            sum=sum%10;
            ans.push_back(sum);
        }
        reverse(ans);
        return ans;
    }
};