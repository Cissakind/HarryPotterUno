#include "BuildUnoGame.h"
#include <allegro5/bitmap_io.h>

BuildUnoGame::BuildUnoGame()
{
	cout << "BuildUnoGame constructed" << endl;
}

BuildUnoGame::~BuildUnoGame()
{
    for(int i = 0; i < 14; i++)
    {
        al_destroy_bitmap(cardsverm[i]);
        al_destroy_bitmap(cardsverd[i]);
        al_destroy_bitmap(cardsamar[i]);
        al_destroy_bitmap(cardsazul[i]);
    }

    for(int i = 0; i < 2; i++)
    {
        al_destroy_bitmap(cardsneu[i]);
    }


    al_destroy_bitmap(cardsback);


    // delete cardsamar;
    // delete cardsazul;
    // delete cardsverd;
    // delete cardsverm;
    // delete cardsneu;
    // delete cardsback;

    al_destroy_font(font);
    al_destroy_bitmap(fundo);
}

UnoGame BuildUnoGame::getGame()
{
	return game;
}

UnoGame &BuildUnoGame::buildUno()
{

 	game.getDeck().addInitialCard(1, Card::VERMELHO, 0, 0, 0);
 	game.getDeck().addInitialCard(2, Card::VERMELHO, 1, 0, 0);
 	game.getDeck().addInitialCard(3, Card::VERMELHO, 2, 0, 0);
	game.getDeck().addInitialCard(4, Card::VERMELHO, 3, 0, 0);
 	game.getDeck().addInitialCard(5, Card::VERMELHO, 4, 0, 0);
 	game.getDeck().addInitialCard(6, Card::VERMELHO, 5, 0, 0);
 	game.getDeck().addInitialCard(7, Card::VERMELHO, 6, 0, 0);
 	game.getDeck().addInitialCard(8, Card::VERMELHO, 7, 0, 0);
 	game.getDeck().addInitialCard(9, Card::VERMELHO, 8, 0, 0);
 	game.getDeck().addInitialCard(10, Card::VERMELHO, 9, 0, 0);
 	game.getDeck().addInitialCard(11, Card::VERMELHO, 10, 0, 1);
 	game.getDeck().addInitialCard(12, Card::VERMELHO, 11, 0, 3);
 	game.getDeck().addInitialCard(13, Card::VERMELHO, 12, 1, 0);
 	game.getDeck().addInitialCard(14, Card::VERMELHO, 13, 2, 0);

 	game.getDeck().addInitialCard(15, Card::VERMELHO, 0, 0, 0);
 	game.getDeck().addInitialCard(16, Card::VERMELHO, 1, 0, 0);
 	game.getDeck().addInitialCard(17, Card::VERMELHO, 2, 0, 0);
	game.getDeck().addInitialCard(18, Card::VERMELHO, 3, 0, 0);
 	game.getDeck().addInitialCard(19, Card::VERMELHO, 4, 0, 0);
 	game.getDeck().addInitialCard(20, Card::VERMELHO, 5, 0, 0);
 	game.getDeck().addInitialCard(21, Card::VERMELHO, 6, 0, 0);
 	game.getDeck().addInitialCard(22, Card::VERMELHO, 7, 0, 0);
 	game.getDeck().addInitialCard(23, Card::VERMELHO, 8, 0, 0);
 	game.getDeck().addInitialCard(24, Card::VERMELHO, 9, 0, 0);
 	game.getDeck().addInitialCard(25, Card::VERMELHO, 10, 0, 1);
 	game.getDeck().addInitialCard(26, Card::VERMELHO, 11, 0, 3);
 	game.getDeck().addInitialCard(27, Card::VERMELHO, 12, 1, 0);
 	game.getDeck().addInitialCard(28, Card::VERMELHO, 13, 2, 0);

 	game.getDeck().addInitialCard(29, Card::VERDE, 0, 0, 0);
 	game.getDeck().addInitialCard(30, Card::VERDE, 1, 0, 0);
 	game.getDeck().addInitialCard(31, Card::VERDE, 2, 0, 0);
	game.getDeck().addInitialCard(32, Card::VERDE, 3, 0, 0);
 	game.getDeck().addInitialCard(33, Card::VERDE, 4, 0, 0);
 	game.getDeck().addInitialCard(34, Card::VERDE, 5, 0, 0);
 	game.getDeck().addInitialCard(35, Card::VERDE, 6, 0, 0);
 	game.getDeck().addInitialCard(36, Card::VERDE, 7, 0, 0);
 	game.getDeck().addInitialCard(37, Card::VERDE, 8, 0, 0);
 	game.getDeck().addInitialCard(38, Card::VERDE, 9, 0, 0);
 	game.getDeck().addInitialCard(39, Card::VERDE, 10, 0, 1);
 	game.getDeck().addInitialCard(40, Card::VERDE, 11, 0, 3);
 	game.getDeck().addInitialCard(41, Card::VERDE, 12, 1, 0);
 	game.getDeck().addInitialCard(42, Card::VERDE, 13, 2, 0);

 	game.getDeck().addInitialCard(43, Card::VERDE, 0, 0, 0);
 	game.getDeck().addInitialCard(44, Card::VERDE, 1, 0, 0);
 	game.getDeck().addInitialCard(45, Card::VERDE, 2, 0, 0);
	game.getDeck().addInitialCard(46, Card::VERDE, 3, 0, 0);
 	game.getDeck().addInitialCard(47, Card::VERDE, 4, 0, 0);
 	game.getDeck().addInitialCard(48, Card::VERDE, 5, 0, 0);
 	game.getDeck().addInitialCard(49, Card::VERDE, 6, 0, 0);
 	game.getDeck().addInitialCard(50, Card::VERDE, 7, 0, 0);
 	game.getDeck().addInitialCard(51, Card::VERDE, 8, 0, 0);
 	game.getDeck().addInitialCard(52, Card::VERDE, 9, 0, 0);
 	game.getDeck().addInitialCard(53, Card::VERDE, 10, 0, 1);
 	game.getDeck().addInitialCard(54, Card::VERDE, 11, 0, 3);
 	game.getDeck().addInitialCard(55, Card::VERDE, 12, 1, 0);
 	game.getDeck().addInitialCard(56, Card::VERDE, 13, 2, 0);

 	game.getDeck().addInitialCard(57, Card::AMARELO, 0, 0, 0);
 	game.getDeck().addInitialCard(58, Card::AMARELO, 1, 0, 0);
 	game.getDeck().addInitialCard(59, Card::AMARELO, 2, 0, 0);
	game.getDeck().addInitialCard(60, Card::AMARELO, 3, 0, 0);
 	game.getDeck().addInitialCard(61, Card::AMARELO, 4, 0, 0);
 	game.getDeck().addInitialCard(62, Card::AMARELO, 5, 0, 0);
 	game.getDeck().addInitialCard(63, Card::AMARELO, 6, 0, 0);
 	game.getDeck().addInitialCard(64, Card::AMARELO, 7, 0, 0);
 	game.getDeck().addInitialCard(65, Card::AMARELO, 8, 0, 0);
 	game.getDeck().addInitialCard(66, Card::AMARELO, 9, 0, 0);
 	game.getDeck().addInitialCard(67, Card::AMARELO, 10, 0, 1);
 	game.getDeck().addInitialCard(68, Card::AMARELO, 11, 0, 3);
 	game.getDeck().addInitialCard(69, Card::AMARELO, 12, 1, 0);
 	game.getDeck().addInitialCard(70, Card::AMARELO, 13, 2, 0);

 	game.getDeck().addInitialCard(71, Card::AMARELO, 0, 0, 0);
 	game.getDeck().addInitialCard(72, Card::AMARELO, 1, 0, 0);
 	game.getDeck().addInitialCard(73, Card::AMARELO, 2, 0, 0);
	game.getDeck().addInitialCard(74, Card::AMARELO, 3, 0, 0);
 	game.getDeck().addInitialCard(75, Card::AMARELO, 4, 0, 0);
 	game.getDeck().addInitialCard(76, Card::AMARELO, 5, 0, 0);
 	game.getDeck().addInitialCard(77, Card::AMARELO, 6, 0, 0);
 	game.getDeck().addInitialCard(78, Card::AMARELO, 7, 0, 0);
 	game.getDeck().addInitialCard(79, Card::AMARELO, 8, 0, 0);
 	game.getDeck().addInitialCard(80, Card::AMARELO, 9, 0, 0);
 	game.getDeck().addInitialCard(81, Card::AMARELO, 10, 0, 1);
 	game.getDeck().addInitialCard(82, Card::AMARELO, 11, 0, 3);
 	game.getDeck().addInitialCard(83, Card::AMARELO, 12, 1, 0);
 	game.getDeck().addInitialCard(84, Card::AMARELO, 13, 2, 0);

 	game.getDeck().addInitialCard(85, Card::AZUL, 0, 0, 0);
 	game.getDeck().addInitialCard(86, Card::AZUL, 1, 0, 0);
 	game.getDeck().addInitialCard(87, Card::AZUL, 2, 0, 0);
	game.getDeck().addInitialCard(88, Card::AZUL, 3, 0, 0);
 	game.getDeck().addInitialCard(89, Card::AZUL, 4, 0, 0);
 	game.getDeck().addInitialCard(90, Card::AZUL, 5, 0, 0);
 	game.getDeck().addInitialCard(91, Card::AZUL, 6, 0, 0);
 	game.getDeck().addInitialCard(92, Card::AZUL, 7, 0, 0);
 	game.getDeck().addInitialCard(93, Card::AZUL, 8, 0, 0);
 	game.getDeck().addInitialCard(94, Card::AZUL, 9, 0, 0);
 	game.getDeck().addInitialCard(95, Card::AZUL, 10, 0, 1);
 	game.getDeck().addInitialCard(96, Card::AZUL, 11, 0, 3);
 	game.getDeck().addInitialCard(97, Card::AZUL, 12, 1, 0);
 	game.getDeck().addInitialCard(98, Card::AZUL, 13, 2, 0);

 	game.getDeck().addInitialCard(99, Card::AZUL, 0, 0, 0);
 	game.getDeck().addInitialCard(100, Card::AZUL, 1, 0, 0);
 	game.getDeck().addInitialCard(101, Card::AZUL, 2, 0, 0);
	game.getDeck().addInitialCard(102, Card::AZUL, 3, 0, 0);
 	game.getDeck().addInitialCard(103, Card::AZUL, 4, 0, 0);
 	game.getDeck().addInitialCard(104, Card::AZUL, 5, 0, 0);
 	game.getDeck().addInitialCard(105, Card::AZUL, 6, 0, 0);
 	game.getDeck().addInitialCard(106, Card::AZUL, 7, 0, 0);
 	game.getDeck().addInitialCard(107, Card::AZUL, 8, 0, 0);
 	game.getDeck().addInitialCard(108, Card::AZUL, 9, 0, 0);
 	game.getDeck().addInitialCard(109, Card::AZUL, 10, 0, 1);
 	game.getDeck().addInitialCard(110, Card::AZUL, 11, 0, 3);
 	game.getDeck().addInitialCard(111, Card::AZUL, 12, 1, 0);
 	game.getDeck().addInitialCard(112, Card::AZUL, 13, 2, 0);

 	game.getDeck().addInitialCard(113, Card::NEUTRO, 14, 0, 2);
 	game.getDeck().addInitialCard(114, Card::NEUTRO, 14, 0, 2);
 	game.getDeck().addInitialCard(115, Card::NEUTRO, 14, 0, 2);
 	game.getDeck().addInitialCard(116, Card::NEUTRO, 14, 0, 2);
 	game.getDeck().addInitialCard(117, Card::NEUTRO, 15, 4, 2);
 	game.getDeck().addInitialCard(118, Card::NEUTRO, 15, 4, 2);
 	game.getDeck().addInitialCard(119, Card::NEUTRO, 15, 4, 2);
 	game.getDeck().addInitialCard(120, Card::NEUTRO, 15, 4, 2);

    // cardsverm = new ALLEGRO_BITMAP*[14]();
    // cardsverd = new ALLEGRO_BITMAP*[14]();
    // cardsamar = new ALLEGRO_BITMAP*[14]();
    // cardsazul = new ALLEGRO_BITMAP*[14]();
    // cardsneu = new ALLEGRO_BITMAP*[2]();
    // cardsback = new ALLEGRO_BITMAP*[1]();

 	cardsverm[0] = al_load_bitmap("assets/cards/vermelho0.png");
    cardsverm[1] = al_load_bitmap("assets/cards/vermelho1.png");
    cardsverm[2] = al_load_bitmap("assets/cards/vermelho2.png");
    cardsverm[3] = al_load_bitmap("assets/cards/vermelho3.png");
    cardsverm[4] = al_load_bitmap("assets/cards/vermelho4.png");
    cardsverm[5] = al_load_bitmap("assets/cards/vermelho5.png"); 
    cardsverm[6] = al_load_bitmap("assets/cards/vermelho6.png");
    cardsverm[7] = al_load_bitmap("assets/cards/vermelho7.png");
    cardsverm[8] = al_load_bitmap("assets/cards/vermelho8.png");
    cardsverm[9] = al_load_bitmap("assets/cards/vermelho9.png");
    cardsverm[10] = al_load_bitmap("assets/cards/vermelhoskip.png");
    cardsverm[11] = al_load_bitmap("assets/cards/vermelhoreverse.png");
    cardsverm[12] = al_load_bitmap("assets/cards/vermelhomais1.png");
    cardsverm[13] = al_load_bitmap("assets/cards/vermelhomais2.png");

    cardsverd[0] = al_load_bitmap("assets/cards/verde0.png");
    cardsverd[1] = al_load_bitmap("assets/cards/verde1.png");
    cardsverd[2] = al_load_bitmap("assets/cards/verde2.png");
    cardsverd[3] = al_load_bitmap("assets/cards/verde3.png");
    cardsverd[4] = al_load_bitmap("assets/cards/verde4.png");
    cardsverd[5] = al_load_bitmap("assets/cards/verde5.png");
    cardsverd[6] = al_load_bitmap("assets/cards/verde6.png");
    cardsverd[7] = al_load_bitmap("assets/cards/verde7.png");
    cardsverd[8] = al_load_bitmap("assets/cards/verde8.png");
    cardsverd[9] = al_load_bitmap("assets/cards/verde9.png");
    cardsverd[10] = al_load_bitmap("assets/cards/verdeskip.png");
    cardsverd[11] = al_load_bitmap("assets/cards/verdereverse.png");
    cardsverd[12] = al_load_bitmap("assets/cards/verdemais1.png");
    cardsverd[13] = al_load_bitmap("assets/cards/verdemais2.png");

    cardsamar[0] = al_load_bitmap("assets/cards/amarelo0.png");
    cardsamar[1] = al_load_bitmap("assets/cards/amarelo1.png");
    cardsamar[2] = al_load_bitmap("assets/cards/amarelo2.png");
    cardsamar[3] = al_load_bitmap("assets/cards/amarelo3.png");
    cardsamar[4] = al_load_bitmap("assets/cards/amarelo4.png");
    cardsamar[5] = al_load_bitmap("assets/cards/amarelo5.png");
    cardsamar[6] = al_load_bitmap("assets/cards/amarelo6.png");
    cardsamar[7] = al_load_bitmap("assets/cards/amarelo7.png");
    cardsamar[8] = al_load_bitmap("assets/cards/amarelo8.png");
    cardsamar[9] = al_load_bitmap("assets/cards/amarelo9.png");
    cardsamar[10] = al_load_bitmap("assets/cards/amareloskip.png");
    cardsamar[11] = al_load_bitmap("assets/cards/amareloreverse.png");
    cardsamar[12] = al_load_bitmap("assets/cards/amarelomais1.png");
    cardsamar[13] = al_load_bitmap("assets/cards/amarelomais2.png");

    cardsazul[0] = al_load_bitmap("assets/cards/azul0.png");
    cardsazul[1] = al_load_bitmap("assets/cards/azul1.png");
    cardsazul[2] = al_load_bitmap("assets/cards/azul2.png");
    cardsazul[3] = al_load_bitmap("assets/cards/azul3.png");
    cardsazul[4] = al_load_bitmap("assets/cards/azul4.png");
    cardsazul[5] = al_load_bitmap("assets/cards/azul5.png");
    cardsazul[6] = al_load_bitmap("assets/cards/azul6.png");
    cardsazul[7] = al_load_bitmap("assets/cards/azul7.png");
    cardsazul[8] = al_load_bitmap("assets/cards/azul8.png");
    cardsazul[9] = al_load_bitmap("assets/cards/azul9.png");
    cardsazul[10] = al_load_bitmap("assets/cards/azulskip.png");
    cardsazul[11] = al_load_bitmap("assets/cards/azulreverse.png");
    cardsazul[12] = al_load_bitmap("assets/cards/azulmais1.png");
    cardsazul[13] = al_load_bitmap("assets/cards/azulmais2.png");

    cardsneu[0] = al_load_bitmap("assets/cards/neutro0.png");
    cardsneu[1] = al_load_bitmap("assets/cards/neutro4.png");

    cardsback = al_load_bitmap("assets/cards/back.png");

    for(int i=0; i<14; i++)
    {
        game.getDeck().getCardDeck()[i].setImage(cardsverm[i]);
        game.getDeck().getCardDeck()[i+14].setImage(cardsverm[i]);
    }

    for(int i=28; i<42; i++)
    {
        game.getDeck().getCardDeck()[i].setImage(cardsverd[i-28]);
        game.getDeck().getCardDeck()[i+14].setImage(cardsverd[i-28]);  
    }

    for(int i=56; i<70; i++)
    {
        game.getDeck().getCardDeck()[i].setImage(cardsamar[i-56]); 
        game.getDeck().getCardDeck()[i+14].setImage(cardsamar[i-56]); 
    }

    for(int i=84; i<98; i++)
    {
        game.getDeck().getCardDeck()[i].setImage(cardsazul[i-84]); 
        game.getDeck().getCardDeck()[i+14].setImage(cardsazul[i-84]); 
    }

    for(int i=112; i<116; i++)
    {
        game.getDeck().getCardDeck()[i].setImage(cardsneu[0]); 
        game.getDeck().getCardDeck()[i+4].setImage(cardsneu[1]); 
    }

    for(int i=0; i<120; i++)
    {
        game.getDeck().getCardDeck()[i].setBackImage(cardsback); 
    }

    fundo = al_load_bitmap("assets/cards/background.png");
    game.setFundo(fundo);

    font = al_load_font("assets/papyrus.ttf", 43, 0);
    game.setFont(font);

 	game.addPlayer(UnoPlayer(0));
 	game.addPlayer(UnoPlayer(1));
 	game.addPlayer(UnoPlayer(2));
  	game.addPlayer(UnoPlayer(3));

  	game.setCurrentPlayer(3,1);
 	game.setCurrentState(new MenuState());

 	return game;
}