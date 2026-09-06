class Solution {
public:
    bool isValid(string sentence) {
        stack<char> s;
        for(int i=0;i<sentence.length();i++){
            char ch=sentence[i];
            if(ch=='(' || ch=='{'||ch=='['){ //pushes the first halves first
                s.push(ch);
            }
            else{
                if(s.empty()){ //stack should not be empty
                    return false;
                }
                    char top=s.top();
                    if((ch==')' && top=='(') ||(ch=='}' && top=='{')||(ch==']' && top=='[') ){
                        s.pop();
                }
                    else{
                        return false;
                    }
                }
            }
            if(s.empty())
            return true;
            else
            return false;
        }
};