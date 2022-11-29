Vídeo:

[Projeto DAMAS - Técnicas de Desenvolvimento de Algoritmos](https://youtu.be/nrA1gAZ1egs)

![rainbow](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)

### Guia de build
### Pré requisitos

1. Mingw64 instalado ([Faça o Download aqui](https://sourceforge.net/projects/mingw/));

2. GCC instalado;

    Verificar se o gcc está instalado:

```c
 gcc --version
```

    Caso não esteja, instale-o da seguinte forma (Requer o Mingw instalado):

```c
 mingw-get install gcc
```

3. Biblioteca ncurses instalada;

    Para instalar o ncurses, digite o comando abaixo no Windows Powershell, ou no Prompt de comando:

```c
 mingw-get install ncurses
```

    E, por último:

```c
 mingw-get install libncurses
```

    Com o ncurses e o gcc devidamente instalado, execute a seguinte linha de comando no Prompt de comando (Execute o comando no diretório raiz do projeto):

```c
 gcc main.c -o main -lncursesw -std=c11 && main
```

![rainbow](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)

### Guia de contribuição
### Features em desenvolvimento:
Marcar com o comentário abaixo funções em desenvolvimento:
```c
 // TODO: (descrição)
```

![rainbow](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)

### Correção de bugs:
Descrever com objetividade qual bug foi corrigido e em qual componente ou funcionalidade usando os commits. (Use com moderação)

![rainbow](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)

### Indice de funções

### clrscr(void)
Limpa a tela (Disponível apenas no Windows).
### pause(void)
Pausa a execução (// // // //).
### showMenu(void)
Mostra o menu. (dãããã)
### showHeader(void)
Mostra o header na área superior central.
### showBoard(void)
Renderiza o tabuleiro.
### showWelcomeMessage(void)
Mostra mensagem de apresentação.
### showTimer(void)
Renderiza o cronômetro.
### createWindow(int height, int width, int y, int x)
Cria uma nova janela do ncurses. (dãããã)
### startGame(void)
Inicia um novo jogo. (dããã)
### finishGame(void)
Finaliza o jogo. (dããã)
### movePiece(player p, WINDOW *window)
Move o jogador de acordo com as coordenadas do tabuleiro.
### clearPiece(WINDOW *window, int positionY, int positionX)
Atualiza o estado do tabuleiro "limpando" a peça que foi movida.

![rainbow](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)

### Functions Sumary

### clrscr(void)
clear the screen (Windows only).
### pause(void)
pause the execution (Windows only).
### showMenu(void)
shows the menu. (dãããã)
### createWindow(int height, int width, int y, int x)
creates a new ncurses window. (dããã)
### showBoard(void)
shows the game board.
### showHeader(void)
shows the game header at the top center.
### showWelcomeMessage(void)
shows the welcome message
### showTimer(void)
Render the timer. 
### startGame(void)
Starts the game. (dããã)
### finishGame
Finish the game. (dããã)
### movePiece(player p, WINDOW *window)
Moves the player according with boards coordenates.
### clearPiece(WINDOW *window, int positionY, int positionX)
Updates the game state "cleaning" the piece that was moved.


