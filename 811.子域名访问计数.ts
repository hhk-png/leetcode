// https://leetcode.cn/problems/subdomain-visit-count/submissions/

function subdomainVisits(cpdomains: string[]): string[] {
    const count: Map<string, number> = new Map()
    for (const cpdomain of cpdomains) {
        const spaceIndex: number = cpdomain.indexOf(' ')
        const num: number = parseInt(cpdomain.slice(0, spaceIndex))
        const domains: string[] = cpdomain.slice(spaceIndex + 1).split('.')
        const len: number = domains.length
        let temp: string = domains[len - 1]
        count.set(temp, (count.get(temp) || 0) + num)
        for (let i = len - 2; i >= 0; i--) {
            temp = domains[i] + '.' + temp
            count.set(temp, (count.get(temp) || 0) + num)
        }
    }
    const result: string[] = []
    for (const [domain, num] of count) {
        result.push(`${num} ${domain}`)
    }
    return result
};