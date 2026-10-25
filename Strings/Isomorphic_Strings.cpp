/*
Isomorphic Strings

Easy

Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get
t.

All occurrences of a character must be replaced with another character while
preserving the order of characters. No two characters may map to the same
character, but a character may map to itself.


Example 1:
Input: s = "egg", t = "add"
Output: true
Explanation:
The strings s and t can be made identical by:
Mapping 'e' to 'a'.
Mapping 'g' to 'd'.

Example 2:
Input: s = "f11", t = "b23"
Output: false
Explanation:
The strings s and t can not be made identical as '1' needs to be mapped to both
'2' and '3'.

Example 3:
Input: s = "paper", t = "title"
Output: true


Constraints:

1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character.


Topics
Hash Table, String

Time Complexity: O(n)
Space Complexity: O(1)

*/

class Solution {
public:
  bool isIsomorphic(string s, string t) {

    unordered_map<char, char> mp1;
    unordered_map<char, char> mp2;

    for (int i = 0; i < s.length(); i++) {

      char a = s[i];
      char b = t[i];

      if (mp1.count(a) && mp1[a] != b) {
        return false;
      }
      if (mp2.count(b) && mp2[b] != a) {
        return false;
      }

      mp1[a] = b;
      mp2[b] = a;
    }

    return true;
  }
};