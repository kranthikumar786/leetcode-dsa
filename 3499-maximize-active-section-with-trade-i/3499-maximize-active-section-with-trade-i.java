class Solution {
    public int maxActiveSectionsAfterTrade(String s) {
        int cnt1= 0;
        for(char ch : s.toCharArray()){
            if(ch == '1') cnt1++;
        }

        int maxGain = 0;
        int prevZeros = 0;
        int n = s.length();
        int i=0;
        while(i<n){
            if(s.charAt(i) == '0'){
                int cnt0 = 0;
                while(i<n && s.charAt(i) == '0'){
                    cnt0++;
                    i++;
                }
                prevZeros = cnt0;
            } else {
                while(i<n && s.charAt(i) == '1'){
                    i++;
                }
                int nextZeros = 0;
                while(i<n && s.charAt(i) == '0'){
                    nextZeros++;
                    i++;
                }
                if(prevZeros  > 0 && nextZeros > 0){
                    maxGain = Math.max(maxGain, prevZeros + nextZeros);
                }
                prevZeros = nextZeros;
            }
        }
        return maxGain+cnt1;
    }
}