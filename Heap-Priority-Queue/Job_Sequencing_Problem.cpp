/*
Job Sequencing Problem


Difficulty: Medium


You are given two arrays: deadline[], and profit[], which represent a set of
jobs, where each job is associated with a deadline, and a profit. Each job takes
1 unit of time to complete, and only one job can be scheduled at a time. You
will earn the profit associated with a job only if it is completed by its
deadline.

Your task is to return the following two values

Number of jobs selected for the maximum profit.
The total maximum profit by completing those jobs.

Examples :
Input: deadline[] = [4, 1, 1, 1], profit[] = [20, 10, 40, 30]
Output: [2, 60]
Explanation: Job1 and Job3 can be done with maximum profit of 60 (20 + 40).

Input: deadline[] = [2, 1, 2, 1, 1], profit[] = [100, 19, 27, 25, 15]
Output: [2, 127]
Explanation: Job1 and Job3 can be done with maximum profit of 127 (100 + 27).

Input: deadline[] = [3, 1, 2, 2], profit[] = [50, 10, 20, 30]
Output: [3, 100]
Explanation: Job1, Job3 and Job4 can be completed with a maximum profit of 100
(50 + 20 + 30).


Constraints:

deadline.size() ≤ 105
1 ≤ deadline[i] ≤ deadline.size()
1 ≤ profit[i] ≤ 500
profit.size() = deadline.size()

Time Complexity: O(n log n)
Auxiliary Space: O(n)
*/

class Solution {
public:
  vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
    // code here

    int n = deadline.size();

    vector<int> ans = {0, 0};
    vector<pair<int, int>> jobs;

    for (int i = 0; i < n; i++) {
      jobs.push_back({deadline[i], profit[i]});
    }

    sort(jobs.begin(), jobs.end());
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < jobs.size(); i++) {

      if (jobs[i].first > pq.size()) {
        pq.push(jobs[i].second);
      } else if (!pq.empty() && pq.top() < jobs[i].second) {
        pq.pop();
        pq.push(jobs[i].second);
      }
    }

    while (!pq.empty()) {
      ans[1] += pq.top();
      pq.pop();
      ans[0]++;
    }

    return ans;
  }
};
