#include <string>
int main()
{
	string str;
	int i;
	while (cin>>str)
	{
		cin.ignore(INT16_MAX, '\n');
		if (str == "ENDOFINPUT") break;
		getline(cin, str, '\n');
		for (i = 0;i < str.length();++i)
			if (isalpha(str[i]))
				str[i] = 'A' + (str[i] - 'A' + 21) % 26;
		cout << str<<endl;
		cin >> str;
	}
}