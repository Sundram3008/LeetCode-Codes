class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n= nums.size(), sum=0;
        vector<int> psum(n+1, 0);
        for(int i=0; i<n; i++){
            sum+= nums[i];
            psum[i+1]= sum;
        }
        int ans=0, cnt=0, o=0, s=0;
        queue<int> q;
        q.push(-1);
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                cnt++;
                q.push(i);
            }
            if(cnt<=k){
                
              //  if(ans<=psum[i]-psum[q.front()+1]+cnt){
                    ans= max(ans, psum[i+1]-psum[q.front()+1]+cnt);
                //    o=i, s= q.front();
                //}
            }else{
                cnt--;
                q.pop();
                //ans= max(ans, psum[i]-psum[q.front()+1]+cnt);
            }
        }
        //cout<<o<<" : "<<s<<endl;
        return ans;
    }
};