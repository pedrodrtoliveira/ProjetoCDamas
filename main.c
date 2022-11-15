#include <stdio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL,"Portuguese");
	int selectoption;
	do{
		puts("==========================\n");	
    	printf("J O G O  D E  D A M A S\n");
    	puts("\n==========================\n\n");
    
    	puts("1 - Novo jogo\n");
    	puts("2 - Regras do jogo\n");
    	puts("3 - Sair do jogo\n\n");
    	printf("Escolha uma opção: ");
    	scanf("%d", &selectoption);
    	switch(selectoption){
    		case 1:{
    		
				break;
			}
		
			case 2:{
				system("cls");
           		puts("=================== Descrição ===================\n");
           		puts("* Jogadores - 2.");
           		puts("* Peças - 24 peças, 12 brancas e 12 pretas.");
           		puts("* Tabuleiro - tabuleiro de 64 casas, claras e escuras.");
           		puts("* Distribuição - 12 peças da mesma cor para cada jogador, posicionadas nas casas escuras, ocupando as três linhas mais próximas de cada jogador.\n");
           		puts("=================== Objetivo ===================\n");
           		puts("* Capturar todas as peças do oponente ou deixá-lo impossibilitado de mover.\n");
           		puts("=================== Regras ===================\n");
           		puts("* Andar uma casa por vez.");
           		puts("* Comer uma peça por vez.");
           		puts("* O jogo dura 3 minutos.\n");
           	
        		system("pause");
        		system("cls");
				break;
			}
		
			case 3:{
				system("cls");
				puts("==========================\n");	
    			printf("J O G O  D E  D A M A S\n");
    			puts("\n==========================\n\n");
				printf("Que pena, você escolheu sair.");
				break;
			}
		
			default:{
				system("cls");
				system("color 4");
				puts("==========================\n");	
    			printf("J O G O  D E  D A M A S\n");
    			puts("\n==========================\n\n");
				printf("OPÇÃO INVÁLIDA\n\n");
				system("pause");
				system("cls");
				break;
			}
		}
	}while(selectoption!=3);
    return 0;
}
