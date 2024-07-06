// Function to find the length of the longest consecutive elements sequence using sorting
int longestSuccessiveElements(vector<int>& a) {
    int count = 0;
    int lsmall = INT_MIN;
    int longest = 1;
    sort(a.begin(), a.end());
    for(int i = 0; i < a.size(); i++) {
        if(a[i] == lsmall + 1) {
            count++;
            lsmall = a[i];
        } else if(a[i] != lsmall) {
            count = 1;
            lsmall = a[i];
        }
        longest = max(count, longest);
    }
    return longest;
}
