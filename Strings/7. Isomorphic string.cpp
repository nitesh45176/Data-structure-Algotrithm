

// Leetcode 205 : Isomorphic string
// Approach : Map
// TC, SC:   O(n) , O(1)


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, char> map;
        unordered_map<char, char> reverseMap;

        for (int i = 0; i < s.length(); i++) {
            char original = s[i];
            char replacement = t[i];

            if (!map.count(original)) {
                if (!reverseMap.count(replacement)) {
                    map[original] = replacement;
                    reverseMap[replacement] = original;
                } else {
                    return false;
                }
            } else {
                if (map[original] != replacement) {
                    return false;
                }
            }
        }
    
    return true;
}
};
