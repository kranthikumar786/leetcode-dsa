
struct _dsu{
    vector <int> _parent;
    vector <int> _size;

    _dsu(int n){
        _parent.resize(n);
        for( int i = 0 ; i < n ; i++ ){
            _parent[i] = i;
        }

        _size.resize(n,1);
    }

    int _find(int n){
        if( _parent[n] == n )
            return n;
        return _parent[n] = _find(_parent[n]);
    }

    void _union(int a,int b){
        a = _find(a);
        b = _find(b);
        if( a == b )
            return;
        if( _size[a] < _size[b])
            swap(a,b);
        
        _parent[b] = a;
        _size[a] += _size[b];   
    }

    int maxComp(){
        return *max_element(_size.begin(), _size.end());
    }
};

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        _dsu dsu = _dsu(n);
        unordered_map <long long,int> mpp;

        for( int i = 0 ; i < n ; i++ ){
            if( mpp.count(nums[i]))
                continue;
            long long x = nums[i];
            long long sq = x*x;
            long long rt = sqrt(x);
            if( mpp.count(sq) > 0 ){
                dsu._union(i, mpp[sq]);
            }
            if( rt*rt == x && mpp.count(rt) > 0 ){
                dsu._union(i, mpp[rt]);
            }
            mpp[x] = i;
        }
        int ans = dsu.maxComp();
        return ans > 1 ? ans : -1;
    }
};