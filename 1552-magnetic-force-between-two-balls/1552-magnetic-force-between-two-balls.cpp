class Solution {
public:
bool isPossible(vector<int>& position,int m,int mid){
    int ballcount=1;
    int lastpos=position[0];
    for(int i=0;i<position.size();i++){
        if(position[i]-lastpos>=mid){
            ballcount++;
            if(ballcount==m){
                return true;
                            }
                            lastpos=position[i];
        }
    }
    return false;
}
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int s=0;
        int maxi=-1;
        for(int i=0;i<position.size();i++){
            maxi=max(maxi,position[i]);
        }
        int e=maxi;
        int ans=-1;
        int mid=s+(e-s)/2;
        while(s<=e){
            if(isPossible(position,m,mid)){
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