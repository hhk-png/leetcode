function reverseArr(nums, i, j) {
  while (i < j) {
    let temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
    i++; j--; 
  }
}

const res = [];

function sort(cakes, n) {
  if (n === 1) return ;
  
  let maxCake = 0;
  let maxCakeIndex = 0;
  for (let i = 0; i < n; i++) {
    if (cakes[i] > maxCake) {
      maxCake = cakes[i];
      maxCakeIndex = i;
    }
  }
  reverseArr(cakes, 0, maxCakeIndex);
  res.push(maxCakeIndex + 1);
  reverseArr(cakes, 0, n-1);
  res.push(n);

  sort(cakes, n-1);
}

var pancakeSort = function(cakes) {
  sort(cakes, cakes.length);
  return res;
}
