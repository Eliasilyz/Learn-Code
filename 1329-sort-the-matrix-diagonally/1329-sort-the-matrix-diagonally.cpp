class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0; i < n; i ++){
            int x = i, y = 0;
            vector<int> arr;
            while(x < n && y < m){
                arr.push_back(mat[x++][y++]);
            }
            sort(arr.begin(), arr.end());
            x = i, y = 0;
            int k = 0;
            while(k < arr.size()){
                mat[x++][y++] = arr[k++];
            }
        }
        for(int j = 1; j < m; j ++){
            int x = 0, y = j;
            vector<int> arr;
            while(x < n && y < m){
                arr.push_back(mat[x++][y++]);
            }
            sort(arr.begin(), arr.end());
            x = 0, y = j;
            int k = 0;
            while(k < arr.size()){
                mat[x++][y++] = arr[k++];
            }
        }
        return mat;
    }
};