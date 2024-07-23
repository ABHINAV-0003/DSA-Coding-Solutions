bool possible(vector<int> &stalls,int mid, int k){
    int count=1;
    int pre=stalls[0];
    for(int i=1;i<stalls.size();i++){
        if(stalls[i]>=pre+mid){
            count++;
            pre=stalls[i];
        }
        if(count>=k){
            return true;
        }
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
    {

        sort(stalls.begin(),stalls.end());   
    int low=0;
    int high=stalls[stalls.size()-1]-stalls[0];
    while(low<=high){
        int mid=(low+high)/2;
        if(possible(stalls,mid,k)==true){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return high;
}
