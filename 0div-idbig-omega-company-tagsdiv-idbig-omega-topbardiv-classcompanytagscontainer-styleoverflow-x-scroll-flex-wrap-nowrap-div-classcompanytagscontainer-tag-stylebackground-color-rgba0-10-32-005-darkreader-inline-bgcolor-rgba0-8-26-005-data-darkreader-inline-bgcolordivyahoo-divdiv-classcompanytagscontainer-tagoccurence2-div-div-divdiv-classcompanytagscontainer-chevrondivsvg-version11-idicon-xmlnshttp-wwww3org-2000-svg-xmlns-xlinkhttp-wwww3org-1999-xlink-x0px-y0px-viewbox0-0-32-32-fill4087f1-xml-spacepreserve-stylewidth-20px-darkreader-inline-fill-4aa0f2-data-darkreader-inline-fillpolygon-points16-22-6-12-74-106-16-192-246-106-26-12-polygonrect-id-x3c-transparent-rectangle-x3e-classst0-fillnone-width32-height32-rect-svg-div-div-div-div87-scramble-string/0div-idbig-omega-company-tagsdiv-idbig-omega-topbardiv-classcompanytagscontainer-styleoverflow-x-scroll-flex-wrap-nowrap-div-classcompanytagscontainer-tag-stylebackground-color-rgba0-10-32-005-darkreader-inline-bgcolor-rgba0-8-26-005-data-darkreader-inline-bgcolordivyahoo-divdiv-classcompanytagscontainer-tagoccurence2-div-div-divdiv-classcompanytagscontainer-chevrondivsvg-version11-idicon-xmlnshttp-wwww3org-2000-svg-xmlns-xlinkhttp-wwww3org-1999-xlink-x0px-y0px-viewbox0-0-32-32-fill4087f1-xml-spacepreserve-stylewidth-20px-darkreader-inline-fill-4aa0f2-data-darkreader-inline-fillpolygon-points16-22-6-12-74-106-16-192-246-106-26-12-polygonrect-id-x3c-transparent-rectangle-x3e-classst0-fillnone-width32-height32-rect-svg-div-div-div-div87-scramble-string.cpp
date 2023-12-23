class Solution {
public:
    unordered_map<string,bool>mem;
    bool scrambleHelper(string s1, string s2) {
        if (s1 == s2) {
            return true;
        }

          string key = s1 + s2 ;
          if(mem.find(key) != mem.end()) {
               return mem[key];
          }
        int n = s1.size();
        for (int i = 1; i < n; i++) {
            if ((scrambleHelper(s1.substr(0, i), s2.substr(0, i)) && scrambleHelper(s1.substr(i), s2.substr(i))) ||
                (scrambleHelper(s1.substr(0, i), s2.substr(n - i)) && scrambleHelper(s1.substr(i), s2.substr(0, n - i)))) {
                return mem[key] =  true;
            }
        }

        return mem[key] =  false;
    }

    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length()) {
            return false;
        }

        return scrambleHelper(s1, s2);
    }
};