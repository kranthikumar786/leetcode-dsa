class Solution {
    public String lexGreaterPermutation(String s, String target) {
        int n = s.length();
        int[] freq = new int[26];

        for(char c : s.toCharArray())
            freq[c - 'a']++;

        StringBuilder ans = new StringBuilder();

        for(int i = 0; i < n; i++) {
            int x = target.charAt(i) - 'a';

            if(freq[x] > 0) {
                ans.append(target.charAt(i));
                freq[x]--;
                continue;
            }

            for(int c = x + 1; c < 26; c++) {
                if(freq[c] > 0) {
                    ans.append((char)('a' + c));
                    freq[c]--;

                    for(int j = 0; j < 26; j++)
                        for(int k = 0; k < freq[j]; k++)
                            ans.append((char)('a' + j));

                    return ans.toString();
                }
            }

            while(ans.length() > 0) {
                int prev = ans.charAt(ans.length() - 1) - 'a';
                ans.deleteCharAt(ans.length() - 1);
                freq[prev]++;

                int y = target.charAt(ans.length()) - 'a';

                for(int c = y + 1; c < 26; c++) {
                    if(freq[c] > 0) {
                        ans.append((char)('a' + c));
                        freq[c]--;

                        for(int j = 0; j < 26; j++)
                            for(int k = 0; k < freq[j]; k++)
                                ans.append((char)('a' + j));

                        return ans.toString();
                    }
                }
            }

            return "";
        }

        while(ans.length() > 0) {
            int prev = ans.charAt(ans.length() - 1) - 'a';
            ans.deleteCharAt(ans.length() - 1);
            freq[prev]++;

            int y = target.charAt(ans.length()) - 'a';

            for(int c = y + 1; c < 26; c++) {
                if(freq[c] > 0) {
                    ans.append((char)('a' + c));
                    freq[c]--;

                    for(int j = 0; j < 26; j++)
                        for(int k = 0; k < freq[j]; k++)
                            ans.append((char)('a' + j));

                    return ans.toString();
                }
            }
        }

        return "";
    }
}