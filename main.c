#include <stdio.h>
#include <stdlib.h>

void clrscr(void)
{
	system("cls");
}

void showBoard(void)
{
	int positionsY[8];
	int positionsX[8];

	for (int y = 0; y < 8; y++)
	{
		positionsY[y] = y;
		printf("\n");
		for (int x = 0; x < 8; x++)
		{
			positionsX[x] = x;
			if (x % 2 == 0 && y % 2 == 0)
			{
				printf("%c", 178);
			}
			else if (y % 2 != 0 && x % 2 == 0)
			{
				printf("%c", 177);
			}
			else if (y % 2 == 0 && x % 2 != 0)
			{
				printf("%c", 177);
			}
			else if (y % 2 != 0 && x % 2 != 0)
			{
				printf("%c", 178);
			}
		}
	}
	printf("\n");
}

void showWelcomeMessage(void){
	clrscr();
	printf("==========================\nJ O G O  D E  D A M A S\n\n==========================\n\n");
}

void showMenu(void)
{
	int selectoption = 0;
	do
	{
		showWelcomeMessage();
		printf("1 - Novo jogo\n");
		printf("2 - Regras do jogo\n");
		printf("3 - Sair do jogo\n\n");
		printf("Escolha uma op��o: ");
		scanf("%d", &selectoption);
		switch (selectoption)
		{
		case 1:
		{
			showBoard();
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

			system("pause");
			break;
		}

		case 3:
		{
			showWelcomeMessage();
			printf("Que pena, voc� escolheu sair.");
			system("color 7");
			exit(0);
			break;
		}

		default:
		{
			system("color 4");
			showWelcomeMessage();
			printf("OP��O INV�LIDA\n\n");
			system("pause");
			clrscr();
			break;
		}
		}
	} while (selectoption != 0);
}

int main()
{
	showMenu();
	return 0;
}