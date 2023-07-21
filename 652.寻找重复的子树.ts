// https://leetcode.cn/problems/find-duplicate-subtrees/submissions/

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


function findDuplicateSubtrees(root: TreeNode | null): Array<TreeNode | null> {
    const seen:Map<string, [TreeNode, number]> = new Map()
    const repeat:Set<TreeNode> = new Set()
    let idx:number = 0
    const dfs = (node: TreeNode): number => {
        if (!node) {
            return 0
        }
        const tuple:[number, number, number] = [node.val, dfs(node.left as TreeNode), dfs(node.right as TreeNode)]
        const hash:string = tuple.toString()
        if (seen.has(hash)) {
            const pair: [TreeNode, number] = seen.get(hash) as [TreeNode, number]
            repeat.add(pair[0])
            return pair[1]
        } else {
            seen.set(hash, [node, ++idx])
            return idx
        }
    }

    dfs(root as TreeNode)
    return [...repeat]
};