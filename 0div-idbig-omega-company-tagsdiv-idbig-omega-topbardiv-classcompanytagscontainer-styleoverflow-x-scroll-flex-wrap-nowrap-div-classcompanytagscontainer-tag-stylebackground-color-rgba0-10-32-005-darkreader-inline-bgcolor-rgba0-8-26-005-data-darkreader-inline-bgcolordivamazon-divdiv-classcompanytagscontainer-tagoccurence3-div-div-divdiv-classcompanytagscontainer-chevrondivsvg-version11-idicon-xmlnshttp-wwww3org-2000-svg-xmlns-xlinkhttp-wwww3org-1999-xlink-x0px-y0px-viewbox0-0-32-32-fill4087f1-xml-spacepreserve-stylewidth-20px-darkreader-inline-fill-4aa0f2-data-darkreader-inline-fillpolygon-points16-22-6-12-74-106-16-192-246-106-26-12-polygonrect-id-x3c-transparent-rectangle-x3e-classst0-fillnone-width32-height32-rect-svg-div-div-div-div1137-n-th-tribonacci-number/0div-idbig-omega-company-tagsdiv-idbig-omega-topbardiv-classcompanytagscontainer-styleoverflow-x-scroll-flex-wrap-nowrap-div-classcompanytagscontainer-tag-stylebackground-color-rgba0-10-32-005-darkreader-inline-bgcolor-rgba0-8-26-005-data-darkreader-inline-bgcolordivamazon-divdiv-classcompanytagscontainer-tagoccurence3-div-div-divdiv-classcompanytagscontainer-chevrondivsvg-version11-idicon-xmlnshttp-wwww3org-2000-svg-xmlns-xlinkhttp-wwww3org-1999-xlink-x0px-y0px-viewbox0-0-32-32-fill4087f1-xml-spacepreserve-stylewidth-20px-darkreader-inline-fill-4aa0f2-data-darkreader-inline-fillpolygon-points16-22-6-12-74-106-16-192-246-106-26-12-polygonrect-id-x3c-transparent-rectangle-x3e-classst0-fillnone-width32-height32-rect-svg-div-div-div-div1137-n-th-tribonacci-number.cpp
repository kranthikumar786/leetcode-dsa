class Solution {
public:
    int tribonacci(int n, int n0 = 0, int n1 = 1, int n2 = 1) {
  while (n-- > 2) {
    int n3 = n2 + n1 + n0;
    n0 = n1, n1 = n2, n2 = n3;
  }
  return n == -1 ? 0 : n2;
}
};