class Solution { //similar to aggressive cows and problem number 1552 (LC)
public:
bool isPossible(vector<int>& price, int k,int mid){
int candycount=1;
    int lastpos=price[0];
    for(int i=0;i<price.size();i++){
        if(price[i]-lastpos>=mid){
            candycount++;
            if(candycount==k){
                return true;
                            }
                            lastpos=price[i];
        }
    }
    return false;
}
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(),price.end());
        int s=0;
        int maxi=-1;
        for(int i=0;i<price.size();i++){
            maxi=max(maxi,price[i]);
        }
        int e=maxi;
        int ans=-1;
        int mid=s+(e-s)/2;
        while(s<=e){
            if(isPossible(price,k,mid)){
                ans=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
            mid=s+(e-s)/2;
        }
        return ans;
    }
};