/*
	��������֮��ĺ�������ָ�������������ֶ�Ӧ������λ��ͬ��λ�õ���Ŀ��

	������������ x �� y����������֮��ĺ������롣

	ע�⣺
	0 �� x, y < 231.

	ʾ��:

	����: x = 1, y = 4

	���: 2

	����:
	1   (0 0 0 1)
	4   (0 1 0 0)
		   ��   ��

	����ļ�ͷָ���˶�Ӧ������λ��ͬ��λ�á�
*/
class Solution {
public:
	int hammingDistance(int x, int y) {
		int XOR = x ^ y;
		int distance = 0;
		while (XOR != 0) {
			distance += 1;
			// remove the rightmost bit of '1'
			XOR = XOR & (XOR - 1);

			//if (XOR % 2 == 1)
			//	distance += 1;
			//XOR = XOR >> 1;
		}
		return distance;
	}
};