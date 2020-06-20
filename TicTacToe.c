#include<stdio.h>
int r,c;
char str[3][3]={{'_','_','_'},{'_','_','_'},{'_','_','_'}};
void printTTT()
{
	int i,j;
	i=r;
	j=c;
	printf("\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%5c",str[i][j]);
		}
		printf("\n\n");
	}
	printf("\n");
}
void printTTTC()
{
	int k=0,i,j;
	printf("\n  For refernce to players:\n");
	for(i=0;i<3;i++)
	{
		k++;
		for(j=0;j<1;j++)
		{
			printf("   ________________\n");
			printf("   | %2d | %2d | %2d |\n",k,k+1,k+2);
			k=k+2;
		}
	}
	printf("   ________________\n");
	printf("\n");
}
void switchNum(int n)
{
	switch(n)
	{
		case 1: r=0;
					c=0;
					break;
		case 2: r=0;
					c=1;
					break;
		case 3: r=0;
					c=2;
					break;
		case 4: r=1;
					c=0;
					break;
		case 5: r=1;
					c=1;
					break;
		case 6: r=1;
					c=2;
					break;
		case 7: r=2;
					c=0;
					break;
		case 8: r=2;
					c=1;
					break;
		case 9: r=2;
					c=2;
					break;
		default: printf("Please Enter correct Input\n");
					r=-1;
					c=-1;
	}
}
int checkRow()
{
	int i,j=0;
	for(i=0;i<3;i++)
	{
		if(str[i][j]!=str[i][j+1])
			continue;
		else
		{
			if(str[i][j+1]!=str[i][j+2])
				continue;
			else
			{
				if(str[i][j]=='_')
					continue;
				else
					return 1;
			}
		}
	}
	return 0;
}
int checkCol()
{
	int i=0,j;
	for(j=0;j<3;j++)
	{
		if(str[i][j]!=str[i+1][j])
			continue;
		else
		{
			if(str[i+1][j]!=str[i+2][j])
				continue;
			else
			{
				if(str[i][j]=='_')
					continue;
				else
					return 1;
			}
		}
	}
	return 0;
}
int checkDiag()
{
	int i=0,j=0;
	if(str[i][j]==str[i+1][j+1])
	{
		if(str[i+1][j+1]==str[i+2][j+2])
		{
			if(str[i][j]!='_')
				return 1;
		}
	}
	i=0;
	j=2;
	if(str[i][j]==str[i+1][j-1])
	{
		if(str[i+1][j-1]==str[i+2][j-2])
		{
			if(str[i][j]!='_')
				return 1;
		}
	}
	return 0;
}
void evaluate()
{
	static int i;
	int count=0,j,l;
	char p;
	for(l=0;l<=1;l++)
	{
		if(l==0)
			p='O';
		else
			p='X';
		if(count==0)
		{
			if(i==0)
			{
				if(str[1][1]=='_')
				{
					str[1][1]='O';
					count++;
				}
				else
				{
					str[2][0]='O';
					count++;
				}
				printTTT() ;
			}
			else
			{
				for(j=0;j<3;j++)
				{
					if(str[j][0]!='_' && str[j][1]!='_' && (str[j][0]==str[j][1]))
					{
						if(str[j][2] == '_' && str[j][0]== p)
						{
							str[j][2] = 'O';
							
							printTTT();
							count++;
							break;
						}
					}
					if(str[j][1]!='_' && str[j][2]!='_' && (str[j][1]==str[j][2]))
					{
						if(str[j][0] == '_' && str[j][1]== p)
						{
							str[j][0] = 'O';
							
							printTTT();
							count++;
							break;
						}
					}
					if(str[j][0]!='_' && str[j][2]!='_' && (str[j][0]==str[j][2]))
					{
						if(str[j][1] == '_' && str[j][0]== p)
						{
							str[j][1] = 'O';
							
							printTTT();
							count++;
							break;
						}
					}
			    }
				if(count==0)
				{
					for(j=0;j<3;j++)
					{
						if(str[0][j]!='_' && str[1][j]!='_' && (str[0][j]==str[1][j]))
						{
							if(str[2][j] == '_' && str[0][j] == p)
							{
								str[2][j] = 'O';
								
								printTTT();
								count++;
								break;
							}
						}
						if(str[1][j]!='_' && str[2][j]!='_' && (str[1][j]==str[2][j]))
						{
							if(str[0][j] == '_' && str[1][j]== p)
							{
								str[0][j] = 'O';
								
								printTTT();
								count++;
								break;
							}
						}
						if(str[0][j]!='_' && str[2][j]!='_' && (str[0][j]==str[2][j]))
						{
							if(str[1][j] == '_' && str[0][j]== p)
							{
								str[1][j] = 'O';
								
								printTTT();
								count++;
								break;
							}
						}
					}
				}
				if(count==0)
				{
					int k=0;
					for(j=0;j<1;j++)
					{
						if(str[0][0]!='_' && str[1][1]!='_' && str[1][1]==str[0][0])
						{
							if(str[2][2] == '_' && str[0][0]== p)
							{
								str[2][2]='O';
								
								printTTT();
								count++;
								break;
							}
						}
						if(str[1][1]!='_' && str[2][2]!='_' && str[1][1]==str[2][2])
						{
							if(str[0][0] == '_' && str[1][1]== p)
							{
								str[0][0]='O';
								
								printTTT();
								count++;
								break;
							}
						}
						if(str[0][0]!='_' && str[2][2]!='_' && str[0][0]==str[2][2])
						{
							if(str[1][1] == '_' && str[0][0]== p)
							{
								str[1][1]='O';
								
								printTTT();
								count++;
								break;
							}
						}
					}
				}
				if(count==0)
				{
					int k=0;
					for(j=0;j<1;j++)
					{
						if(str[2][0]!='_' && str[1][1]!='_' && str[1][1]==str[2][0])
						{
							if(str[0][2] == '_' && str[2][0]== p )
							{
								str[0][2]='O';
								
								printTTT();
								count++;
								break;
							}
						}
						if(str[1][1]!='_' && str[0][2]!='_' && str[1][1]==str[0][2])
						{
							if(str[2][0] == '_' && str[0][2]== p)
							{
								str[2][0]='O';
								
								printTTT();
								count++;
								break;
							}
						}
						if(str[0][2]!='_' && str[2][0]!='_' && str[0][2]==str[2][0])
						{
							if(str[1][1] == '_' && str[0][2]== p)
							{
								str[1][1]='O';
								
								printTTT();
								count++;
								break;
							}
						}
					}
				}
			}
		}
	}
	if(count == 0)
	{
		 int k,p=0;
		 if(str[0][0] == '_')
		 {
			printf("\n 13 \n");
			str[0][0]='O';
			printTTT();
			count++;
			//break;
		 }
		 else if(str[0][2]=='_')
		 {
			str[0][2]='O';
			printf("\n 14 \n");
			printTTT();
			count++;
			//break;
		 }
		 else if(str[2][2]=='_')
		 {
			str[2][2]='O';
			printf("\n 15 \n");
			printTTT();
			count++;
			//break;
		 }
		 else if(str[2][0]=='_')
		 {
			str[2][0]='O';
			printf("\n 16 \n");
			printTTT();
			count++;
			//break;
		 }
		 else
		 {
			for(k=0;k<3;k++)
			{
				for(j=0;j<3;j++)
				{
					if(str[k][j]=='_')
					{
						str[k][j]='O';
						printf("\n 17 \n");
						printTTT();
						count++;
						p=1 ;
						break;
					}
				}
				if(p==1)
					break;
			}
		 }
	}
	
	i++;
}



int main()
{
	int n,flag=1,i=0;
	printf("\t\t Welcome to Tic Tac Toe Game:\n ");
	printf("\t\t ____________________________\n");
	printTTTC();
	while(i<5)
	{
		if(flag==1)
		{
			printf("Enter any position : ");
			while(1)
			{
				scanf("%d",&n);
				switchNum(n);
				if(str[r][c]=='_')
				{
					str[r][c]='X';
					if(r!=-1 && c!=-1)
					{
						printTTT();
						break;
					}
				}
				else
					printf("Enter Correct Position : ");

			}

			int k=checkRow();
			int p=checkCol();
			int m=checkDiag();
			if(k==1||p==1||m==1)
			{
				printf("Player 1 has won\n");
				break;
			}
			if(i!=4)
				flag=0;
		}
		if(flag==0)
		{
			printf(" Its Computer Choice now");
			evaluate();

			int k=checkRow();
			int p=checkCol();
			int m=checkDiag();
			if(k==1||p==1||m==1)
			{
				printf("Computer has won\n");
				break;
			}
			flag=1;
		}
		i++;
	}
	if(i==5)
	{
		printf("Game tie\n");
		printf("Thank you for playing the game\n");
	}
	
		
	return 0;


}

