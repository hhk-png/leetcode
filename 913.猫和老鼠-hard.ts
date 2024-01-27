// https://leetcode.cn/problems/cat-and-mouse/solutions/1190205/mao-he-lao-shu-by-leetcode-solution-444x/

const MOUSE_TURN = 0;
const CAT_TURN = 1;
const DRAW = 0;
const MOUSE_WIN = 1;
const CAT_WIN = 2;

var catMouseGame = function (graph: number[][]) {
  const n = graph.length;
  const degrees: number[][][] = new Array(n).fill(0).map(() => new Array(n).fill(0).map(() => new Array(2).fill(0)));
  const results: number[][][] = new Array(n).fill(0).map(() => new Array(n).fill(0).map(() => new Array(2).fill(0)));
  const queue: number[][] = [];
  for (let i = 0; i < n; i++) {
    for (let j = 1; j < n; j++) {
      degrees[i][j][MOUSE_TURN] = graph[i].length;
      degrees[i][j][CAT_TURN] = graph[j].length;
    }
  }
  for (const node of graph[0]) {
    for (let i = 0; i < n; i++) {
      degrees[i][node][CAT_TURN]--;
    }
  }
  for (let j = 1; j < n; j++) {
    results[0][j][MOUSE_TURN] = MOUSE_WIN;
    results[0][j][CAT_TURN] = MOUSE_WIN;
    queue.push([0, j, MOUSE_TURN]);
    queue.push([0, j, CAT_TURN]);
  }
  for (let i = 1; i < n; i++) {
    results[i][i][MOUSE_TURN] = CAT_WIN;
    results[i][i][CAT_TURN] = CAT_WIN;
    queue.push([i, i, MOUSE_TURN]);
    queue.push([i, i, CAT_TURN]);
  }
  while (queue.length) {
    const state = queue.shift()!;
    const mouse = state[0];
    const cat = state[1],
      turn = state[2];
    const result = results[mouse][cat][turn];
    const prevStates = getPrevStates(mouse, cat, turn, graph);
    for (const prevState of prevStates) {
      let prevMouse = prevState[0],
        prevCat = prevState[1],
        prevTurn = prevState[2];
      if (results[prevMouse][prevCat][prevTurn] === DRAW) {
        const canWin =
          (result === MOUSE_WIN && prevTurn === MOUSE_TURN) ||
          (result === CAT_WIN && prevTurn === CAT_TURN);
        if (canWin) {
          results[prevMouse][prevCat][prevTurn] = result;
          queue.push([prevMouse, prevCat, prevTurn]);
        } else {
          degrees[prevMouse][prevCat][prevTurn]--;
          if (degrees[prevMouse][prevCat][prevTurn] == 0) {
            const loseResult = prevTurn === MOUSE_TURN ? CAT_WIN : MOUSE_WIN;
            results[prevMouse][prevCat][prevTurn] = loseResult;
            queue.push([prevMouse, prevCat, prevTurn]);
          }
        }
      }
    }
  }
  return results[1][2][MOUSE_TURN];
};

const getPrevStates = (mouse: number, cat: number, turn: number, graph: number[][]) => {
  const prevStates: number[][] = [];
  const prevTurn = turn == MOUSE_TURN ? CAT_TURN : MOUSE_TURN;
  if (prevTurn === MOUSE_TURN) {
    for (const prev of graph[mouse]) {
      prevStates.push([prev, cat, prevTurn]);
    }
  } else {
    for (const prev of graph[cat]) {
      if (prev != 0) {
        prevStates.push([mouse, prev, prevTurn]);
      }
    }
  }
  return prevStates;
};
