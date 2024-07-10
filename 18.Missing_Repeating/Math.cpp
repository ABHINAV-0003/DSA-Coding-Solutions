#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        long long N = n;
        long long sum = 0;
        long long ssum = 0;
        long long sumn = 0;
        long long ssumn = 0;

        for (int i = 0; i < n; i++) {
            sum += arr[i];
            ssum += (long long)arr[i] * (long long)arr[i];
        }

        ssumn = (N * (N + 1) * (2 * N + 1)) / 6;
        sumn = (N * (N + 1)) / 2;

        long long val1 = sum - sumn;
        long long val2 = ssum - ssumn;
        val2 = val2 / val1;

        long long b = (val2 + val1) / 2;
        long long a = (val2 - val1) / 2;

        vector<int> ans;
        ans.push_back((int)b);
        ans.push_back((int)a);

        return ans;
    }
};

class Solution {
  public:
    long long merge(long long arr[],int low,int mid,int high){
        long long cnt=0;
        int left=low;
        int right=mid+1;
        vector<long long> temp;
        while(left<=mid && right<=high){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                cnt+=(mid-left+1);
                right++;
            }
        }
            while(left<=mid){
                  temp.push_back(arr[left]);
                left++;
            }
            while(right<=high){
                temp.push_back(arr[right]);
                right++;
            }
        
        for(int i=low;i<=high;i++){
            arr[i]=temp[i-low];
        }
        return cnt;
    }
    long long mergesort(long long arr[],int low,int high){
    long long cnt=0;
    if(low>=high){
        return cnt;
    }
    int mid=(high+low)/2;
    cnt+=mergesort(arr,low,mid);
    cnt+=mergesort(arr,mid+1,high);
    cnt+=merge(arr,low,mid,high);
    return cnt;
    }
    long long int inversionCount(long long arr[], int n) {
      return  mergesort(arr,0,n-1);
        
    }
};


class Solution {
public:
    int countpairs(vector<int>& nums, int low, int mid, int high){
        int cnt=0;
        int right=mid+1;
        for(int i=low;i<=mid;i++){
            while(right<=high && nums[i]>2LL*nums[right]){
                right++;
            }
            cnt += (right - (mid + 1));
        }
        return cnt;
    }
    void merge(vector<int>& nums, int low, int mid, int high) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;
        while (left <= mid && right <= high){ 
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            }
            if (nums[left] > nums[right]) {
                temp.push_back(nums[right]);
                right++;
            }
        }
            while (left <= mid) {
                temp.push_back(nums[left]);
                left++;
            }
            while (right <= high) {
                temp.push_back(nums[right]);
                right++;
            }
        
        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
    }
    int mergesort(vector<int>& nums, int low, int high) {
        int cnt = 0;
        if (low >= high) {
            return cnt;
        }
        int mid = (low + high) / 2;
        cnt += mergesort(nums, low, mid);
        cnt += mergesort(nums, mid + 1, high);
        cnt+=countpairs(nums,low,mid,high);
        merge(nums,low,mid,high);
        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        return mergesort(nums,0,nums.size()-1);
    }
};

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        long long  maxi=INT_MIN;
        for(int i=0;i<n;i++){
              long long prod=1;
            for(int j=i;j<n;j++){
                prod=prod*nums[j];
                maxi=max(maxi,prod);
            }
        }
        return maxi;
    }
};


class Solution {
public:
    int maxProduct(vector<int>& nums) {
          int n = nums.size();
        double prefix = 1;
        double suffix = 1;
        double maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (prefix == 0)
                prefix = 1;
            if (suffix == 0)
                suffix = 1;
            prefix = prefix * nums[i];
            suffix = suffix * nums[n - i - 1];
            maxi=max(prefix,max(suffix,maxi));
        }
        return maxi;
    }  
    
};
