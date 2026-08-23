class TrieNode{
public:
    bool wordEnd;
    vector<TrieNode*> arr;
    TrieNode(){
        wordEnd = false;
        arr.assign(26, NULL);
    }
};
class Trie{
public:
    TrieNode *root;
    Trie(){
        root = new TrieNode();
    }
    void add(string &s){
        TrieNode *temp = root;
        for(auto i : s){
            if(temp->arr[i - 'a'] == NULL){
                temp->arr[i - 'a'] = new TrieNode();
            }
            temp = temp->arr[i - 'a'];
        }
        temp->wordEnd = true;
    }
    string prefix(string &s){
        TrieNode *temp = root;
        string str = "";
        for(auto i : s){
            if(temp->wordEnd)return str;
            if(temp->arr[i-'a'] == NULL)break;
            temp = temp->arr[i - 'a'];
            str.push_back(i);
        }
        return s;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie *trie = new Trie();
        for(auto i : dictionary){
            trie->add(i);
        }
        vector<string> arr;
        string temp = "";
        for(auto i :  sentence){
            if(i == ' '){
                arr.push_back(temp);
                temp = "";
            }else{
                temp.push_back(i);
            }
        }
        if(temp != "")arr.push_back(temp);

        string ans = "";
        for(auto i : arr){
            ans += trie->prefix(i);
            ans.push_back(' ');
        }
        ans.pop_back();
        return ans;
    }
};