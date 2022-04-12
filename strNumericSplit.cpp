#include <bits/stdc++.h>
using namespace std;

void split(string str)
{
	int len = str.length();
			
	if (len == 1) {
		cout << ("Not Possible");
		return;
	}

	string s1 = "", s2 = "";
	long num1, num2;

	for (int i = 0; i <= len / 2; i++) {

		int flag = 0;
						
		s1 = str.substr(0, i + 1);
		num1 = stoi((s1));
		num2 = num1 + 1;
						
		s2 = to_string(num2);
		int k = i + 1;
		while (flag == 0) {
			int l = s2.length();
						
			if (k + l > len) {
				flag = 1;
				break;
			}
						
			if ((str.substr(k, k + l) == s2)) {
				flag = 0;
								
				num2++;
				k = k + l;
								
				if (k == len)
					break;
				s2 = to_string(num2);
				l = s2.length();
				if (k + 1 > len) {
															
					flag = 1;
					break;
				}
			}

			else
				flag = 1;
		}
				
		if (flag == 0) {
			cout << "Possible " << s1 << endl;
			break;
		}
		
		else if (flag == 1 && i > len / 2 - 1) {
			cout << "Not Possible" << endl;
			break;
		}
	}
}

int main()
{
	string str = "99100";
	split(str);
	return 0;
}

