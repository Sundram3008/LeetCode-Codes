//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    string rearrange (string s, int N)
    {
        vector<int> c(26,0), v(26,0);
        int csum=0, vsum=0;
        for(int i=0; i<N; i++){
            if(s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o' && s[i]!='u'){ 
                c[s[i]-'a']++;
                csum++;
            }
            else{ 
                v[s[i]-'a']++;
                vsum++;
            }
        }
        if(csum> vsum){
            for(int i=0; i<N; i++){
                if(i%2==0){
                    bool f=true;
                    for(int j=0; j<26; j++){
                        if(c[j]>0){
                            s[i]= char(j+'a');
                            c[j]--;
                            f=false;
                            break;
                        }
                    }
                    if(f) return "-1";
                }else{
                    bool f= true;
                    for(int j=0; j<26; j++){
                        if(v[j]>0){
                            s[i]= char(j+'a');
                            v[j]--;
                            f=false;
                            break;
                        }
                    }
                    if(f) return "-1";
                }
            }
        }
        else if(vsum>csum){
            for(int i=0; i<N; i++){
                if(i%2==0){
                    bool f= true;
                    for(int j=0; j<26; j++){
                        if(v[j]>0){
                            s[i]= char(j+'a');
                            v[j]--;
                            f=false;
                            break;
                        }
                    }
                    if(f) return "-1";
                }else{
                    bool f=true;
                    for(int j=0; j<26; j++){
                        if(c[j]>0){
                            s[i]= char(j+'a');
                            c[j]--;
                            f=false;
                            break;
                        }
                    }
                    if(f) return "-1";
                }
            }
        }else{
            char ch;
            for(int i=0; i<26; i++){
                if(v[i]>0){
                    ch= 'v';
                    break;
                }if(c[i]>0){
                    ch='c';
                }
            }
            if(ch=='c'){
                for(int i=0; i<N; i++){
                if(i%2==0){
                    bool f=true;
                    for(int j=0; j<26; j++){
                        if(c[j]>0){
                            s[i]= char(j+'a');
                            c[j]--;
                            f=false;
                            break;
                        }
                    }
                    if(f) return "-1";
                }else{
                    bool f= true;
                    for(int j=0; j<26; j++){
                        if(v[j]>0){
                            s[i]= char(j+'a');
                            v[j]--;
                            f=false;
                            break;
                        }
                    }
                    if(f) return "-1";
                }
                }
            }else{
                for(int i=0; i<N; i++){
                if(i%2==0){
                    bool f= true;
                    for(int j=0; j<26; j++){
                        if(v[j]>0){
                            s[i]= char(j+'a');
                            v[j]--;
                            f=false;
                            break;
                        }
                    }
                    if(f) return "-1";
                }else{
                    bool f=true;
                    for(int j=0; j<26; j++){
                        if(c[j]>0){
                            s[i]= char(j+'a');
                            c[j]--;
                            f=false;
                            break;
                        }
                    }
                    if(f) return "-1";
                }
            }
            }
        }
        return s;
    }
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		Solution ob;
		cout << ob.rearrange (s, n) << endl;
	}
}
// Contributed By: Pranay Bansal

// } Driver Code Ends