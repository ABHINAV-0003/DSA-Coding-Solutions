class Solution{
public:    
    int first(int arr[], int n,int x){
        int low=0;
        int high=n-1;
        int first=-1;
        while(low<=high){
            int mid=(high+low)/2;
            if(arr[mid]==x){
                first=mid;
                high=mid-1;
            }
            else if(arr[mid]<x){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return first;
    }
    int last(int arr[], int n,int x){
         int low=0;
        int high=n-1;
        int last=-1;
        while(low<=high){
            int mid=(high+low)/2;
            if(arr[mid]==x){
                last=mid;
                low=mid+1;
            }
            else if(arr[mid]<x){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return last;
    }
    int count(int arr[], int n, int x) {
       int cnt=last(arr,n,x)-first(arr,n,x)+1;
        if(first(arr,n,x)==-1){
            return 0;
        }
        else{
            return cnt;
        }
    }
};
