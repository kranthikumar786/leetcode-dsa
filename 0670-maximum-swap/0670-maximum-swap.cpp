class Solution {
public:
    int maximumSwap(int num) {
        string numStr = to_string(num);
        int n = numStr.size();
        
        int maxIdx = n - 1;
        int leftIdx = -1, rightIdx = -1;
        
        for (int i = n - 2; i >= 0; --i) {
            if (numStr[i] > numStr[maxIdx]) {
                maxIdx = i; 
            } else if (numStr[i] < numStr[maxIdx]) {
                leftIdx = i;
                rightIdx = maxIdx;
            }
        }
        
        if (leftIdx == -1) return num;
        swap(numStr[leftIdx], numStr[rightIdx]);
        return stoi(numStr);
    }
};
