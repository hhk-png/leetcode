#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

/* https://leetcode.cn/problems/brick-wall/

�����ǰ��һ�¾��εġ��� n ��ש����ɵ�שǽ��
    ��Щש��߶���ͬ��Ҳ����һ����λ�ߣ����ǿ�Ȳ�ͬ��ÿһ��ש��Ŀ��֮����ȡ�

������Ҫ��һ�� �Զ����� �ġ����� ���� ש��Ĵ��ߡ�
    ����㻭����ֻ�Ǵ�ש��ı�Ե�������Ͳ��㴩�����ש��
    �㲻������ǽ��������ֱ��Ե֮һ���ߣ�������Ȼ��û�д���һ��ש�ġ�

����һ����ά���� wall ��������������ǽ�������Ϣ��
    ���У�wall[i] ��һ�������������ÿ��ש�Ŀ�ȵ����顣
    ����Ҫ�ҳ�����������ʹ������ ������ש���������� ��
    ���ҷ��� ������ש������ ��

*/

class Solution {
public:
    // ש��ĸ߶ȼ�ȥ��϶���������Ǵ�����������ש�����������ש����ۼƿ����ȵĵط����ǳ��ַ�϶�ĵط���
    //      ���ש��ĸ߶ȼ�ȥ����϶�������Ǵ���������ש�����С��Ŀ
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> cnt;
        for (auto& widths : wall) {
            int n = widths.size();
            int sum = 0;
            for (int i = 0; i < n - 1; i++) {
                sum += widths[i];
                cnt[sum]++;
            }
        }

        int maxVal = 0;
        for (auto& [_, val] : cnt) {
            maxVal = max(maxVal, val);
        }

        return wall.size() - maxVal;
    }
};