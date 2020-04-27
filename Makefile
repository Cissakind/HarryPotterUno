LIBS=`pkg-config --cflags --libs allegro-5 allegro_acodec-5 allegro_audio-5 allegro_color-5 allegro_dialog-5 allegro_font-5 allegro_image-5 allegro_main-5 allegro_memfile-5 allegro_physfs-5 allegro_primitives-5 allegro_ttf-5` -lm
CXX_FLAGS=-std=c++2a -g -O3
OBJ=main.o Card.o Deck.o UnoPlayer.o UnoGame.o BuildUnoGame.o State.o

INCLUDES=-I/usr/include/allegro5/

all: Card.o Deck.o UnoPlayer.o UnoGame.o BuildUnoGame.o State.o main.o main

main: $(OBJ)
	g++ $^ $(LIBS) -o $@ $(CXX_FLAGS)

Card.o: Card.cpp Card.h
	g++ -c Card.cpp -o $@ $(LIBS) $(CXX_FLAGS)

Deck.o: Deck.cpp Deck.h Card.h
	g++ -c Deck.cpp -o $@ $(LIBS) $(CXX_FLAGS)

UnoPlayer.o: UnoPlayer.cpp UnoPlayer.h Deck.h
	g++ -c UnoPlayer.cpp -o $@ $(LIBS) $(CXX_FLAGS)

UnoGame.o: UnoGame.cpp UnoGame.h UnoPlayer.h UnoState.h
	g++ -c UnoGame.cpp -o $@ $(LIBS) $(CXX_FLAGS)

BuildUnoGame.o: BuildUnoGame.cpp BuildUnoGame.h UnoGame.h
	g++ -c BuildUnoGame.cpp -o $@ $(LIBS) $(CXX_FLAGS)

State.o: State.cpp State.h UnoPlayer.h 
	g++ -c State.cpp -o $@ $(LIBS) $(CXX_FLAGS)

main.o: main.cpp BuildUnoGame.h UnoGame.h UnoState.h UnoPlayer.h
	g++ -c main.cpp -o $@ $(LIBS) $(CXX_FLAGS)


clean:
	rm *.o main
