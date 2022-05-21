#include <iostream>
#include <windows.h>
using namespace std;

//128 bits 4 bits -> 0000 - 1111 0-F
//128 bits -> 32 char
static char sNumberToLiterial[16] = 
{
	'0', '1', '2', '3',
	'4', '5', '6', '7',
	'8', '9', 'a', 'b', 
	'c', 'd', 'e', 'f'
};

void PrintTest()
{
	int i = 0;
	for (int nVal : sNumberToLiterial)
	{
		cout << i << " -> " << (char)nVal << endl;
		i++;
	}	
}

int main(int argc, char* argv[])
{
	cout << "Test for GUID-----------------" << endl;
	PrintTest();
	
	unsigned int data[4] = {12345};
	CoCreateGuid((GUID*)data);
	char guid[33] = { 0 };
	for (int i = 0; i < 4; i++)
	{
		for (int j = 7; j >= 0; j--)
		{
			unsigned int current = data[i];
			current >>= (j * 4);
			current &= 0xf;
			char current_char = sNumberToLiterial[current];
			guid[i * 8 + j] = current_char;
		}
	}
	cout << guid << endl;
	system("pause");
	return 0;
}