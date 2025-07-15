class Solution {
    public boolean isValid(String word) {
        if (word.length() < 3) return false;
        int vowels = 0, consonants = 0;
        for (char ch : word.toCharArray()) {
            if (!Character.isLetterOrDigit(ch)) return false;

            if (Character.isLetter(ch)) {
                char lower = Character.toLowerCase(ch);
                if (isVowel(lower)) {
                    vowels++;
                } else {
                    consonants++;
                }
            }
        }
        return vowels > 0 && consonants > 0;
    }
    private boolean isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
}
