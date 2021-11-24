CXX?=c++
SDL2FLAGS=$(shell pkg-config sdl2 --cflags --libs)
CXXFLAGS?=-std=c++20 -Wall -pedantic -Werror -Wshadow -Wstrict-aliasing -Wstrict-overflow

.PHONY: all msg clean fullclean

all: msg main ray grid line cube life rotation sand rotating_cube emitter

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

cube: cube.cpp
	${CXX} ${CXXFLAGS} -O2 -o $@ $< ${SDL2FLAGS}

life: life.cpp
	${CXX} ${CXXFLAGS} -O2 -o $@ $< ${SDL2FLAGS}

rotation: rotation.cpp
	${CXX} ${CXXFLAGS} -O2 -o $@ $< ${SDL2FLAGS}

sand: sand.cpp
	${CXX} ${CXXFLAGS} -O2 -o $@ $< ${SDL2FLAGS}

rotating_cube: rotating_cube.cpp
	${CXX} ${CXXFLAGS} -O2 -o $@ $< ${SDL2FLAGS}
	
emitter: emitter.cpp
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
