#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
#include<Windows.h>

//ÁREA DE DECLARAÇÃO DAS STRUCTS
typedef struct{
    char login[20];
    char senha[16];
} Usuario;
Usuario usuarios[10];

typedef struct{
    char tipo_cadas[20];
    char nome[50];
    char email[40];
    char nasc[20];
    char cpf[20];
    char tel[20];
} cadastro_clie;
 cadastro_clie todos[150];

//ÁREA DE DECLARAÇÃO DAS VARIÁVEIS GLOBAIS
int op;
int n;

//ÁREA DE DECLARAÇÃO DE FUNÇÕES
int logo();
int login();
void cadastro();
void pesquisar();
void listar();
void carregar_base_d();
void Atualizacao_base_d();

//FUNÇÃO DE EXIBIÇÃO DE MENSAGEM NA TELA
int logo(){

    printf("\n");
    system("color 3"); //ALTERA A COR DO TEXTO A SER EXIBIDO

    printf("\n\t\t\t\t      ________________________________________\n");
    printf("\t\t\t\t     |                                        |\n");
    printf("\t\t\t\t     |             MENU PRINCIPAL             |\n");
    printf("\t\t\t\t     |________________________________________|\n");

	return(0);
}

//FUNÇÃO DE LOGIN
int login ()
 {
    system("cls");

    char login[20], senha[16];
    int cont=0,d;
    int i=0;
    int s=0; //VARIÁVEL AUXILIADORA DE ARMAZENAMENTO DA SENHA
    char c; //VARIÁVEL PARA PEGAR UM CARACTER POR VEZ DA SENHA

    printf("---------------------------------------LOGIN DO PROGRAMA---------------------------------------\n");
    printf("-----------------------------------------------------------------------------------------------\n\n");

    printf("Digite o login: ");
    gets(login);
    printf("Digite a senha: ");
    while ((c=getch())!=13)//ESSE LAÇO VAI ATÉ O USUÁRIO DIGITAR A TECLA ENTER
    {
        if(c==8) //VALOR DO BACKSPACE
        {
            printf("\b");
            printf("\t");
            printf("\b");
            printf("\b");
            printf("\b");
            printf("\b");
            printf("\b");
            printf("\b");
            s--;//DECREMENTO PARA ESTA VARIÁVEL
        }
        else
        {
        senha[s]=c; //ESTÁ COLOCANDO UM CARACTER POR VEZ NA VARIÁVEL
        printf("*"); //ESSA * MOSTRA NA TELA NO LUGAR DA SENHA
        cont++;
        s++;
        }
    }
    senha[s]='\0'; //FINALIZANDO A SENHA
        if ( s < 2)
        {
            senha[0] = 'e';
            login[0] = 'e';
        }

        for(i=0; i<2; ++i){

            if(strcmp(usuarios[i].login, login)==0 && strcmp(usuarios[i].senha, senha)==0)//CONDIÇÃO CRIADA PARA COMPARAR SE O LOGIN E SENHA PRÉ-DEFINIDOS SÃO IGUAIS AO LOGIN E SENHA DIGITADOS
            {
                return 1;
            }

        }
        printf("\n\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),20);
        printf("---------------------------------------------\n");
        printf("|Login incorreto!\7\7 Por favor, tente novamente. |\n");
        printf("---------------------------------------------\n\n");
        system("pause");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),23);
        return 0;

 }
//FUNÇÃO DE CADASTRO
void cadastro()
 {

    do{
        op = 1;
                printf("---------------------------------------------CADASTRO---------------------------------------------\n");
                printf("------------------------------------------------------------------------------------------------\n\n");
                printf("DIGITE SE O CADASTRO É PARA UM FUNCIONARIO OU CLIENTE:\n");
                scanf("%s", &todos[n].tipo_cadas);
                printf("DIGITE O NOME COMPLETO(DE ACORDO COM ESTA ESTRUTURA= NOME_SOBRENOME_SOBRENOME):\n");
                scanf("%s", &todos[n].nome);
                printf("DIGITE O EMAIL:\n");
                scanf("%s", &todos[n].email);
                printf("DIGITE A DATA DE NASCIMENTO:(USAR APENAS NÚMEROS)\n");
                scanf("%s",&todos[n].nasc);
                printf("DIGITE O CPF:\n");
                scanf("%s",&todos[n].cpf);
                printf("DIGITE O TELEFONE:\n");
                scanf("%s",&todos[n].tel);
                printf("\n\n");


            printf("----------------------------------\n");
            printf("|1 - CONTINUAR O CADASTRAMENTO   |\n");
            printf("|--------------------------------|\n");
            printf("|2 - VOLTAR AO MENU PRINCIPAL    |\n");
            printf("----------------------------------\n");
            printf("OPCAO ESCOLHIDA: ");
            scanf("%d", &op);
            Atualizacao_base_d();

        n++;//COMANDO QUE RETORNA O VALOR DE INDICE NO MOMENTO EM QUE É CHAMADO E DEPOIS INCREMENTA ESSE VALOR
        system("cls");

    }while(op == 1);



 }
//FUNÇÃO DE PESQUISA DE CADASTROS
 void pesquisa()
 {

    char pesquisacpf[20], cpf1[20];
    char pesquisatel[20], tel1[20];
    char pesquisaemail[40],email1[40];
    int i,j,op2;

    do{
        op = 1;
        printf("-------------------------------------PESQUISA DE CADASTROS-------------------------------------\n");
        printf("-----------------------------------------------------------------------------------------------\n\n");

        printf("\t---------------------------------------------------------\n");
        printf("\t|\t1 - PESQUISAR POR CPF       \t\t\t|\n");
        printf("\t---------------------------------------------------------\n");
        printf("\t|\t2 - PESQUISAR POR EMAIL     \t\t\t|\n");
        printf("\t--------------------------------------------------------|\n");
        printf("\t|\t3 - PESQUISAR POR TELEFONE  \t\t\t|\n");
        printf("\t|-------------------------------------------------------|\n");
        printf("\t|\t4 - VOLTAR AO MENU PRINCIPAL\t\t\t|\n");
        printf("\t--------------------------------------------------------|\n\n");
        printf("OPCAO DESEJADA: ");
        scanf("%d", &op2);
        system("cls");
        switch(op2)
        {

            case 1:
                printf("-------------------------------------PESQUISA DE CADASTROS-------------------------------------\n");
                printf("-----------------------------------------------------------------------------------------------\n\n");
                printf("\t\t-----------------------------------\n");
                printf("\t\t|       PESQUISA POR CPF          |\n");
                printf("\t\t-----------------------------------\n\n");

                printf("POR FAVOR, DIGITE O CPF DESEJADO: ");
                scanf("%s", &cpf1);
                for(j = 0; j < 20;j++)//LAÇO FEITO PARA INCREMENTAR O CPF DIGITADO PARA A VARIÁVEL DE "pesquisacpf"
                {
                    pesquisacpf[j] = (cpf1[j]);
                }
                printf("\n\n");

                printf("\t\t--RESULTADO DA PESQUISA--\n");
                printf("\t\t-------------------------\n\n");

                for(i=0; i<n; i++){
                    //CONDIÇÃO PARA QUE SE O CPF DIGITADO NA PESQUISA SER IGUAL A ALGUM DOS CPFs CADASTRADOS, MOSTRA O CADASTRO FEITO COM ESSE CPF
                    if (strcmp(todos[i].cpf, pesquisacpf)==0){

                        printf("--------------------------------------\n");
                        printf("Tipo de pessoa cadastrada: %s\n", todos[i].tipo_cadas);
                        printf("Nome: %s\n", todos[i].nome);
                        printf("Email: %s\n",todos[i].email);
                        printf("CPF: %s\n", todos[i].cpf);
                        printf("Telefone: %s\n", todos[i].tel);
                        printf("Nascimento: %s\n", todos[i].nasc);
                        printf("--------------------------------------\n");
                        printf("\n\n");
                    }
                }
                break;

            case 2:
            printf("-------------------------------------PESQUISA DE CADASTROS-------------------------------------\n");
            printf("-----------------------------------------------------------------------------------------------\n\n");

                printf("\t\t-----------------------------------\n");
                printf("\t\t|       PESQUISA POR EMAIL        |\n");
                printf("\t\t-----------------------------------\n\n");

                printf("POR FAVOR, DIGITE O EMAIL DESEJADO: ");
                scanf("%s",&email1);
                for(j = 0; j < 40;j++)
                {
                    pesquisaemail[j] = (email1[j]);
                }

                printf("\n\n");

                printf("\t\t--RESULTADO DA PESQUISA--\n");
                printf("\t\t-------------------------\n\n");

                for(i=0; i<n; i++){
                    if (strcmp(todos[i].email, pesquisaemail)==0){

                        printf("--------------------------------------\n");
                        printf("Tipo de pessoa cadastrada: %s\n", todos[i].tipo_cadas);
                        printf("Nome: %s\n", todos[i].nome);
                        printf("Email: %s\n",todos[i].email);
                        printf("CPF: %s\n", todos[i].cpf);
                        printf("Telefone: %s\n", todos[i].tel);
                        printf("Nascimento: %s\n", todos[i].nasc);
                        printf("--------------------------------------\n");
                        printf("\n\n");
                    }
                }
            break;
            case 3:
                printf("-------------------------------------PESQUISA DE CADASTROS-------------------------------------\n");
                printf("-----------------------------------------------------------------------------------------------\n\n");

                printf("\t\t-----------------------------------\n");
                printf("\t\t|       PESQUISA POR TELEFONE      |\n");
                printf("\t\t-----------------------------------\n\n");

                printf("POR FAVOR, DIGITE O CPF DESEJADO: ");
                scanf("%s", &tel1);
                for(j = 0; j < 20;j++)
                {
                    pesquisatel[j] = (tel1[j]);
                }
                printf("\n\n");

                printf("\t\t--RESULTADO DA PESQUISA--\n");
                printf("\t\t-------------------------\n\n");

                for(i=0; i<n; i++){
                    if (strcmp(todos[i].tel, pesquisatel)==0){

                        printf("--------------------------------------\n");
                        printf("Tipo de pessoa cadastrada: %s\n", todos[i].tipo_cadas);
                        printf("Nome: %s\n", todos[i].nome);
                        printf("Email: %s\n",todos[i].email);
                        printf("CPF: %s\n", todos[i].cpf);
                        printf("Telefone: %s\n", todos[i].tel);
                        printf("Nascimento: %s\n", todos[i].nasc);
                        printf("--------------------------------------\n");
                        printf("\n\n");
                    }
                }

                break;
            case 4:
                op = 2;
            break;

            default:
                printf("-------------------------------------PESQUISA DE CADASTROS-------------------------------------\n");
                printf("-----------------------------------------------------------------------------------------------\n\n");
                printf("OPCAO INVALIDA\n");
            break;

            }
                printf("-----------------------------------\n");
                printf("|1 - CONTINUAR A PESQUISA         |\n");
                printf("|---------------------------------|\n");
                printf("|2 - VOLTAR AO MENU PRINCIPAL     |\n");
                printf("-----------------------------------\n");
                printf("SELECIONE A OPCAO DESEJADA: ");
                scanf("%d", &op);
                system("cls");
    }while(op == 1);



 }
//FUNÇÃO DA LISTAGEM DE USUÁRIOS
void lista()
 {

    int i;

    printf("-------------------------------LISTA DE CADASTRADOS DO SISTEMA-----------------------------------\n");
    printf("-----------------------------------------------------------------------------------------------\n\n");

    //CRIAÇÃO DE UMA ESTRUTURA DE REPETIÇÃO PARA LISTAR APENAS O QUE FOI CADASTRADO
    for(i=0; i<n; i++){

         printf("--------------------------------------\n");
         printf("Tipo de pessoa cadastrada: %s\n", todos[i].tipo_cadas);
         printf("Nome: %s\n", todos[i].nome);
         printf("Email: %s\n",todos[i].email);
         printf("CPF: %s\n", todos[i].cpf);
         printf("Telefone: %s\n", todos[i].tel);
         printf("Nascimento: %s\n", todos[i].nasc);
         printf("--------------------------------------\n");
         printf("\n\n");
    }
 }
//FUNÇÃO PARA CARREGAR TUDO QUE FOI CADASTRADO NO ARQUIVO TXT
  void carregar_base_d()
 {
    FILE*banco_d;//CRIAÇÃO DO PONTEIRO
    banco_d =fopen("Base_de_dados.txt","a+");//ABERTURA DO ARQUIVO
    if(banco_d == NULL)
    {
        printf("Não foi possivel acessar a Base de dados, sera criado um arquivo de backup");
        system("pause");
        banco_d =fopen("Base_de_dados","w");
    }
    fscanf(banco_d,"%s %s %s %s %s %s\n", &todos[n].tipo_cadas, &todos[n].nome, &todos[n].email, &todos[n].nasc, &todos[n].cpf, &todos[n].tel);
    fclose(banco_d);//FECHAMENTO DO ARQUIVO

 }
 //FUNÇÃO PARA ATUALIZAR OS CADASTROS NO ARQUIVO TXT
 void Atualizacao_base_d()
 {
     FILE*banco_d;
    banco_d =fopen("Base_de_dados.txt","a+");
    if(banco_d == NULL)
    {
        printf("Não foi possivel gravar os dados");
        system("pause");
        banco_d =fopen("Base_de_dados","w");
    }
    fprintf(banco_d,"%s /Nome Completo:%s /Email:%s /Data de Nascimento:%s /CPF:%s /Telefone:%s\n", todos[n].tipo_cadas, todos[n].nome, todos[n].email, todos[n].nasc, todos[n].cpf, todos[n].tel);
    fclose(banco_d);
 }
int main (void)
 {

    setlocale(LC_ALL,"portuguese");// COMANDO PARA PERMITIR O USO DE ACENTUAÇÃO
    system("cls"); //LIMPANDO A TELA
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),23);
    carregar_base_d();

    //PRÉ-DEFINIÇÃO DO LOGIN E SENHA
    strcpy(usuarios[0].login, "Admin");
    strcpy(usuarios[0].senha, "123456");
    while(login()==0);

    do{
    system("cls");
    logo(); //CHAMADA DE FUNÇÃO PARA MENSAGEM NA TELA
	printf("\n\t\t\t\t\t\tESCOLHA UMA OPÇÃO\n\n");
    printf("\t\t\t|---------------------------------------------------------------|\n");
	printf("\t\t\t\t1 - CADASTRAR\n\n");
    printf("\t\t\t|---------------------------------------------------------------|\n");
    printf("\t\t\t\t2 - PESQUISAR POR USUÁRIOS CADASTRADOS\n\n");
    printf("\t\t\t|---------------------------------------------------------------|\n");
    printf("\t\t\t\t3 - LISTAR TODOS OS USUÁRIOS CADASTRADOS\n\n");
    printf("\t\t\t|---------------------------------------------------------------|\n");
    printf("\t\t\t\t4 - SAIR DO PROGRAMA\n\n");
    printf("\t\t\t|---------------------------------------------------------------|\n");
    printf("\t\t->");
    scanf ("%d", &op);
    system("cls");

    /*ESTRUTURA PARA DEFINIÇÃO DE OPÇÃO
      CADA OPÇÃO DEFINE O CAMINHO A SER TOMADO POR FUNÇÕES DISTINTAS*/
       switch (op)
    {
        case 1:
            cadastro();
        break;

        case 2:
            pesquisa();
        break;

        case 3:
            lista();
        break;

        case 4:
            system("exit");
        break;
        default:
            printf("OPÇÃO INVÁLIDA!\n");
        break;
    }

	system ("pause");
     }while(op!=4);
    printf("--OBRIGADO POR UTILIZAR O NOSSO PROGRAMA!--\n");
    printf("-------------------------------------------\n\n");

    system("pause");
 }
