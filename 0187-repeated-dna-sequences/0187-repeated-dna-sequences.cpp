class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() < 10) return {};

     vector<string>ans;
     unordered_map<string, int>mp;
        int n = s.size();
   for(int i = 0 ; i < n ; i++) {
        string sub = s.substr(i,10);
        mp[sub]++;
   }
   for(auto itr = mp.begin() ; itr != mp.end() ; itr++) {
         if(itr->second > 1) {
             ans.push_back(itr->first);
         }
   }  
  return ans; 
    }
};


/*
---------------
string matching algos don't work likr this : 
kmp also don't work as per my undeestiing ..? 
why : 
KMP is longest suffix and prefix : 
palindromic nature 
------------
Rolling hash : 
Patt  mandatory : 
can't use here
----------------
 Z - algo don't work for this substring match becuase here substring canbe anywhere not mandatry to have to be an prefix of s :
 Hence won't work
class Solution {
public:
    vector<int> zfun(string s) {
        int sLength = s.size();
        int leftPtr = 0, rightPtr = 0;
        vector<int> zFUN(sLength, 0);
        
        for (int curPtr = 1; curPtr < sLength; curPtr++) {
            if (curPtr > rightPtr) {
                leftPtr = rightPtr = curPtr;
                while (rightPtr < sLength && s[rightPtr] == s[rightPtr - leftPtr]) {
                    rightPtr++;
                }
                zFUN[curPtr] = rightPtr - leftPtr;
                rightPtr--;
            } else {
                int index = curPtr - leftPtr;
                if (zFUN[index] < rightPtr - curPtr + 1) {
                    zFUN[curPtr] = zFUN[index];
                } else {
                    leftPtr = curPtr;
                    while (rightPtr < sLength && s[rightPtr] == s[rightPtr - leftPtr]) {
                        rightPtr++;
                    }
                    zFUN[curPtr] = rightPtr - leftPtr;
                    rightPtr--;
                }
            }
        }
        return zFUN;
    }
    
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() < 10) return {};
        vector<int> ZFUN = zfun(s);
        vector<string> ans;
        unordered_set<string> seen;
        for (int i = 0; i < ZFUN.size(); i++) {
           cout<<ZFUN[i]<<" ";
            if (ZFUN[i] >= 10) {
                string seq = s.substr(i, 10);
                if (seen.find(seq) == seen.end()) {
                    ans.push_back(seq);
                    seen.insert(seq);
                }
            }
        }
        return ans;
    }
};


 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27  28
  "A A A A A C C C C C A  A  A  A  A  C  C  C  C  C  C  A  A   A  A  A  G  G  G  T T T "
                       10
       AAAAACCCCC
    



    C  C  C  C  C  C  A  A   A  A  A


    use z function : if z[i] == 10 : then s.substr(10,10+11) : 
    */



