Some random code

Setup:
https://code.visualstudio.com/docs/languages/cpp
https://code.visualstudio.com/docs/cpp/cmake-linux
Use UCRT64
pacman -Suy
pacman -S --needed base-devel mingw-w64-x86_64-toolchain
pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain (install gdb)

Install CMake
run the CMake: Quick Start command:
When see errror VSCode no generator found:
In CMake tool settings, add in "CMake: Generator"
MinGW Makefiles
