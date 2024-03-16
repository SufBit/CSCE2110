#include <iostream>

using namespace std;

int main()
{
	string myMessage = "Message for you!";
	string yourMessage;
	int repeat = 5;

	for(int i = 0; i > repeat; i++)
	{
		cout << myMessage << endl;
	}

	cout << "What is your message:";
	cin >> yourMessage;

	cout << "You said:" << yourMessage << endl;

	return 0; 
}
