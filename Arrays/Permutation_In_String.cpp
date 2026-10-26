/*

Permutation in String

Medium

Given two strings s1 and s2, return true if s2 contains a permutation of s1, or
false otherwise. In other words, return true if one of s1's permutations is the
substring of s2.


Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false


Constraints:

1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.


Topics
Principal, Hash Table, Two Pointers, String, Sliding Window


Time: O(m)
Space: O(1)

*/

class Solution {
public:
  bool checkInclusion(string s1, string s2) {

    int n = s1.length();
    int m = s2.length();

    if (n > m)
      return false;

    vector<int> freq(26, 0);

    for (char c : s1) {
      freq[c - 'a']++;
    }

    int left = 0;

    for (int right = 0; right < m; right++) {

      freq[s2[right] - 'a']--;

      if (right - left + 1 > n) {
        freq[s2[left] - 'a']++;
        left++;
      }

      if (right - left + 1 == n) {
        bool match = true;

        for (int i = 0; i < 26; i++) {
          if (freq[i] != 0) {
            match = false;
            break;
          }
        }

        if (match)
          return true;
      }
    }

    return false;
  }
};