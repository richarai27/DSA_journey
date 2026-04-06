class Solution {
  // Time Complexity: O(n) where n is the length of string s2. We traverse s2 once with the right pointer, and the left pointer also moves at most n times in total.
    // Space Complexity: O(1) since the frequency arrays can hold at most 26 entries for lowercase English letters.
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()) return false;

        vector<int> s1count(26,0);
        vector<int> s2count(26,0);
        for(int i=0; i<s1.length(); i++){
            s1count[s1[i]-'a']++;
            s2count[s2[i]-'a']++;
        }
        int match=0;
        for (int i=0; i<26; i++){
            if(s1count[i]==s2count[i]) match++;
        }
        int l=0;
        for(int r=s1.length(); r<s2.length(); r++){
            if(match==26) return true;

            s2count[s2[r]-'a']++;
            if(s1count[s2[r]-'a']==s2count[s2[r]-'a']) match++;
            else if(s1count[s2[r]-'a']+1==s2count[s2[r]-'a']) match--;

            s2count[s2[l]-'a']--;
            if(s1count[s2[l]-'a']==s2count[s2[l]-'a']) match++;
            else if(s1count[s2[l]-'a']==s2count[s2[l]-'a']+1) match--;

            l++;
        }
        return match==26;
    }
};