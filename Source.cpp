#include <iostream>
using namespace std;

class String
{
public:
	String(const char* st)
		: size{ (int)strlen(st) }, str{ new char[size + 1] }
	{
		strcpy_s(str, strlen(st) + 1, st);
	}

	char* getString()
	{
		return str;
	}

	int length()
	{
		return size;
	}

	char* changeString(const char* st)
	{
		delete[] str;
		size = strlen(st);
		str = new char[size + 1];
		strcpy_s(str, size + 1, st);
		return str;
	}

	char* unionString(const char* st)
	{
		int newSize = strlen(st) + size;
		char* tmp_str = new char[newSize + 1];
		strcpy_s(tmp_str, newSize + 1, str);
		strcat_s(tmp_str, newSize + 1, st);
		delete[] str;
		str = tmp_str;
		size = newSize;
		return str;
	}

	char* addSymbol(char sym, int index)
	{
		if (index < 0 || index > size)
		{
			cout << "Invalid index." << endl;
			return str;
		}
		++size;
		char* tmp_str = new char[size + 1];
		strncpy_s(tmp_str, size + 1, str, index);
		strcat_s(tmp_str, size + 1, &str[index - 1]);
		tmp_str[index] = sym;
		delete[] str;
		str = tmp_str;
		return str;
	}

	void showASCII()
	{
		for (int i = 0; i < size; ++i)
			cout << (int)str[i] << " ";
		cout << endl;
	}

	char* upString()
	{
		for (int i = 0; i < size; ++i)
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;

		return str;
	}

	char* downString()
	{
		for (int i = 0; i < size; ++i)
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;

		return str;
	}

	~String()
	{
		delete[] str;
	}

private:
	int size;
	char* str;
};

int main()
{
	String str_("Hello World!");
	cout << str_.getString() << endl;
	cout << str_.length() << endl;
	cout << str_.changeString("GoodBye World") << endl;
	cout << str_.unionString(" GoodBye") << endl;
	cout << str_.addSymbol('?', 21) << endl;
	str_.showASCII();
	cout << str_.upString() << endl;
	cout << str_.downString() << endl;

	return 0;
}