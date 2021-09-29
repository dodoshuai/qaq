
#boost:
#	g++ test_boost.cpp -g -o test_boost -lpthread -lboost_system

CXX             = g++
BIN             = timer 
OBJ             = test_timer.o
LINKOBJ         = -pthread -lboost_system
CXXINC          = 
CXXFLAGS        = $(CXXINC) -std=c++11 -O3 -Wall
RM              = rm -f
LINK 			= /home/ys/tools/boost_1_76_0

all:timer timer2 $(BIN)

$(BIN):$(OBJ)
	$(CXX)  $(CXXFLAGS) $(OBJ) -pthread  -o $(BIN) -I $(LINK)

$(OBJ):%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $<
timer2:test_timer2.cpp
	$(CXX)  $(CXXFLAGS) $< -pthread  -o $@ -I $(LINK)
#timer2.o:test_timer2.cpp
#	$(CXX) $(CXXFLAGS) -c timer2.o
clean:
	        $(RM) $(OBJ) $(BIN)
ctags:
	@rm -rf tags
	@ctags -R -h ".c.cpp.h" --exclude=*.hpp --append=yes -o tags

rebuild:
	        make clean
			        make

#write_fifo: test_write_fifo.c
#	gcc test_write_fifo.c -g -o write_fifo
#read_fifo: test_read_fifo.c
#	gcc test_read_fifo.c -g -o read_fifo

