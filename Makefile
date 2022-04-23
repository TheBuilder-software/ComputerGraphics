CXX:= g++
SDL2_CFLAGS:= $(shell pkg-config sdl2 --cflags)
SDL2_LIBS:= $(shell pkg-config sdl2 --libs)
CXXFLAGS:= -g -O0 -std=c++20 -Wall -Wextra -pedantic -Werror -Wshadow -Wconversion -fsanitize=address -fmax-errors=3

BINS:= main ray grid line cube life rotation sand rotating_cube emitter explode

.PHONY: all clean

all: $(BINS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(SDL2_CFLAGS) -c -o $@ $<

$(BINS): %: %.o
	$(CXX) $(CXXFLAGS) $(LIBS) $(SDL2_LIBS) -o $@.out $<

clean:
	rm -f -- *.o
	rm -f -- *.out
