class Solution {
private:
    unordered_map<string, string> mp;
    int id = 0;

public:
    Solution() {}

    string encode(string longUrl) {
        string shortUrl = "http://tinyurl.com/" + to_string(id++);
        mp[shortUrl] = longUrl;
        return shortUrl;
    }

    string decode(string shortUrl) {
        return mp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));