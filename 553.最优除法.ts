// https://leetcode.cn/problems/optimal-division/submissions/

function optimalDivision(nums: number[]): string {
    const n: number = nums.length;
    if (n === 1) {
        return '' + nums[0];
    }
    if (n === 2) {
        return '' + nums[0] + "/" + '' + nums[1];
    }
    const result: string[] = [`${nums[0]}/(`];
    for (let i = 1; i < n; i++) {
        result.push(`${nums[i]}/`);
    }
    result.pop();
    result.push(nums[n - 1] + ')');
    return result.join('');
};

