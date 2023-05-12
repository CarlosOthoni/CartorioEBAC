#include <stdio.h> //biblioteca de comunic. com o usuario
#include <stdlib.h> // bibLioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //bilbioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca de strings

int registro() 				   // FUN��O REGISTRAR;
{
	setlocale(LC_ALL,"Portuguese");
	char arquivo[40];						             // variaveis tipo STRING de 40 caracteres 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
  	int opcao=0;
 	
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s",cpf);	       							// %S_tring
			
	strcpy(arquivo,cpf);								// Responsavel por copiar os valores das string associando o titulo do 'file' com a info 'cpf'
					
	FILE *file;											// FILE 'fun��o inata do software'		           	//cria o arquivo
	file = fopen(arquivo, "a");							//altera��o: de "w" para "a"		//  como o valor 'cpf' j� foi colocado no titulo do arquivo, s� precisamos atualizar o 'arq' colocando o cpf no primeiro espa�o' cpf ,nome, sobrenome,cargo'
	fprintf(file,cpf);									//salva o valor da vari�vel
	fclose(file);										//fecha o arquivo
		
	file = fopen(arquivo,"a");							// "a" de ATUALIZA��O
	fprintf(file,",");
	fclose(file);
		
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
		
	file = fopen(arquivo, "a");    						 // *** resumindo aqui : v� at� os arquivos e abra o 'ARQUIVO' para atualiza��o ("a")
	fprintf(file,nome); 								//***leia o 'nome' e salve no arquivo 
	fclose(file);										//***feche o arquivo d
		
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
		
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
		
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
		
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
		
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
		
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);	
	
}
int consultar() 			// FUN��O CONSULTAR;
{
	setlocale(LC_ALL,"Portuguese");
	
	char cpf[40];
	char conteudo[200];
				
			
	printf("Digite o cpf a ser consultado: \n");
	scanf("%s",cpf);                                     // pega o cpf digitado 
			
	FILE *file;											// vai nos arquivos e encontra o 'arquivo'
	file = fopen(cpf,"r");								// abre o cpf para ler ' r '
			
	if (file == NULL) 									//SE Nexistir fa�a...
	{
		printf("Arquivo n�o localizado!\n");
	}
	while(fgets(conteudo, 200, file) != NULL)			//sen�o		
	{
		printf("\n Essas s�o as informa��es do usu�rio:");
		printf("%s", conteudo);
		printf("\n\n");
	}
	fclose(file);
	system("pause");
				
}
int deletar() 				// FUN��O DELETAR;
{
	char cpf[40];
		
	setlocale(LC_ALL,"Portuguese");	
	printf("Digite o CPF do USU�RIO a ser DELETADO: ");
	scanf("%s",cpf);
	remove(cpf);
		
	FILE *file;         								//Fun��o respons�vel pela biblioteca de arquivamento : FILE  // Par�mentro 'arquivo': file 
	file = fopen(cpf,"r");    							// abrir e ler o arquivo
	
	if(file == NULL) 									//se n existir
	{
		printf("O usu�rio n�o se encontra no sistema!  \n");
		system("pause");
		fclose(file);		
	}							

}

int main()   			// 	FUN��O PRINCIPAL 
{
	int opcao=0;                     					//definindo variaveis
	int x=1;   										// variavel 'la�o' de repeti��o do programa
    
	for(x=1;x=1;)                    				 	// definindo o FOR e sua condi��o para repetir ''enquanto o x for 1 :repetir''
	{
		system("cls");
		setlocale(LC_ALL,"Portuguese");             	// definindo o idioma do texto
		printf("### Cart�rio da EBAC ###\n\n");     	
    	printf("escolha uma op��o desejada no menu\n");
   		printf("\t1 - registrar nomes\n");
   		printf("\t2 - Consultar nomes\n");
   		printf("\t3 - Deletar nomes\n\n");              
   		printf("         .");
    	
		scanf("%d", &opcao);           				//armazenando a escolha do usuario
		system("cls");
    		
   		switch(opcao)   									// inicio da condi��o ( VAR inserida)
 		{
    		case 1:
    		registro(); 									// chamando fun��o
    		break;
    		case 2:
    		consultar();									// chamando fun��o
			break;
			case 3:
			deletar(); 										//chamando fun��o
			break;
			default: 										// procedimento padr�o para 'erro de op��o inserida'
			printf("Essa op��o n�o est� dispon�vel\n");
			system("pause");	
			break;
		
		} //switch..
	} // for..
     
}  //main..
		
	  
