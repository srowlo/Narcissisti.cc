#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>

using namespace std;

DWORD Process(char* ProcessName)
{
	HANDLE hPID = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	PROCESSENTRY32 ProcEntry;
	ProcEntry.dwSize = sizeof(ProcEntry);
	do
		if (!strcmp(ProcEntry.szExeFile, ProcessName))
		{
			DWORD dwPID = ProcEntry.th32ProcessID;
			CloseHandle(hPID);
			return dwPID;
		}
	while (Process32Next(hPID, &ProcEntry));

	cout << "noprocessfounderror" << endl;
}

int main() {
	if (1) {
		char myDLL[MAX_PATH];
		GetFullPathName("narcissisti.cc.dll", MAX_PATH, myDLL, 0);

		DWORD dwProcess = Process("csgo.exe");
		HANDLE hProcess = OpenProcess(PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION | PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_VM_OPERATION, FALSE, dwProcess);

		LPVOID allocatedMem = VirtualAllocEx(hProcess, NULL, sizeof(myDLL), MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
		WriteProcessMemory(hProcess, allocatedMem, myDLL, sizeof(myDLL), NULL);

		CreateRemoteThread(hProcess, 0, 0, (LPTHREAD_START_ROUTINE)LoadLibrary, allocatedMem, 0, 0);

		CloseHandle(hProcess);
	}

	return 0;
}