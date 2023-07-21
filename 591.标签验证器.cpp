#include<iostream>
#include<stack>
#include<string>
#include<algorithm>

using namespace std;

// https://leetcode.cn/problems/tag-validator/

class Solution {
public:
    bool isValid(string code) {
        int n = code.size();
        stack<string> tags;

        int i = 0;
        while (i < n) {
            // ���� < �ٽ��д���
            if (code[i] == '<') {
                if (i == n - 1) {
                    return false;
                }
                // ������ǩ
                if (code[i + 1] == '/') {
                    // �Ҳ����������ţ�����false
                    int j = code.find('>', i);
                    if (j == string::npos) {
                        return false;
                    }
                    // ��ȡ������ǩ�� tagname
                    string tagName = code.substr(i + 2, j - (i + 2));
                    // ֮ǰ��tags Ϊ�ջ��߱�ǩ��ƥ��
                    if (tags.empty() || tags.top() != tagName) {
                        return false;
                    }
                    tags.pop();
                    // �ƶ�i ��λ��
                    i = j + 1;
                    // ������û�н�����tags��Ϊ�գ�����false
                    if (tags.empty() && i != n) {
                        return false;
                    }
                // cdata
                } else if (code[i + 1] == '!') {
                    // ��ʾcdata û�б���ǩ����
                    if (tags.empty()) {
                        return false;
                    }
                    // ��ȡcdata ��ǩ
                    string cdata = code.substr(i + 2, 7);
                    if (cdata != "[CDATA[") {
                        return false;
                    }
                    // Ѱ��cdata content ��Ľ�������
                    int j = code.find("]]>", i);
                    if (j == string::npos) {
                        return false;
                    }
                    // �ƶ�i ��λ��
                    i = j + 3;
                // ��ʼ��ǩ
                } else {
                    // ��ʼ��ǩ����Ҫ���tags �Ƿ�Ϊ��
                    // �Ҳ�����ʼ��ǩ�Ľ������ţ�
                    int j = code.find('>', i);
                    if (j == string::npos) {
                        return false;
                    }
                    // tagname
                    string tagName = code.substr(i + 1, j - (i + 1));
                    if (tagName.size() < 1 || tagName.size() > 9) {
                        return false;
                    }
                    // tagname ��ȫ��Ϊ��д��ĸ
                    if (!all_of(tagName.begin(), tagName.end(), [](unsigned char c) {return isupper(c);})) {
                        return false;
                    }

                    tags.push(move(tagName));
                    // �ƶ�i ��λ��
                    i = j + 1;
                }
            } else {
                // 
                if (tags.empty()) {
                    return false;
                }
                ++i;
            }
        }

        // ����tags ��Ϊ�գ��˱�ǩ�ַ������ǺϷ���
        return tags.empty();
    }
};


