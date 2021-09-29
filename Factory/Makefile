CXX 		= g++
BIN 		= main
OBJ 		= Product.o Factory.o main.o
SOURCE  	= Product.cpp Factory.cpp main.cpp
CXXFLAGS 	= $( CXXINC ) -std=c++11 -O3 -Wall
RM 			= rm -f

all:main

$(BIN):$(OBJ)
	$(CXX) $(CXXFLAGS) $(SOURCE) -o $(BIN)
#$(OBJ):%.o:%.cpp
#	$(CXX) $(CXXFLAGS) $< -o $@

clean:
		$(RM) $(OBJ) $(BIN)

ctags:
	@$(RM) tags
	@ctags -R -h ".c.cpp.h" --exclude=*.hpp --append=yes -o tags

rebuild:
			make clean
			make
			
.PHONY:cleanTemp
cleanTemp:
		-$(RM) $(OBJ)
