#include <stdio.h>
#include <Windows.h>

void getOSInformation();
void getCPUInformation();
void getMemoryInformation();

int main() {
    printf("Windows System Information Tool\n\n");
    getOSInformation();
    getCPUInformation();
    getMemoryInformation();

    return 0;
}

void getOSInformation() {
    OSVERSIONINFOEX osInfo;
    ZeroMemory(&osInfo, sizeof(OSVERSIONINFOEX));
    osInfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);

    if (GetVersionEx((LPOSVERSIONINFO)&osInfo)) {
        printf("Operating System Information:\n");
        printf("  - Version: %d.%d\n", osInfo.dwMajorVersion, osInfo.dwMinorVersion);
        printf("  - Build Number: %d\n", osInfo.dwBuildNumber);
        printf("  - Platform: %s\n", osInfo.dwPlatformId == VER_PLATFORM_WIN32_NT ? "Windows NT" : "Windows 9x");
    } else {
        printf("Error retrieving OS information.\n");
    }
}

void getCPUInformation() {
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);

    printf("\nCPU Information:\n");
    printf("  - Processor Architecture: ");
    switch (sysInfo.wProcessorArchitecture) {
        case PROCESSOR_ARCHITECTURE_AMD64:
            printf("x64\n");
            break;
        case PROCESSOR_ARCHITECTURE_INTEL:
            printf("x86\n");
            break;
        case PROCESSOR_ARCHITECTURE_ARM:
            printf("ARM\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }
    printf("  - Number of Processors: %u\n", sysInfo.dwNumberOfProcessors);
}

void getMemoryInformation() {
    MEMORYSTATUSEX memoryInfo;
    memoryInfo.dwLength = sizeof(MEMORYSTATUSEX);

    if (GlobalMemoryStatusEx(&memoryInfo)) {
        printf("\nMemory Information:\n");
        printf("  - Total Physical Memory: %lld MB\n", memoryInfo.ullTotalPhys / (1024 * 1024));
        printf("  - Available Physical Memory: %lld MB\n", memoryInfo.ullAvailPhys / (1024 * 1024));
        printf("  - Total Virtual Memory: %lld MB\n", memoryInfo.ullTotalVirtual / (1024 * 1024));
        printf("  - Available Virtual Memory: %lld MB\n", memoryInfo.ullAvailVirtual / (1024 * 1024));
    } else {
        printf("Error retrieving memory information.\n");
    }
}
