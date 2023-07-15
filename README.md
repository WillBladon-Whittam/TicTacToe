# TicTacToe
TicTacToe Game using C++ and SDL

# Dependencies
 - SDL (2.28.1) - https://github.com/libsdl-org/SDL/releases
 - SDL Image (2.6.3) - https://github.com/libsdl-org/SDL_image/releases
 - SDL TTF - (2.20.2) https://github.com/libsdl-org/SDL_ttf/releases

# Binary Executable
To download the executable, go to https://github.com/WillBladon-Whittam/TicTacToe/releases and download the latest release.
Extract the downloaded zip file and run TicTacToe.exe

# Enviroment Setup

## Pull down source code from git
Pull down  from the main branch of the TicTacToe project. Within that project, create folder called 'src' and a folder called 'bin'
Here will be where we add all the SDL assets and binaries.

## Download and add the dependencies to the project
Download all the dependencies listed above. Make sure to install the developer files, and the mingw of the correct versions.
The files extracted from the depencdencies need to be added to the project folder.
To do this, first go into the SDL2 folder that was extracted, then open the 64 or 32 bit folder for mingw. 
(Check system by opening file explorer, right-click "This PC", then the system type will be displayed)

Now copy the 'include' folder and the 'lib' folders into the 'src' folder created in the project earlier.
Go into the 'bin' folder, and copy the .dll file in the 'bin' folder created earlier.

Now for SDL Image and SDL TTF.
Go into the SDL2 folder within the extracted file, and select the mingw folder for your system type.
Copy the files in include/SDL2 into src/include/SDL2 wihtin local your project.
Copy the folder in lib/cmake into src/lib/cmake within your local project.
Copy the files in lib/pkgconfig into src/lib/pkgconfig within your local project.
Copy the remaining files (not folders, just files) from lib into src/lib within your local project.
Copy the files in bin into the local bin folder in the project.

Repeat this for both SDL Image and SDL TTF folders that were downloaded.
The Makefile is already pulled down from the git repository.
Adjustments can be made to the makefile if you wish to move the location of any of the files.

## Compile and run the software
Open up a terminal and move to the root page of the project.
Run the command 'make' to compile the code.
Now a .exe file has been generated which can be ran by entereing ./TicTacToe.exe or double clicking the file.
