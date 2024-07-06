class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> mpp;
        int count = 0;
        int presum = 0;
        mpp[0] = 1;
        for(int i = 0; i < nums.size(); i++) {
            presum += nums[i];
            int remove = presum - k;
            count += mpp[remove];
            mpp[presum]++;
        }
        return count;
    }
};
