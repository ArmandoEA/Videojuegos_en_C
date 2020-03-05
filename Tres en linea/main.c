#include <stdio.h>
#include <time.h>

void loop(char c[3][3]);
void Intro_Primera(char c[3][3]);
void Intro_Yo(char[3][3]);
void Intro_IA(char c[3][3]);
void tablero(char c[3][3]);
int ganador(char c[3][3]);

int main()
{
	char c[3][3];
	
	loop(c);
	
	system("pause");
	return 0;
}


void loop(char c[3][3])
{
	int i=0, j;
	
	Intro_Primera(c);
	do{
		system("cls");
		tablero(c);
		
		if(i%2 == 0){
        	Intro_Yo(c);
		}
		else{
			Intro_IA(c);
		}
		j = ganador(c);
		i++;
		
	}while(i<9 && j==2);
	
	system("cls");
	tablero(c);
	if(j==0){
		printf("Has ganado!\n\n");
	}
	else if(j==1){
		printf("Has perdido!\n\n");
	}
	else{
		printf("Has empatado\n\n");
	}
}

void Intro_Primera(char c[3][3])
{
	int i,j;
	char aux='1';
	
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			c[i][j] = aux++;
		}
	}
}

void Intro_Yo(char c[3][3])
{
	int i,j,k;
	char aux;
	do{
		do{
			printf("Coloca una ficha: ");
			fflush(stdin);
			scanf("%c",&aux);
		}while(aux<'1' || aux>'9');
		
		k = 0;
		switch(aux){
			case '1':
			{
				i = 0;
				j = 0;
				break;
			}
			case '2':
			{
				i = 0;
				j = 1;
				break;
			}
			case '3':
			{
				i = 0;
				j = 2;
				break;
			}
			case '4':
			{
				i = 1;
				j = 0;
				break;
			}
			case '5':
			{
				i = 1;
				j = 1;
				break;
			}
			case '6':
			{
				i = 1;
				j = 2;
				break;
			}
			case '7':
			{
				i = 2;
				j = 0;
				break;
			}
			case '8':
			{
				i = 2;
				j = 1;
				break;
			}
			case '9':
			{
				i = 2;
				j = 2;
				break;
			}
		}
		if(aux >= '1' && aux <= '9'){
            if(c[i][j] == 'X' || c[i][j] == 'O'){
				k = 1;
				printf("La casilla esta ocupada\n");
			}
		}
	}while(k==1);
	
	c[i][j] = 'X';
}

void Intro_IA(char c[3][3])
{
	int i,j,k;
	
	srand(time(NULL));
	do{
		i = rand()%3;
		j = rand()%3;
		k = 0;
		
		if(c[i][j]=='X' || c[i][j]=='O'){
			k = 1;
		}
	}while(k==1);
	c[i][j] = 'O';
}

void tablero(char c[3][3])
{
	int i,j;
	
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			if(j < 2){
				printf(" %c |", c[i][j]);
			}
			else{
				printf(" %c ", c[i][j]);
			}
		}
		if(i < 2){
			printf("\n-----------\n");
		}
	}
	printf("\n\n");
}

int ganador(char c[3][3]){
	if(c[0][0] == 'X' || c[0][0] == 'O'){
		if(c[0][0] == c[0][1] && c[0][0] == c[0][2]){
			if(c[0][0] == 'X'){
				return 0;   //has ganado
			}
			else{
				return 1;   //has perdido
			}
		}
		if(c[0][0] == c[1][0] && c[0][0] == c[2][0]){
			if(c[0][0] == 'X'){
				return 0;   //has ganado
			}
			else{
				return 1;   //has perdido
			}
		}
	}
	
	if(c[1][1] == 'X' || c[1][1] == 'O'){
        if(c[1][1] == c[0][0] && c[1][1] == c[2][2]){
			if(c[1][1] == 'X'){
				return 0;   //has ganado
			}
			else{
				return 1;   //has perdido
			}
		}
		if(c[1][1] == c[1][0] && c[1][1] == c[1][2]){
			if(c[1][1] == 'X'){
				return 0;   //has ganado
			}
			else{
				return 1;   //has perdido
			}
		}
		if(c[1][1] == c[2][0] && c[1][1] == c[0][2]){
			if(c[1][1] == 'X'){
				return 0;   //has ganado
			}
			else{
				return 1;   //has perdido
			}
		}
		if(c[1][1] == c[0][1] && c[1][1] == c[2][1]){
			if(c[1][1] == 'X'){
				return 0;   //has ganado
			}
			else{
				return 1;   //has perdido
			}
		}
	}
	
	if(c[2][2] == 'X' || c[2][2] == 'O'){
        if(c[2][2] == c[2][0] && c[2][2] == c[2][1]){
			if(c[2][2] == 'X'){
				return 0;   //has ganado
			}
			else{
				return 1;   //has perdido
			}
		}
		if(c[2][2] == c[0][2] && c[2][2] == c[1][2]){
			if(c[2][2] == 'X'){
				return 0;   //has ganado
			}
			else{
				return 1;   //has perdido
			}
		}
	}
	return 2;
}
