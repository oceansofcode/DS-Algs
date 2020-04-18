CC = g++
CFLAGS = -g -c -std=c++11
DEPS = sorts.hpp dynArray.hpp linkedList.hpp
OBJ = sorts.o main.o linkedList.o

a.exe: $(OBJ)
	$(CC) -g -std=c++11 $^

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) $< -o $@

clean:
	-rm *.o a.exe

all:
	gcc alarm_mutex.c -g -D_POSIX_PTHREAD_SEMANTICS -lpthread -o alarm.exe
	gcc New_Alarm_Mutex.c -g -D_POSIX_PTHREAD_SEMANTICS -lpthread -o new_alarm.exe