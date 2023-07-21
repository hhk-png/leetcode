class Union {
  constructor(n) {
    this.count = n;
    this.parent = new Array(n).fill(0);
    for (let i = 0; i < n; i++) {
      this.parent[i] = i;
    }
  }

  find = (index) => {
    if (index === this.parent[index]) 
      this.parent[index] = this.find(this.parent[index]);
    return this.parent[index];
  }

  union = (index1, index2) => {
    let root1 = this.find(index1);
    let root2 = this.find(index2);
    if (root1 === root2) return ;
    this.parent[root1] = root2;
    this.count--;
  }

  same = (index1, index2) => {
    return this.find(index1) === this.find(index2);
  }

}