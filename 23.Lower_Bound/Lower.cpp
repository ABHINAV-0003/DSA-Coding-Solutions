int lowerBound(vector<int> arr, int n, int x) {
    int low=0;
    int high=n-1;
    int lb=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>=x){
            lb=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return lb;
}
