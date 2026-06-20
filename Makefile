CXX = g++
CXXFLAGS = -g -Wall -Werror
EXECS = blackjack

all: $(EXECS)
blackjack: main.o player.o card.o
	$(CXX) $(CXXFLAGS) -o $@ $^
clean:
	rm -f *.o $(EXECS)