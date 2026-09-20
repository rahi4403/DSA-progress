class MinStack {
    stack<long long> s;
    long long mini;

public:
    void push(int value) {
        if(s.empty()){
            s.push(value);
            mini=value;
        }
        else{
            if(value<mini){
                s.push(2LL*value-mini);
                mini=value;
            }
            else{
                s.push(value);
            }
        }
    }

    void pop() {
        if(s.empty())
            return;

        long long curr=s.top();
        s.pop();

        if(curr>mini){
            return;
        }
        else{
            long long prevMin=mini;
            long long val=2LL*mini-curr;
            mini=val;
        }
    }

    int top() {
        if(s.empty())
            return -1;

        long long curr=s.top();

        if(curr<mini){
            return mini;
        }
        else{
            return curr;
        }
    }

    bool isEmpty(){
        return s.empty();
    }

    int getMin() {
        if(s.empty())
            return -1;

        return mini;
    }
};