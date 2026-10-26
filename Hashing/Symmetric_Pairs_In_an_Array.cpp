/*

Symmetric pairs in an array

Given an array of pairs arr[], a pair (a, b) is said to be symmetric with (c, d)
if b = c and a = d. In other words, reversing the elements of one pair should
result in the other pair. The first element of each pair is guaranteed to be
distinct.

Examples:

Input: arr[] = [[10, 20], [30, 40], [20, 10], [50, 60]]
Output: [10, 20]
Explanation: [10, 20] and [20, 10] form a symmetric pair.

Input: arr[] = [[1, 2], [2, 3], [3, 4], [4, 1], [3, 2]]
Output: [2, 3]
Explanation: [2, 3] and [3, 2] are symmetric pairs.

Input: arr[] = [[5, 8], [7, 9], [8, 5], [9, 7], [6, 10]]
Output: [5, 8], [7, 9]
Explanation: [5, 8] & [8, 5] and [7, 9] & [9, 7] are symmetric pairs.


[Expected Approach] Using Hashing - O(n) Time and O(n) Space

*/
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {

  vector<vector<int>> nums = {
                            {1, 2}, 
                            {2, 3}, 
                            {3, 4}, 
                            {4, 1}, 
                            {3, 2}
                        };

    int n = nums.size();
    int m = 2;
    vector<vector<int>> res;

    unordered_map<int, int> mp;

    for(int i = 0; i < n; i++){

        int first = nums[i][0];
        int second = nums[i][1];

        if(mp.find(second) != mp.end() && mp[second] == first){
            res.push_back({second, first});
        }else{
            mp[first] = second;
        }
    }       

    for(auto p: res){
        cout << p[0] << " " << p[1] << endl;
    }

      return 0;
}