class Solution {
    public int characterReplacement(String s, int k) {
        int ans = 0;
        int n = s.length();
        int l = 0, maxFreq = 0;
        int fre[] = new int[26];

        for (int r = 0; r < n; r++) {
            int index = s.charAt(r) - 'A';
            fre[index]++;
            maxFreq = Math.max(maxFreq, fre[index]);

            while ((r - l + 1) - maxFreq > k) {   
                fre[s.charAt(l) - 'A']--;
                l++;
            }

            ans = Math.max(ans, r - l + 1);
        }
        return ans;
    }
}

/**
 for(int i = 0 ; i < n ;i++) {
           int fre[] = new int[26];
           int maxFreq = 0;
           for(int j = i ; j < n ;j++) {
                 int idex = s.charAt(j)-'A';
                 fre[idex]++;
                maxFreq = Math.max(maxFreq,fre[idex]);
                int windowLen = j-i+1;
                int replacements =windowLen-maxFreq;
                if(replacements <= k){
                   ans = Math.max(ans,windowLen); 
                }
           }
      }
 */