int main()
{
	string wname, name;
	int wsol = 0, sol;
	int wpt = 0, pt; 
	int sub, time; 
	int n; 
	cin >> n;
	for (int i = 0;i < n;++i)
	{
		pt = 0;
		sol = 0;
		cin >> name;
		for (int j = 0;j < 4;++j)
		{
			cin >> sub >> time;
			if (0 != time)
			{
				++sol;
				pt += (sub - 1) * 20 + time;
			}
		}
		if ((sol > wsol) || (sol == wsol && wpt > pt)) //确定当前冠军
		{
			wname = name;
			wsol = sol;
			wpt = pt;
		}
	}
	cout << wname << " " << wsol << " " << wpt << endl;
	return 0;
}
