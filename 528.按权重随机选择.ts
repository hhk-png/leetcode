// https://leetcode.cn/problems/random-pick-with-weight/submissions/

var Solution = function(w: number[]) {
    this.pre = new Array(w.length).fill(0);
    this.pre[0] = w[0];
    for (let i = 1; i < w.length; ++i) {
        this.pre[i] = this.pre[i - 1] + w[i];
    }
    this.total = w.reduce((acc, val) => acc + val, 0)
};

Solution.prototype.pickIndex = function() {
    const x = Math.floor((Math.random() * this.total)) + 1;
    const binarySearch = (x: number) => {
        let low = 0, high = this.pre.length - 1;
        while (low < high) {
            const mid = Math.floor((high - low) / 2) + low;
            if (this.pre[mid] < x) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
    return binarySearch(x);
};