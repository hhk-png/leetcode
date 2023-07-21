var findMedianSortedArrays = function(nums1, nums2){
    let arr = [];
    let i=0, k=0, j=0;
    let len = nums1.length + nums2.length;
    let halflen = Math.floor(len/2);

    // 归并排序
    for(;i<nums1.length||j<nums2,length;){
        if( (i<nums1.length) && ((j >= nums2.length)||(nums1[i]<=nums2[j])) ){
            arr[k++] = nums1[i++];
        }
        if((j<nums2.length)&&((i > nums1.length)||(nums2[j] < nums1[i]))){
            arr[k++] = nums2[j++];
        }
    }

    // 返回
    if(len%2===1){
        return arr[halflen];
    }else{
        return (arr[halflen]+arr[halflen-1])/2;
    }

};


/*
public double findMedianSortedArrays(int[] A, int[] B) {
    int m = A.length;
    int n = B.length;
    int len = m + n;
    int left = -1, right = -1;
    int aStart = 0, bStart = 0;
    for (int i = 0; i <= len / 2; i++) {
        left = right;
        if (aStart < m && (bStart >= n || A[aStart] < B[bStart])) {
            right = A[aStart++];
        } else {
            right = B[bStart++];
        }
    }
    if ((len & 1) == 0)
        return (left + right) / 2.0;
    else
        return right;
}
*/

/*
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();
        int lStart = 0, rStart = 0;
        double leftVal = -1, rightVal = -1;


        for (int i = 0; i <= len / 2; i++) {
            leftVal = rightVal;
            if (lStart < nums1.size() && (rStart >= nums2.size() || nums1[lStart] < nums2[rStart])) {
                rightVal = nums1[lStart++];
            } else {
                rightVal = nums2[rStart++];
            }
        }

        if (len % 2 == 1) {
            return rightVal;
        }  else {
            return (leftVal + rightVal) / 2;
        }
    }
};
*/