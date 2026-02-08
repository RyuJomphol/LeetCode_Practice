#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestNiceSubstring(string s) {
        if (s.length() < 2) return "";
        
        // Use a set for quick lookup of characters present in the current string
        unordered_set<char> charSet(s.begin(), s.end());
        
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            
            // Check if both upper and lower versions exist
            if (charSet.count(tolower(c)) && charSet.count(toupper(c))) {
                continue;
            }
            
            // If the character is 'bad', split the string into two halves
            // excluding the current character s[i]
            string left = longestNiceSubstring(s.substr(0, i));
            string right = longestNiceSubstring(s.substr(i + 1));
            
            // Return the longer of the two. If tied, return 'left' (earliest occurrence)
            return (left.length() >= right.length()) ? left : right;
        }
        
        // If the loop completes, every character has a pair, so the string is nice
        return s;
    }
};