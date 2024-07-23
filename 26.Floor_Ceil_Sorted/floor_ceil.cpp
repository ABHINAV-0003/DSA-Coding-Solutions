pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
    int ceil=-1;
    int floor=-1;
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=low+(high-low/2);
        if(a[mid]>=x){
            ceil=a[mid];
            high=mid-1;
        }
        else {
            low=mid+1;
        }
    }
    floor=-1;
    low=0;
    high=n-1;
    while(low<=high){
        int mid=low+(high-low/2);
        if(a[mid]<=x){
            floor=a[mid];
            low=mid+1;
        }
        else {
            high=mid-1;
        }
    }
    return {floor,ceil};
}
