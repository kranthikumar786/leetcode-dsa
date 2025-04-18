class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for (int i = 2; i <= n; i++) {
            string temp = "";
            int count = 1;
            char ch = ans[0];
            for (int j = 1; j < ans.size(); j++) {
                if (ans[j] == ch) {
                    count++;
                } else {
                    temp += to_string(count) + ch;
                    ch = ans[j];
                    count = 1;
                }
            }
            temp += to_string(count) + ch;
            ans = temp;
        }
        return ans;
    }
};
