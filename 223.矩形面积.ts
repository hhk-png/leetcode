// https://leetcode.cn/problems/rectangle-area/submissions/

function computeArea(ax1: number, ay1: number, ax2: number, ay2: number, bx1: number, by1: number, bx2: number, by2: number): number {
    const area1: number = (ax2 - ax1) * (ay2 - ay1)
    const area2: number = (bx2 - bx1) * (by2 - by1);
    const overlapWidth: number = Math.min(ax2, bx2) - Math.max(ax1, bx1)
    const overlapHeight: number = Math.min(ay2, by2) - Math.max(ay1, by1);
    const overlapArea: number = Math.max(overlapWidth, 0) * Math.max(overlapHeight, 0);
    return area1 + area2 - overlapArea;
};