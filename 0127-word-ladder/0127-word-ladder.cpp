class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int>mp;
        for(auto i : wordList)mp[i]++;
        queue<string> q;
        q.push(beginWord);
        mp.erase(beginWord);
        int level = 0;
        while(!q.empty()){
            int n = q.size();
            level++;
            for(int i = 0; i < n;i++){
                string f = q.front();
                q.pop();
                if(f == endWord){
                    return level;
                }
                for(int i = 0; i < f.length();i++){
                    char temp = f[i];
                    for(int j = 'a'; j <= 'z';j++){
                        f[i] = j;
                        if(mp[f]){
                            q.push(f);
                            mp.erase(f);
                        }
                    }
                    f[i] = temp;
                }
            }
        }
        return 0;
    }
};