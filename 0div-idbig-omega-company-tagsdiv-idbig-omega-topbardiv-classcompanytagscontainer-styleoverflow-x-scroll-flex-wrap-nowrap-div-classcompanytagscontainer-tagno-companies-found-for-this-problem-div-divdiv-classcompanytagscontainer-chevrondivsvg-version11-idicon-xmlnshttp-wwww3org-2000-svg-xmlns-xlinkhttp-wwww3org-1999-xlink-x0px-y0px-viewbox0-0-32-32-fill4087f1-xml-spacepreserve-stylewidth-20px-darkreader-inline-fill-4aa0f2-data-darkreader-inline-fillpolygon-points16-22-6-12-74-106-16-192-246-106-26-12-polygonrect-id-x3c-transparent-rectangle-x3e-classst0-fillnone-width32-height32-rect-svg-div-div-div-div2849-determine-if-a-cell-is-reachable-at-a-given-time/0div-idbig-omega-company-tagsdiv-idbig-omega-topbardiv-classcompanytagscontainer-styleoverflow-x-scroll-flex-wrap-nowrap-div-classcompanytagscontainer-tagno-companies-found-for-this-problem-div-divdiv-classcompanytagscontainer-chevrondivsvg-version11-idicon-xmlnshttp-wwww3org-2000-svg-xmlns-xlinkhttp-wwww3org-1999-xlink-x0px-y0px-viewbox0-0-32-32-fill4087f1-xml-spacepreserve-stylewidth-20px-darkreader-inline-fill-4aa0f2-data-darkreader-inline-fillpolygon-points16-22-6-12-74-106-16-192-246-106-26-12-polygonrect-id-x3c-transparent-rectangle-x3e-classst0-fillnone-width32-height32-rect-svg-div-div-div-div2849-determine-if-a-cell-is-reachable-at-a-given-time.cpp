class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
  
         int width = abs(sx-fx);
         int height = abs(sy-fy);
        if (width == 0 && height == 0 && t == 1) {return 0;}
        return t >= max(width, height);
    }
};