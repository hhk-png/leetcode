#include<iostream>
using namespace std;
int main() {

	char str[21];
	cin.getline(str, 20);
	int i = 0;
	while (str[i] != '\0') {
		if (str[i] >= 'A'&&str[i] <= 'Z') {
			// important
			str[i] = (str[i] + 32 - 'a' + 3) % 26 + 'a';
		}
		else {
			// important
			str[i] = (str[i] - 32 - 'A' + 3) % 26 + 'A';
		}
		i++;
	}
	str[i] = '\0';

	cout << str << endl;

	system("pause");
	return 0;
}

