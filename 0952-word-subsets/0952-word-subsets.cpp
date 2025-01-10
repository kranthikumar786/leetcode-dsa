class Solution {
public:
    vector<string> wordSubsets(vector<string>& mainWords, vector<string>& requiredWords) {
        int maxCharFreq[26] = {0};
        int tempCharFreq[26];
        
        for (const auto& word : requiredWords) {
            memset(tempCharFreq, 0, sizeof tempCharFreq);//To Set Temp freq all to zero 
//You can do vector<int> tempCharFreq(26,0);
            for (char ch : word) {
                tempCharFreq[ch - 'a']++;
            }
            for (int i = 0; i < 26; ++i) {
                maxCharFreq[i] = max(maxCharFreq[i], tempCharFreq[i]);
            }
        }
        
        vector<string> universalWords;
        
        for (const auto& word : mainWords) {
            memset(tempCharFreq, 0, sizeof tempCharFreq);
            for (char ch : word) {
                tempCharFreq[ch - 'a']++;
            }
            bool isUniversal = true;
            for (int i = 0; i < 26; ++i) {
                if (maxCharFreq[i] > tempCharFreq[i]) {
                    isUniversal = false;
                    break;
                }
            }
            if (isUniversal) {
                universalWords.emplace_back(word);
            }
        }
        
        return universalWords;
    }
};


  /*
    my first appproach : 
           generate all subsets and  if subset legnth >= my checking words then for check and check it is a subset or not 
    ----------------------

 tc : O(2^n)
 sc :O(2^n) : 
 


 -----------------------

 Any String matching algo helps..?

s = "w a r r i o r"
     
t = "w r r"




if match move ahed both ptr:    t * (lengthogWords  everywordlength)
 if not only move s ptr and not t ptr : 
 10^4 * 10^4 *10 = 10^9 : wont't work may get TLE : 
  
  
  
  class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
     vector<string>ans;
     set<string>s;
      int n1 = words1.size();
      int n2 = words2.size();
    for(int i = 0 ; i < n2 ; i++) {
         string word2 = words2[i];
            for(int  j = 0 ; j < n1 ; j++) {
                string word1 = words1.at(j);
                int i1 = 0 , j1 = 0 ;
                //cout<<word1<<"  "<<word2<<"\n";
                // amazon e
                // facebook e 

                while( i1 < words2.size() && j1 < word1.size()) {  
                       cout<<word2[i1]<<word1[j1]<<" \n";
                       if(word2[i1] == word1[j1]) {
                            i1++;j1++;
                       } else{
                         j1++;
                       }
                }
              if(i1 == word2.size() ){
                s.insert(word1);
              }
          }
    }
   ans.assign(s.begin(), s.end());
return ans;

  
  
  */

//     }
// };