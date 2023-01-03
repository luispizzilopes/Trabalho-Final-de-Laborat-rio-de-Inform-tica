/*
Enunciado: Escreva um programa em Linguagem C para controlar o treino de classifica��o de um
Grande Pr�mio (GP) de FormulaX. Sabe-se que o treino ser� realizado em 8 voltas e participar�o 12
pilotos. O circuito tem 4.275 metros. Os dados devem ser armazenados em 2 matrizes, distintas:
a) de tempos. b) de nomes dos pilotos (strings). Carregando os dados, analise e apresente:
A. Qual o tempo gasto por cada piloto (�quadro� de tempo) para todas as voltas.
- apresentar os valores de uma forma tabulada.
- apresentar os tempos em MM:SS:mmm (M = Minutos / S = Segundos / m=mil�simos)
B. Qual a m�dia de tempo de cada piloto? (s� usar as voltas contabilizadas com tempo)
C. Qual a m�dia de tempo de cada volta? (n�o contabilizar tempos nulos)
D. Quantas voltas cada piloto liderou?
E. Quais pilotos abandonaram o treino antes do final?
F. Apresentar o grid de largada (classifica��o do treino).
- apresentar o nome do piloto, o tempo da volta e a diferen�a de tempo entre eles (pilotos).
- o grid � formado pelo melhor tempo de cada piloto (independente da volta).
G. Apresentar a classifica��o volta a volta (para cada volta, apresentar a classifica��o tempor�ria).
H. Dar a possibilidade de, baseado no nome do piloto, apresentar todo scouting deste piloto.
I. (extra) Apresentar alguma informa��o relevante / interessante baseada no conjunto de dados.

/**********************************************************************
Nome: Luis Felipe Pizzi Lopes
Turma: ADS 2022.2
Mat�ria: Laborat�rio de inform�tica
Exerc�cio: Trabalho final
**********************************************************************/

//Bibliotecas utilizadas para desenvolver o algoritmo
#include <stdio.h>
#include <string.h>

//Array multidimensional criado e inicializado com todos os dados de tempo passados no projeto
int Tempo[8][12] = {{68925,70341,69311,67409,68026,70597,67392,69421,69520,68299,70680,69680}, 
					{70874,67839,67655,67034,67142,68220,68193,70841,70538,70251,67475,70189}, 
					{67130,70221,68724,69749,67324,70798,88349,70560,67913,69648,69113,70029},
					{67281,67934,67305,70456,68964,67950,00000,70639,68992,68938,69974,70536},
					{67982,70697,70378,70099,68711,67120,00000,69508,69605,70866,68862,69198},
					{68295,68899,70987,69509,69323,69417,00000,68713,68902,70069,74761,69941},
					{67388,69958,67665,67808,70645,68582,00000,68855,67001,70871,00000,70340}, 
					{68770,67258,67339,70602,67360,68681,00000,69986,67548,69699,00000,67211}}; 
//Array multidimensional criado e inicializado com todos os dados de nomes dos pilotos passados no projeto	 
char Nomes[12][50] = {{"Max Verstappen"}, {"Daniel Ricciardo"}, {"Lando Norris"}, {"Sebastian Vettel"}, 
					{"Nicholas Latifi"}, {"Pierre Gasly"}, {"Sergio Perez"}, {"Fernando Alonso"}, 
					{"Charles Leclerc"},{"Lance Stroll"}, {"Kevin Magnussen"}, {"Yuki Tsunoda"}}; 

//Procedimento de converter o tempo em Milissegundos para minutos,segundos e milissegundos		
void ConverterMilissegundos(int tempo)
{
	int minuto, segundos, milis;

	minuto = tempo / 60000; 
	segundos = tempo % 60000 / 1000; 
	milis = tempo % 1000; 
	printf("%d:%d:%03d", minuto,segundos,milis); 
}

//Procedimento utilizado para mostrar a tabela de tempo de cada volta de todos os piloto na tela
void TabelaPilotos()
{
	int i, j; 
	for(j=0;j<12;j++) //La�o de repeti��o for para passar primeiro pelas colunas
	{	
		printf("\n------------------------------------------------\n        Quadro de tempo do %s: \n------------------------------------------------\n", Nomes[j]);
		for(i=0;i<8;i++) //La�o de repeti��o for para passar pelas linhas 
		{
			printf("\nVolta %d - ", i+1); 
			ConverterMilissegundos(Tempo[i][j]); //Apresenta��o do tempo de cada volta de cada piloto convertido em min,seg,mil pela fun��o criada
		}
		printf("\n\n"); 
		system("pause"); 
	}
}

//Procedimento utilizado para mostrar a media de tempo de cada volta de forma geral
void MediaTempoVoltas()
{
	int i, j; 
	int media=0, cont=0; 
	
	printf("\n\n"); 
	printf("------------------------------------------\n       MEDIA DE TEMPO DE CADA VOLTA \n------------------------------------------\n");
	for(i=0;i<8;i++) //La�o de repeti��o que come�a pelas linhas pois cada volta corresponde a uma linha completa
	{	
		printf("\nMedia da volta %d: ", i+1);
		for(j=0;j<12;j++) //Passagem por cada coluna
		{	
			if(Tempo[i][j] > 0) //Condi��o para verificar se o tempo armazenado na matriz � diferente de zero
			{
				media += Tempo[i][j]; //Caso seja diferente de zero o vari�vel media recebe o valor da posi��o da matriz 
				cont++; //Vari�vel contador recebe mais 1 para realizar a divis�o depois
			}
		}
		media = media / cont; //Dividir a soma pelo contador para ter a m�dia exata
		ConverterMilissegundos(media); //Chamar o procedimento de apresenta��o do valor convetido
		printf("\n");
		media = 0; //Zerando as vari�veis auxiliares para refazer o la�o de repeti��o interno 
		cont = 0; 
	}
}

//Procedimento utilizado para mostrar a media de tempo de cada piloto
void MediaTempoPilotos()
{
	//Vari�veis utilizadas dentro do procedimento
	int i, j;
	int media=0, cont=0; 
	
	printf("\n");
	printf("------------------------------------------\n     MEDIA DE TEMPO DE CADA PILOTO \n------------------------------------------\n");
	for(j=0;j<12;j++) //La�o de repeti��o que come�a pelas colunas pois uma coluna inteira corresponde a todas as voltas de um piloto
	{	
		printf("\nMedia de tempo do %s: ", Nomes[j]); //Sa�da do nome do piloto
		for(i=0;i<8;i++) //La�o de repeti��o para passar em todas as linhas da coluna do la�o de repeti��o de fora
		{
			if(Tempo[i][j] > 0) //Condi��o para verificar se o valor da matriz naquela posi��o � maior que zero
			{
				media += Tempo[i][j]; //Caso seja maior que zero, a vari�vel m�dia recebe o valor da matriz 
				cont++; //E contador ganha um incremento de +1
			}
		}
		media = media / cont; //Divis�o para calculo da m�dia 
		ConverterMilissegundos(media); //Chamar o procedimento de apresenta��o do valor convetido
		printf("\n");
		media = 0; //Zerar as vari�veis auxiliares
		cont = 0; 
	}
}

//Procedimento para verificar quantas rodadas cada piloto ficou na lideran�a e apresentar ao usu�rio
void LiderancaPilotos()
{
	int i, j;
	int menor=0, cont=0, aux=0;
	int pilotos[12] = {0,0,0,0,0,0,0,0,0,0,0,0}; //Vetor de 12 posi��es inicializados com 0, cada posi��o � referente a um corredor  
	
	printf("\n\n"); 
	for(i=0;i<8;i++) //La�o de repeti��o de repeti��o que come�a nas linhas para percorrer cada volta por completa
	{	
		for(j=0;j<12;j++) //Passando pelas colunas para verificar o valor da volta de cada piloto 
		{	
			if (aux == 0) //Caso o valor de auxiliar seja igual a zero ele armazena o primeiro valor que passar pelo la�o
			{
				menor = Tempo[i][j]; 
				cont = j; //Armazena a posi��o da coluna
				aux = 1; //E muda o valor de aux para quebrar a primeira condi��o
			}
			
			if (Tempo[i][j] < menor && Tempo[i][j] != 0) //Caso o valor da matriz seja menor que o tempo armazenado na vari�vel menor e diferente de zero
			{
				menor = Tempo[i][j]; //A vari�vel menor recebe o valor da posi��o da matriz
				cont = j; //Contador ganha a posi��o de j
			}
		}
		pilotos[cont] += 1; //A posi��o de j que foi armazenada na vari�vel cont corresponde a posi��o do piloto dentro do vetor pilotos,
							//pilotos recebe +1 para informar que aquele piloto naquela posi��o ganhou uma volta
		cont = 0;	//Zerando as vari�veis aux
		aux = 0; 
	}
	//La�o de repeti��o para sa�da de dados da matriz de nomes e do vetor de n�mero de voltas ganhas pelo piloto
	for(i=0;i<12;i++)
	{
		printf("O piloto %s venceu %d volta(s)!", Nomes[i], pilotos[i]);
		printf("\n------------------------------------------\n");
	}
}

//Procedimento para verificar quais pilotos abandonaram o treino antes do final
void AbandonaramTreino()
{
	int i, j; //Vari�veis utilizadas durante o o procedimento
	int pilotos[12] = {0,0,0,0,0,0,0,0,0,0,0,0}; //Array de 12 posi��es (cada posi��o representa um piloto)
	
	printf("\n\n"); 
	for(i=0;i<8;i++) //La�o de repeti��o passando primeiro pelas linhas
	{	
		for(j=0;j<12;j++) //E depois pelas colunas
		{	
			if (Tempo[i][j] == 0) //Condi��o para verificar se aquela posi��o do vetor est� zerado, caso esteja a posi��o da coluna (referente ao piloto) recebe 1
			{
				pilotos[j] = 1; 
			}
		}
	}
	//La�o de repeti��o para percorrer o array e verificar se � diferente de 0
	for(i=0;i<12;i++)
	{
		if(pilotos[i] != 0)
		{
			printf("O piloto %s abandonou o treino!\n\n", Nomes[i]); //Caso seja, significa que aquele piloto da posi��o do array abandonou a corrida
		}
	}
}


//Procedimento para apresentar o Grid da melhor volta de cada piloto
void Grid()
{
	int i, j ,aux = 0; 
	int melhorvolta[12]; //Array para armazenar a melhor volta de cada piloto
	
	printf("\n----------------------------------------------------------------\n                           GRID DE LARGADA \n----------------------------------------------------------------\n");
	for(j=0;j<12;j++) //La�o de repeti��o come�ando pelas colunas (cada coluna � referente as voltas de um �nico piloto)
	{	
		for(i=0;i<8;i++)//Percorrendo as linhas de um �nico piloto
		{
			//Condicional para pegar o primeiro valor e ter como refer�ncia para outros valores
			if(aux == 0)
			{
				melhorvolta[j] = Tempo[i][j]; 
				aux++;  
			}
			//Condicional para receber o melhor tempo do piloto que seja diferente de zero
			if ((Tempo[i][j] < melhorvolta[j]) && Tempo[i][j] != 0)
			{
				melhorvolta[j] = Tempo[i][j]; 
			}
		}
		aux = 0; //Zerar a aux
	}
	
	int valor=0, cont=0; 
	char valornome[50]; 
	//Array de nomes para inverter as posi��es de acordo com o grid
	char Nomes[12][50] = {{"Max Verstappen"}, {"Daniel Ricciardo"}, {"Lando Norris"}, {"Sebastian Vettel"},
						 {"Nicholas Latifi"}, {"Pierre Gasly"}, {"Sergio Perez"}, {"Fernando Alonso"}, 
						 {"Charles Leclerc"},{"Lance Stroll"}, {"Kevin Magnussen"}, {"Yuki Tsunoda"}};			
	for(i=0;i<12;i++)
	{
		for(j=i+1;j<12;j++)
		{
			if (melhorvolta[i] > melhorvolta[j])
			{
				//Trocar as posi��es do array de melhor volta de cada piloto
				valor = melhorvolta[i]; 
				melhorvolta[i] = melhorvolta[j]; 
				melhorvolta[j] = valor;
				//Trocar as posi��es de nome de nome dos pilotos para o �ndice concidir com o �ndice de melhor volta
				strcpy(valornome,Nomes[i]);
				strcpy(Nomes[i],Nomes[j]);
				strcpy(Nomes[j], valornome); 
			}
		}
		//Sa�da de dados
		printf("\n#%d %s - ", i+1, Nomes[i]); 
		ConverterMilissegundos(melhorvolta[i]); //Chamada da fun��o de conves�o
		if (cont == 0) //Vari�vel cont para n�o apresentar a diferen�a de tempo do primeiro colocado
		{
			cont++; 
			printf("\n"); 
		}
		else
		{
			printf(" || Diferenca de tempo do #1: "); 
			int diferenca = melhorvolta[0] - melhorvolta[i]; 
			ConverterMilissegundos(-diferenca); //Chamar a fun��o de convers�o com o valor negativo para mostrar o valor positivo da diferen�a na tela
			printf("\n"); 
		}
	}
	printf("-----------------------------------------------------------------------\n");
}

//Procedimento para mostrar ao usu�rio o Grid por volta 
void ClassPorVolta()
{
	int i, j ,aux = 0;
	int linha = 0; 
	int volta = 1; 
	
	while (linha < 8) //La�o para repetir o bloco 8 vezes (n�mero de voltas)
	{
		unsigned int voltas[12] = {0,0,0,0,0,0,0,0,0,0,0,0}; //Array do tipo unsigned int para aceitar apenas valores positivos
		
		printf("\n-----------------------------------------------------------------------\n\n");
		for(j=0;j<12;j++) //La�o para pegar a volta de cada piloto
		{	
			if (Tempo[linha][j] != 0) //Caso o valor seja maior que zero, a volta � armazenada no vetor
			{
				voltas[j] = Tempo[linha][j];
			} 
			else
			{
				voltas[j] = -1; //Caso contrario o valor daquela posi��o recebe -1
			}
		}
		aux = 0;
		linha++; //Aumentar o valor da linha para rodar o la�o para a prox�ma volta
		
		int valor=0, cont=0; 
		char valornome[50]; 
		char Nomes[12][50] = {{"Max Verstappen"}, {"Daniel Ricciardo"}, {"Lando Norris"}, {"Sebastian Vettel"},
							 {"Nicholas Latifi"}, {"Pierre Gasly"}, {"Sergio Perez"}, {"Fernando Alonso"}, 
							 {"Charles Leclerc"},{"Lance Stroll"}, {"Kevin Magnussen"}, {"Yuki Tsunoda"}};
							 
		printf("Resultado da volta %d: \n\n", volta);			
		for(i=0;i<12;i++)//La�os para inverter a posi��o pela ordem crescente (do menor para o maior)
		{
			for(j=i+1;j<12;j++)
			{
				if (voltas[i] > voltas[j])
				{
					//Inverter as posi��es de melhor volta 
					valor = voltas[i]; 
					voltas[i] = voltas[j]; 
					voltas[j] = valor;
					//Inverter as posi��es dos nomes de acordo com o mesmo �ndice da volta
					strcpy(valornome,Nomes[i]);
					strcpy(Nomes[i],Nomes[j]);
					strcpy(Nomes[j], valornome); 
				}
			}
			if (voltas[i] == -1) //Caso o valor da volta seja menos um, significa que o piloto abandonou a corrida
			{
				printf("%s Abandandou o treino \n\n", Nomes[i]); 
			}
			else //Caso contr�rio sa�da de dados com o nome do piloto 
			{
				printf("#%d %s - ", i+1, Nomes[i]); 
				ConverterMilissegundos(voltas[i]);
				if (cont == 0) //Caso seja o primeiro n�o vai aparecer diferen�a de tempo
				{
					cont++; 
					printf("\n\n"); 
				}
				else //Sa�da da diferen�a de tempo para o primeiro colocado 
				{
					printf(" || Diferenca de tempo do #1: "); 
					int diferenca = voltas[0] - voltas[i]; 
					ConverterMilissegundos(-diferenca);
					printf("\n\n"); 
				}
			}
		}
		printf("-----------------------------------------------------------------------\n");
		volta++; 
		system("pause"); 
	}
}

//Fun��o para consultar o nome e passar o return do valor do piloto para o procedimento "Scouting"
int Consulta()
{
	int i, aux=0;
	char nomeconsulta[50]; 
	
	system("cls"); 
	printf("\nLista de nomes:\n\n"); 
	for(i=0;i<12;i++) //Apresentar uma lista de nomes possiveis
	{
		printf("%s\n", Nomes[i]); 
	}
	printf("\nInforme o nome do piloto que deseja consultar o scouting: ");
	scanf(" %[^\n]", &nomeconsulta); //Entrada do nome do piloto que deseja consultar
	
	for(i=0;i<12;i++)
	{
		if(strcmp(nomeconsulta, Nomes[i]) == 0) //Caso o usu�rio informe um valor que esteja na matriz de nomes 
		{
			system("cls"); 
			printf("Scouting do piloto %s:\n\n", Nomes[i]); 
			return i; //A fun��o retorna o valor da coluna referente ao piloto
		}
		else if (aux == 0) //Caso n�o encontre 
		{
			printf("\nInformacao invalida!\n"); //Mostrar op��o invalida apenas uma vez, fazendo esse controle pela auxiliar 
			aux++; 
		}
	}
	return -1; //Retornar -1 caso n�o seja uma busca v�lida
}

//Procedimento utilizado para apresentar ao usu�rio o Scouting do piloto informado
void Scouting(int piloto) //Receber a posi��o da coluna do piloto a partir da fun��o Consulta()
{
	int i, j, valor, media=0, cont=0; 
	unsigned int melhorVoltaPiloto[8] = {0,0,0,0,0,0,0,0}; 
	
	if (piloto >= 0 && piloto <= 11) //Condi��o para verificar se a coluna do piloto � v�lida
	{
		//Sa�da de dados do tempo de cada volta do piloto
		for(i=0;i<8;i++)
		{
			if (Tempo[i][piloto] > 0)
			{
				printf("\nTempo na #%d volta: ", i+1); 
				ConverterMilissegundos(Tempo[i][piloto]);
				printf("\n\n"); 
				
				melhorVoltaPiloto[i] = Tempo[i][piloto]; //Armazenar o valor no vetor que ser� utilizado logo ap�s
				media += Tempo[i][piloto];  //Armazenar na vari�vel para determinar a m�dia depois
				cont++; //Contador para dividir pela m�dia
				
				system("pause");
			}
			else //Caso o valor seja 0, o programa vai informar que o piloto abandonou a volta
			{
				printf("Tempo na #%d volta: ", i+1);
				printf("Abandonou o treino!\n\n"); 
				melhorVoltaPiloto[i] = -1; //E vai atribuir -1 no vetor de voltas do piloto 
				system("pause");
			}
		}
		
		system("cls"); 
		
		printf("Tabela de melhor performace de tempo do piloto: \n"); 
		for(i=0;i<8;i++)
		{
			for(j=i+1;j<8;j++) //Trocar as posi��es de ordem crescente (do menor para o maior)
			{
				if (melhorVoltaPiloto[i] > 	melhorVoltaPiloto[j])
				{
					valor = melhorVoltaPiloto[i]; 
					melhorVoltaPiloto[i] = melhorVoltaPiloto[j]; 
					melhorVoltaPiloto[j] = valor;
				}
			}
			if (melhorVoltaPiloto[i] != -1) //Caso o valor seja diferente de -1 (-1 significa que abandonou o treino)
			{
				printf("%d - ", i+1); 
				ConverterMilissegundos(melhorVoltaPiloto[i]); //Apresentar o valor convertido da volta
				printf("\n");
			}
			else //Caso seja -1
			{
				printf("%d - Abandonou o treino!\n", i+1); 	//Apresentar que o piloto abandonou o treino
			}
		}
		
		system("pause"); 
		system("cls"); 
		//Apresentar a m�dia daquele piloto
		media = media / cont; 
		printf("\nA media de voltas validas do piloto e: "); 
		ConverterMilissegundos(media); 
		printf("\n"); 
	}	
}

//(extra) Apresentar alguma informa��o relevante / interessante baseada no conjunto de dados
void Adicional() 
{
	int i, j, tempototal=0, cont=0; 
	
	for(i=0;i<8;i++)
	{
		for(j=0;j<12;j++)
		{
			if (Tempo[i][j] > 0)
			{
				tempototal += Tempo[i][j]; 
				cont++; 
			}
		}
	}
	
	tempototal = tempototal / cont; 
	
	printf("\nA media da soma de todos os tempos validos dos pilotos e: "); 
	ConverterMilissegundos(tempototal);
	printf("\n"); 
}


//Fun��o principal do sistema
int main(void)
{
	int opc;
	char sn;  
	//La�o de repeti��o para apresentar um menu com criterio de parada
	do
	{
		printf("-----------------------------MENU----------------------------\n\n"); 
		printf("1 - APRESENTAR O QUADRO DE TEMPO DE TODOS OS PILOTOS\n");
		printf("2 - APRESENTAR A MEDIA DE TEMPO DE CADA PILOTO\n");
		printf("3 - APRESENTAR A MEDIA DE TEMPO DE CADA VOLTA\n");
		printf("4 - APRESENTAR QUANTAS VOLTAS CADA PILOTO LIDEROU\n");
		printf("5 - APRESENTAR QUAIS PILOTOS ABANDONARAM O TREINO ANTES DO FINAL\n");
		printf("6 - APRESENTAR O GRID DE LARGADA (CLASSIFICACAO DO TREINO)\n"); 
		printf("7 - APRESENTAR CLASSIFICACAO VOLTA A VOLTA)\n");
		printf("8 - CONSULTA POR NOME DO SCOUTING DOS PILOTOS\n"); 
		printf("9 - INFORMACAO ADICIONAL!\n");
		printf("\n--------------------------------------------------------------\n"); 
		printf("Informe a opcao que voce deseja: \n");
		scanf("%d", &opc); 
		system("cls");
		//Estrutura de sele��o para verificar qual op��o o usu�rio deseja
		if (opc == 1) TabelaPilotos();
		else if (opc == 2) MediaTempoPilotos(); 
		else if (opc == 3) MediaTempoVoltas(); 
		else if (opc == 4) LiderancaPilotos(); 
		else if (opc == 5) AbandonaramTreino(); 
		else if (opc == 6) Grid(); 
		else if (opc == 7) ClassPorVolta();
		else if (opc == 8) Scouting(Consulta()); 
		else if (opc == 9) Adicional(); 
		else printf("\nOpcao Invalida!\n"); 
		
		printf("\nDeseja voltar para o menu? (S/N)"); 
		scanf(" %c", &sn); 
		system("cls");
	} while (sn == 's' || sn == 'S');
	
	return 0; 
}
