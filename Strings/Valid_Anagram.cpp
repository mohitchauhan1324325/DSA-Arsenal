/*
Valid Anagram

Easy

Given two strings s and t, return true if t is an anagram of s, and false
otherwise.


Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false


Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.


Follow up: What if the inputs contain Unicode characters? How would you adapt
your solution to such a case?


Topics
Hash Table, String, Sorting


Time Complexity: O(n)
Space Complexity: O(1)

*/

class Solution {
public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size())
      return false;

    int freq[26] = {};

    for (int i = 0; i < s.size(); i++) {
      freq[s[i] - 'a']++;
      freq[t[i] - 'a']--;
    }

    for (int count : freq) {
      if (count != 0)
        return false;
    }

    return true;
  }
};