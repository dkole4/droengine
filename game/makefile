TARGET = out

CXX = g++
CXXFLAGS = -Wall -Weffc++ -Wextra -Wsign-conversion -Werror -pedantic-errors

ENGINE_DIRS = . components core prefabs util
DIRS = $(addprefix ../droengine/src/, $(ENGINE_DIRS))
GAME_DIRS = . player
DIRS += $(addprefix src/, $(GAME_DIRS))

SDL2FLAGS = `sdl2-config --cflags --libs`


default: $(TARGET)
all: default

# substitute '.cpp' with '.o' in any *.cpp 
OBJECTS = $(patsubst %.cpp, %.o, $(wildcard *.cpp $(addsuffix /*.cpp, $(DIRS))))
HEADERS = $(wildcard *.h)

# build the executable
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(SDL2FLAGS)
    
# if make is interupted, dont delete any object file
.PRECIOUS: $(TARGET) $(OBJECTS)

# build the objects
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -Wall -o $@ $(SDL2FLAGS)

clean:
	-rm -f *.o $(addsuffix /*.o, $(DIRS))
	-rm -f $(TARGET)