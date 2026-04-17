class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class WordDictionary {
private:
    TrieNode* root;

    bool searchInNode(string& word, int index, TrieNode* node) {
        TrieNode* curr = node;
        
        for (int i = index; i < word.length(); i++) {
            char c = word[i];
            
            if (c == '.') {
                for (int j = 0; j < 26; j++) {
                    if (curr->children[j] != nullptr) {
                        if (searchInNode(word, i + 1, curr->children[j])) {
                            return true;
                        }
                    }
                }
                return false;
            } else {
                int idx = c - 'a';
                if (curr->children[idx] == nullptr) return false;
                curr = curr->children[idx];
            }
        }
        return curr->isEndOfWord;
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) {
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }
        curr->isEndOfWord = true;
    }
    
    bool search(string word) {
        return searchInNode(word, 0, root);
    }
};