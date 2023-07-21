/* https://leetcode.cn/problems/find-duplicate-file-in-system/ */

function findDuplicate(paths: string[]): string[][] {
    let obj:Record<string, string[]> = {}
    for (const path of paths) {
        const tmp:string[] = path.split(' ')
        const root:string = tmp[0]
        for (let i:number = 1; i < tmp.length; i++) {
            const fileInfo:RegExpMatchArray = tmp[i].match(/(.*)\((.*)\)/)
            const fileName:string = fileInfo[1]
            const fileContent:string = fileInfo[2]
            const format:string = `${root}/${fileName}`
            if (obj[fileContent]) {
                obj[fileContent].push(format)
            } else {
                obj[fileContent] = [format]
            }
        }
    }
    return Object.values(obj).filter(item => item.length > 1)
};