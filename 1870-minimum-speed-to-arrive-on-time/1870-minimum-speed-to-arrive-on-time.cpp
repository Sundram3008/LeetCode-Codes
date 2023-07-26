class Solution {
public:
    bool isPossible(vector<int> &dist, double hour, int speed){
        double timeTaken=0;
        for(int i=0; i<dist.size()-1; i++){
            timeTaken+= ceil(1.0* dist[i]/speed);
        }
        timeTaken+= (1.0 *dist.back()/speed);
        return (hour>=timeTaken);
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int lowSpeed=1, highSpeed = 10000000, ans=INT_MAX;
        while(lowSpeed<=highSpeed){
            int currSpeed= lowSpeed+((highSpeed-lowSpeed)/2);
            if(isPossible(dist, hour, currSpeed)){
                ans= currSpeed;
                highSpeed= currSpeed-1;
            }else{
                lowSpeed= currSpeed+1;
            }
        }
        return (ans==INT_MAX)? -1: ans;
    }
};