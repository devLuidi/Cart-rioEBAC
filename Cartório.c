#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //Fun��o responsavel por cadastras os usu�rios no sistema
{
	//in�cio da cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado:  "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se � strings
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo
	fprintf(file, cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:  ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:  ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:  ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:  ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado:  ");
	scanf("%s",cpf);
	system("pause");
	
	FILE *file;
	file = fopen(cpf,"r");
	
	remove(cpf);
	
	printf("Usu�rio Deletado com sucesso!.\n");
	system("pause");
	
	if(file == NULL)
	{
		printf("Usu�rio n�o se encontra no sistema!.\n");
		system("pause");
		
	}
}

int main()
{
	int opcao=0; //Definindo as vari�veis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("###Sistema de Registro Institucioanl EBAC###\n\n");
	while(1)//inicio do loop de valida��o de senha
	{
		printf("Login de Administrador!\n\nDigite a sua senha:  ");
		scanf("%s", senhadigitada);// armazena a senha na variavel 'senhadigitada'
		
		comparacao = strcmp(senhadigitada, "admin");
		if (comparacao == 0)
		{
			printf("Acesso permitido!\n");
			break;
		}
		else
		{
			printf("Senha incorreta! Tente novamente.\n");
			system("pause");
		}
	}
	    while (1)
	    {
	     setlocale(LC_ALL, "Portuguese");
	     system("cls");
	     printf("###Sistema de Registro Institucional EBAC###\n\n");
	     printf("Escolha a op��o desejada do menu:\n\n");
	     printf("\t1 - Registrar Nomes\n");
	     printf("\t2 - Consultar Nomes\n");
	     printf("\t3 - Deletar Nomes\n");
	     printf("\t4 - Sair do sistema\n\n");
	     printf("Op��o: ");
	    
	     scanf("%d", &opcao);
	    
	     system("cls");
	    
	     switch(opcao)
	     {
	     	case 1:
	      	 registro();
	      	 break;
	      	
	      	 case 2:
	      	 consulta();
	      	 break;
	      	
	      	 case 3:
	      	 deletar();
	      	 break;
	      	
	      	 case 4:
	      	 printf("Obrigado por utilizar o sistema!");
	      	 return 0;
	      	 break;
		     } //fim do switch  	 
		 } //fim do while
		  
	 } //Fim da sele��o
