# LSP's servem para mostrar erros no código, sugestões, ações de navegação, etc
# Mudamos o CC para clang++ pois usamos o clangd como LSP, por coerência.
# Por default, o clangd assume que o arquivo que você está editando será
# compilado com um comando simples, ex.: `clang++ main.cpp`
# Isso gera problemas quando seus arquivos incluem cabeçalhos em outros
# diretórios, quando flags de compilação específicas são usadas, etc.
# Para acalmar o clangd sobre essas mudanças, instalamos o bear, que cria um
# arquivo chamado compile_commands.json através deste Makefile, que informa como
# o projeto será compilado de fato (ao invés do default simples).
# O clangd sempre procura o compile_commands.json no diretório acima dos
# arquivos observados, e encontrando um gerado corretamente, para de apontar
# erros indevidamente. Como o compile_commands.json contém as informações do
# Makefile, se fizer mudanças neste Makefile e estiver usando o clangd,
# execute `make clean` e `bear make`, nessa ordem, para gerar/atualizar o
# compile_commands.json correspondente ao Makefile mais atual.

CC := clang++
CXX_FLAGS := -g -Wall -O3 -std=c++17

SRCDIR := src
BUILDDIR := build

TARGET := main
SRCEXT := cpp

SRC := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJ := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SRC:.$(SRCEXT)=.o))

INCLUDE := -Iinclude/ -I/usr/include/allegro5/
LIBS=`pkg-config --cflags --libs allegro-5 allegro_acodec-5 allegro_audio-5 allegro_color-5 allegro_dialog-5 allegro_font-5 allegro_image-5 allegro_main-5 allegro_memfile-5 allegro_physfs-5 allegro_primitives-5 allegro_ttf-5` -lm

all: $(OBJ) $(TARGET)

$(TARGET): $(OBJ)
	g++ $^ $(INCLUDE) $(LIBS) -o $@ $(CXX_FLAGS)

$(BUILDDIR)/Card.o: src/Card.cpp include/Card.h
	g++ -c src/Card.cpp -o $@ $(INCLUDE) $(LIBS) $(CXX_FLAGS)

$(BUILDDIR)/Deck.o: src/Deck.cpp include/Deck.h include/Card.h
	g++ -c src/Deck.cpp -o $@ $(INCLUDE) $(LIBS) $(CXX_FLAGS)

$(BUILDDIR)/UnoPlayer.o: src/UnoPlayer.cpp include/UnoPlayer.h include/Deck.h
	g++ -c src/UnoPlayer.cpp -o $@ $(INCLUDE) $(LIBS) $(CXX_FLAGS)

$(BUILDDIR)/UnoGame.o: src/UnoGame.cpp include/UnoGame.h include/UnoPlayer.h include/State.h
	g++ -c src/UnoGame.cpp -o $@ $(INCLUDE) $(LIBS) $(CXX_FLAGS)

$(BUILDDIR)/BuildUnoGame.o: src/BuildUnoGame.cpp include/BuildUnoGame.h include/UnoGame.h include/MenuState.h
	g++ -c src/BuildUnoGame.cpp -o $@ $(INCLUDE) $(LIBS) $(CXX_FLAGS)

$(BUILDDIR)/State.o: src/State.cpp include/State.h include/UnoGame.h 
	g++ -c src/State.cpp -o $@ $(INCLUDE) $(LIBS) $(CXX_FLAGS)

$(BUILDDIR)/StartingUno.o: src/StartingUno.cpp include/StartingUno.h include/State.h include/StartingPlay.h include/EndingGame.h 
	g++ -c src/StartingUno.cpp -o $@ $(INCLUDE) $(LIBS) $(CXX_FLAGS)

$(BUILDDIR)/StartingPlay.o: src/StartingPlay.cpp include/StartingPlay.h include/State.h include/EndingPlay.h
	g++ -c src/StartingPlay.cpp -o $@ $(INCLUDE) $(LIBS) $(CXX_FLAGS)

$(BUILDDIR)/StartingBotPlay.o: src/StartingBotPlay.cpp include/StartingBotPlay.h include/State.h include/EndingPlay.h
	g++ -c src/StartingBotPlay.cpp -o $@ $(INCLUDE) $(LIBS) $(CXX_FLAGS)

$(BUILDDIR)/EndingPlay.o: src/EndingPlay.cpp include/EndingPlay.h include/State.h include/StartingPlay.h
	g++ -c src/EndingPlay.cpp -o $@ $(INCLUDE) $(LIBS) $(CXX_FLAGS)

$(BUILDDIR)/EndingGame.o: src/EndingGame.cpp include/EndingGame.h include/State.h include/GameOver.h 
	g++ -c src/EndingGame.cpp -o $@ $(INCLUDE) $(LIBS) $(CXX_FLAGS)

$(BUILDDIR)/GameOver.o: src/GameOver.cpp include/GameOver.h include/State.h include/EndingGame.h 
	g++ -c src/GameOver.cpp -o $@ $(INCLUDE) $(LIBS) $(CXX_FLAGS)

$(BUILDDIR)/MenuState.o: src/MenuState.cpp include/MenuState.h include/State.h include/EndingGame.h 
	g++ -c src/MenuState.cpp -o $@ $(INCLUDE) $(LIBS) $(CXX_FLAGS)

$(BUILDDIR)/main.o: src/main.cpp include/BuildUnoGame.h include/EndingGame.h
	g++ -c src/main.cpp -o $@ $(INCLUDE) $(LIBS) $(CXX_FLAGS)

clean:
	$(RM) -r $(BUILDDIR)/* $(TARGET)

.PHONY: clean
