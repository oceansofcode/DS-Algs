CC = g++
CFLAGS = -g -c
DEPS = sorts.h dynArray.h linkedList.h
OBJ = sorts.o main.o dynArray.o linkedList.o

a.exe: $(OBJ)
	$(CC) -g $^

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) $< -o $@

clean:
	-rm *.o a.exe