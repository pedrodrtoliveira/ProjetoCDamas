# Guia de build
## Pré requisitos

### Mingw64 instalado [title](https://sourceforge.net/projects/mingw/);

### GCC instalado;

Verificar se o gcc está instalado:

```c
  gcc --version
```

Caso não esteja, instale-o da seguinte forma (Requer o Mingw instalado):

```c
  mingw-get install gcc
```

![rainbow](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)

### Biblioteca ncurses instalada;

Para instalar o ncurses, digite o comando abaixo no Windows Powershell, ou no Prompt de comando:

```c
 mingw-get install ncurses
```

Com o ncurses e o gcc devidamente instalado, execute a seguinte linha de comando no Prompt de comando (Execute o comando no diretório raiz do projeto):

```c
 gcc main.c -o main -lpdcurses && main
```

# Guia de contribuição
## Features em desenvolvimento:
Marcar com o comentário abaixo funções em desenvolvimento:
```c
 // TODO: (descrição)
```
## Correção de bugs:
Descrever com objetividade qual bug foi corrigido e em qual componente ou funcionalidade.

# Indice de funções

## clrscr
Limpa a tela (Disponível apenas no Windows).
## pause
Pausa a execução (// // // //).
## showBoard
Renderiza o tabuleiro.
## showWelcomeMessage
Mostra mensagem de apresentação.
## showTimer
Faz a contagem do tempo em minutos. 

# Functions Sumary

## clrscr
clear the screen (Windows only).
## pause
pause the execution (Windows only).
## showBoard
shows the game board.
## showWelcomeMessage
shows the welcome message
## showTimer
Counts the time in minutes. 


