class TrieNode {
public:
    TrieNode* children[26] = {};
    bool isEnd = false;
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    string getLongestCommonPrefix() {
        string prefix;
        TrieNode* node = root;

        while (true) {
            int count = 0;
            int nextCharIdx = -1;

            for (int i = 0; i < 26; ++i) {
                if (node->children[i]) {
                    count++;
                    nextCharIdx = i;
                }
            }

            if (count != 1 || node->isEnd)
                break;

            node = node->children[nextCharIdx];
            prefix += (char)(nextCharIdx + 'a');
        }

        return prefix;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        Trie trie;
        for (const string& word : strs) {
            if (word.empty()) return "";
            trie.insert(word);
        }

        return trie.getLongestCommonPrefix();
    }
};


// class Solution {
// public:

//    void insert(stirng s) {
//       Trie * node = root;
//         for(char ch : s){
//             if(node->chid[ch-'a'] == nullptr){
//                 node->child[ch-'a'] = new node(ch);
//             }
//            node = node->child[ch-'a']; 
//         }
//         node->endWord = true;
//    }

//      bool serach (stirng s){
//            Tre*node = root;
//            for(char ch : s){
//               if(node->child[ch -'a'] == nullptr) {
//                    return false;
//               }
//               node = node->child[ch-'a'];
//            }
//            return node->endWord;  
//      }

//      void updateallChar(char src, char dest) {
//            Trie * node = root;
//              f
              

//      } 

//     string longestCommonPrefix(vector<string>& strs) {

//     int  n = strs.length();
//       for(int i = 0 ; i < n ; i++) {
                       
//            tre.insert(s);

//       }  


//     }
// };