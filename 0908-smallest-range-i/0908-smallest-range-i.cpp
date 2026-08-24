class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        // int mini = *min_element(A.begin(), A.end());
        // int maxi = *max_element(A.begin(), A.end());
        // sort(A.begin(), A.end());
        // int mini = A[0];
        // int maxi = A[A.size() - 1];
        
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i=0;i<A.size();i++){
            mini = min(mini, A[i]);
            maxi = max(maxi, A[i]);
        }
        
        
        
        return max(0, maxi - mini - 2*K);
    }
};