class Solution {
public:
    int minLength(string s) {
        bool flag = false ;
        while(1){
            string t ;
            flag = false ;
            for(int i = 0; i < s.size(); i++){
                if(i < s.size()-1 && (s.substr(i, 2) == "AB" || s.substr(i, 2) == "CD")){
                    i++ ;
                    flag = true ;
                    continue ;
                }
                else{
                    t.push_back(s[i]) ;    
                }
                    
            }
            s = t ;
            if(flag == false)
                break ;
        }
        return s.size() ;
    }
};