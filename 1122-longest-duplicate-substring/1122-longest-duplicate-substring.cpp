class Solution {
public:
    string longestDupSubstring(string s) {
        int n = s.size(), l = 1, r = n-1;
        power = vector<int>(n);
        for(int i = 0; i < n; i++)  
            power[i] = (i == 0) ? 1 : (power[i-1] * 26) % prime;
        string res;
        while(l <= r) 
        {
            int mid = l + (r - l) / 2;
            string dup = rabinKarp(s, mid);
            
            if((int)dup.size() > (int)res.size()) 
            {
                res = dup;
                l = mid+1;
            } 
            else  
                r = mid-1;
        }
        return res;
    }
    
private:
    int prime = 10000007;
    vector<int> power;
    
    string rabinKarp(string s, int len) {
        if(len == 0)    
            return "";
        int n = s.size(), curr = 0;
        unordered_map<int, vector<int>> hash;
        for(int i = 0; i < len; i++) {
            curr = (curr * 26 + (s[i]-'a')) % prime;
        }
        hash[curr] = {0};   
        for(int i = len; i < n; i++) 
        {
            curr = ((curr - power[len-1] * (s[i-len]-'a')) % prime + prime) % prime;
            curr = (curr * 26 + (s[i]-'a')) % prime;
            if(hash.find(curr) == hash.end())   
                hash[curr] = {i-len+1};
            else 
            {
                for(int index: hash[curr]) 
                {
                    if(s.substr(index, len) == s.substr(i-len+1, len))  
                        return s.substr(index, len);
                }
                hash[curr].push_back({i-len+1});
            }
        }
        return "";      
    }
};
       

        /*

    BruteForce approach : 
    timeComplexity: O(sLength*sLength) + O(sLength*sLength)  = 3 *10^4 * 3*10^4 = 9*10^8 ~ 10^9 , can expect TLE  
    spaceComplexity : O(sLength*sLength) in linear space : 

class Solution {
public:
    string longestDupSubstring(string s) {
       unordered_map<string,int>subStringWithFrequncy;
        for(int lIndex = 0;s[lIndex]; lIndex++){
               string subString = "";
            for(int rIndex = lIndex ;s[rIndex] ; rIndex++) {
                 subString += s[rIndex];
                 subStringWithFrequncy[subString]++;
            }
        }
 int maxLength = 0; 
 string ans = ""; 
  for(auto itr = subStringWithFrequncy.begin() ; itr!= subStringWithFrequncy.end(); itr++) {
      if(itr->second >= 2){
           string word = itr->first;
         if(word.length() > maxLength){
             maxLength = word.length();
             ans = word;
         }
      }
  }
return ans;
 }
    };


TestCases : 
    1. "aaaaaaa" 
    2. "aa" 
    3. "banana" overlapping : 
    4. 





         b a n a n a
         substrind - > frequncy
         b ->1
         ba ->1
         ban ->1
         bana->1
         banan - >1
         banana ->1


         ----
       
         a -> 3 : 
         an - > 2 
         ana - > 2 : 
         anan->1:
          but answer is longest string not occurance of it : so 

           geenrate all substrings and maintanint frqucnyas well and check for each of substring : 
           first condtion is frequcny >= 2 
              second update based on length : 
        */