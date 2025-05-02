class TrieNode {
public:
    TrieNode* child[26];
    bool isEndOfWord;
    TrieNode() {
        for (int i = 0; i < 26; ++i) 
             child[i] = nullptr;
        isEndOfWord = false;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
      TrieNode* node  = root;
       for(char ch : word) {
          int idx = ch -'a';
          if(!node->child[idx]){
              node->child[idx] = new TrieNode();
          }
          node = node->child[idx];
       }
    node->isEndOfWord = true; 
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for(char ch : word) {
            int idx = ch -'a';
            if(!node->child[idx]){
                  return false;
            }
            node = node->child[idx];
        }
        return node->isEndOfWord;
    }
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(char ch : prefix){
             int idx = ch-'a';
             if(!node->child[idx]){
                return false;
             }
             node = node->child[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */