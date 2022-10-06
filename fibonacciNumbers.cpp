#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int FibsVal(string name)
{
	int numberVal, Term1 = 0, Term2 = 1, nextTerm = 0;

	cout << "Enter the number of terms: ";
	cin >> numberVal;
	cout << '\n';

	ofstream writeFile(name + ".txt");

	for (int i = 1; i <= numberVal; ++i)
	{

		if (i == 1)
		{
			writeFile << Term1 << endl;
			cout << Term1 << endl;
			continue;
		}
		if (i == 2)
		{
			writeFile << Term2 << endl;
			cout << Term2 << endl;
			continue;
		}

		nextTerm = Term1 + Term2;
		Term1 = Term2;
		Term2 = nextTerm;

		cout << nextTerm << endl;

		writeFile << nextTerm << endl;
	}

	cout << "\n";
	cout << "***File created, CONGRATULATIONS!***";
	cout << '\n';
	cout << "----------------------" << endl;

	writeFile.close();

	return 0;
}

void Searching()
{
	int count = 0;

	string name;
	string multiple;

	string countLine;

	cout << "Input the filename: " << endl;
	cin >> name;
	cout << "----------------------" << endl;

	ifstream readFile(name + ".txt");

	if (readFile.is_open())
	{
		cout << "***File exist, viewing the data***" << endl;
		cout << "\n";

		while (!readFile.eof())
		{
			getline(readFile, countLine);
			cout << countLine << endl;
			++count;
		}
		cout << "----------------------" << endl;

		readFile.close();
	}
	else
	{
		cout << "***File doesn't exist, create one***" << endl;
		cout << "----------------------" << endl;
		FibsVal(name);
	}
}

int main()
{
	char option1;

	cout << "***Fibonacci File Inverter***" << endl;

	do {
		cout << "[S] Search" << endl;
		cout << "[E] Exit" << endl;
		cout << '\n';
		cin >> option1;
		cout << "----------------------" << endl;

		switch (option1)
		{
		case 'S':
		case 's':
			Searching();
			break;
		}
	}

	while ((option1 != 'e') == (option1 != 'E'));

	return 0;

}
