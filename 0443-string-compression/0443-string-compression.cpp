class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0; //stays at the beginning 
        int ans=0;
        while(i<chars.size()){
            int j=i+1; //i stays at the beginning and j begins looking ahead 
            while(j<chars.size() && chars[i]== chars[j]){ //j keeps looking till the length of the string and keeps checking the duplicate characters and stops only when it finds a different character
                j++;
            }
            chars[ans++]=chars[i]; //the current character is written into the ans
            int count=j-i; //j is last matching character and i is the starting character,and the difference represents the number of total repeated characters
            if(count>1){ //only if count is >1 since if count is 1 we dont have to include the digit we only write the character
                string cnt=to_string(count); //because the double digits cant be stored together,they are needed to be stored as single characters so we convert them to string
                for(char ch:cnt){ //range based for loop for visiting every character in the string 
                    chars[ans++]=ch; //the character is stored into the ans
                }
            }
            i=j; //i jumps to j to start inspecting the next group
        }
        return ans;
    }
};