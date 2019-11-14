SRCS = main.cpp stack.cpp read.cpp commands.cpp history.cpp convert.cpp list.cpp
HEADERS = stack.h
WARNING = -Wall -Wshadow --pedantic
ERROR = -Werror -Wvla
INCLUDE = -Iinclude
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --show-leak-kinds=all --track-origins=yes
EXE = calculator
CPP = g++ -std=c++11 -g $(WARNING) $(ERROR) $(INCLUDE)
OBJS = $(SRCS:%.cpp=%.o)
run: clean $(EXE) memory 
	./$(EXE)
$(EXE): $(OBJS) 
	$(CPP) $(OBJS) -o $(EXE) 
.cpp.o: $(HEADERS)
	$(CPP) -c $*.cpp 
gdb: $(EXE)
	gdb ./$(EXE)
memory: $(EXE)
	$(VAL) ./$(EXE)
	vim memcheck.txt
clean:
	rm -rf memcheck.txt $(OBJS) $(EXE)
