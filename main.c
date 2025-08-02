#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

void mostrar_termos_e_condições()
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
}

void cadastrar_produto()
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

    FILE *arquivo = fopen("lista.txt", "a"); /*Você não tenha permissão para criar o arquivo.
                                             u esteja em um diretório inexistente ou protegido*/

    if (arquivo == NULL)
    {

        printf("Erro\n");
        printf("Talvez você não tenha permissão para criar o documento \nou esteja em um diretório inexistente/protegido");

        return 2;
    }

    fprintf(arquivo, "product: %s\n currency: %s\n user: %s\n description: %s\n price: %.2f\n \n\n\n\n", p->product, p->currency, p->name_user, p->description, p->price);
}

void deletar_produtos()
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

        return 2;
    }

    printf("lista de produtos");
}

void lista_comandos()
{
    printf("Lista de comandos\n");
    printf("Digite 1 para realizar cadastro de produto\n");
    printf("Digite 2 para deletar produtos cadastrados\n");
    printf("digite 3 para acessar produtos cadastrados\n");
    printf("digite 4 para lista de comandos");
    printf("digite 5 para fechar progama\n");
    printf("digite 10 para acessar termos de condição ou licença do software\n");
}

void termos_e_condições()
{

    char resp;

    printf("você que os termos e condições sejam printados no terminal?\n");
    printf("s\\n\n");
    scanf("%c", resp);

    resp = tolower(resp);

    switch (resp)
    {
    case 'n':
        FILE *arquivo_termo = fopen("TERMS.txt", "r");

        if (arquivo_termo == NULL)
        {
            printf("termos e condições não baixados em seu computador");

            return 3;
        }
        break;

    case 's':

        mostrar_termos_e_condições();

        break;

    default:
        break;
    }
}

int main()
{

    cadastro_produto produtos[MAX_PRODUCTS];

    printf("digite seu nome");
    scanf("%22s", user);

    do
    {

        printf("Escolha o serviço nescessário:\n");
        printf("Digite 1 para realizar cadastro de produto\n");
        printf("Digite 2 para deletar produtos cadastrados\n");
        printf("digite 3 para acessar produtos cadastrados\n");
        printf("digite 4 para lista de comandos");
        printf("digite 5 para fechar progama\n");
        scanf("%d", &opcao_menu);

        if (opcao_menu == 1)
        {
            cadastrar_produto();
            pause(3);
        }
        if (opcao_menu == 2)
        {
            deletar_produtos();
            pause(3);
        }
        if (opcao_menu == 3)
        {
            deletar_produtos();
            pause(3);
        }
        if (opcao_menu == 4)
        {
            lista_comandos();
        }
        if (opcao_menu == 10)
        {
        }

    } while (opcao_menu != 5);

    return 0;
}