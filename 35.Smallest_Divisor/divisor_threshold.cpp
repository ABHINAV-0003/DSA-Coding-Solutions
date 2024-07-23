class Solution {
public:
    int possible(vector<int>& nums,int mid,int threshold){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum=sum+ceil((double)nums[i]/(double)mid);
        }
        if(sum<=threshold){
            return 1;
        }
        return 0;

    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid=(low+high)/2;
            if(possible(nums,mid,threshold)==1){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};
