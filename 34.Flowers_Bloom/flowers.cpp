class Solution {
public:
    int possible(vector<int>& bloomDay,int day, int m, int k){
        int count=0;
        int bday=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=day){
                count++;
            
            if(count==k){
                bday++;
                count=0;
            }
            }
            else{
                count=0;
            }
        }
        if(bday>=m){
            return 1;
        }
        return 0;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
       if (((long)m * k) > bloomDay.size()) return -1;
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<bloomDay.size();i++){
            mini=min(bloomDay[i],mini);
            maxi=max(bloomDay[i],maxi);
        }
        int high=maxi;
        int low=mini;
        while(low<=high){
            int mid=(high+low)/2;
        if(possible(bloomDay,mid,m,k)==1){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
        }
        return low;
    }
};
