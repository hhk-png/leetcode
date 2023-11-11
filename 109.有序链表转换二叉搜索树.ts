// https://leetcode.cn/problems/convert-sorted-list-to-binary-search-tree/description/

class TreeNode {
  val: number
  left: TreeNode | null
  right: TreeNode | null
  constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
    this.val = (val === undefined ? 0 : val)
    this.left = (left === undefined ? null : left)
    this.right = (right === undefined ? null : right)
  }
}

class ListNode {
  val: number
  next: ListNode | null
  constructor(val?: number, next?: ListNode | null) {
    this.val = (val === undefined ? 0 : val)
    this.next = (next === undefined ? null : next)
  }
}
const getLength = (node: ListNode | null): number => {
  let len: number = 0;
  while (node) {
    len++;
    node = node.next;
  }
  return len;
}

function sortedListToBST(head: ListNode | null): TreeNode | null {
  let globalHead = head;
  const buildTree = (left: number, right: number) => {
    if (left > right) {
      return null;
    }
    const mid = Math.floor((left + right) / 2);
    const root: TreeNode | null = new TreeNode();
    root.left = buildTree(left, mid - 1)!;
    root.val = globalHead?.val!;
    globalHead = globalHead?.next!;
    root.right = buildTree(mid + 1, right)!;
    return root;
  }

  const len = getLength(head);

  return buildTree(0, len - 1);
};

