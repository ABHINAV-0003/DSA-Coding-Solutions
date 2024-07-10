class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
       vector<int> ans;
       int a,b;
       map<int,int> mpp;
       for(int i=0;i<n;i++){
           mpp[arr[i]]++;
       }
       for(int i=1;i<=n;i++){
           if(mpp[i]==0){
               a=i;
           }
           if(mpp[i]==2){
               b=i;
           }
       }
       ans.push_back(b);
       ans.push_back(a);
       return ans;
    }
};