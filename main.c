#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#endif
#include <ncurses/curses.h>

typedef struct player {
	int positionX;
	int positionY;
}player;

int timeInMinutes = 0;
int timeInSeconds = 1;
int screenX = 0;
int screenY = 0;

char commandBase[7] = "color ";
WINDOW *firstWindow;
WINDOW *timerWindow;

void clrscr(void)
{
	system("cls");
}

void setColor(char *color)
{
	int colorAsInt = (int)color;
	if (colorAsInt >= 48 && colorAsInt <= 55)
	{
		system(strcat(commandBase, color));
	}
}

void pause(void)
{
	system("pause");
}

WINDOW *createWindow(int height, int width, int x, int y)
{
	WINDOW *window = newwin(height, width, x, y);
	return window;
}

// TODO: format the output correctly
void showTimer(WINDOW *window)
{
	do
	{
		wclear(window);
		wprintw(window, "0%i:%i\n", timeInMinutes, timeInSeconds);
		Sleep(1000);
		wrefresh(window);
		timeInSeconds++;
		if (timeInSeconds % 60 == 0)
		{
			timeInMinutes++;
			timeInSeconds = 0;
		}
	} while (timeInMinutes < 3);
}

void showBoard(void)
{
	firstWindow = createWindow(8, 14, screenY / 2.3, screenX / 2.3);
	timerWindow = createWindow(5, 5, 0, 0);
	for (int lines = 0; lines < 8; lines++)
	{
		for (int cols = 0; cols < 14; cols++)
		{
			if (lines % 2 == 0 && cols % 2 == 0)
			{
				waddch(firstWindow, ACS_CKBOARD);
			}
			else if (cols % 2 != 0 && lines % 2 == 0)
			{
				wprintw(firstWindow, "%c", 175);
			}
			else if (cols % 2 == 0 && lines % 2 != 0)
			{
				wprintw(firstWindow, "%c", 175);
			}
			else if (cols % 2 != 0 && lines % 2 != 0)
			{
				waddch(firstWindow, ACS_CKBOARD);
			}
		}
	}
	printw("\n");
}

void showWelcomeMessage(void)
{
	clrscr();
	printf("==========================\n\nJ O G O  D E  D A M A S\n\n==========================\n\n");
}

void init(void)
{
	initscr();
	noecho();
	curs_set(0);
	refresh();
	getmaxyx(stdscr, screenY, screenX);
	mvwin(firstWindow, 5, 30);
	showBoard();
	wrefresh(firstWindow);
	wprintw(timerWindow, "00:00");
	wrefresh(timerWindow);
	showTimer(timerWindow);
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
		printf("Escolha uma opção: ");
		scanf("%d", &selectedOption);
		switch (selectedOption)
		{
		case 1:
		{
			init();
			pause();
			break;
		}

		case 2:
		{
			showWelcomeMessage();
			puts("=================== Descri��o ===================\n");
			puts("* Jogadores - 2.");
			puts("* Pe�as - 24 pe�as, 12 brancas e 12 pretas.");
			puts("* Tabuleiro - tabuleiro de 64 casas, claras e escuras.");
			puts("* Distribui��o - 12 pe�as da mesma cor para cada jogador, posicionadas nas casas escuras, ocupando as tr�s linhas mais pr�ximas de cada jogador.\n");
			puts("=================== Objetivo ===================\n");
			puts("* Capturar todas as pe�as do oponente ou deix�-lo impossibilitado de mover-se.\n");
			puts("=================== Regras ===================\n");
			puts("* Andar uma casa por vez.");
			puts("* Comer uma pe�a por vez.");
			puts("* O jogo dura 3 minutos.\n");
			pause();
			break;
		}

		case 3:
		{
			clrscr();
			setColor("7");
			printf("Que pena, voc� escolheu sair.");
			exit(EXIT_SUCCESS);
			break;
		}

		default:
		{
			clrscr();
			setColor("4");
			showWelcomeMessage();
			printf("OP��O INV�LIDA\n\n");
			pause();
			setColor("7");
			break;
		}
		}
	} while (selectedOption != 0);
}

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "");
	showMenu();
	return 0;
}
