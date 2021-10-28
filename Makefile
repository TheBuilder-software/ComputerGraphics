CXX?=c++
SDL2FLAGS=$(shell pkg-config sdl2 --cflags --libs)
CXXFLAGS?=-std=c++20 -Wall -pedantic -Werror -Wshadow -Wstrict-aliasing -Wstrict-overflow

.PHONY: all msg clean fullclean

all: msg main ray grid line

msg:
	@echo '--- C++11 ---'

main: main.cpp
	${CXX} ${CXXFLAGS} -O2 -o $@ $< ${SDL2FLAGS}

ray: ray.cpp
	${CXX} ${CXXFLAGS} -O2 -o $@ $< ${SDL2FLAGS}

grid: grid.cpp
	${CXX} ${CXXFLAGS} -O2 -o $@ $< ${SDL2FLAGS}

line: line.cpp
	${CXX} ${CXXFLAGS} -O2 -o $@ $< ${SDL2FLAGS}


small: main.cpp
	${CXX} ${CXXFLAGS} -Os -o main $< ${SDL2FLAGS}
	-strip main
	-sstrip main

debug: main.cpp
	${CXX} ${CXXFLAGS} -O0 -g -o main $< ${SDL2FLAGS}

asm: main.asm

main.asm: main.cpp
	${CXX} ${CFLAGS} -S -o main.asm $< ${SDL2FLAGS}

run: msg main
	time ./main

clean:
	rm -f main *.o main.asm

fullclean: clean
