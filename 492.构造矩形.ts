// https://leetcode.cn/problems/construct-the-rectangle/submissions/

function constructRectangle(area: number): number[] {
    let w: number = Math.floor(Math.sqrt(area))
    while (area % w !== 0) {
        w--
    }
    return [Math.floor(area / w), w]
};
