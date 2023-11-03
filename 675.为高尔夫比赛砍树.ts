// https://leetcode.cn/problems/cut-off-trees-for-golf-event/solutions/1510776/wei-gao-er-fu-bi-sai-kan-shu-by-leetcode-rlrc/

function cutOffTree(forest: number[][]): number {
    const dirs: number[][] = [[-1, 0], [1, 0], [0, -1], [0, 1]]
    const row: number = forest.length
    const col: number = forest[0].length
    const bfs = (sx: number, sy: number, tx: number, ty: number) => {
        if (sx === tx && sy === ty) {
            return 0
        }
        
        let step: number = 0
        const queue: number[][] = []
        queue.push([sx, sy])
        const visited: boolean[][] = new Array(row).fill(0).map(() => new Array(col).fill(false))
        visited[sx][sy] = true
        while (queue.length) {
            step++
            const size = queue.length
            for (let i = 0; i < size; i++) {
                const cell = queue.shift()
                const cx = cell![0]
                const cy = cell![1]
                for (const dir of dirs) {
                    const nx = cx + dir[0]
                    const ny = cy + dir[1]
                    if (nx >= 0 && nx < row && ny >= 0 && ny < col) {
                        if (!visited[nx][ny] && forest[nx][ny] > 0) {
                            if (nx === tx && ny === ty) {
                                return step
                            }
                            queue.push([nx, ny])
                            visited[nx][ny] = true
                        }
                    }
                }
            }
        }
        return -1
    }
    const trees: number[][] = []

    for (let i = 0; i < row; i++) {
        for (let j = 0; j < col; j++) {
            if (forest[i][j] > 1) {
                trees.push([i, j])
            }
        }
    }
    trees.sort((a, b) => forest[a[0]][a[1]] - forest[b[0]][b[1]])
    
    let cx: number = 0
    let cy: number = 0
    let res: number = 0
    for (let i = 0; i < trees.length; i++) {
        let steps = bfs(cx, cy, trees[i][0], trees[i][1])
        if (steps === -1) {
            return -1
        }
        res += steps
        cx = trees[i][0]
        cy = trees[i][1]
    }
    return res
};
