@echo off
cd /d "%~dp0"

:menu
echo ===========================
echo  Simulation Control Script
echo ===========================
echo.
echo 1. Build Simulation
echo 2. Run Simulation
echo 3. Exit
echo.
set /p choice=Enter choice (1/2/3): 

if "%choice%"=="1" goto build
if "%choice%"=="2" goto run
if "%choice%"=="3" goto end

echo Invalid choice!
goto menu

:build
echo.
echo --- Building Simulation ---
g++ src/gravity_sim.cpp -o gravity_sim.exe -lglfw3 -lopengl32 -lgdi32
echo.
pause
goto menu

:run
echo.
echo --- Running Simulation ---
gravity_sim.exe
echo.
pause
goto menu

:end
echo Goodbye!
