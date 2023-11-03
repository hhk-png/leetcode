// https://leetcode.cn/problems/accounts-merge/submissions/

function accountsMerge(accounts: string[][]): string[][] {
    const emailToIndex: Map<string, number> = new Map()
    const emailToName: Map<string, string> = new Map()
    let emailCount = 0
    for (const account of accounts) {
        const name: string = account[0]
        for (let i = 1; i < account.length; i++) {
            const email = account[i]
            if (!emailToIndex.has(email)) {
                emailToIndex.set(email, emailCount++)
                emailToName.set(email, name)
            }
        }
    }

    const uinonFind: UnionFind = new UnionFind(emailCount)
    for (const account of accounts) {
        const index = emailToIndex.get(account[1])!
        for (let i = 2; i < account.length; i++) {
            const nextIndex = emailToIndex.get(account[i])!
            uinonFind.union(index, nextIndex)
        }
    }

    const indexToEmail: Map<number, string[]> = new Map()
    for (const email of emailToIndex.keys()) {
        const index = uinonFind.find(emailToIndex.get(email)!)
        const account:string[] = indexToEmail.has(index) ? indexToEmail.get(index)! : []
        account.push(email)
        indexToEmail.set(index, account)
    }

    const merged: string[][] = []
    for (const email of indexToEmail.values()) {
        email.sort()
        const name = emailToName.get(email[0])!
        merged.push([name, ...email])
    }
    return merged
};


class UnionFind {
    parent: number[]

    constructor(n: number) {
        this.parent = new Array(n).fill(0).map((_, index) => index)
    }

    union(index1: number, index2: number) {
        this.parent[this.find(index2)] = this.find(index1)
    }

    find(index: number): number {
        if (this.parent[index] !== index) {
            this.parent[index] = this.find(this.parent[index])
        }
        return this.parent[index]
    }
}

