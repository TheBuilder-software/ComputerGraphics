CXX:= c++
SDL2_CFLAGS:= $(shell pkg-config sdl2 --cflags)
SDL2_LIBS:= $(shell pkg-config sdl2 --libs)
CXXFLAGS:= -O2 -std=c++20 -Wall -pedantic -Werror -Wshadow -Wstrict-aliasing -Wstrict-overflow

BINS:= main ray grid line cube life rotation sand rotating_cube emitter

.PHONY: all clean

all: $(BINS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(SDL2_CFLAGS) -c -o $@ $<

$(BINS): %: %.o
	$(CXX) $(LIBS) $(SDL2_LIBS) -o $@ $<

clean:
	rm -f -- $(BINS) *.o
