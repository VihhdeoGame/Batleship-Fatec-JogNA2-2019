/************* UDP CLIENT CODE *******************/

#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <locale.h>

#define linha 11
#define coluna 11

//TABULEIRO DO JOGADOR
char myTable[linha][coluna];

//TABULEIRO INIMIGO
char enemyTable[linha][coluna];

void ZerarMapa(char Mapa[linha][coluna]) {
	//Esse código limpa o tabuleiro para começar um jogo novo
    
	int y, x;
    for (x = 0; x < coluna; x++) {
		for (y = 0; y < linha; y++) {
		Mapa[y][x] = ' ';
    }
  }
}

void Submarino(char Mapa[linha][coluna]) {
	//Esse código posiciona os submarinos no tabuleiro impedindo que os mesmos fiquem muito proximos de outros navios.
	
	int i, c, d, rx, ry;
	int valido = 1;
	for(i = 0; i <4 ;i ++) {
		do{
			printf("Escolha a posição X do Submarino %d: ", i+1);		
			scanf("%d", &rx);
			if(rx < 0 || rx >9) printf("Valor inválido\n");
		}while (rx < 0 || rx >9);
		do{
			printf("Escolha a posição Y do Submarino %d: ", i+1);
			scanf("%d", &ry);
			if(ry < 0 || ry >9) printf("Valor inválido\n");
		}while (ry < 0 || ry >9);
		for (d = 0; d < 3; d++) {
			for (c = 0; c < 3; c++) {
				if(rx == 0 && c == 0) c = c + 1;
				if(ry == 0 && d == 0) d = d + 1;  
				if(Mapa[ry + (- 1 + d)][rx + (- 1 + c)] != ' ')
					valido = 0;
			}
		}
		
		if(valido == 1)
			Mapa[ry][rx] = '#';
		else{ 
			printf("Posição inválida, escolha novamente.\n");
			i--; valido = 1;
		}
	}
}


void Cruzador(char Mapa[linha][coluna]) {
	
	//Esse código posiciona os cruzadores no tabuleiro impedindo que os mesmos fiquem muito proximos de outros navios.

	int i, c, d, rx, ry, dir;
	int valido = 1;
	for(i = 0; i <3 ;i ++) {
		do{
			printf("Escolha a posição X do Cruzador %d: ", i+1);		
			scanf("%d", &rx);
			if(rx < 0 || rx >9) printf("Valor inválido\n");
		}while (rx < 0 || rx >9);
		do{
			printf("Escolha a posição Y do Cruzador %d: ", i+1);
			scanf("%d", &ry);
			if(ry < 0 || ry >9) printf("Valor inválido\n");
		}while (ry < 0 || ry >9);
		do
		{
			printf("Para posicionar horizontalmente digite 0, para posicionar verticalmente digite 1: ");
			scanf("%d",&dir);
		} while (dir != 0 && dir != 1);
  		//rx = rand()%10; ry = rand()%10; 
		if(dir == 0){
			for (d = 0; d < 3; d++) {
				for (c = 0; c < 4; c++) {
					if(rx == 0 && c == 0) c = c + 1;
					if(ry == 0 && d == 0) d = d + 1;  
					if(Mapa[ry + (- 1 + d)][rx + (- 1 + c)] != ' ')
						valido = 0;
				}
			}
		}
		if(dir == 1){
			for (d = 0; d < 4; d++) {
				for (c = 0; c < 3; c++) {
					if(rx == 0 && c == 0) c = c + 1;
					if(ry == 0 && d == 0) d = d + 1;  
					if(Mapa[ry + (- 1 + d)][rx + (- 1 + c)] != ' ')
						valido = 0;
				}
			}
		}
		
		if(valido == 1) {
			
			Mapa[ry][rx] = '@';
			//dir = rand()%2;
			if(dir == 0) Mapa[ry][rx + 1] = '@';
			if(dir == 1) Mapa[ry + 1][rx] = '@';
			
		}
		else{
			printf("Posição inválida, Escolha novamente.\n");
			i--; valido = 1;
		}
	}

}

void Encouracado(char Mapa[linha][coluna]) {
	
	//Esse código posiciona os encouraçados no tabuleiro impedindo que os mesmos fiquem muito proximos de outros navios.

	int i, c, d, t, rx, ry, dir;
	int valido = 1;
	for(i = 0; i <2 ;i ++) {
		do{
			printf("Escolha a posição X do Encouraçado %d:", i + 1);		
			scanf("%d", &rx);
			if(rx < 0 || rx >9) printf("Valor inválido");
		}while (rx < 0 || rx >9);
		do{
			printf("Escolha a posição Y do Encouraçado %d:", i + 1);
			scanf("%d", &ry);
			if(ry < 0 || ry >9) printf("Valor inválido");
		}while (ry < 0 || ry >9);
		do
		{
			printf("Para posicionar horizontalmente digite 0, para posicionar verticalmente digite 1: ");
			scanf("%d",&dir);
		}while (dir != 0 && dir != 1);
		if(dir == 0){
			for (d = 0; d < 3; d++) {
				for (c = 0; c < 5; c++) {
					if(rx == 0 && c == 0) c = c + 1;
					if(ry == 0 && d == 0) d = d + 1;  
					if(Mapa[ry + (- 1 + d)][rx + (- 1 + c)] != ' ')
						valido = 0;
				}
			}
		}
		if(dir == 1){
			for (d = 0; d < 5; d++) {
				for (c = 0; c < 3; c++) {
					if(rx == 0 && c == 0) c = c + 1;
					if(ry == 0 && d == 0) d = d + 1;  
					if(Mapa[ry + (- 1 + d)][rx + (- 1 + c)] != ' ')
						valido = 0;
				}
			}
		}
		
		if(valido == 1) {
			
			Mapa[ry][rx] = '$';
			//dir = rand()%2;
			if(dir == 0){
				Mapa[ry][rx + 1] = '$';
				Mapa[ry][rx + 2] = '$';
			}
			if(dir == 1) {
				Mapa[ry + 1][rx] = '$';
				Mapa[ry + 2][rx] = '$';
			}
		}
		else{
			printf("posição invalida, Escolha novamente.\n");
			i--; valido = 1;
		}
	}	
}


void PortaAviao(char Mapa[linha][coluna]) {
	
	//Esse código posiciona os Porta Aviões no tabuleiro impedindo que os mesmos fiquem muito proximos de outros navios.
	
	int i, c, d, t, rx, ry, dir;
	int valido = 1;
	for(i = 0; i < 1 ;i ++) {
		do{
			printf("Escolha a posição X do Porta Aviões:");		
			scanf("%d", &rx);
			if(rx < 0 || rx >9) printf("Valor inválido");
		}while (rx < 0 || rx >9);
		do{
			printf("Escolha a posição Y do Porta Aviões:");
			scanf("%d", &ry);
			if(ry < 0 || ry >9) printf("Valor inválido");
		}while (ry < 0 || ry >9);
		do
		{
			printf("Para posicionar horizontalmente digite 0, para posicionar verticalmente digite 1: ");
			scanf("%d",&dir);
		} while (dir != 0 && dir != 1);
		
		if(dir == 0){
			for (d = 0; d < 3; d++) {
				for (c = 0; c < 6; c++) {
					if(rx == 0 && c == 0) c = c + 1;
					if(ry == 0 && d == 0) d = d + 1;  
					if(Mapa[ry + (- 1 + d)][rx + (- 1 + c)] != ' ')
						valido = 0;
				}
			}
		}
		
		if(dir == 1){
			for (d = 0; d < 6; d++) {
				for (c = 0; c < 3; c++) {
					if(rx == 0 && c == 0) c = c + 1;
					if(ry == 0 && d == 0) d = d + 1;  
					if(Mapa[ry + (- 1 + d)][rx + (- 1 + c)] != ' ')
						valido = 0;
				}
			}
		}
		
		if(valido == 1) {
			
			Mapa[ry][rx] = '&';
			
			if(dir == 0){
				Mapa[ry][rx + 1] = '&';
				Mapa[ry][rx + 2] = '&';
				Mapa[ry][rx + 3] = '&';
			}
			
			if(dir == 1) {
				Mapa[ry + 1][rx] = '&';
				Mapa[ry + 2][rx] = '&';
				Mapa[ry + 3][rx] = '&';
			}
		}
		
		else{
			printf("Posição inválida, escolha novamente.\n");
			i--; valido = 1;
		}
	}	
}

int ganhou = 0;//Variavel para verificar se a condição de vitoria é atingida. 

int contarNavios()
//Este metodo verifica se ainda há navios no tabuleiro.
{
	int i,j;
	ganhou = 1;

	for(i = 0;i<10;i++)
	{
		for(j = 0;j<10;j++)
		{
			if(enemyTable[i][j] == '#' || enemyTable[i][j] == '@' || enemyTable[i][j] == '$' || enemyTable[i][j] == '&')
			{
				ganhou = 0;
				break;
			}
		}
	}

	if(ganhou == 1)
	// Se todos os navios inimigos foram destruidos o jogador venceu.
	{
		printf("\nVOCE GANHOU!!");
		return 0;
	}
	// Caso isso não ocorra o codigo abaixo mantem a variavel de vitoria em 0
	for(i = 0;i<10;i++)
		{
			for(j = 0;j<10;j++)
			{
				if(enemyTable[i][j] == '#' || enemyTable[i][j] == '@' || enemyTable[i][j] == '$' || enemyTable[i][j] == '&')
				{
					ganhou = 0;
					break;
				}
			}
		}
	if(ganhou == 1)
	// Caso o jogador inimigo ganhe, informe que jogador perdeu.
	{
		printf("\nVOCE PERDEU!!");
		return 0;
	}
}

int Attack(int y, int x)
// Este metodo serve para atacar o tabuleiro inimigo.
{
	printf("Canhão nas posições X %d, Y %d",x,y);
	switch(enemyTable[y][x])
	{
		case' ':
		/*CASO A CASA ATACADA FOR VAZIA PREENCHE COM UM SIMBOLO QUE SIGNIFICA QUE O TIRO
		 * FOI ERRADO OU SEJA (O);
		 */
		{
			enemyTable[y][x] = 'O';
			break;
		}
		case'#':
		/*CASO A CASA ATACADA POSSUIR UM NAVIO PREENCHE COM UM SIMBOLO QUE SIGNIFICA QUE O
		* TIRO FOI CERTEIRO OU SEJA (X);
		*/
		{
			enemyTable[y][x] = 'X';
			printf("Você acertou um Submarino deles, continue atirando.\n");
			do
			{
				printf("Digite posição X: ");
				scanf("%d",&x);
				printf("Digite posição Y: ");
				scanf("%d",&y);
				if((x < 0 || x > 9) || (y < 0 || y > 9)) printf("Valores inválidos\n");
			} while ((x < 0 || x > 9) || (y < 0 || y > 9));
	  		Attack(y,x);	
			break;
		}
		case'@':
		/*CASO A CASA ATACADA POSSUIR UM NAVIO PREENCHE COM UM SIMBOLO QUE SIGNIFICA QUE O
		* TIRO FOI CERTEIRO OU SEJA (X);
		*/
		{
			enemyTable[y][x] = 'X';
			printf("Você acertou um Cruzador deles, continue atirando.\n");
			do
			{
				printf("Digite posição X: ");
				scanf("%d",&x);
				printf("Digite posição Y: ");
				scanf("%d",&y);
				if((x < 0 || x > 9) || (y < 0 || y > 9)) printf("Valores inválidos\n");
			} while ((x < 0 || x > 9) || (y < 0 || y > 9));
	  		Attack(y,x);
			break;
		}
		case'$':
		/*CASO A CASA ATACADA POSSUIR UM NAVIO PREENCHE COM UM SIMBOLO QUE SIGNIFICA QUE O
		* TIRO FOI CERTEIRO OU SEJA (X);
		*/
		{
			enemyTable[y][x] = 'X';
			printf("Você acertou um Encouraçado deles, continue atirando.\n");
			do
			{
				printf("Digite posicao X: ");
				scanf("%d",&x);
				printf("Digite posicao Y: ");
				scanf("%d",&y);
				if((x < 0 || x > 9) || (y < 0 || y > 9)) printf("Valores inválidos\n");
			} while ((x < 0 || x > 9) || (y < 0 || y > 9));
	  		Attack(y,x);
			break;
		}
		case'&':
		/*CASO A CASA ATACADA POSSUIR UM NAVIO PREENCHE COM UM SIMBOLO QUE SIGNIFICA QUE O
		* TIRO FOI CERTEIRO OU SEJA (X);
		*/
		{
			enemyTable[y][x] = 'X';
			printf("Você acertou o Porta Aviões deles, continue atirando.\n");
			do
			{
				printf("Digite posição X: ");
				scanf("%d",&x);
				printf("Digite posição Y: ");
				scanf("%d",&y);
				if((x < 0 || x > 9) || (y < 0 || y > 9)) printf("Valores inválidos\n");
			} while ((x < 0 || x > 9) || (y < 0 || y > 9));
	  		Attack(y,x);
			break;
		}
		case'X':
		{
			enemyTable[y][x] = 'X';
			printf("Você já atirou ali, mire em outro lugar.\n");
			do
			{
				printf("Digite posição X: ");
				scanf("%d",&x);
				printf("Digite posição Y: ");
				scanf("%d",&y);
				if((x < 0 || x > 9) || (y < 0 || y > 9)) printf("Valores inválidos\n");
			} while ((x < 0 || x > 9) || (y < 0 || y > 9));
	  		Attack(y,x);
			break;
		}
		case'O':
		{
			enemyTable[y][x] = 'O';
			printf("Você já atirou ali, mire em outro lugar.\n");
			do
			{
				printf("Digite posição X: ");
				scanf("%d",&x);
				printf("Digite posição Y: ");
				scanf("%d",&y);
				if((x < 0 || x > 9) || (y < 0 || y > 9)) printf("Valores inválidos\n");
			} while ((x < 0 || x > 9) || (y < 0 || y > 9));
	  		Attack(y,x);
			break;
		}
	}
	return 0;
}


int PrintTable()
/*ESSE METODO IMPRIMI O TABULEIRO DO JOGADOR E DO INIMIGO NA TELA*/
{
	int i,j;
	printf("\nMEU TABULEIRO\n");
	printf("  0123456789\n");
	printf("------------\n");

	for(i = 0;i<10;i++)	//coluna
	{
		printf("%d|",i);
		for(j = 0;j<10;j++)	//linha
		{
			printf("%c",myTable[i][j]);
		}
		printf("\n");
	}

		printf("TABULEIRO INIMIGO\n");
		printf("  0123456789\n");
		printf("------------\n");

		for(i = 0;i<10;i++)	//coluna
		{
			printf("%d|",i);
			for(j = 0;j<10;j++)	//linha
			{
				char temp = enemyTable[i][j];
				if (temp == '#' || temp == '@' || temp == '$' || temp == '&' )
				/*POR SE TRATAR DO TABULEIRO INIMIGO, NÃO SE PODE MOSTRAR AS CASAS QUE
				 * POSSUEM NAVIO, LOGO O SIMBOLO DO NAVIO É MASCARADO POR UM VAZIO
				 */
				{
					temp = ' ';
				}
				printf("%c",temp);
			}
			printf("\n");
		}
	return 0;
}

int main(){
	/*CODIGOS PARA SOCKET QUE NAO FAÇO A MENOR IDEIA DE COMO FUNCIONA
	*POR FAVOR NAO MEXER POR NADA NESSE MUNDO
	*/
  setlocale(LC_ALL, "Portuguese");
  srand(time(NULL));
  int clientSocket, portNum, nBytes;
  char buffer[1024];
  struct sockaddr_in serverAddr;
  socklen_t addr_size;

  /*Create UDP socket*/
  clientSocket = socket(PF_INET, SOCK_DGRAM, 0);

  /*Configure settings in address struct*/
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(7891);
  serverAddr.sin_addr.s_addr = inet_addr("10.0.0.3");
  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  

  /*Initialize size variable to be used later on*/
  addr_size = sizeof serverAddr;
  
  ZerarMapa(myTable);
  PortaAviao(myTable);
  Encouracado(myTable);
  Cruzador(myTable);
  Submarino(myTable);

  sendto(clientSocket,myTable,sizeof(myTable),0,(struct sockaddr *)&serverAddr,addr_size);
  recvfrom(clientSocket,enemyTable,sizeof(enemyTable),0,NULL, NULL);
  
  printf("VOCE E O PRIMEIRO A JOGAR! c:");
  //PRINTA O COMEÇO DO JOGO
  PrintTable();

  while(1){
	int y, x;

	printf("Seu turno:\n");
    printf("Digite posição X: ");
    scanf("%d",&x);
	printf("Digite posição Y: ");
    scanf("%d",&y);
    printf("\n----------------------------\nSEU TURNO:\n");
    Attack(y,x);
    PrintTable();

    contarNavios();
    /*CHECA SE ESSE JOGADOR VENCEU ANTES DE PERMITIR O MOVIMENTO ADVERSARIO
     *
     */
    if(ganhou == 1)
    {
        break;
    }

    sendto(clientSocket,enemyTable,sizeof(enemyTable),0,(struct sockaddr *)&serverAddr,addr_size);
    /*ENVIA PARA O ADVERSARIO O VETOR COM O TABULEIRO DO ADVERSARIO APOS O ATAQUE DESSE
    *JOGADOR
	*/

    printf("\nAGUARGANDO ADVERSARIO...\n");
    /*AGUARDA O ADVERSARIO FAZER SUA JOGADA E ENVIAR O TABULEIRO DESSE JOGADOR APOS
    * O ADVERSARIO TER REALIZADO SUA JOGADA
	*/
    recvfrom(clientSocket,myTable,sizeof(myTable),0,NULL, NULL);
    printf("\n----------------------------\nTURNO INIMIGO:\n");
    PrintTable();

    contarNavios();
    /*CHECA SE ESSE JOGADOR PERDEU ANTES DE PERMITIR QUE ELE JOGUE
     *
     */
    if(ganhou == 1)
    {
        break;
    }


  }

  return 0;
}
