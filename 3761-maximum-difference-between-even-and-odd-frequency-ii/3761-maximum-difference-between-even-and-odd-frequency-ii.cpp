class Solution {
 public:
  int maxDifference(string s, int k) {
    int n = s.size();
    vector<vector<int>> freq(5, vector<int>(n + 1, 0));
    for (int i = 0; i < n; ++i) {
      for (int d = 0; d < 5; ++d) {
        freq[d][i + 1] = freq[d][i];
      }
      freq[s[i] - '0'][i + 1]++;
    }
    int result = INT_MIN;
    for (int a = 0; a < 5; ++a) {
      if (freq[a][n] == 0) continue;
      for (int b = 0; b < 5; ++b) {
        if (a == b || freq[b][n] == 0) continue;
        result = max(result, maxDfromAtoB(a, b, k, n, freq));
      }
    }

    return result;
  }

 private:
  int maxDfromAtoB(int a, int b, int k, int n, const vector<vector<int>>& freq) {
    int max_diff = INT_MIN;
    const int kMod = 1e8;
    int min_freq[2][2] = {{kMod, kMod}, {kMod, kMod}};
    int freq_a = 0, freq_b = 0;
    int prev_a = 0, prev_b = 0;
    int left = 0;

    for (int right = k - 1; right < n; ++right) {
      freq_a = freq[a][right + 1];
      freq_b = freq[b][right + 1];

      while ((right - left + 1) >= k && (freq_b - prev_b) >= 2) {
        min_freq[prev_a & 1][prev_b & 1] =
            min(min_freq[prev_a & 1][prev_b & 1], prev_a - prev_b);
        prev_a = freq[a][left + 1];
        prev_b = freq[b][left + 1];
        ++left;
      }

      max_diff = max(max_diff,
                     freq_a - freq_b -
                         min_freq[1 - (freq_a & 1)][freq_b & 1]);
    }

    return max_diff;
  }
};
