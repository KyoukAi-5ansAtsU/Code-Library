#include<iostream>
using namespace std;

bool exactMatch(char *text, char *pat)
{
	if (*text == '\0' && *pat != '\0')
		return false;
	if (*pat == '\0')
		return true;
	if (*text == *pat)
		return exactMatch(text + 1, pat + 1);
	return false;
}

bool contains(char *text, char *pat)
{

	if (*text == '\0')
		return false;


	if (*text == *pat)
		if(exactMatch(text, pat))
			return 1;
		else
		return contains(text + 1, pat);
	return contains(text + 1, pat);
}

int main()
{
	cout << contains("geeksforgeeks", "geeks") << endl;
	cout << contains("geeksforgeeks", "geeksquiz") << endl;
	cout << contains("geeksquizgeeks", "quiz") << endl;
	return 0;
}
