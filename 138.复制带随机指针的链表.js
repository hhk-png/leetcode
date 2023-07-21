function Node(val, next, random) {
  this.val = val;
  this.next = next;
  this.random = random;
}


// 1

let visitedHash = new Map();

var copyRandomList = function (head) {
  if (!head) return head;

  if (visitedHash.has(head)) return visitedHash.get(head);

  let node = new Node(head.val, null, null);

  visitedHash.set(head, node);

  node.next = copyRandomList(head.next);
  node.random = copyRandomList(head.random);

  return node;
};


// 2

var getClonedNode = function (node) {
  if (node !== null) {
    if (visitedHash.has(node)) {
      // random指向的结点已经创建完成，在正在创建的结点的后面，
      return visitedHash.get(node);
    } else {
      // 当node.random在正在创建的node前面，
      //  或者创建next的时候，走这一条线
      visitedHash.set(node, new Node(node.val, null, null)); // good solution
      return visitedHash.get(node);
    }
  }

  return null;
};
var copyRandomList2 = function (head) {
  if (!head) return head;

  let oldNode = head;

  // 第一个结点的处理
  newNode = new Node(oldNode.val, null, null);
  visitedHash.set(oldNode, newNode);

  while (oldNode) {
    // 第一次执行的时候，执行的是head结点的random和next的复制
    // old 复制-> new
    newNode.random = getClonedNode(oldNode.random);
    newNode.next = getClonedNode(oldNode.next);

    oldNode = oldNode.next;
    newNode = newNode.next;
  }

  // good solution
  return visitedHash.get(head);
};

/*
public Node copyRandomList(Node head) {
  HashMap<Node, Node> copyMap = new HashMap<>();

  // copy val
  Node cur = head;
  while (cur != null) {
    Node copy = new Node(cur.val);
    copyMap.put(cur, copy);
    cur = cur.next;
  }

  // copy next and random
  cur = head;
  while (cur != null) {
    Node copy = copyMap.get(cur);
    copy.next = copyMap.get(cur.next);
    copy.random = copyMap.get(cur.random);

    cur = cur.next;
  }

  return copyMap.getOrDefault(head, null);
}
*/
