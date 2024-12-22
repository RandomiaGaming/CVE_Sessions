#include <windows.h>
#include <iostream>

void PrintLastError() {
	// Get the last error code.
	DWORD errorCode = GetLastError();

	// Get a pointer to a system allocated wide string containing the error message.
	WCHAR* errorMessage = nullptr;
	DWORD size = FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL, errorCode, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&errorMessage, 0, NULL);

	// Print the narrow version of errorMessage to the console.
	std::wcout << L"Error: " << errorMessage;

	// Cleanup and free memory.
	LocalFree(errorMessage);
}

int main()
{
    HANDLE token;
    if (!LogonUser(L"RootKit", NULL, L"Password123", LOGON32_LOGON_INTERACTIVE, LOGON32_PROVIDER_DEFAULT, &token))
    {
		PrintLastError();
    }

}