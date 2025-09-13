:: Build and Setup Script for Computer Graphics Mini Project
:: Run this script to set up the project properly

@echo off
echo ========================================
echo Computer Graphics Mini Project Setup
echo ========================================
echo.

:: Check if MSBuild is available
where msbuild >nul 2>nul
if %errorlevel% neq 0 (
    echo ERROR: MSBuild not found in PATH
    echo Please run this script from a "Developer Command Prompt for VS" 
    echo or ensure MSBuild is installed and added to PATH.
    pause
    exit /b 1
)

:: Create resources directory if it doesn't exist
if not exist "resources" (
    echo Creating resources directory...
    mkdir resources
)

:: Create profile files for extrusions and sweeps
echo Creating profile files...

:: Windshield profile
echo 0.0, 0.0 > resources\windshield_profile.txt
echo 1.0, 0.0 >> resources\windshield_profile.txt
echo 1.0, 1.0 >> resources\windshield_profile.txt
echo 0.0, 1.0 >> resources\windshield_profile.txt

:: Windshield path
echo p > resources\windshield_path.txt
echo m 0.1 >> resources\windshield_path.txt
echo s 1.1 0.8 >> resources\windshield_path.txt
echo p >> resources\windshield_path.txt
echo m 0.2 >> resources\windshield_path.txt
echo p >> resources\windshield_path.txt

:: Cockpit profile
echo 0.0, 0.0 > resources\cockpit_profile.txt
echo 0.8, 0.0 >> resources\cockpit_profile.txt
echo 1.0, 0.3 >> resources\cockpit_profile.txt
echo 0.8, 0.8 >> resources\cockpit_profile.txt
echo 0.0, 0.8 >> resources\cockpit_profile.txt

:: Cockpit path
echo p > resources\cockpit_path.txt
echo m 0.5 >> resources\cockpit_path.txt
echo s 0.9 1.2 >> resources\cockpit_path.txt
echo p >> resources\cockpit_path.txt
echo m 1.0 >> resources\cockpit_path.txt
echo s 0.8 0.8 >> resources\cockpit_path.txt
echo p >> resources\cockpit_path.txt

:: Exhaust profile (circular)
echo 0.3, 0.0 > resources\exhaust_profile.txt
echo 0.21, 0.21 >> resources\exhaust_profile.txt
echo 0.0, 0.3 >> resources\exhaust_profile.txt
echo -0.21, 0.21 >> resources\exhaust_profile.txt
echo -0.3, 0.0 >> resources\exhaust_profile.txt
echo -0.21, -0.21 >> resources\exhaust_profile.txt
echo 0.0, -0.3 >> resources\exhaust_profile.txt
echo 0.21, -0.21 >> resources\exhaust_profile.txt

echo Profile files created successfully!

:: Check for texture file
if not exist "resources\boxtex.jpg" (
    echo WARNING: boxtex.jpg not found in resources folder
    echo Please copy a texture file named 'boxtex.jpg' to the resources folder
    echo You can use any JPEG image file for texturing
    echo.
)

:: Check if source files exist
echo Checking source files...
if not exist "objects-student\Composite1.h" (
    echo ERROR: Composite1.h not found in objects-student folder
    echo Please ensure all source files are copied correctly
    pause
    exit /b 1
)

if not exist "objects-student\Composite1.cpp" (
    echo ERROR: Composite1.cpp not found in objects-student folder
    pause
    exit /b 1
)

if not exist "objects-student\Composite2.h" (
    echo ERROR: Composite2.h not found in objects-student folder
    pause
    exit /b 1
)

if not exist "objects-student\Composite2.cpp" (
    echo ERROR: Composite2.cpp not found in objects-student folder
    pause
    exit /b 1
)

echo Source files found!

:: Build the project
echo.
echo Building project...
echo ========================================

:: Clean previous builds
if exist "build" rmdir /s /q build
mkdir build

:: Build using MSBuild
msbuild assig2.sln /p:Configuration=Release /p:Platform=Win32 /verbosity:minimal

if %errorlevel% neq 0 (
    echo.
    echo BUILD FAILED!
    echo Please check the error messages above
    echo Common issues:
    echo - Missing header files
    echo - Syntax errors in source code
    echo - Missing dependencies
    pause
    exit /b 1
)

echo.
echo ========================================
echo BUILD SUCCESSFUL!
echo ========================================
echo.
echo The project has been built successfully.
echo Executable location: build\assig2.exe
echo.
echo To run the program:
echo 1. Double-click the executable, or
echo 2. Run from command line: build\assig2.exe
echo.
echo Controls:
echo   'a' - Start animation
echo   'p' - Pause/unpause
echo   'f' - Toggle fullscreen  
echo   'w' - Toggle wireframe
echo   'q' - Quit
echo.
echo Enjoy the vehicle animation!
pause