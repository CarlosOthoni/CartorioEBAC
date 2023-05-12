#include <stdio.h> //biblioteca de comunic. com o usuario
#include <stdlib.h> // bibLioteca de alocação de espaço em memória
#include <locale.h> //bilbioteca de alocações de texto por região
#include <string.h> // biblioteca de strings

int registro() 				   // FUNÇÃO REGISTRAR;
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
					
	FILE *file;											// FILE 'função inata do software'		           	//cria o arquivo
	file = fopen(arquivo, "a");							//alteração: de "w" para "a"		//  como o valor 'cpf' já foi colocado no titulo do arquivo, só precisamos atualizar o 'arq' colocando o cpf no primeiro espaço' cpf ,nome, sobrenome,cargo'
	fprintf(file,cpf);									//salva o valor da variável
	fclose(file);										//fecha o arquivo
		
	file = fopen(arquivo,"a");							// "a" de ATUALIZAÇÃO
	fprintf(file,",");
	fclose(file);
		
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
		
	file = fopen(arquivo, "a");    						 // *** resumindo aqui : vá até os arquivos e abra o 'ARQUIVO' para atualização ("a")
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
int consultar() 			// FUNÇÃO CONSULTAR;
{
	setlocale(LC_ALL,"Portuguese");
	
	char cpf[40];
	char conteudo[200];
				
			
	printf("Digite o cpf a ser consultado: \n");
	scanf("%s",cpf);                                     // pega o cpf digitado 
			
	FILE *file;											// vai nos arquivos e encontra o 'arquivo'
	file = fopen(cpf,"r");								// abre o cpf para ler ' r '
			
	if (file == NULL) 									//SE Nexistir faça...
	{
		printf("Arquivo não localizado!\n");
	}
	while(fgets(conteudo, 200, file) != NULL)			//senão		
	{
		printf("\n Essas são as informações do usuário:");
		printf("%s", conteudo);
		printf("\n\n");
	}
	fclose(file);
	system("pause");
				
}
int deletar() 				// FUNÇÃO DELETAR;
{
	char cpf[40];
		
	setlocale(LC_ALL,"Portuguese");	
	printf("Digite o CPF do USUÁRIO a ser DELETADO: ");
	scanf("%s",cpf);
	remove(cpf);
		
	FILE *file;         								//Função responsável pela biblioteca de arquivamento : FILE  // Parâmentro 'arquivo': file 
	file = fopen(cpf,"r");    							// abrir e ler o arquivo
	
	if(file == NULL) 									//se n existir
	{
		printf("O usuário não se encontra no sistema!  \n");
		system("pause");
		fclose(file);		
	}							

}

int main()   			// 	FUNÇÃO PRINCIPAL 
{
	int opcao=0;                     					//definindo variaveis
	int x=1;   										// variavel 'laço' de repetição do programa
    
	for(x=1;x=1;)                    				 	// definindo o FOR e sua condição para repetir ''enquanto o x for 1 :repetir''
	{
		system("cls");
		setlocale(LC_ALL,"Portuguese");             	// definindo o idioma do texto
		printf("### Cartório da EBAC ###\n\n");     	
    	printf("escolha uma opção desejada no menu\n");
   		printf("\t1 - registrar nomes\n");
   		printf("\t2 - Consultar nomes\n");
   		printf("\t3 - Deletar nomes\n\n");              
   		printf("         .");
    	
		scanf("%d", &opcao);           				//armazenando a escolha do usuario
		system("cls");
    		
   		switch(opcao)   									// inicio da condição ( VAR inserida)
 		{
    		case 1:
    		registro(); 									// chamando função
    		break;
    		case 2:
    		consultar();									// chamando função
			break;
			case 3:
			deletar(); 										//chamando função
			break;
			default: 										// procedimento padrão para 'erro de opção inserida'
			printf("Essa opção não está disponível\n");
			system("pause");	
			break;
		
		} //switch..
	} // for..
     
}  //main..
		
	  
