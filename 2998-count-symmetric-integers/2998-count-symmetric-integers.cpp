class Solution {
public:
    vector<int> numberConvertingToDigits(int num) {
        vector<int> digits;
        while (num) {
            digits.push_back(num % 10);
            num /= 10;  
        }
        return digits;
    }

    bool leftSumAndRightSum(vector<int>& digits) {
        int leftPtr = 0;
        int rightPtr = digits.size() - 1;  
        int leftSum = 0;
        int rightSum = 0;
        while (leftPtr < rightPtr) {
            leftSum += digits[leftPtr++];
            rightSum += digits[rightPtr--];
        }
        return leftSum == rightSum;
    }

    bool isSymmetric(int num) {
        vector<int> digits = numberConvertingToDigits(num);
        return leftSumAndRightSum(digits);
    }

    int countSymmetricIntegers(int low, int high) {
        int ans1 = 0;
        while (low <= high) {
            string s = to_string(low);
            if (s.length() % 2 == 1) {
                int nextLength = s.length() + 1;
                low = pow(10, nextLength - 1);
                continue;
            }
            if (isSymmetric(low)) {
                ans1++;
            }
            low++;  
        }
        return ans1;
    }
};
