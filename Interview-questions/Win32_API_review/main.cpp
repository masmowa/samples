#include <iostream>
#include <Windows.h>
#include <cstdio>

using namespace std;

/***
Area’s to review on Win32 APIs:
 API’s used to manipulate files
 Thread Synchronization APIs/Objects
 Be prepared to walk through the process of how you could test a core Windows app by leveraging Win32 API’s (what to use and why)

***/

// Threads and Thread synchronization


void ThreadTest(size_t want) {

}

DWORD WINAPI myThread(LPVOID lpParameter)
{
	unsigned int& myCounter = *((unsigned int*)lpParameter);
	while(myCounter < 0xFFFFFFFF) ++myCounter;


	return 0;
}

int main()
{
    cout << "Hello world!" << endl;

	unsigned int myCounter = 0;
	DWORD myThreadID;
	HANDLE myHandle = CreateThread(0, 0, myThread, &myCounter, 0, &myThreadID);
	char myChar = ' ';
	while(myChar != 'q') {
		cout << myCounter << endl;
		myChar = getchar();
	}

	CloseHandle(myHandle);

    return 0;
}
