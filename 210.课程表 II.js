var findOrder = function (numCourses, prerequisites) {
  const result = [];
  let valid = true;
  function dfs(adjacency, marked, i) {
      marked[i] = 1;

      let children = adjacency[i];

      for (let value of children) {
          if (marked[value] === 0) {
              dfs(adjacency, marked, value);
              if (!valid) {
                  return;
              }
          } else if (marked[value] === 1) {
              valid = false;
              return;
          }
      }

      marked[i] = 2;
      result.unshift(i);
  }
  const adjacency = new Array(numCourses);
  const marked = new Array(numCourses).fill(0);
  for (let i = 0; i < numCourses; i++) {
      adjacency[i] = [];
  }
  for (let item of prerequisites) {
      adjacency[item[1]].push(item[0]);
  }

  // dfs
  for (let i = 0; i < numCourses && valid; i++) {
      if (marked[i] === 0) {
          dfs(adjacency, marked, i);
      }
  }

  if (!valid) {
      return [];
  }

  return result.slice(0, numCourses);
};

