run: queue
	./queue

queue: PriorityQueue.o PriorityQueueDr.o
	g++ -Wall -ggdb -O0 -pedantic-errors -o queue PriorityQueue.o PriorityQueueDr.o 

PriorityQueue.o: PriorityQueue.h PriorityQueue.cpp
	g++ -g -c PriorityQueue.cpp

PriorityQueueDr.o: PriorityQueueDr.cpp
	g++ -g -c PriorityQueueDr.cpp

clean:
	rm -f *.o queue