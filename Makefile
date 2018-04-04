CC = g++
CFLAGS = -g -c
DEPS = sorts.hpp dynArray.hpp linkedList.hpp
OBJ = sorts.o main.o dynArray.o linkedList.o

a.exe: $(OBJ)
	$(CC) -g $^

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) $< -o $@

clean:
	-rm *.o a.exe