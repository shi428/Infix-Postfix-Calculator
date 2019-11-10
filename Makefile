SRCS = main.cpp stack.cpp list.cpp read.cpp
HEADERS = stack.h
WARNING = -Wall -Wshadow --pedantic
ERROR = -Werror -Wvla
INCLUDE = -Iinclude
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --show-leak-kinds=all --track-origins=yes
EXE = calculator
CPP = c++ -std=c++11 -g $(WARNING) $(ERROR) $(INCLUDE)
OBJS = $(SRCS:%.cpp=%.o)
run: $(EXE) memory
	./$(EXE)
$(EXE): $(OBJS) 
	$(CPP) $(OBJS) -o $(EXE)
.cpp.o: $(HEADERS)
	$(CPP) -c $*.cpp
memory: $(EXE)
	$(VAL) ./$(EXE)
	vim memcheck.txt
clean:
	rm -rf *.txt $(OBJS) $(EXE)
