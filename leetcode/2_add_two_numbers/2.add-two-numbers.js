/**
 * [2] Add Two Numbers

https://leetcode.com/problems/add-two-numbers/description/

* algorithms
* Medium (32.05%)
* Total Accepted:    1.1M
* Total Submissions: 3.3M
* Testcase Example:  '[2,4,3]\n[5,6,4]'

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:


Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807
*/
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
	let out = null;
	let v1 = 0;
	let v2 = 0;
	let carry = 0;
	let sum = 0;
	let cur = out;
	while (l1 || l2) {
		v1 = l1.value;
		v2 = l2.value;
		l1 = l1.next || null;
		l2 = l2.next || null;
		sum = v1 + v2 + carry;
		carry = parseInt(sum / 10);
		let n = new ListNode(sum % 10);
		if (cur) cur.next = n;
		else {
			cur = n;
			out = n;
		}
	}
	if (carry > 0) {
		let n = new ListNode(carry%10);
		cur.next = n;
	}
	return out;
};
