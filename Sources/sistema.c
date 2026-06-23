#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#include "../Headers/sistema.h"

void limpar_tela()
{

#ifdef _WIN32
    system("cls");

#else
    system("clear");

#endif
}

void pause(int segundos)
{
#ifdef _WIN32
    Sleep(segundos * 1000);
#else
    sleep(segundos);
#endif
}