SFML_DIR = C:/Users/Cor/Documents/SFML-3.0.2-windows-gcc-14.2.0-mingw-64-bit/SFML-3.0.2
INCLUDE  = -I$(SFML_DIR)/include -Iheaders

LIBS = -L$(SFML_DIR)/lib \
       -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lsfml-main \
       -lopengl32 -lgdi32 -lwinmm -luuid -lws2_32 -lcomdlg32

# fuck this file
SRC = $(wildcard *.cpp) $(wildcard headers/*.cpp)
OBJ = $(SRC:.cpp=.o)

all: sfml-app.exe

sfml-app.exe: $(OBJ)
	g++ $(OBJ) -o $@ $(LIBS)

%.o: %.cpp
	g++ -c $< -o $@ -DSFML_STATIC $(INCLUDE)

clean:
	del /Q *.o headers\*.o sfml-app.exe 2>nul || exit 0
