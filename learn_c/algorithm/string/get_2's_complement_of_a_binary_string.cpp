#include <iostream>
#include <string>

using namespace std;

string to_two_complement(string str)
{
	int i = str.length();
	for (--i; i >= 0; --i)
		if (str[i] == '1')
			break;
	
	if (i == -1)
		return '1' + str;
	
	for (--i; i >= 0; --i) {
		if (str[i] == '1')
			str[i] = '0';
		else
			str[i] = '1';
	}
	
	return str;
}

int main()
{
	string str = "00101111";
	
	cout << to_two_complement(str) << "\n";
	
	return 0;
}
