CC = g++
CFLAGS = -g -c
DEPS = sorts.h
OBJ = sorts.o main.o dynArray.o

a.exe: $(OBJ)
	$(CC) -g $^

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) $< -o $@

clean:
	-rm *.o a.exe