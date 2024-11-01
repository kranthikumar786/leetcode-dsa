class Solution {
public:
    string makeFancyString(std::string s) {
        string result;
        for (char c : s) {
            if (result.size() >= 2 && result[result.size() - 1] == c && result[result.size() - 2] == c) continue;
            result += c;
        }
        return result;
    }
};
