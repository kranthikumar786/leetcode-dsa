class Solution {
public:
    static const int MOD;  

    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int maxElement = *max_element(nums.begin(), nums.end());

        vector<int> primeScores = getPrimeScores(maxElement);
        vector<int> scores(n);
        for (int i = 0; i < n; i++) {
            scores[i] = primeScores[nums[i]];
        }

        vector<int> nextDominant(n, n), prevDominant(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && scores[st.top()] < scores[i]) {
                nextDominant[st.top()] = i;
                st.pop();
            }
            if (!st.empty()) prevDominant[i] = st.top();
            st.push(i);
        }

        vector<long long> subarrayCount(n);
        for (int i = 0; i < n; i++) {
            subarrayCount[i] = (long long)(nextDominant[i] - i) * (i - prevDominant[i]);
        }

        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }

        long long score = 1;
        
        while (k > 0 && !pq.empty()) {
            auto [num, idx] = pq.top();
            pq.pop();

            long long ops = min((long long)k, subarrayCount[idx]);
            score = (score * power(num, ops)) % MOD;

            k -= ops;
        }

        return (int)score;
    }

private:
    vector<int> getPrimeScores(int maxElement) {
        vector<int> primeScores(maxElement + 1, 0);
        vector<bool> isPrime(maxElement + 1, true);

        for (int i = 2; i <= maxElement; i++) {
            if (isPrime[i]) {
                for (int j = i; j <= maxElement; j += i) {
                    isPrime[j] = false;
                    primeScores[j]++;
                }
            }
        }
        return primeScores;
    }

    static long long power(long long base, long long exponent) {
        long long result = 1;
        while (exponent > 0) {
            if (exponent % 2 == 1) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exponent /= 2;
        }
        return result;
    }
};

const int Solution::MOD = 1e9 + 7;
