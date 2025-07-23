public class Solution {

  public int maximumGain(String s, int x, int y) {
    int totalScore = 0;
    char[] characters = s.toCharArray();
    int length = characters.length;
    char firstChar = 'a';
    char secondChar = 'b';
    int firstScore = x;
    int secondScore = y;

    if (x < y) {
      firstChar = 'b';
      secondChar = 'a';
      firstScore = y;
      secondScore = x;
    }

    int countFirst = 0;
    int countSecond = 0;

    for (int i = 0; i < length; i++) {
      char currentChar = characters[i];

      if (currentChar == firstChar) {
        countFirst++;
      } else if (currentChar == secondChar) {
        if (countFirst > 0) {
          countFirst--;
          totalScore += firstScore;
        } else {
          countSecond++;
        }
      } else {
        totalScore += Math.min(countFirst, countSecond) * secondScore;
        countFirst = 0;
        countSecond = 0;
      }
    }
    totalScore += Math.min(countFirst, countSecond) * secondScore;
    return totalScore;
  }
}
