# Windows System Information Tool

The Windows System Information Tool is a command-line application written in C that gathers essential system information from a Windows operating system. This tool utilizes the Windows API to access information about the OS version, CPU, and memory, providing users with valuable insights into their system's configuration.

## Features

- Retrieve OS version, build number, and platform (Windows NT or Windows 9x).
- Display CPU information, including architecture (x64, x86, ARM), and the number of processors.
- Obtain memory details, such as total physical memory, available physical memory, total virtual memory, and available virtual memory.

## How to Use

1. Make sure you have a C compiler (e.g., GCC, MinGW) installed on your Windows machine.
2. Download the source code files and save them in a directory.
3. Open a command prompt and navigate to the directory where the source code is located.
4. Compile the code using the C compiler. For example, using GCC:

gcc windows_system_info.c -o windows_system_info

5. Run the compiled executable:

windows_system_info

## Sample Output

Windows System Information Tool

Operating System Information:

Version: 10.0
Build Number: 19043
Platform: Windows NT
CPU Information:

Processor Architecture: x64
Number of Processors: 8
Memory Information:

Total Physical Memory: 16384 MB
Available Physical Memory: 8966 MB
Total Virtual Memory: 2097024 MB
Available Virtual Memory: 2097024 MB

## Contributions

Contributions to the Windows System Information Tool are welcome. If you find a bug, have a suggestion, or want to add new features, feel free to create an issue or submit a pull request.

## Acknowledgments

- The Windows API Documentation for providing the necessary functions to access system information.
