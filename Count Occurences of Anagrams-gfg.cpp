class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	    int n=txt.length();
        int k=pat.length();
        int ans=0;
        vector<int>hpat(26,0);
        for(int i=0;i<k;i++){
            hpat[pat[i]-'a']++;
        }
        vector<int>htxt(26,0);
        int i=0,j=0;
        while(j<n){
            htxt[txt[j]-'a']++;
            if(j-i+1==k){
                if(htxt==hpat) ans++;
                
                
                htxt[txt[i]-'a']--;
                i++;
            }
            j++;
        }
        return ans;
	}

};
