class Solution {
public:
    struct TrieNode {
        TrieNode* child[2];
        TrieNode() {
            child[0] = nullptr;
            child[1] = nullptr;
        }
    };

    class Trie {
        TrieNode* root;

    public:
        Trie() {
            root = new TrieNode();
        }

        void insert(int num) {
            TrieNode* node = root;
            for (int i = 31; i >= 0; --i) {
                int bit = (num >> i) & 1;
                if (!node->child[bit]) {
                    node->child[bit] = new TrieNode();
                }
                node = node->child[bit];
            }
        }

        int getMaxXor(int num) {
            TrieNode* node = root;
            int maxXor = 0;
            for (int i = 31; i >= 0; --i) {
                int bit = (num >> i) & 1;
                int toggledBit = 1 - bit;
                if (node->child[toggledBit]) {
                    maxXor |= (1 << i);
                    node = node->child[toggledBit];
                } else {
                    node = node->child[bit];
                }
            }
            return maxXor;
        }
    };

    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for (int num : nums) {
            trie.insert(num);
        }

        int maxXor = 0;
        for (int num : nums) {
            maxXor = max(maxXor, trie.getMaxXor(num));
        }
        return maxXor;
    }
};




// class Solution {
// public:
//     int findMaximumXOR(vector<int>& nums) {
//      int ans = 0 ;
//      int n = nums.size();
//       for(int i = 0 ; i < n ;i++) {
//            for(int j = i +1 ; j < n ;j++) {
//                 ans = max(ans, nums[i]^nums[j]);
//            }
//       }
//     return ans;
//     }
// };
// // TLE


// /*

//   let's sort : 
// 2 3 5 8 10 25 :  if right means max value and not mandary more set bits
// 2 = 10

//    prefix ...? 
 
//      long suffix also not helping 
//  1  2 3  5  8 
// 0   5


// */