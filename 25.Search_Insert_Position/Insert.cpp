class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
       int low=0;
        int high=nums.size()-1;
        int ind=nums.size();
        while(low<=high){
            int mid=(high+low)/2;
            if(nums[mid]>=target){
                ind=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ind;
    }
};
