class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> answer;
        for(int i=1;i<=n;i++){ //since it is 1-indexed
            if(i%3==0 && i%5==0){
answer.push_back("FizzBuzz");
            }
            else if(i%3==0){
                answer.push_back("Fizz");
            }
            else if(i%5==0){
                answer.push_back("Buzz");
            }
            else{
                answer.push_back(to_string(i)); //since i as a string to be returned
            }
        }
            return answer;
        }
    
};