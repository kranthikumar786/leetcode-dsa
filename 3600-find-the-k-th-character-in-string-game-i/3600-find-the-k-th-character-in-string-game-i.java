class Solution {
    public char kthCharacter(int k) {
        StringBuilder str = new StringBuilder("a");
        while (str.length() < k) {
            int len = str.length();
            for (int i = 0; i < len; i++) {
                char nextChar = (char)('a' + ((str.charAt(i) - 'a' + 1) % 26));
                str.append(nextChar);
            }
        }
        return str.charAt(k - 1);
    }
}
