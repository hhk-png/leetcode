/*
	ʵ��һ���㷨��ȷ��һ���ַ��� s �������ַ��Ƿ�ȫ����ͬ��

	ʾ�� 1��
		����: s = "leetcode"
		���: false

	ʾ�� 2��
		����: s = "abc"
		���: true

*/
class Solution {
public:
	bool isUnique(string astr) {
		// ͨ�������Ƽ�¼��ĸ�Ƿ���ֹ�
		int temp = 0;
		for (char s : astr) {
			// Сд��ĸ�����ֱ�ʾ��Ҫ�ƶ���λ��
			int move_bit = s - 'a';
			// Сд��ĸ�Ķ����Ʊ�ʾ
			int ans = (1 << move_bit);
			// ans �Ķ����Ʊ�ʾ�У�ֻ��һλΪ 1
			//	����� temp �����Ϊ 0��˵�������� s ��ͬ����ĸ
			if (temp & ans) {
				return false;
			}
			else {
				// �� s ��ǵ� temp ��
				temp |= ans;
			}
		}
		return true;
	}
};