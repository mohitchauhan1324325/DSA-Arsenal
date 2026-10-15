/*
Maximum Meetings in One Room


Given n meetings in the form of start[] and end[], where start[i] is the start
time of ith meeting and end[i] is the end time of ith meeting. The task is to
find the maximum number of meetings which can be held in a single room. The
meeting room can have only one meeting at a particular time.

Note: The start time of one chosen meeting can’t be equal to the end time of any
other chosen meeting.

Examples:
Input: start[] = {1, 3, 0, 5, 8, 5}, end[] = {2, 4, 6, 7, 9, 9}

Output: 4
Explanation: We can attend at most 4 meetings: 1st meeting from (1 to 2), then
2nd meeting from (3 to 4), then 4th meeting from (5 to 7), and 5th meeting from
(8 to 9).

Input: start[] = {10, 12, 20}, end[] = {20, 25, 30}

Output: 1
Explanation: We can attend at most one meeting in a single meeting room.


1 <= N <= 10^5
0 <= start[i] < end[i] <= 10^5


Time complexity: O(N log N)
Auxiliary space: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

struct meeting {
  int startTime, endTime;
};

bool compare(meeting m1, meeting m2) { return m1.endTime < m2.endTime; }

int maxMeetings(vector<int> &start, vector<int> &end) {

  int res = 0;
  int n = start.size();

  vector<meeting> meets(n);

  for (int i = 0; i < n; i++) {
    meets[i].startTime = start[i];
    meets[i].endTime = end[i];
  }

  sort(meets.begin(), meets.end(), compare);

  int curr = -1;
  for (int i = 0; i < n; i++) {
    if (curr < meets[i].startTime) {
      curr = meets[i].endTime;
      res += 1;
    }
  }

  return res;
}

int main() {
  vector<int> start = {1, 3, 0, 5, 8, 5};
  vector<int> end = {2, 4, 6, 7, 9, 9};

  cout << maxMeetings(start, end);
  return 0;
}
