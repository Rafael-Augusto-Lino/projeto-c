#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// inclusão de outros arquivos nesse main
#include "../Headers/sistema.h"

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

/*variáveis globais*/
int c;
int opcao_menu;
int total_products = 0;
char user[23]; /*variável global*/
cadastro_produto produtos[MAX_PRODUCTS];

void mostrar_termos_e_condicoes()
{
    printf("===========================================================================\n");
    printf("TERMS AND CONDITIONS - APLICATIVO DE CONTROLE E CADASTRO DE PRODUTOS\n");
    printf("===========================================================================\n\n");

    printf("1. ACEITAÇÃO DOS TERMOS\n");
    printf("Ao utilizar este aplicativo, você concorda em cumprir estes Termos e Condições.\n");
    printf("Caso não concorde, não utilize este software.\n\n");

    printf("2. USO DO APLICATIVO\n");
    printf("O aplicativo destina-se exclusivamente ao gerenciamento interno de produtos,\n");
    printf("incluindo cadastro, alteração e controle de estoque. O usuário compromete-se\n");
    printf("a utilizar o sistema para fins legais e éticos, não prejudicando a integridade\n");
    printf("do sistema ou dos dados.\n\n");

    printf("3. RESPONSABILIDADES DO USUÁRIO\n");
    printf("- O usuário é responsável pela veracidade e integridade dos dados cadastrados.\n");
    printf("- Recomenda-se realizar backups periódicos para evitar perdas de dados.\n");
    printf("- O desenvolvedor não se responsabiliza por perdas ou danos decorrentes do uso.\n\n");

    printf("4. PROPRIEDADE INTELECTUAL\n");
    printf("Todos os direitos do software, incluindo código-fonte e funcionalidades, são\n");
    printf("reservados ao desenvolvedor. É proibida a reprodução ou modificação não autorizada.\n\n");

    printf("5. PRIVACIDADE E DADOS\n");
    printf("Os dados armazenados serão utilizados exclusivamente para fins do gerenciamento\n");
    printf("no aplicativo, respeitando as normas de privacidade vigentes.\n\n");

    printf("6. ATUALIZAÇÕES E MANUTENÇÃO\n");
    printf("O desenvolvedor pode atualizar ou modificar o software a qualquer momento, sem\n");
    printf("aviso prévio.\n\n");

    printf("7. LIMITAÇÃO DE RESPONSABILIDADE\n");
    printf("O software é fornecido \"no estado em que se encontra\", sem garantias. O desenvolvedor\n");
    printf("não se responsabiliza por quaisquer danos decorrentes do uso.\n\n");

    printf("8. ALTERAÇÕES NOS TERMOS\n");
    printf("Estes termos podem ser alterados a qualquer momento, sendo a versão vigente\n");
    printf("disponível no software.\n\n");

    printf("9. LEI APLICÁVEL E FORO\n");
    printf("Estes termos são regidos pela legislação brasileira, com foro na comarca de [cidade].\n\n");

    printf("===========================================================================\n");

    return;
}

int cadastrar_produto()
{

    printf("serviço acessado com sucesso!");

    pause(3);
    limpar_tela();

    if (total_products >= MAX_PRODUCTS)
    {
        printf("Limite de produtos atingido. Não é possível cadastrar mais produtos.\n");
        return 0;
    }

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

    FILE *arquivo = fopen("lista.txt", "a"); /*Você não tenha permissão para criar o arquivo.
                                             ou esteja em um diretório inexistente ou protegido*/

    if (arquivo == NULL)
    {

        printf("Erro\n");
        printf("Talvez você não tenha permissão para criar o documento \nou esteja em um diretório inexistente/protegido");

        return 2;
    }

    fprintf(arquivo, "product: %s\n currency: %s\n user: %s\n description: %s\n price: %.2f\n \n\n\n\n", p->product, p->currency, p->name_user, p->description, p->price);
    fclose(arquivo);
    return 0;
}

int deletar_produtos()
{

    printf("Função em desenvolvimento");
    return 1;
}

void listar_produtos()
{

    FILE *arquivo = fopen("produtos.txt", "r");

    if (arquivo == NULL)
    {
        printf("arquivo não encontrado");

        return;
    }

    printf("lista de produtos");
    fclose(arquivo);
}

int lista_comandos()
{
    int numero;
    printf("Lista de comandos\n");
    printf("Digite 1 para realizar cadastro de produto\n");
    printf("Digite 2 para deletar produtos cadastrados\n");
    printf("digite 3 para acessar produtos cadastrados\n");
    printf("digite 4 para lista de comandos\n");
    printf("digite 5 para fechar progama\n");
    printf("digite 10 para acessar termos de condição ou licença do software\n");
    scanf("%d", &numero);
    pause(2);
    return numero;
}

void termos_e_condicoes()
{

    char resp;

    printf("você quer os termos e condições sejam printados no terminal?\n");
    printf("s\n");
    scanf(" %c", &resp);

    resp = tolower(resp);

    switch (resp)
    {
    case 'n':
    {
        FILE *arquivo_termo = fopen("TERMS.txt", "r");

        if (arquivo_termo == NULL)
        {
            printf("termos e condições não baixados em seu computador, por favor/n baixe os termos e condições para acessar o conteúdo");
            return;
        }

        fclose(arquivo_termo);
        break;
    }

    case 's':
    {
        mostrar_termos_e_condicoes();

        break;
    }
    default:
        break;
    }
}

int main(int argc, char *argv[])
// o argc é um dado inteiro que eu posso usar dentro do main para saber quantos argumentos foram passados
// para o programa no terminal )

// quando o programa for executado pelo terminal, ex: projeto-c.exe
// tudo de texto que vier depois do nome do programa, será considerado um argumento
// e será armazenado no array argv

// lembra que o argv é um array de strings, ou seja, um array de arrays de caracteres
{

    printf("digite seu nome");
    scanf("%22s", user);
    // tem que integrar algumas funções quase prontas neste main aqui(anotei aqui para depois fazer)
    do
    {
        int opcao_menu = lista_comandos();

        switch (opcao_menu)
        {
        case 0: // caso queira parar o ciclo do "do e while"
            printf("Comando de admin");
            pause(100);
            break;
        case 1:
            cadastrar_produto();
            pause(3);
            break;
        case 2:

            deletar_produtos();
            pause(3);
            break;
        case 3:

            listar_produtos();
            pause(3);
            break;
        case 4:
            limpar_tela();
            break;
        case 10:

            termos_e_condicoes();
            break;
        }

    } while (opcao_menu != 5);

    return 0;
}