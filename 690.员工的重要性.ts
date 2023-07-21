// https://leetcode.cn/problems/employee-importance/submissions/

// Definition for Employee.
class Employee {
    id: number
    importance: number
    subordinates: number[]
    constructor(id: number, importance: number, subordinates: number[]) {
        this.id = (id === undefined) ? 0 : id;
        this.importance = (importance === undefined) ? 0 : importance;
        this.subordinates = (subordinates === undefined) ? [] : subordinates;
    }
}

function getImportance(employees: Employee[], id: number): number {
    const map:Map<number, Employee> = new Map()
    for (const employee of employees) {
        map.set(employee.id, employee)
    }
    const dfs = (id: number): number => {
        const employee: Employee = map.get(id) as Employee
        const subordinates: number[] = employee.subordinates
        let total:number = 0
        total += employee.importance
        if (!employee.subordinates.length) return total
        for (const sub of subordinates) {
            total += dfs(sub)
        }
        return total
    }
    return dfs(id)
};