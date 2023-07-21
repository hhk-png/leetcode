#include<iostream>
#include<string>
#include<deque>
using namespace std;

/*

����һ���ַ��� s ���ߵ��ַ����� ���� ��˳��

���� ���ɷǿո��ַ���ɵ��ַ�����s ��ʹ������һ���ո��ַ����е� ���� �ָ�����

���� ���� ˳��ߵ��� ���� ֮���õ����ո����ӵĽ���ַ�����

ע�⣺�����ַ��� s�п��ܻ����ǰ���ո�β��ո���ߵ��ʼ�Ķ���ո�
    ���صĽ���ַ����У����ʼ�Ӧ�����õ����ո�ָ����Ҳ������κζ���Ŀո�

*/

class Solution {
public:
    string reverseWords(string s) {
        // ��ָ�룬ָ���ַ����ĵ�һ���ַ�
        int left = 0;
        // ��ָ�룬ָ���ַ��������һ���ַ�
        int right = s.length() - 1;
        
        // ���ε�ǰ��Ŀո�
        while (left <= right && s[left] == ' ') left++;
        // ���ε������Ŀո�
        while (left <= right && s[right] == ' ') right--;

        // ˫�˶��У�ֻ�õ���ǰ��ĳ����
        deque<string> d;
        // �洢��������
        string word = "";
        while (left <= right) {
            char c = s[left];
            // �������ո��ʱ�򣬲���word��һ�����ʵ�ʱ��
            //   ��ֹ��������֮����ֶ���ո�
            if (c == ' ' && word.size()) {
                // ��ͷ�����룬����ͷ��ȡ����ջ�ṹ
                //      ��ջջ�ṹҲ��һ����
                d.push_front(word);
                word = "";
            }
            else if (c != ' ') {
                word += c;
            }
            left++;
        }
        // ��Ϊ�������ո�ʱ�Ž����ʷ��뵽�����У��������һ������û�з������
        d.push_front(word);

        // ���ս��
        string res = "";
        while (!d.empty()) {
            // ���˴Ӷ�����ȡ�����ʣ�����ƴ��
            res += d.front();
            d.pop_front();
            // ����������һ�����ʣ���ƴ��һ���ո�
            if (!d.empty()) res += ' ';
        }
        return res;
    }
};
