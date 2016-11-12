run: single_node.o linked_list.o Game.o PlayGame.o
	g++ single_node.o linked_list.o Game.o PlayGame.o -o run
PlayGame.o: PlayGame.cpp
	g++ -c PlayGame.cpp
Game.o: Game.h Game.cpp
	g++ -c Game.cpp
linked_list.o: linked_list.h linked_list.cpp
	g++ -c linked_list.cpp
single_node.o: single_node.h single_node.cpp
	g++ -c single_node.cpp
clean:
	rm -rf *.o
	rm -rf run
