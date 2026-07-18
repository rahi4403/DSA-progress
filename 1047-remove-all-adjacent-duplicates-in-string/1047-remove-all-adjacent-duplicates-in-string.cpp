class Solution {
public:
    string removeDuplicates(string s) {
        string ans="";
        for(int i=0;i<s.length();i++){ 
            char ch=s[i]; //we keep storing every character in ch
            if(!ans.empty() && ans.back()==ch){ //ans.back to check if the last character we stored matches the current character
                ans.pop_back();//if it matches which means its duplicate then remove it
            }
            else{
                ans.push_back(ch); //if not duplicate we add it to ans to keep it
            }
        }
        return ans;
    }
};