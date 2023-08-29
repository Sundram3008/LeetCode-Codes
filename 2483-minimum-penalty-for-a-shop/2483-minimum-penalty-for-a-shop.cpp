class Solution {
public:
    int bestClosingTime(string customers) {
        int ans=0, maxProf=0, currProf=0;
        for(int i=0; i<customers.size(); i++){
            if(customers[i]=='Y') currProf++;
            else currProf--;
            if(maxProf<currProf){
                maxProf=currProf;
                ans=i+1;
            }
        }
        return ans;
    }
};