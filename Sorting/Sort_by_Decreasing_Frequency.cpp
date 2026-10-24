/*
Sort by Decreasing Frequency

Difficulty: Medium

Given an array of integers arr[], sort the array according to frequency of
elements, i.e. elements that have higher frequency comes first. If the
frequencies of two elements are the same, the smaller number comes first.


Examples :

Input: arr[] = [5, 5, 4, 6, 4]
Output: [4, 4, 5, 5, 6]
Explanation: The highest frequency here is 2. Both 5 and 4 have that frequency.
Now since the frequencies are the same the smaller element comes first. So 4 4
comes first then comes 5 5. Finally comes 6. The output is 4 4 5 5 6. 

Input:
arr[] = [9, 9, 9, 2, 5] Output: [9, 9, 9, 2, 5] Explanation: The highest
frequency here is 3. Element 9 has the highest frequency So 9 9 9 comes first.
Now both 2 and 5 have the same frequency. So we print smaller elements first.
The output is 9 9 9 2 5. Constraints:


1 ≤ arr.size(), arr[i] ≤ 105


Time Complexity: O(n log n)
Auxiliary Space: O(n)


Topics:
Arrays, Hash, Sorting, STL, Map, Java-Collections
*/

class Solution {
public:
    vector<int> sortByFreq(vector<int>& arr) {

        unordered_map<int, int> um;

        // Count frequency
        for (int x : arr) {
            um[x]++;
        }

        // Store {element, frequency}
        vector<pair<int, int>> v;

        for (auto x : um) {
            v.push_back(x);
        }

        // Sort
        sort(v.begin(), v.end(), [](auto a, auto b) {

            if (a.second != b.second) {
                return a.second > b.second;
            }

            return a.first < b.first;
        });

        // Build answer
        vector<int> ans;

        for (auto x : v) {

            for (int i = 0; i < x.second; i++) {
                ans.push_back(x.first);
            }
        }

        return ans;
    }
};