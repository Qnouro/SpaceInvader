PROGS = Game
OBJS  = Grid.o Game.o Player.o Entities.o Console.o
 
CPPOPTS = -std=c++17 -Wall -Wextra -pedantic
LINKOPT = -std=c++17 -lncurses
 
all: $(PROGS)
 
%.o: src/%.cpp
	g++ $(CPPOPTS) -c $<
 
Game: src/Game.o src/Player.o src/Entities.o src/Console.o src/Grid.o
	g++ -o $@ $^  $(LINKOPT)

clean:
	rm -f $(PROGS) $(OBJS)
