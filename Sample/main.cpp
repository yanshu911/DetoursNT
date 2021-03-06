#define WIN32_LEAN_AND_MEAN
#include <cstdio>
#include <windows.h>

typedef LONG NTSTATUS;

EXTERN_C
NTSYSAPI
NTSTATUS
NTAPI
NtTestAlert(
  VOID
  );

int main()
{
  printf("Original:\n");
  printf("\t0x%08x\n\n", NtTestAlert());

  HMODULE SampleHookDllModule = LoadLibrary(TEXT("SampleHookDLL.dll"));

  printf("Hook:\n");
  printf("\t0x%08x\n\n", NtTestAlert());

  FreeLibrary(SampleHookDllModule);

  printf("Unhook:\n");
  printf("\t0x%08x\n\n", NtTestAlert());

  return 0;
}
