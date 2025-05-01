class Solution {
public:
    struct TrieNode {
        TrieNode* child[10] = {};
        bool endofWord = false;
    };

    class Trie {
    public:
        TrieNode* root;
        Trie() {
            root = new TrieNode();
        }

        void insert(int num) {
            TrieNode* node = root;
            string str = to_string(num);
            for (char ch : str) {
                int idx = ch - '0';
                if (!node->child[idx])
                    node->child[idx] = new TrieNode();
                node = node->child[idx];
            }
            node->endofWord = true;
        }

        int search(int num) {
            TrieNode* node = root;
            string str = to_string(num);
            int cnt = 0;
            for (char ch : str) {
                int idx = ch - '0';
                if (!node->child[idx]) {
                    return cnt;
                }
                cnt++;
                node = node->child[idx];
            }
            return cnt;
        }
    };

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie;
        for (int num : arr1) {
            trie.insert(num);
        }

        int ans = 0;
        for (int num : arr2) {
            ans = max(ans, trie.search(num));
        }
        return ans;
    }
};

////  10000 ,12345 , 123456,  100000, 11111 , 12333 , 12345: 
/*
vector<int>ans;
       for(int num : arr1){
        ans.push_back(num);
       }
       for(int num : arr2){
         ans.push_back(num);
       }
      sort(ans.begin(),ans.end());
      
      int n = ans.size();
      int rptr = n-1; 
      int leftptr = n-2;
      while(leftPtr >= 0 ){
          string s1 = []
      }
*/

/// 
// class Solution {
// public:
//     int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
//     int n = arr1.size();
//     int m = arr2.size();
//     int ans = 0 ;
//      for(int i = 0 ; i < n ;i++) {
//           string s1 = to_string(arr1[i]);
//           for(int j = 0 ; j < m ;j++) {
//               string s2 = to_string(arr2[j]) ;
//                 int minlengh = min(s1.length(),s2.length());
//                   int ptr = 0;
//                   while(ptr < minlengh){
//                       if(s1[ptr] != s2[ptr]){
//                            break;
//                       }
//                       ptr++;
//                   }
//                  ans = max(ans,ptr); 
//           }
//      }
//       return ans;
//     }
// };

//  /*
 
//  sorting is good ...? 
 


//  1 ,10, 100, 10000,  100000, 1000000, 100000000 :
//  1,10,100,10000,10000,12345, 1000000: 

//  i   j
//  j : 
//  1

//  minlenght: min longest common prefix lenght: 



//   100000000 , 10000000 : 


 
//  */

// /*
// TLE
// */