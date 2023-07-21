/* 
    给定一个用字符数组表示的 CPU 需要执行的任务列表。其中包含使用大写的 A - Z 字母表示的26 种不同种类的任务。任务可以以任意顺序执行，并且每个任务都可以在 1 个单位时间内执行完。CPU 在任何一个单位时间内都可以执行一个任务，或者在待命状态。

    然而，两个相同种类的任务之间必须有长度为 n 的冷却时间，因此至少有连续 n 个单位时间内 CPU 在执行不同的任务，或者在待命状态。

    你需要计算完成所有任务所需要的最短时间。

     
    示例 ：

    输入：tasks = ["A","A","A","B","B","B"], n = 2
    输出：8
    解释：A -> B -> (待命) -> A -> B -> (待命) -> A -> B.
        在本示例中，两个相同类型任务之间必须间隔长度为 n = 2 的冷却时间，而执行一个任务只需要一个单位时间，所以中间出现了（待命）状态。 
*/

/**
 * @param {character[]} tasks
 * @param {number} n
 * @return {number}
 */
// 排序
var leastInterval = function(tasks, n) {
  // 初始化，总共就26个字母
  let map = new Array(26).fill(0),
      code,
      // 需要的时间
      time = 0;
  for(let task of tasks) {
    // js中不能直接进行字符串的减法，先转换成ascall码，在进行减法
    // 'A' 的ascall码为65
    code = task.charCodeAt() - 65;
    map[code]++;
  }

  // 升序排序
  map.sort(function (a, b) {
      return a-b;
  });

  // 所有任务执行完成之后退出循环
  while(map[25] > 0) {
    // 记录每一个周期(n+1)执行任务的index
    let i = 0;
    while(i <= n) {
      // map[25]===0，表示任务全部执行完成，退出循环
      if(!map[25]) {
        break;
      }
      // 还有任务没有执行
      if(i < 26 && map[25 - i]) {
        map[25 - i]--;
      }
      // 时间加一
      time++;
      // index加一
      i++;
    }
    // 执行完一轮任务之后再进行排序
    map.sort(function (a, b) {
        return a-b;
    });
  }

  // 返回
  return time;
};

// 设计
var leastInterval = function(tasks, n) {
  let map = new Array(26).fill(0);
  let code;
  for (let task of tasks) {
    code = task.charCodeAt() - 65;
    map[code]++;
  }
  // 升序排序
  map.sort((a, b) => a - b);

  let max_val = map[25] - 1,
      idle_slots = max_val * n;
  for (let i = 24; i >= 0 && map[i] > 0; i--) {
    idle_slots -= Math.min(max_val, map[i]);
  }

  return idle_slots > 0 ? (idle_slots + tasks.length) : tasks.length;
}

var leastInterval = function(tasks, n) {
  let map = new Array(26).fill(0);
  let code;
  for (let task of tasks) {
    code = task.charCodeAt() - 65;
    map[code]++;
  }
  let max_val = Math.max(...map),
      same = 0;
  for(let i = 24; i >=0; i--) {
    if(map[i] === max_val) {
      same++;
    }
  }

  let ans = Math.max((max_val-1)*n+max_val+same, tasks.length);
  return ans;
}