class Solution {
public:
    bool isPalindrome(string s) {
		transform(s.begin(),s.end(),s.begin(),::tolower);
        int l=0, r=s.size()-1;
        while(l < r){
            if(!isalpha(s[l]) && !isdigit(s[l])) { l++; continue;}
            if(!isalpha(s[r]) && !isdigit(s[r])) { r--; continue;}
            if(s[r] != s[l]) {  
				return false; 
			}
            else{ r--; l++;}
        }
        return true;
    }
};
