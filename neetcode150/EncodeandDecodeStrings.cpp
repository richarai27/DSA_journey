class Solution {
  //I have used a string to encode the list of strings and then decode it back to the original list of strings, with TC O(n) and SC O(n) for both encoding and decoding where n is the total number of characters in all the strings in the list.
public:
    string encode(vector<string>& strs) {
        string encoded= "";
        for(string s: strs){
            encoded = encoded + to_string(s.length()) + '#' + s;
        }
        return encoded;
    }
    vector<string> decode(string s) {
        vector<string> decoded;
        int i= 0;
        while(i < s.size()){
            int j = i;
            while(s[j] != '#'){
                j++;
            }
            int len= stoi(s.substr(i,j-i)); i = j+1;
            decoded.push_back(s.substr(i,len));
            i += len;
        }
        return decoded;
    }
};
