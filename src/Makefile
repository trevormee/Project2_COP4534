CXX = g++
CXXFLAGS = -g -std=c++11 -Wall

OBJS = main.o AnalyticalModel.o PriorityQueue.o Fifo.o Simulator.o
GCH = Headers/AnalyticalModel.hpp.gch Headers/PriorityQueue.hpp.gch Headers/Node.hpp.gch Headers/Fifo.hpp.gch

proj2 : ${OBJS}
	 ${CXX} $(CXXFLAGS) -o $@ ${OBJS}

main.o : main.cpp
	${CXX} ${CXXFLAGS} -c main.cpp Headers/AnalyticalModel.hpp Headers/PriorityQueue.hpp Headers/Node.hpp Headers/Fifo.hpp

AnalyticalModel.o : AnalyticalModel.cpp Headers/AnalyticalModel.hpp
	${CXX} ${CXXFLAGS} -c AnalyticalModel.cpp

PriorityQueue.o : PriorityQueue.cpp Headers/PriorityQueue.hpp
	${CXX} ${CXXFLAGS} -c PriorityQueue.cpp

Fifo.o : Fifo.cpp Headers/Fifo.hpp
	${CXX} ${CXXFLAGS} -c Fifo.cpp

Simulator.o : Simulator.cpp Headers/Simulator.hpp
	${CXX} ${CXXFLAGS} -c Simulator.cpp

clean : 
	rm ${OBJS} ${GCH} ${TXTFILES}
