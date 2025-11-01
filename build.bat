@echo off
REM Compiles an AoC solution. Ultimately produces a .exe and a .S (assembly output).
REM %MSYS_ROOT% should be the path to your MSYS2 install's root dir (default is C:\msys64); no trailing slashes please

set compiler_args=-fdiagnostics-color=always -std=c23 -march=native -Ofast -Wpedantic -I%MSYS_ROOT%\usr\include

REM .exe
gcc %compiler_args% main.c -o main.exe

REM .S
gcc %compiler_args% -S main.c -o main.S
