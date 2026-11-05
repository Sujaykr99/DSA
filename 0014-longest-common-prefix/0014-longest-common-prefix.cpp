class TrieNode {
public:
    char data;
    TrieNode* children[26];
    int childcount;
    bool isterminal;

    TrieNode(char ch) {
        data = ch;
        childcount = 0;
        isterminal = false;

        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() { 
        root = new TrieNode('\0'); 
        }

    void insertUtil(TrieNode* root, string word) {
        if (word.length() == 0) {
            root->isterminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childcount++;
        }

        insertUtil(child, word.substr(1));
    }

    void insertword(string word) { insertUtil(root, word); }

    void lcp(string str, string& ans) {
        TrieNode* curr = root;

        for (int i = 0; i < str.length(); i++) {

            int index = str[i] - 'a';

            if (curr->childcount == 1 && !curr->isterminal) {
                ans.push_back(str[i]);
                curr = curr->children[index];
            } else {
                break;
            }
        }
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        if (strs.size() == 0)
            return "";

        Trie* t = new Trie();

        for (int i = 0; i < strs.size(); i++) {
            t->insertword(strs[i]);
        }

        string ans = "";
        t->lcp(strs[0], ans);

        return ans;
    }
};