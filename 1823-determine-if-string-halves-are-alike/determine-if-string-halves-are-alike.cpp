class Solution {
public:
    bool halvesAreAlike(string s) {
        int n=s.size();
        string a,b;
        for(int i=0;i<n/2;i++){
            a+=s[i];
        }
        for(int i=(n/2);i<n;i++){
            b+=s[i];
        }
        int vovA=0;
        int vovB=0;
        for(int i=0;i<a.size();i++){
            if(a[i]=='a' || a[i]=='e' || a[i]=='i' || a[i]=='o' || a[i]=='u' || a[i]=='A' || a[i]=='E' || a[i]=='I' || a[i]=='O' || a[i]=='U'){
                vovA++;
            }
        }
        for(int i=0;i<b.size();i++){
            if(b[i]=='a' || b[i]=='e' || b[i]=='i' || b[i]=='o' || b[i]=='u' || b[i]=='A' ||b[i]=='E' || b[i]=='I' || b[i]=='O' || b[i]=='U'){
                vovB++;
            }
        }
        return vovA==vovB;
    }
};