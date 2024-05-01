class Solution {
public:
    string reversePrefix(string word, char ch) {
    
        int index = -1;
        for(int i = 0 ; word[i] ; i++) {
               if(word[i] == ch) {
                     index = i;
                    break;
               }
        }
        
       if(index == -1) {
            return word;
       } 
            int left  = 0 , right = index;
        while (left <= right) {
               swap(word[left++] , word[right--]);
        }
        return word;
    }
};