PROJECT_DIR=.

# Config Compiler
ifeq ($(OS),Windows_NT)
	# You are using Windows
	MINGW_BIN=C:/mingw64/bin
	OPENCV_DIR=C:/opencv/build/install
	CC=${MINGW_BIN}/gcc.exe
	CXX=${MINGW_BIN}/g++.exe
else
	# You are using Linux or MacOS
	CC=gcc
	CXX=g++
endif

CFLAGS=-I${PROJECT_DIR}/include/ -std=c++11

# Using OpenCV for Visualization
OPENCV=0
OPENCV4=0
ifeq ($(OS),Windows_NT)
	ifeq ($(OPENCV), 1)
		CFLAGS+= -DOPENCV=1 -I${OPENCV_DIR}/include -std=c++11
		LDFLAGS+= -L${OPENCV_DIR}/x64/mingw/bin -lopencv_imgcodecs3413 -lopencv_core3413 -lopencv_highgui3413 -lopencv_imgproc3413
	endif
else
	ifeq ($(OPENCV), 1)
		ifeq ($(OPENCV4), 0)
			LDFLAGS+=  `pkg-config --libs opencv`
			CFLAGS+= -DOPENCV=1 `pkg-config --cflags opencv`
		else
			LDFLAGS+= `pkg-config --libs opencv4`
			CFLAGS+= -DOPENCV=1 `pkg-config --cflags opencv4`
		endif
	endif
endif


FILES=graph.cpp main.cpp disjointSet.cpp sort/msort.cpp

SRC_DIR=${PROJECT_DIR}/src/

SRC_FILES=$(addprefix ${SRC_DIR}, ${FILES})

all: 
	$(warning "You have to type one of the following commands")
	$(warning "     Type 'make prim' on Linux/MacOS or 'mingw32-make prim' on Windows to run compile and run the Prim's algorithm")
	$(warning "     Type 'make kruskal' on Linux/MacOS or 'mingw32-make kruskal' on Windows to run compile and run the Kruskal's algorithm")
	$(warning "     Type 'make dijkstra' on Linux/MacOS or 'mingw32-make dijkstra' on Windows to run compile and run the Dijkstra algorithm")

prim: ${SRC_FILES} ${SRC_DIR}algorithms/prim.cpp
	${CXX} ${CFLAGS} -DPRIM $^ ${LDFLAGS} -o bin/$@ 
	./bin/$@ 

kruskal: ${SRC_FILES} ${SRC_DIR}algorithms/kruskal.cpp
	${CXX} ${CFLAGS} -DKRUSKAL $^ ${LDFLAGS} -o bin/$@ 
	./bin/$@ 

dijkstra: ${SRC_FILES} ${SRC_DIR}algorithms/dijkstra.cpp
	${CXX} ${CFLAGS} -DDIJKSTRA $^ ${LDFLAGS} -o bin/$@ 
	./bin/$@ 


