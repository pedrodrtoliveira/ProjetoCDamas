#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#endif
#include <ncurses/ncurses.h>
#define ERROR_COLOR init_pair(1, COLOR_BLACK, COLOR_RED)

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
WINDOW *headerWindow;

void clrscr(void)
{
	system("cls");
}

void setColor()
{
	// int colorAsInt = (int)color;
	// if (colorAsInt >= 48 && colorAsInt <= 55)
	// {
	// 	system(strcat(commandBase, color));
	// }
	if (has_colors()) {
		start_color();
		attron(COLOR_PAIR(ERROR_COLOR));
		refresh();
	} else {
		endwin();
		printf("Seu terminal não possui compatibilidade de cores.");
		exit(1);
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
void header(WINDOW *window)
{
	wprintw(window, "==========================\nJ O G O  D E  D A M A S\n==========================");
}
void showBoard(void)
{
	firstWindow = createWindow(8, 14, screenY / 2.3, screenX / 2.3);
	wattron(firstWindow, ERROR_COLOR);
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

void initGame(void)
{
	initscr();
	start_color();
	noecho();
	curs_set(0);
	setColor();
	refresh();
	getmaxyx(stdscr, screenY, screenX);
	timerWindow = createWindow(5, 5, 0, 0);
	mvwin(firstWindow, 5, 30);
	showBoard();
	header(headerWindow);
	wrefresh(headerWindow);
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
		printf("Escolha uma opçao: ");
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
			clrscr();
			setColor();
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
			setColor();
			break;
		}
		}
	} while (selectedOption != 0);
}

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "");
	setColor();
	showMenu();
	return 0;
}
