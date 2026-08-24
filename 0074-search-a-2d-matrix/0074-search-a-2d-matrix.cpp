class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        
        int lo = 0, hi = n- 1, pos = -1;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(target >= matrix[mid][0] && target <= matrix[mid][m-1]){
                pos = mid;
                break;
            }
            else if(target >= matrix[mid][0]){
                lo = mid + 1;
            }else{
                hi = mid - 1;
            }
        }
        if(pos == -1)return false;
        
        lo = 0, hi = m -1;
        while(lo<= hi){
            int mid = lo + (hi - lo)/2;
            if(target == matrix[pos][mid]){
                return true;
            }
            else if(target > matrix[pos][mid]){
                lo = mid + 1;
            }else{
                hi = mid - 1;
            }
        }
        return false;
    }
};