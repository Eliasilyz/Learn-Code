class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix[0].size(); i++){
            int x = 0, y = i;
            set<int> st;
            while(x < matrix.size() && y < matrix[0].size()){
                st.insert(matrix[x][y]);
                x++;
                y++;
            }
            if(st.size() != 1)return false;
        }
        for(int i = 0; i < matrix.size(); i++){
            int x = i, y = 0;
            set<int> st;
            while(x < matrix.size() && y < matrix[0].size()){
                st.insert(matrix[x][y]);
                x++;
                y++;
            }
            if(st.size() != 1)return false;
        }
        return true;
    }
};