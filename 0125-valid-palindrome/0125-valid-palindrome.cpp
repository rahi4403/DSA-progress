class Solution {
    private: //can be made public too
    bool valid(char ch){
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z' || ch>='0' && ch<='9')){ //because constraint says to remove any character other than alphanumeric 
            return 1 ;
        }
        return 0;
    }
    char toLower(char ch){
if((ch>='a' && ch<='z')||(ch>='0' && ch<='9')) //lower case conversion function,if it is already lower case or a number then return as it is
return ch;
else{
    char temp=ch-'A'+'a';
    return temp;
}
    }
    bool check(string a){
        int s=0;
        int e=a.length()-1;
        while(s<=e){
            if(a[s]!=a[e]){ //if the 1st character is not equal to last character it certainly is not palindrome,if it is then by s++ and e-- check the inner characters one by one
                return 0;
            }
            else{
                s++;
                e--;
            }
        }
        return 1;
    }
public:
    bool isPalindrome(string s) {
        int i=0;
        string temp=""; //empty string for containing the answer
        for(int j=0;j<s.length();j++){
            if(valid(s[j])){ //if it fulfills condition of having only alphanumeric characters 
                temp.push_back(s[j]); //then store it inside temp
            }
        }
        for(int j=0;j<temp.length();j++){
            temp[j]=toLower(temp[j]); //first convert it to lowercase 
        } 
        return check(temp); //then check it for palindrome function
    }
};