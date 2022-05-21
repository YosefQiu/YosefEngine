## GUID

When Wen completes a huge system, we need a way to uniquely mark each file and even every object in memory. 

The ideal state is to give a large enough number that can uniquely identify any object in the world. Because intuitively, the number is used as the key of the hash table, and then the value stores the specific object. With such a key, it is very convenient for everyone to build the relationship between objects through this key.

```c++
static char sNumberToLiterial[16] = 
{
	'0', '1', '2', '3',
	'4', '5', '6', '7',
	'8', '9', 'a', 'b', 
	'c', 'd', 'e', 'f'
};
```

```c++
void PrintTest()
{
	int i = 0;
	for (int nVal : sNumberToLiterial)
	{
		cout << i << " -> " << (char)nVal << endl;
		i++;
	}	
}
```

```c++
void GUID()
{
    unsigned int data[4];
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
}
```

