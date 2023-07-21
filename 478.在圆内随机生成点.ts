// https://leetcode.cn/problems/generate-random-point-in-a-circle/submissions/

// 因为圆的面积是π*r*r，正比于r的平方，必须从[0,r*r]内随机才能保证是整个圆面中的均匀分布。

class Solution {
    x_center: number
    y_center: number
    r: number
    constructor(radius: number, x_center: number, y_center: number) {
        this.x_center = x_center;
        this.y_center = y_center;
        this.r = radius;
    }

    randPoint(): number[] {
        const theta: number = Math.random() * 2 * Math.PI
        const rProbability: number = Math.sqrt(Math.random())
        return [
            this.x_center + rProbability * Math.cos(theta) * this.r,
            this.y_center + rProbability * Math.sin(theta) * this.r
        ]
    }
}


//  js
// var Solution = function(radius, x_center, y_center) {
//     this.xc = x_center;
//     this.yc = y_center;
//     this.r = radius;
// };

// Solution.prototype.randPoint = function() {
//     while (true) {
//         const x = Math.random() * (2 * this.r) - this.r;
//         const y = Math.random() * (2 * this.r) - this.r;
//         if (x * x + y * y <= this.r * this.r) {
//             return [this.xc + x, this.yc + y];
//         }
//     }
// };