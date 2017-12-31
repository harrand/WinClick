@echo off

set scriptdir=%cd%
set cpldirX=%scriptdir%\cpl\%date%
set cpldir=%cpldirX:/=.%
set incdir=%cd%\inc
set libdir=%cd%\lib
echo Compiling WinClick
cd src
gcc *.c -static -o winclick.exe

if not exist "%cpldir%" mkdir "%cpldir%"
set lnkdir=%cpldir%\lnk
if not exist %lnkdir% mkdir %lnkdir%

move winclick.exe %lnkdir%
echo Compilation script finished.
explorer %lnkdir%
pause