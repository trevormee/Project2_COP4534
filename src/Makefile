CXX = g++
CXXFLAGS = -std=c++11 -Wall

OBJS = main.o AnalyticalModel.o PriorityQueue.o
GCH = Headers/AnalyticalModel.hpp.gch 

proj2 : ${OBJS}
	 ${CXX} $(CXXFLAGS) -o $@ ${OBJS}

main.o : main.cpp
	${CXX} ${CXXFLAGS} -c main.cpp Headers/AnalyticalModel.hpp

AnalyticalModel.o : AnalyticalModel.cpp Headers/AnalyticalModel.hpp
	${CXX} ${CXXFLAGS} -c AnalyticalModel.cpp

PriorityQueue.o : PriorityQueue.cpp Headers/PriorityQueue.hpp
	${CXX} ${CXXFLAGS} -c PriorityQueue.cpp

clean : 
	rm ${OBJS} ${GCH} ${TXTFILES}
