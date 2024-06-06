class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
  sort(begin(hand), end(hand));
  vector<pair<int, int>> groups(hand.size() / W);
  for (auto i = 0; i < hand.size(); ++i) {
    for (auto j = 0; j <= groups.size(); ++j) {
      if (j == groups.size()) return false;
      if (groups[j].second == 0 || (groups[j].second < W && groups[j].first == hand[i] - 1)) {
        groups[j].first = hand[i], ++groups[j].second;
        break;
      }
    }
  }
  return true;
}
};