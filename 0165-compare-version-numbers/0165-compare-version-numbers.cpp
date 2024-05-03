class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0,j=0;
        while(i<version1.length() || j<version2.length()){
            int a=0,b=0;
            while(i<version1.length() && version1[i]!='.'){
                a*=10;
                a+= version1[i]-'0';
                i++;
            }
            while(j<version2.length() && version2[j]!='.'){
                b*=10;
                b+= version2[j]-'0';
                j++;
            }
            
            if(a>b) return 1;
            else if(a<b) return -1;
            if(i<version1.length()) i++;
            if(j<version2.length()) j++;
        }
                                            
        return 0;
    }
};