class Solution {
public:
    unordered_map<int,bool>me;
    unordered_set<string>Myset;
    bool partiotion(string s, int pos){
       
        if(pos == s.size()) {return 1;}
        
        if(me.count(pos)) {return me[pos];}
        string t = "";
        for(int i = pos ; i < s.size() ;i++) {
            if(Myset.count(s.substr(pos, i - pos + 1)) && partiotion(s,i+1)) {
                return me[pos] = true;
            }
           
        }
        return me[pos] = false; 
    }
    bool wordBreak(string s, vector<string>& wordDict) {
     
        
        for(auto str : wordDict) {
            Myset.insert(str);
        }
      
        return partiotion(s,0);
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        /*
     
     s = "applepenapple" , wordDict = ["apple","pen"]:


     
      compare chay by chat s and  one string of wordDict : 

  for(int  i = 0 ;i < s.size() ;) {
     string word = wrodDict[everytime start with];
for(int i = 0 ;i < word.size() ; i++) {

       s[i] != word[j] 
          i = previousI;
          break;
}
 if not break ;
 i+= word.size()   
  }
     */   
    }
};