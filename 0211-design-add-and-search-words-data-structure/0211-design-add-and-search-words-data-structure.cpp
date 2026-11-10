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

class WordDictionary {
public:
    TrieNode* root;

    WordDictionary() {
        root = new TrieNode('\0');
    }

    void insertutil(TrieNode* root, string word) {
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
        }

        insertutil(child, word.substr(1));
    }

    void addWord(string word) {
        insertutil(root, word);
    }

    bool searchHelper(const string& word, int index, TrieNode* node) {
        if (index == word.size())
            return node->isterminal;

        char ch = word[index];

        if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->children[i] &&
                    searchHelper(word, index + 1, node->children[i])) {
                    return true;
                }
            }
            return false;
        }

        if (node->children[ch - 'a'] == NULL)
            return false;

        return searchHelper(word, index + 1, node->children[ch - 'a']);
    }

    bool search(string word) {
        return searchHelper(word, 0, root);
    }
};