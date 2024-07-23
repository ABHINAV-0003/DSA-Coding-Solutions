class Solution {
public:
    int possible(vector<int>& weights,int mid, int days){
        int day=1;
        int load=0;
        for(int i=0;i<weights.size();i++){
            if(load+weights[i]<=mid){
                load+=weights[i];
            }
            else{
                load=weights[i];
                day++;
            }
        }
        if(day<=days){
            return 1;
        }
        return 0;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        while(low<=high){
            int mid=(low+high)/2;
            if(possible(weights,mid,days)==1){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};
