// https://leetcode.cn/problems/max-area-of-island/submissions/

function maxAreaOfIsland(grid: number[][]): number {
    let res: number = 0
    const m: number = grid.length
    const n: number = grid[0].length
    const dirX: number[] = [0, 0, 1, -1]
    const dirY: number[] = [1, -1, 0, 0]

    const dfs = (x: number, y: number) => {
        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] === 0) {
            return 0
        }
        grid[x][y] = 0
        let res: number = 1
        for (let i = 0; i < 4; i++) {
            const nx: number = x + dirX[i]
            const ny: number = y + dirY[i]
            res += dfs(nx, ny)
        }
        return res
    }

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            res = Math.max(res, dfs(i, j))
        }
    }

    return res
};