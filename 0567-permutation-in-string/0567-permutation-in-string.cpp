class Solution {
    private:
    bool checkequal(int a[26],int b[26]){
        for(int i=0;i<26;i++){
            if(a[i]!=b[i]) //this function is for comparing the frequencies of the two arrays.Suppose in ab a=1 and b=1; its permutation,i.e,ba also should be b=1 and a=1.So if the frequencies do not match,then return 0/false;
            return 0;
        }
        return 1;
    }
public:
    bool checkInclusion(string s1, string s2) {
         int count1[26]={0}; //this is for storing the frequency of s1
    for(int i=0;i<s1.length();i++){
        int index=s1[i]-'a'; //conversion of character into index(if char is c then its index is 2[a-0,b-1,c-2..])
        count1[index]++; //increase the count of the letter
    }
    int i=0;
    int count2[26]={0}; //this is for storing the frequence of s2 characters
    int window=s1.length();
    while(i<window && i<s2.length()){ //permutation must have same length as the original string 
        int index=s2[i]-'a'; //conversion from character to index again
        count2[index]++;
        i++; // moves on to the next character
    }
    if(checkequal(count1,count2)) //check if the frequencies of both s1 & s2 are same
    return 1;
    while(i<s2.length()){
        char news=s2[i]; //this moves to the right because as the sliding window moves right a new character keep entering
        int index=news-'a';
        count2[index]++;
        char old=s2[i-window]; //when checking window moves towards right,one old character leaves and a new one enters.Suppose for abc,the window then moves to bcd;so a left,and d enters.i is the current position and window represents windowsize
        index=old-'a'; //calculates the index of the character which leaves the window
        count2[index]--; //frequency of the character which leaves the window is decreased
        i++;
        if(checkequal(count1,count2)) //checks the count of the next set of characters now
        return true;
    }
    return 0;
    }
};