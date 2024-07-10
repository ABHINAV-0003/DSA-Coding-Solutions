#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        long long maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            long long prod = 1;
            for (int j = i; j < n; j++) {
                prod = prod * nums[j];
                maxi = max(maxi, prod);
            }
        }
        return maxi;
    }
};
