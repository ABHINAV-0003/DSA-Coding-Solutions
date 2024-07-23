class Solution {
public:
    long long findmax(vector<int> &piles){
        long long ans=INT_MIN;
        for(int i=0;i<piles.size();i++){
            ans=max(ans,(long long)piles[i]);
        }
        return ans;
    }
    long long hours(vector<int>& piles,int mid){
        long long hour=0;
        for(int i=0;i<piles.size();i++){
            hour+=ceil((double)piles[i]/(double)mid);
        }
        return hour;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=findmax(piles);
        while(low<=high){
            int mid=(high+low)/2;
            if(hours(piles,mid)<=h){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};
