class Solution {
public:
    int bulbSwitch(int n) {
        int ans=1, cnt=0, x=1;
        while(cnt<n){
            x+=2;
            cnt+=x;
            ans++;
        }
        return ans-1;
    }
};
// sequence - 
// 0
// 1
// 1
// 1
// 2
// 2
// 2
// 2
// 2
// 3
// 3
// 3
// 3
// 3
// 3
// 3
// 4
// 4