#include <stdio.h>
#include <stdlib.h>
//#include <windows.h>
#include <string.h>

int main()
{
    int qtdc,c, i, opc, numlinhas;
    int buscador;
    char caracter;

    FILE *parquivo;

    struct Animal
    {
        char nome[50];
        char raca[50];
        int idade;
        char cor[50];
    };

    struct Cliente
    {
        int codcliente;
        char nome[50];
        char endereco[50];
        char cpf[50];
        char branco[50];
        struct Animal dadoanimal;
    };

    struct Cliente clientes;


    do
    {
        printf("\n\n1 - Inserir Clientes");
        printf("\n\n2 - Buscar Clientes");
        printf("\n\n3 - Consultar Clientes");
        printf("\n\n4 - Sair do Programa\n\n");
        scanf("%d", &opc);

        switch(opc)
        {
            case 1: //inserir clientes
                parquivo = fopen("trabalhoclientes.txt", "a");
                do
                {

                    printf("Quantos Clientes você deseja cadastrar(mínimo 2)? ");
                    scanf("%d", &qtdc);
                    c=getchar();//para usar no linux
                }while(qtdc<2);

                /*if (!(clientes = (struct Cliente *)malloc(qtdc * sizeof(struct Cliente))))
                {
                    printf("Não foi possível alocar os clientes\n");
                    exit(0);
                }*/
                for(i = 0; i < qtdc; i++)
                {
                    printf("\n\nDigite codigo do cliente %d: ", i+1);
                    scanf("%d", &clientes.codcliente);
                    c=getchar();

                    printf("\n\nDigite o nome do cliente %d:", i+1);
                    gets(clientes.nome);

                    printf("\n\nDigite endereco do cliente %d:", i+1);
                    gets(clientes.endereco);

                    printf("\n\nDigite o CPF do cliente %d: ", i+1);
                    gets(clientes.cpf);

                    printf("\n\nDigite nome do Animal do Cliente %d: " , i+1);
                    gets(clientes.dadoanimal.nome);

                    printf("\n\nDigite a raca do Animal do Cliente %d: ", i+1);
                    gets(clientes.dadoanimal.raca);

                    printf("\n\nDigite a idade do Animal do Cliente: ");
                    scanf("%d", &clientes.dadoanimal.idade);
                    c=getchar();

                    printf("\n\nDigite a cor do Animal do Cliente %d: ", i+1);
                    gets(clientes.dadoanimal.cor);
                    printf("\n\n");
                    c=getchar();

                    fprintf(parquivo, "%d %s %s %s %s %s %d %s \n", clientes.codcliente, clientes.nome, clientes.endereco, clientes.cpf, clientes.dadoanimal.nome, clientes.dadoanimal.raca, clientes.dadoanimal.idade, clientes.dadoanimal.cor);
            }
                //fscanf para leitura fprintf para escrita
            fclose(parquivo);
            break;
            case 2: //buscar clientes
                printf("\nDigite o cliente que deseja buscar: ");
                scanf("%d", &buscador);
                c=getchar();

                parquivo = fopen("trabalhoclientes.txt", "r");

                if(!parquivo)
                {
                    printf("Error: não foi possivel abrir o arquivo!\n");
                    c=getchar();
                }
                    numlinhas=0;
                    while(!feof(parquivo))
                    {
                            caracter=fgetc(parquivo);
                            if (caracter == '\n')
                                numlinhas++;
                    }
                    fseek (parquivo, 0, SEEK_SET);
                    for(i=1; i<=numlinhas; i++)
                    {
                        fscanf(parquivo, "%d %s %s %s %s %s %d %s", &clientes.codcliente, clientes.nome, clientes.endereco, clientes.cpf, clientes.dadoanimal.nome, clientes.dadoanimal.raca, &clientes.dadoanimal.idade, clientes.dadoanimal.cor);

                        if(buscador == clientes.codcliente)
                        {
                            printf("\nCodigo: %d", clientes.codcliente);

                            printf("\nNome: %s",clientes.nome);

                            //if(resultado[j] = !strcmp(buscador,clientes.endereco) && (fscanf(parquivo, "%s", clientes.endereco)) != EOF )
                            printf("\nEndereço: %s",clientes.endereco);

                            //if(resultado[j] = !strcmp(buscador,clientes.cpf) && (fscanf(parquivo, "%s", clientes.cpf)) != EOF )
                            printf("\nCPF: %s",clientes.cpf);

                            //if(resultado[j] = !strcmp(buscador,clientes.dadoanimal.nome) && (fscanf(parquivo, "%s", clientes.dadoanimal.nome)) != EOF )
                            printf("\nNome do animal: %s",clientes.dadoanimal.nome);

                            //if(resultado[j] = !strcmp(buscador,clientes.dadoanimal.raca) && (fscanf(parquivo, "%s", clientes.dadoanimal.raca)) != EOF )
                            printf("\nRaça do animal: %s",clientes.dadoanimal.raca);

                            //if((buscador[j]) == (fscanf(parquivo, "%d", &clientes.dadoanimal.idade)) != EOF )
                            printf("\nIdade do Animal: %d", clientes.dadoanimal.idade);

                            //if(resultado[j] = !strcmp(buscador,clientes.dadoanimal.cor) && (fscanf(parquivo, "%s", clientes.dadoanimal.cor)) != EOF )
                            printf("\nCor do animal: %s",clientes.dadoanimal.cor);
                        }

                    }
            fclose(parquivo);
            break;

            case 3:
                printf("\n\tConsultar Clientes:\n\n\n");

                parquivo = fopen("trabalhoclientes.txt", "r");
                if(!parquivo)
                {
                    printf("Error: não foi possivel abrir o arquivo!\n");
                    c=getchar();
                }
                numlinhas=0;
                while(!feof(parquivo))
                {
                    caracter=fgetc(parquivo);
                    if (caracter == '\n')
                        numlinhas++;
                }
                fseek (parquivo, 0, SEEK_SET);
                printf("\nQuantidade de clientes: %d\n", numlinhas);
                for(i=0; i<numlinhas; i++)
                {
                    //fseek (parquivo, i*308, SEEK_SET);
                    fscanf(parquivo, "%d %s %s %s %s %s %d %s", &clientes.codcliente, clientes.nome, clientes.endereco, clientes.cpf, clientes.dadoanimal.nome, clientes.dadoanimal.raca, &clientes.dadoanimal.idade, clientes.dadoanimal.cor);
                    printf("\nCódigo Cliente: %d", clientes.codcliente);
                    printf("\nNome: %s", clientes.nome);
                    printf("\nEndereco: %s", clientes.endereco);
                    printf("\nCPF: %s", clientes.cpf);
                    printf("\nNome do Animal: %s", clientes.dadoanimal.nome);
                    printf("\nRaca do Animal: %s", clientes.dadoanimal.raca);
                    printf("\nIdade do Animal: %d", clientes.dadoanimal.idade);
                    printf("\nCor do Animal: %s\n\n",clientes.dadoanimal.cor);

                }
                fclose(parquivo);
                break;
            case 4:
                break;
            default:
                printf("\nOpção inválida\n");
        }
    }while(opc!=4);
    return 0;
}


