class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        string ans;
        sort(arr.begin(), arr.end());
        do{
            string str;
            int h=arr[0]*10+arr[1], m= arr[2]*10+arr[3];
            if(h<24 && m<60){
                if(h<10) str.push_back('0');
                str+= to_string(h)+':';
                if(m<10) str.push_back('0');
                str+= to_string(m);
                if(str>ans) ans=str;
            }
        }while(next_permutation(arr.begin(), arr.end()));
        return ans;
    }
};