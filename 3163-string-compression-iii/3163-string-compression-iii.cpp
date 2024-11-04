class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int cnt,ind=0;
        while(ind < word.size()){
            cnt = 0;
            char currChar = word[ind];
            while(ind < word.size() && currChar == word[ind] && cnt < 9){
                cnt++;
                ind++;
            }
            comp += ((char)cnt+'0');
            comp += currChar;
        }
        return comp;
    }
};