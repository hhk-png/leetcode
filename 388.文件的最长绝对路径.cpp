#include<iostream>
#include<vector>
#include<string>

using namespace std;

/* https://leetcode.cn/problems/longest-absolute-file-path/ */
class Solution {
public:
    int lengthLongestPath(string input) {
        int n = input.size();
        int pos = 0;
        int ans = 0;
        // ��¼�ۼӵ��ļ�Ŀ¼���ȣ�ͨ��len �ۼ�
        vector<int> level(n + 1);

        // �����ļ�Ŀ¼�ַ�����ÿһ�п����ԡ�\t �ļ����ļ������� \n�� ���ֱ�ʾ���������ֱ�ʾ������
        //   ÿһ��ѭ�� level �������´� 1 ��ʼ����
        while (pos < n) {
            // ͨ�� \t �ĸ�����������ļ�Ŀ¼�����
            int depth = 1;
            while (pos < n && input[pos] == '\t') {
                pos++; // ǰ��һ���ַ�
                depth++; // ��ȼ� 1
            }

            // �����ļ����ļ������Ƶĳ���
            int len = 0;
            bool isFile = false;
            while (pos < n && input[pos] != '\n') {
                // ������ ��.�� ���ʾ���ļ���
                if (input[pos] == '.') {
                    isFile = true;
                }
                // ���Ƴ���+1
                len++;
                // λ��ǰ��һλ
                pos++;
            }
            // �������з� \n 
            pos++; // ������һ��

            // �����ۼ�
            if (depth > 1) {
                len += level[depth - 1] + 1;
            }

            // ������ļ�����ͳ�����ֵ
            if (isFile) {
                ans = max(len, ans);
            }
            else {
                // ���򽫳��ȼ���level��
                level[depth] = len;
            }

        }
        return ans;
    }
};

