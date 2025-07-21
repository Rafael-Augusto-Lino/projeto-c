#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#define MAX_PRODUCTS 1000

typedef struct
{
    char product[100];
    char currency[4];
    char name_user[100];
    char description[1000];
    float price;

} cadastro_produto;

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

int main()
{

    int c;
    int opcao_menu;
    int total_products = 0;
    char user[23]; /*variável global*/
    cadastro_produto produtos[MAX_PRODUCTS];

    scanf("%22s", user);

    printf("Escolha o serviço nescessário:\n");
    printf("Digite 1 para realizar cadastro de produto\n");
    scanf("%d", &opcao_menu);

    if (opcao_menu == 1)
    {
        printf("serviço acessado com sucesso!");

        pause(3);
        limpar_tela();

        while ((c = getchar()) != '\n' && c != EOF)
            ;

        cadastro_produto *p = &produtos[total_products]; /* o * cria o ponteiro e o & acessa o endereço de memória necessário de
        determinado array*/

        /*cria um ponteiro chamado p do tipo struct que vai sempre apontar para
        o struct nescesário que está dentro do array produtos( a variável total_products define qual é o struct necessário)*/

        strcpy(p->name_user, user);

        printf("Digite o nome do produto:\n");
        fgets(p->product, sizeof(p->product), stdin); /*acessa o campo product da struct que p aponta.*/

        printf("Digite a sigla da moeda do país:\n");
        fgets(p->currency, sizeof(p->currency), stdin);

        printf("Preço do produto:\n");
        scanf("%f", &p->price);

        while ((c = getchar()) != '\n' && c != EOF)
            ;

        printf("Descrição do produto:\n");
        fgets(p->description, sizeof(p->description), stdin);

        total_products++;
    }

    return 0;
}