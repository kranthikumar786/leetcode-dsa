class Solution {
public:
      vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int diff = (accumulate(B.begin(), B.end(), 0) - accumulate(A.begin(), A.end(), 0)) >> 1;
        unordered_set<int> setB(B.begin(), B.end());

        for (int i : A) {
            if(setB.count(diff + i)) 
                return {i, diff + i};
        }
        return {};
    }
};