all:
	g++ -I src/include -I Headers -L src/lib -o bin/TicTacToe SourceCode/main.cpp SourceCode/window.cpp SourceCode/rect.cpp SourceCode/text.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf