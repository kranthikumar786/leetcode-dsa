class Solution {
public:
    struct Node {
        unordered_map<int, int> freq;
        int maxLen = 0;
    };

    vector<Node> seg;
    vector<int> arr;
    int n;

    void build(int ind, int low, int high) {
        if (low == high) {
            seg[ind].freq[arr[low]] = 1;
            seg[ind].maxLen = 1;
            return;
        }
        int mid = (low + high) / 2;
        build(2 * ind + 1, low, mid);
        build(2 * ind + 2, mid + 1, high);

        merge(ind, 2 * ind + 1, 2 * ind + 2);
    }

    void merge(int ind, int leftChild, int rightChild) {
        // Combine frequency maps (just for full range knowledge, not used in maxLen here)
        seg[ind].freq = seg[leftChild].freq;
        for (const auto& [k, v] : seg[rightChild].freq)
            seg[ind].freq[k] += v;

        // Compute max contiguous subarray with at most 2 types crossing mid
        seg[ind].maxLen = max(seg[leftChild].maxLen, seg[rightChild].maxLen);

        // Merge across boundary
        int l = (ind == 0) ? 0 : -1, r = -1;
        if (ind == 0) {
            l = 0;
            r = arr.size() - 1;
        }

        unordered_map<int, int> freq;
        int left = (ind == 0) ? 0 : -1;
        int right = (ind == 0) ? 0 : -1;
        int maxF = 0;
        if (ind == 0) {
            for (int i = 0; i < n; i++) {
                freq[arr[i]]++;
                while (freq.size() > 2) {
                    freq[arr[left]]--;
                    if (freq[arr[left]] == 0)
                        freq.erase(arr[left]);
                    left++;
                }
                maxF = max(maxF, i - left + 1);
            }
            seg[ind].maxLen = maxF;
        }
    }

    int totalFruit(vector<int>& fruits) {
        arr = fruits;
        n = arr.size();
        seg.resize(4 * n);
        build(0, 0, n - 1);
        return seg[0].maxLen;
    }
};






// class Solution {
// public:
//     int totalFruit(vector<int>& fruits) {

//        int n = fruits.size();
//        int firstfruit = 0 , secondfruit = -1;
//        int firstfruitcnt = 0 , secondfruitcnt = 0;
//        int maxSum = 0 ;
//        int ans = 0;
//        for(int i = 0 ; i < n ;i++) {
//                 firstfruit = fruits[i];
//                 firstfruitcnt = 1;
//                 secondfruit = -1;
//                 secondfruitcnt = 0;
//             for(int j = i+1 ; j < n ;j++ ) {
//                   if(firstfruit == fruits[j]){
//                      firstfruitcnt++;
//                   } 
//                      if(secondfruit == -1 || secondfruit == fruits[j]) {
//                           secondfruit = fruits[j];
//                           secondfruitcnt++;
//                      }
//                 }
            
//             int  sum = 0;
//              if(secondfruit != -1){
//                     sum += (firstfruit*firstfruitcnt);
//                     sum += (secondfruit*secondfruitcnt);
//              }
//              if(sum > maxSum){
//                  maxSum = sum;
//                  ans = firstfruitcnt +secondfruitcnt; 
//              }
//        }
//        return ans;
//     }
// };

// /*TLE*/