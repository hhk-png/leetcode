function BoyerMoore(pat) {
  let M = pat.length;
  let R = 256;
  let right = new Array(R);
  for (let i = 0; i < R; i++) {
    right[i] = -1;
  }

  for (let j = 0; j < M; j++) {
    right[pat[j]] = j;
  }
  return right;
}

function search(txt, pat) {
  let N = txt.length;
  let M = pat.length;
  let skip;
  let right = BoyerMoore(pat);
  for (let i = 0; i < N - M; i += skip) {
    skip = 0;
    for (let j = M - 1; j >= 0; j--) {
      if (pat[j] !== txt[i + j]) {
        skip = j - right[txt[i + j]];
        if (skip < 1) skip = 1;
        break;
      }
    }

    if (skip = 0) return i;
  }
  return N;
}


