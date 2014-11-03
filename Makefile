
# vnd Makefile

SH=/bin/sh
BP=~/boost_1_54_0
VP=~/vde2-2.3.2
CC=g++
CFL=-I $(BP) -I $(VP)/include
LFL=-L $(BP)/stage/lib \
	-lrt -lpthread \
    -lboost_chrono -lboost_regex -lboost_system -lboost_thread \
    -lreadline -lcurses -lvdeplug \
    -lssl -lcrypto
HDR=$(wildcard *.hpp)
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
EXE=vnd

all: $(EXE)

$(EXE): $(OBJ)
	@$(CC) -o $@ $^ $(LFL)

%.o: %.cpp
	@$(CC) -o $@ -c $< $(CFL)

.PHONY: clean cleanall

clean:
	@-/bin/rm -f $(OBJ) *.log

cleanall: clean
	@-/bin/rm -f $(EXE)

# EOF
