class Solution {
public:
    int countOdds(int low, int high) {
        if((high-low+1)%2==0) return (high-low+1)/2;
        else{
            int ans=ceil((high-low+1)/2.0);
            if(high%2==0 && low%2==0) ans--;
            return ans;
        }
    }
};