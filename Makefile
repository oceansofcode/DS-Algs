CC = g++
CFLAGS = -g -c -std=c++11
DEPS = sorts.hpp dynArray.hpp linkedList.hpp
OBJ = sorts.o main.o dynArray.o linkedList.o

a.exe: $(OBJ)
	$(CC) -g -std=c++11 $^

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) $< -o $@

clean:
	-rm *.o a.exe