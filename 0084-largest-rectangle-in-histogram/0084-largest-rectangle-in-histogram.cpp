class Solution {
    private:
vector<int> nextSmallerElement(vector<int> arr,int n){
    stack<int> s;
    s.push(-1); //dummy index for when there is no smaller index
    vector<int> ans(n);
    for(int i=n-1;i>=0;i--){ //because we are looking for smaller element to the right 
        int curr=arr[i]; //stores current element in curr
        while(s.top()!=-1 && arr[s.top()]>=curr){ //we remove elements from the stack till it reaches -1 and height of the stack is greater than or equal to the curr element
            s.pop();
        }
        ans[i]=s.top(); //index of the next smaller element
        s.push(i);//that is pushed
    }
    return ans;
}
 private:
vector<int> prevSmallerElement(vector<int> arr,int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for(int i=0;i<n;i++){ //checking for smaller element to the left
        int curr=arr[i];
        while(s.top()!=-1 && arr[s.top()]>=curr){
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> next(n);
        next=nextSmallerElement(heights,n); //calls the function and stores element in next
        vector<int> prev(n);
        prev=prevSmallerElement(heights,n);//calls function to store previous element
        int area=INT_MIN; //to store maximum area
        for(int i=0;i<n;i++){
            int l=heights[i]; //stores height of current bar in l 
            if(next[i]==-1){
                next[i]=n; //if no smaller element found we state n as boundary
            }
                        int b=next[i]-prev[i]-1; //calculates the width of the largest rectangle
            int newArea=l*b;
            area=max(area,newArea); //compares then returns the actual answer
        }
        return area;
    }
};