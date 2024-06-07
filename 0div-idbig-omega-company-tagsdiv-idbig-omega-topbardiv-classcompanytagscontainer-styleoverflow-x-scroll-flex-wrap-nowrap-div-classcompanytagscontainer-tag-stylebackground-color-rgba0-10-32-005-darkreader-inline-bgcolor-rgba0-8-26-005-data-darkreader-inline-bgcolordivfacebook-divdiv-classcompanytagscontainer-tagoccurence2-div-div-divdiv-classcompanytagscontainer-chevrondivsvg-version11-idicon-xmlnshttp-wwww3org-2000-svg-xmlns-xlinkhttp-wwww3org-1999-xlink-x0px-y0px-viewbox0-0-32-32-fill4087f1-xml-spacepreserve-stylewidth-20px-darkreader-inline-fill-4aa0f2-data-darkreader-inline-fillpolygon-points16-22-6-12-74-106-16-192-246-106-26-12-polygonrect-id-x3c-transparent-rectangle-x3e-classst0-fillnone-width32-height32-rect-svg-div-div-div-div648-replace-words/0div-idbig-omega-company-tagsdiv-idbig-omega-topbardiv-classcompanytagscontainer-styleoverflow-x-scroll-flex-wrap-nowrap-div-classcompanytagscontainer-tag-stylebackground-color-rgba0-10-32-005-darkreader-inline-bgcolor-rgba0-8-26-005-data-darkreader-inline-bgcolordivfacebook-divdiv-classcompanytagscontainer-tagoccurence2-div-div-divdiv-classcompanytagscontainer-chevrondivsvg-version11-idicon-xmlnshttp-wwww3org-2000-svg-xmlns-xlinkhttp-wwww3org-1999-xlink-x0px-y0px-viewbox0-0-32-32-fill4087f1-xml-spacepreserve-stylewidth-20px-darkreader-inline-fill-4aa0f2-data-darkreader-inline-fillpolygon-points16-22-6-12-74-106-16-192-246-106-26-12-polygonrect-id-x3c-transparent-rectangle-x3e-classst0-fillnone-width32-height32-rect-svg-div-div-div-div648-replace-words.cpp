class Solution {
public:
     string replaceWords(vector<string>& dict, string sentence) {
        
        unordered_set<string> rootDict;
        for(string s : dict)
            rootDict.insert(s);
        
        sentence.append(" ");
        string res;
        string word;
        
        for(char ch : sentence)
        {
            if(ch == ' ')
            {
                string temp = "";
                int flag = false;
                for(char chars : word)
                {
                    temp += chars;
                    if(rootDict.find(temp) != rootDict.end())
                    {
                        res += temp + " ";
                        flag = true;
                        break;
                    }
                }
                
                if(!flag)
                    res += word + " ";
                word = "";
            }
            else
                word += ch;
        }
        
        while(res[res.size() - 1] == ' ')
            res.pop_back();
        return res;
    }
};