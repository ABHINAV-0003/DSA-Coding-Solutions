int upperBound(vector<int> &arr, int x, int n){
    int low=0;
    int high=n-1;
    int ub=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>x){
            ub=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ub;
}
