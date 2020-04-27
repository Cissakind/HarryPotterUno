#include "BuildUnoGame.h"
#include <allegro5/bitmap_io.h>

using namespace std;

BuildUnoGame::BuildUnoGame()
{
	cout << "BuildUnoGame constructed" << endl;
}

UnoGame BuildUnoGame::getGame()
{
	return game;
}

 UnoGame BuildUnoGame::buildUno()
 {

 	//init cartas
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
;

 	game.addPlayer(UnoPlayer(0));
 	game.addPlayer(UnoPlayer(1));
 	game.addPlayer(UnoPlayer(2));
  	game.addPlayer(UnoPlayer(3));

 	game.setCurrentState(UnoState::STARTGAME);
  	game.setCurrentPlayer(3,1);
 	//game.getCurrentState().createState(game.getPlayers()[0]);

 	return game;
 }