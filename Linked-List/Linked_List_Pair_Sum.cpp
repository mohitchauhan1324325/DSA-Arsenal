/*

Linked List Pair Sum

Given a linked list, and a number, check if their exist two numbers whose sum is
equal to given number. If there exist two numbers, print them. If there are
multiple answer, print any of them.

Examples:

Input : 1 -> 2 -> 3 -> 4 -> 5 -> NULL
        sum = 3
Output : Pair is (1, 2)

Input : 10 -> 12 -> 31 -> 42 -> 53 -> NULL
        sum = 15
Output : NO PAIR EXIST

*/

bool check_pair_sum(struct Node *head, int sum) {

  unordered_set<int> s;
  struct Node *p = head;

  while (p != NULL) {
    int curr = p->data;
    if (s.find(sum - curr) != s.end()) {
      cout << curr << " " << sum - curr;
      return true;
    }
    s.insert(p->data);
    p = p->next;

  }

  return false;
}