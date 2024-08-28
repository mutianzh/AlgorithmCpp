class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {return false;}
        unordered_map<char, int> hash;
        for (int i=0; i < s.length(); i++){
            char item = s[i];
            if (!hash.count(item)){
                hash[item] = 1;
            } else {
                hash[item] += 1;
            }
        }

        for (int i = 0; i < t.length(); i++){
            char item = t[i];
            if (!hash.count(item)){
                return false;
            }
            hash[item] -= 1;
            if (hash[item] < 0){return false;}
        }
        return true;

    }
};
