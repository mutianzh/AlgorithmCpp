class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int curRes = 0;
        string resStr = "";
        for (int i=0; i < n; i++){
            // odd
            int l = i;
            int r = i;
            while (l >=0 && r < n && s[l] == s[r]){
                if (r - l + 1 > curRes) {
                    curRes = r - l + 1;
                    resStr = s.substr(l, r - l + 1);
                }
                l--;
                r++;
            }
            // even
            l = i;
            r = i+1;
            while (l >=0 && r < n && s[l] == s[r]){
                if (r - l + 1 > curRes) {
                    curRes = r - l + 1;
                    resStr = s.substr(l, r - l + 1);
                }
                l--;
                r++;
            }
        }
        return resStr;
    }
};
