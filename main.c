#define NCURSES_WIDECHAR 1

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#endif
#include "checkers.h"
#include <ncurses/curses.h>

int timeInMinutes = 0;
int timeInSeconds = 0;
int screenX = 0;
int screenY = 0;
int middleScreenY = 0;
int middleScreenX = 0;

player p1;

char commandBase[7] = "color ";
WINDOW *boardWindow;
WINDOW *timerWindow;
WINDOW *headerWindow;
WINDOW *positionWindow;

void clrscr(void)
{
	system("cls");
}

void setColor(char *color)
{
	if ((int)color >= 48 && (int)color <= 57)
	{
		system(strcat(commandBase, color));
	}
	else
	{
		printf("Comando Inválido");
		exit(EXIT_FAILURE);
	}
}

void pause(void)
{
	system("pause");
}

WINDOW *createWindow(int height, int width, int y, int x)
{
	WINDOW *window = newwin(height, width, y, x);
	return window;
}

void finishGame(void)
{
	mvprintw(middleScreenY, middleScreenX, "O jogo acabou!");
}

void clearPiece(WINDOW *window, int positionY, int positionX)
{
	wmove(window, positionY, positionX);
	waddch(window, 175);
	wrefresh(window);
}

void movePiece(player p, WINDOW *window)
{
	p.positionY = 0;
	p.positionX = 0;
	keypad(window, TRUE);
	int ch;
	do
	{
		wclear(positionWindow);
		wprintw(positionWindow, "X: %d e Y: %d", p.positionX, p.positionY);
		wrefresh(positionWindow);
		ch = wgetch(window);
		switch (ch)
		{
		case KEY_UP:
			p.positionY++;
			if (p.positionY < 0 || p.positionY > 8)
			{
				p.positionY = 0;
			}
			break;

		case KEY_DOWN:
			p.positionY--;
			if (p.positionY < 0 || p.positionY > 8)
			{
				p.positionY = 0;
			}
			break;

		case KEY_LEFT:
			p.positionX--;
			if (p.positionX < 0 || p.positionX > 8)
			{
				p.positionX = 0;
			}
			break;

		case KEY_RIGHT:
			p.positionX++;
			if (p.positionX < 0 || p.positionX > 8)
			{
				p.positionX = 0;
			}
			break;
		case 'j':
			wmove(window, p.positionY, p.positionX);
			waddch(window, 183);
			wrefresh(window);
			break;
		default:
			break;
		}
	} while (1);
}

void showTimer(WINDOW *window)
{
	do
	{
		wclear(window);
		timeInSeconds++;
		timeInSeconds < 10 ? wprintw(window, "0%i:0%i\n", timeInMinutes, timeInSeconds) : wprintw(window, "0%i:%i\n", timeInMinutes, timeInSeconds);
		Sleep(1000);
		wrefresh(window);
		if (timeInSeconds % 60 == 0)
		{
			timeInSeconds = 0;
			timeInMinutes++;
		}
	} while (timeInMinutes != 3);
	timeInMinutes = 0;
	timeInSeconds = 0;
	wclear(window);
	clear();
	finishGame();
}
void showHeader(WINDOW *window)
{
	wprintw(window, "==========================\n J O G O  D E  D A M A S \n==========================");
}
void showBoard(void)
{
	boardWindow = createWindow(8, 8, middleScreenY, middleScreenX);
	for (int cols = 0; cols < 8; cols++)
	{
		for (int lines = 0; lines < 8; lines++)
		{
			if (lines % 2 == 0 && cols % 2 == 0)
			{
				waddch(boardWindow, ACS_BOARD);
			}
			else if (cols % 2 != 0 && lines % 2 == 0)
			{
				cols <= 2 || cols >= 5 ? waddch(boardWindow, 183) : waddch(boardWindow, 175);
			}
			else if (cols % 2 == 0 && lines % 2 != 0)
			{
				cols <= 2 || cols >= 5 ? waddch(boardWindow, 183) : waddch(boardWindow, 175);
			}
			else if (cols % 2 != 0 && lines % 2 != 0)
			{
				waddch(boardWindow, ACS_BOARD);
			}
		}
	}
	movePiece(p1, boardWindow);
}

void showWelcomeMessage(void)
{
	clrscr();
	printf("\n\n==========================\n\nJ O G O  D E  D A M A S\n\n==========================\n\n");
}

void initGame(void)
{
	setlocale(LC_ALL, ".UTF-8");
	initscr();
	noecho();
	curs_set(0);
	getmaxyx(stdscr, screenY, screenX);
	middleScreenX = screenX / 2.3;
	middleScreenY = screenY / 2.3;
	refresh();
	positionWindow = createWindow(1, 11, 0, 0);
	timerWindow = createWindow(5, 5, screenY - 1, screenX / 2.7);
	headerWindow = createWindow(3, 35, 0, screenX / 2.6);
	mvwin(boardWindow, middleScreenY, middleScreenX);
	showBoard();
	wrefresh(boardWindow);
	wprintw(timerWindow, "00:00");
	wrefresh(timerWindow);
	showHeader(headerWindow);
	wrefresh(headerWindow);
	showTimer(timerWindow);
	wclear(timerWindow);
	getch();
	endwin();
}

void showMenu(void)
{
	int selectedOption = 0;
	do
	{
		showWelcomeMessage();
		printf("1 - Novo jogo\n");
		printf("2 - Regras do jogo\n");
		printf("3 - Sair do jogo\n\n");
		printf("Escolha uma opcao: ");
		scanf("%d", &selectedOption);
		switch (selectedOption)
		{
		case 1:
		{
			clear();
			initGame();
			break;
		}

		case 2:
		{
			showWelcomeMessage();
			puts("=================== Descricao ===================\n");
			puts("* Jogadores - 2.");
			puts("* Pecas - 24 pecas, 12 brancas e 12 pretas.");
			puts("* Tabuleiro - tabuleiro de 64 casas, claras e escuras.");
			puts("* Distribuicao - 12 pecas da mesma cor para cada jogador, posicionadas nas casas escuras, ocupando as tres linhas mais proximas de cada jogador.\n");
			puts("=================== Objetivo ===================\n");
			puts("* Capturar todas as pecas do oponente ou deixa-lo impossibilitado de mover-se.\n");
			puts("=================== Regras ===================\n");
			puts("* Andar uma casa por vez.");
			puts("* Comer uma peca por vez.");
			puts("* O jogo dura 3 minutos.\n");
			pause();
			break;
		}

		case 3:
		{
			setColor("7");
			printf("Que pena, voce escolheu sair.");
			exit(EXIT_SUCCESS);
			break;
		}

		default:
		{
			clrscr();
			setColor("4");
			showWelcomeMessage();
			printf("OPCAO INVALIDA\n\n");
			pause();
			setColor("7");
			break;
		}
		}
	} while (selectedOption != 0);
}

int main(int argc, char *argv[])
{
	showMenu();
	return 0;
}