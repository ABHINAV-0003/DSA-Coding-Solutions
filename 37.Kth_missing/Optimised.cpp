class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low=1;
        int high=arr.size()-1;
        while(low<=high){
            int mid=(high+low)/2;
            if(arr[mid]-mid=1>=k){
                high=mid-1;
            }
            else{
                low=mid+1;
            }

        }
        return high+k+1;
    }
};
