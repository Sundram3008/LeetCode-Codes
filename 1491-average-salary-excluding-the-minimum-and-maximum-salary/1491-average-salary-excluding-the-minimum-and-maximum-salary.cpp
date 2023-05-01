class Solution {
public:
    double average(vector<int>& salary) {
        int mi= *min_element(salary.begin(), salary.end());
        int ma= *max_element(salary.begin(), salary.end());
        long sum=0;
        for(auto i: salary) sum+= i;
        sum= sum-mi-ma;
        return (sum*1.00000/(salary.size()-2));
    }
};