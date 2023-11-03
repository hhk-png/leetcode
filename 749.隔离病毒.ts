// https://leetcode.cn/problems/contain-virus/submissions/

const dirs: number[][] = [[-1, 0], [1, 0], [0, -1], [0, 1]];
const containVirus = function(isInfected: number[][]) {
    const m: number = isInfected.length
    const n: number = isInfected[0].length;
    let ans = 0;
    while (true) {
        // 每一次 while 循环对应一天
        const neighbors: Array<Set<number>> = [];
        const firewalls: number[] = [];
        for (let i = 0; i < m; ++i) {
            for (let j = 0; j < n; ++j) {
                // 被感染
                if (isInfected[i][j] === 1) {
                    const queue: number[][] = [];
                    queue.push([i, j]);
                    const neighbor: Set<number> = new Set();
                    // 本次 bfs 周围防火墙数量
                    let firewall: number = 0
                    // 遍历的层数
                    let idx: number = neighbors.length + 1;
                    isInfected[i][j] = -idx;

                    while (queue.length > 0) {
                        const arr: number[] = queue.shift()!;
                        let x: number = arr[0]
                        let y: number = arr[1];
                        for (let d = 0; d < 4; ++d) {
                            let nx: number = x + dirs[d][0]
                            let ny: number = y + dirs[d][1];
                            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                                if (isInfected[nx][ny] === 1) {
                                    // 被感染的方块
                                    queue.push([nx, ny]);
                                    isInfected[nx][ny] = -idx;
                                } else if (isInfected[nx][ny] === 0) {
                                    // 未被感染的区域
                                    ++firewall;
                                    neighbor.add(getHash(nx, ny));
                                }
                            }
                        }
                    }
                    neighbors.push(neighbor);
                    firewalls.push(firewall);
                }
            }
        }

        if (neighbors.length === 0) {
            break;
        }

        // 找到 neighbors 最大元素的下标， 找到「对未感染区域的威胁最大」的区域
        let idx = 0;
        for (let i = 1; i < neighbors.length; ++i) {
            if (neighbors[i].size > neighbors[idx].size) {
                idx = i;
            }
        }
        // 加上该 neibor 对应的防火墙数量
        ans += firewalls[idx];
        for (let i = 0; i < m; ++i) {
            for (let j = 0; j < n; ++j) {
                // 在确定了区域（假设是第 idx 块区域）后，
                //  我们把矩阵中所有的 −idx 都变成 1，这样可以不影响任何搜索和判断；
                //  除此之外的所有负数都恢复成 2
                // isInfected[i][j] < 0 表示被感染的区域
                if (isInfected[i][j] < 0) {
                    if (isInfected[i][j] !== -idx - 1) {
                        isInfected[i][j] = 1;
                    } else {
                        isInfected[i][j] = 2;
                    }
                }
            }
        }
        // 扩散病毒
        for (let i = 0; i < neighbors.length; ++i) {
            if (i !== idx) {
                for (const val of neighbors[i]) {
                    let x = val >> 16, y = val & ((1 << 16) - 1);
                    isInfected[x][y] = 1;
                }
            }
        }
        if (neighbors.length === 1) {
            break;
        }
    }
    return ans;
}

const getHash = (x: number, y: number): number => {
    return (x << 16) ^ y;
};

