#include <string>
int main() {
	int n;
	cin >> n;
	string s;
	int year, month, day,hour,min,second;
	while (n--) {
		scanf("%d/%d/%d-%d:%d:%d", &year, &month, &day, &hour, &min, &second);
		int temp = hour;
		if (hour == 0) {
			hour = 12;
		}
		else
			hour = hour > 12 ? hour - 12 : hour;
		printf("%02d/%02d/%4d-%02d:%02d:%02d", month, day, year, hour, min, second);
		cout << (temp >= 12 ? "pm" : "am");
	}
}