class Solution {
    public String getPermutation(int n, int k) {
        // 默认值为false
        boolean[] visited = new boolean[n];        
        // 将 n! 种排列分为：n 组，每组有 (n - 1)! 种排列
        return recursive(n, factorial(n - 1), k, visited);
    }

    /**
    * @param n 剩余的数字个数，递减
    * @param f 每组的排列个数
    */
    private String recursive(int n, int f, int k, boolean[]visited){
        int offset = k%f;// 组内偏移量
        int groupIndex = k/f + (offset > 0 ? 1 : 0);// 第几组
        // 在没有被访问的数字里找第 groupIndex 个数字
        int i = 0; // 作用域原因，要这样写
        for(; i < visited.length && groupIndex > 0; i++){
            if(!visited[i]){
                groupIndex--;
            }
        }
        visited[i-1] = true;// 标记为已访问
        if(n - 1 > 0){
            // offset = 0 时，则取第 i 组的第 f 个排列，否则取第 i 组的第 offset 个排列
            // String.valueof()：将数字转换为字符串
            return String.valueOf(i) + recursive(n-1, f/(n - 1), offset == 0 ? f : offset, visited);
        }else{
            // 最后一数字
            return String.valueOf(i);
        }
    }

    /**
    * 求 n!
    */
    private int factorial(int n){
        int res = 1;
        for(int i = n; i > 1; i--){
            res *= i;
        }
        return res;
    }

}