LIBS=`pkg-config --cflags --libs allegro-5 allegro_acodec-5 allegro_audio-5 allegro_color-5 allegro_dialog-5 allegro_font-5 allegro_image-5 allegro_main-5 allegro_memfile-5 allegro_physfs-5 allegro_primitives-5 allegro_ttf-5` -lm

OBJ=main.o Card.o Deck.o UnoPlayer.o UnoGame.o BuildUnoGame.o State.o

INCLUDES=-I/usr/include/allegro5/

all: main 


main: main.o
	gcc -o main main.o $(LIBS) 

main.o: main.cpp UnoGame.h UnoPlayer.h State.h
	gcc -c main.cpp $(LIBS) 


Card.o: Card.cpp Card.h
	gcc -c Card.cpp $(LIBS) 


Deck.o: Deck.cpp Deck.h Card.h
	gcc -c Deck.cpp $(LIBS) 


UnoPlayer.o: UnoPlayer.cpp UnoPlayer.h Deck.h
	gcc -c UnoPlayer.cpp $(LIBS) 


UnoGame.o: UnoGame.cpp UnoGame.h UnoPlayer.h State.h
	gcc -c UnoGame.cpp $(LIBS)

BuildUnoGame.o: BuildUnoGame.cpp BuildUnoGame.h UnoGame.h State.h
	gcc -c BuildUnoGame.cpp $(LIBS) 

State.o: State.cpp State.h UnoGame.h
	gcc -c State.cpp $(LIBS) 


clean:
	rm -f $(OBJ)
	rm -f main




