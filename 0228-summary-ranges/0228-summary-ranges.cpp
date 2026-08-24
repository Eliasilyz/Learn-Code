class Solution {
public:
    vector<string> summaryRanges(vector<int>& arr) {
        if(arr.size() == 0){
            return {};
        }
        vector<string> ans;
        int start = arr[0];
        int prev = arr[0];
        for(int i=1;i<arr.size();i++){
            prev++;
            if(arr[i] != prev){
                string s = to_string(start);
                if(start != prev - 1){
                    s+= "->" + to_string(prev- 1);
                }
                ans.push_back(s);
                prev = arr[i];
                start = arr[i];
            }
        }
        if(start == arr[arr.size() - 1]){
            string s = to_string(start);
            ans.push_back(s);
        }else{
            string s = to_string(start) + "->" + to_string(prev);
            ans.push_back(s);
        }
        return ans;
    }
};