#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Portuguese");
	int selectoption = 0;
	do
	{
		system("color 7");
		puts("==========================\n");
		printf("J O G O  D E  D A M A S\n");
		puts("\n==========================\n\n");

		puts("1 - Novo jogo\n");
		puts("2 - Regras do jogo\n");
		puts("3 - Sair do jogo\n\n");
		printf("Escolha uma op��o: ");
		scanf("%d", &selectoption);
		switch (selectoption)
		{
		case 1:
		{
			// adds new game here
			break;
		}

		case 2:
		{
			system("cls");
			puts("=================== Descri��o ===================\n");
			puts("* Jogadores - 2.");
			puts("* Pe�as - 24 pe�as, 12 brancas e 12 pretas.");
			puts("* Tabuleiro - tabuleiro de 64 casas, claras e escuras.");
			puts("* Distribui��o - 12 pe�as da mesma cor para cada jogador, posicionadas nas casas escuras, ocupando as tr�s linhas mais pr�ximas de cada jogador.\n");
			puts("=================== Objetivo ===================\n");
			puts("* Capturar todas as pe�as do oponente ou deix�-lo impossibilitado de mover.\n");
			puts("=================== Regras ===================\n");
			puts("* Andar uma casa por vez.");
			puts("* Comer uma pe�a por vez.");
			puts("* O jogo dura 3 minutos.\n");

			system("pause");
			system("cls");
			break;
		}

		case 3:
		{
			system("cls");
			puts("==========================\n");
			printf("J O G O  D E  D A M A S\n");
			puts("\n==========================\n\n");
			printf("Que pena, voc� escolheu sair.");
			break;
		}

		default:
		{
			system("cls");
			system("color 4");
			puts("==========================\n");
			printf("J O G O  D E  D A M A S\n");
			puts("\n==========================\n\n");
			printf("OP��O INV�LIDA\n\n");
			system("pause");
			system("cls");
			break;
		}
		}
	} while (selectoption != 3);
	return 0;
}
