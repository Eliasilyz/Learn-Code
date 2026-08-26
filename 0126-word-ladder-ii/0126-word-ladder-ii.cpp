class Solution {
public:

    void dfs(vector<vector<string>> &ans, vector<string> &temp, unordered_map<string, int> &levels, set<string> &st, string curr, int level){
        if(level == 1){
            temp.push_back(curr);
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        temp.push_back(curr);
        // cout<<curr<<" "<<level<<endl;
        for(int i = 0; i < curr.length();i++){
            char c = curr[i];
            for(int j = 'a'; j<='z';j++){
                curr[i] = j;
                if(st.find(curr) != st.end() && levels[curr] == level - 1){
                    dfs(ans, temp, levels, st, curr, level - 1);
                }
            }
            curr[i] = c;
        }
        temp.pop_back();
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> wordList)
    {
        set<string> st(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        st.erase(beginWord);
        int level = 0;
        unordered_map<string, int> levels;
        bool found = false;
        while(!q.empty()){
            level++;
            int n = q.size();
            for(int i = 0; i < n;i++){
                auto f = q.front();
                q.pop();
                levels[f] = level;
                if(f == endWord){
                    found = true;
                    break;
                }
                for(int i = 0; i < f.length();i++){
                    char c = f[i];
                    for(int j = 'a'; j <= 'z';j++){
                        f[i] = j;
                        if(st.find(f)!=st.end()){
                            q.push(f);
                            st.erase(f);
                        }
                    }
                    f[i] = c;
                }
            }
            if(found)break;
        }
        if(!found)return {};
        vector<vector<string>> ans;
        vector<string> temp;
        set<string> st2(wordList.begin(), wordList.end());
        st2.insert(beginWord);
        dfs(ans, temp, levels, st2, endWord, levels[endWord]);
        for(auto &i : ans){
            reverse(i.begin(), i.end());
        }
        return ans;
    }
};