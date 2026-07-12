class Solution {
public:
bool isPossible(vector<int>&weights,int days,int mid){
    int cargocount=1;
    int sum=0;
    for(int i=0;i<weights.size();i++){
        if(sum+weights[i]<=mid){
            sum+=weights[i];
        }
        else{
            cargocount++;
            if(cargocount>days||weights[i]>mid){
                return false;
            }
            sum=weights[i];
        }
    }
    return true;
}
    int shipWithinDays(vector<int>& weights, int dayslimit) {
        int s=0;
        int sum2=0;
        int ans=-1;
        for(int i=0;i<weights.size();i++){
            sum2+=weights[i];
        }
    int e=sum2;
    int mid=s+(e-s)/2;
    while(s<=e){
        if(isPossible(weights,dayslimit,mid)){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
        
    }
};