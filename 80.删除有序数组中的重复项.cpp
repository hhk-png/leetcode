#include<iostream>
#include<vector>
using namespace std;

/*
����һ���������� nums ������ ԭ�� ɾ���ظ����ֵ�Ԫ�أ�ʹÿ��Ԫ�� ���������� ������ɾ����������³��ȡ�

��Ҫʹ�ö��������ռ䣬������� ԭ�� �޸��������� ����ʹ�� O(1) ����ռ����������ɡ�

*/

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int n = nums.size();
		if (n <= 2) {
			return n;
		}
		int slow = 2;
		int fast = 2;
		while (fast < n) {
			if (nums[slow - 2] != nums[fast]) {
				nums[slow] = nums[fast];
				slow++;
			}
			fast++;
		}

		return slow;
	}
};

