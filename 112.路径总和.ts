// https://leetcode.cn/problems/path-sum/submissions/

function hasPathSum(root: TreeNode | null, targetSum: number): boolean {
  const dfs = (node: TreeNode, sum: number): boolean => {
      // 不存在根节点，返回false
      if (!node) {
          return false
      }
      const currSum = sum + node.val
      if (!node.left && !node.right) {
          return targetSum === currSum;
      }
      return dfs(node.left, currSum) ||
              dfs(node.right, currSum)
  }
  return dfs(root, 0)
};

