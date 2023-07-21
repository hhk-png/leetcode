/*
    你这个学期必须选修 numCourse 门课程，记为 0 到 numCourse-1 。

    在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们：[0,1]

    给定课程总量以及它们的先决条件，请你判断是否可能完成所有课程的学习？


    示例 1:
    输入: 2, [[1,0]] 
    输出: true
    解释: 总共有 2 门课程。学习课程 1 之前，你需要完成课程 0。所以这是可能的。
    
    示例 2:
    输入: 2, [[1,0],[0,1]]
    输出: false
    解释: 总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0；并且学习课程 0 之前，你还应先完成课程 1。这是不可能的。
*/

/**
 * @param {number} numCourses
 * @param {number[][]} prerequisites
 * @return {boolean}
 */

// 两种数据结构，数组+Set(有向无环图)，数组(marked)
// dfs
var canFinish = function(numCourses, prerequisites) {
  if(numCourses <= 0) return false;

  // 初始化
  // 有向无环图
  let adjacency = new Array(numCourses);
  for (let i = 0; i < numCourses; i++) {
    adjacency[i] = new Set();
  }
  for(let item of prerequisites) {
    adjacency[item[1]].add(item[0]);
  }

  // 访问标记
  let marked = new Array(numCourses).fill(0);

  // dfs
  for(let i = 0; i < numCourses; i++) {
    if(dfs(adjacency, marked, i)) {
      return false;
    }
  }

  return true;
};

// 判断有环
// 有环就返回true，无环就返回false
function dfs(adjacency, marked, i) {
  // 为1表示正在访问当前节点或当前节点的后续节点
  // 为2表示当前节点以及当前节点的后续节点均已访问结束，且没有遇到环
  if(marked[i] === 1) return true;
  if(marked[i] === 2) return false;

  marked[i] = 1;

  let children = adjacency[i];

  for(let value of children) {
    if(dfs(adjacency, marked, value)) {
      return true;
    }
  }

  marked[i] = 2;
  return false;
}

// canFinish(4, [[1,0],[2,0],[3,1],[3,2]]);



// BFS
var canFinish2 = function(numCourses, prerequisites) {
  // 初始化
  let indegrees = new Array(numCourses).fill(0);
  let queue = new Array();
  let adjacency = new Array();
  for(let i = 0; i < numCourses; i++) {
    adjacency[i] = new Array();
  }
  for(let cp of prerequisites) {
    indegrees[cp[0]]++;
    adjacency[cp[1]].push(cp[0]);
  }

  for(let i = 0; i < numCourses; i++)
    if(indegrees[i] === 0) queue.push(i);

  while(queue.length !== 0) {
    let pre = queue.shift();
    numCourses--;
    for(let cur of adjacency[pre])
      if(--indegrees[cur] === 0) queue.push(cur);
  }
  
  return numCourses == 0;
}