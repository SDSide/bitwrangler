SFML_DIR = C:/Users/Cor/Documents/SFML-3.0.2-windows-gcc-14.2.0-mingw-64-bit/SFML-3.0.2
INCLUDE  = -I$(SFML_DIR)/include

LIBS = -L$(SFML_DIR)/lib \
       -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lsfml-main \
       -lopengl32 -lgdi32 -lwinmm -luuid -lws2_32 -lcomdlg32

# Automatically gather all .cpp files
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

all: sfml-app.exe

sfml-app.exe: $(OBJ)
	g++ $(OBJ) -o $@ $(LIBS)

%.o: %.cpp
	g++ -c $< -DSFML_STATIC $(INCLUDE)

clean:
	del /Q *.o sfml-app.exe 2>nul || exit 0
