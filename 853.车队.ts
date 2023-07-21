// https://leetcode.cn/problems/car-fleet/submissions/

function carFleet(target: number, position: number[], speed: number[]): number {
  const cars: [number, number][] = []
  for (let i = 0; i < position.length; i++) {
      cars.push([position[i], speed[i]])
  }
  cars.sort((a, b) => a[0] - b[0])
  const times: number[] = []
  for (let i = 0; i < position.length; i++) {
      times.push((target - cars[i][0]) / cars[i][1])
  }
  let res: number = 0
  while (times.length > 1) {
    const lead: number = times.pop()!
    if (lead < times[times.length - 1]) {
      res += 1 
    } else {
      times[times.length - 1] = lead
    }
  }
  return res + (times.length > 0 ? 1 : 0)
};