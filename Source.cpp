#include <iostream>
using namespace std;

class String
{
private:
	int sizeclass;
	char* str;
public:
	String(const char* st)
		: sizeclass{ (int)strlen(st) }, str{ new char[sizeclass + 1] }
	{
		strcpy_s(str, strlen(st) + 1, st);
	}

	char* getString()
	{
		return str;
	}

	int getSize()
	{
		return sizeclass;
	}

	char* changingStr(const char* st)
	{
		delete[] str;
		sizeclass = strlen(st);
		str = new char[sizeclass + 1];
		strcpy_s(str, sizeclass + 1, st);
		return str;
	}

	char* unionStr(const char* st)
	{
		int newsizeclass = strlen(st) + sizeclass;
		char* tempstr = new char[newsizeclass + 1];
		strcpy_s(tempstr, newsizeclass + 1, str);
		strcat_s(tempstr, newsizeclass + 1, st);
		delete[] str;
		str = tempstr;
		sizeclass = newsizeclass;
		return str;
	}

	char* addSymboltoStr(char sym, int index)
	{
		if (index < 0 || index > sizeclass)
		{
			cout << "Invalid index.\n";
			return str;
		}
		sizeclass++;
		char* tmp_str = new char[sizeclass + 1];
		strncpy_s(tmp_str, sizeclass + 1, str, index);
		strcat_s(tmp_str, sizeclass + 1, &str[index - 1]);
		tmp_str[index] = sym;
		delete[] str;
		str = tmp_str;
		return str;
	}

	void showASCII()
	{
		for (int i = 0; i < sizeclass; ++i)
			cout << (int)str[i] << " ";
		cout << endl;
	}

	char* uplettersString()
	{
		for (int i = 0; i < sizeclass; ++i)
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		return str;
	}

	char* downlettersString()
	{
		for (int i = 0; i < sizeclass; ++i)
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		return str;
	}

	~String()
	{
		delete[] str;
	}
};

int main()
{
	String str("Hi Igor!");
	cout << str.getString() << endl;
	cout << str.getSize() << endl;
	cout << str.changingStr("Bye Igor!") << endl;
	cout << str.unionStr("Bye") << endl;
	cout << str.addSymboltoStr('a',str.getSize()) << endl;
	str.showASCII();
	cout << str.uplettersString() << endl;
	cout << str.downlettersString() << endl;

	return 0;
}