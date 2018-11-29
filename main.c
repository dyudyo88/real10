#include <stdio.h>
#include <stdlib.h>
#include "keyword.h"

int is_whitespace(char c)
{
	if (c == ' '  || c == '\t' || c == '\n' || c == '\r' || c == '('  || c == ')' )
	{	return 1; // ������ڴ�.
		return 0; // ���ǹ��� ���ڴ�.	
	}
}	

int fget_word(FILE *fp, char *word)
{
	char c;
	int cnt;

	while( (c=fgetc(fp)) != EOF)//���ǹ��� ���ڰ� ���ö����� �Էµ� ���� ���� �ݺ�  
	{	
		if(is_whitespace(c)==0)
		{
			break;
		}
	}

	if(c == EOF)//���� ���� ���ڰ� �������� ��  
	{
		return 0; 
	} 
	
	//���ǹ��� �������� 
	cnt = 0;  
	word[cnt++] = c; //�Ʊ� ���� ù���� �Է�  
	word[cnt]='\0';		//Ȥ�� �ڿ��� �� ���� �� �����Ƿ�  

	while( (word[cnt]=fgetc(fp)) != EOF)
	{
		if( is_whitespace(word[cnt]) == 1)
		{
			word[cnt] = '\0';
			break;
		 } 
		 cnt++;
	}
	

	return cnt;
 } 


  int main(){
	
	FILE *fp;
	char name[100];
	char word[100];
	
//printf, scanf
	printf("Input the file name : ");
	scanf("%s", name); //&�� ���̸� �ȵȴ�.
	 
//fopen
	fp=fopen(name, "r"); //�б���� ���� ���� ->r 
	
//error handling (����ڵ�)
	if(fp==NULL)
	{
		printf("ERROR! check the file name : %s\n",name);
		return -1; //���������� ���Ḧ �ǹ��Ѵ�. 
	}


while(fget_word(fp, word) != 0)
{
	//word processing
	count_word(word);
}
print_word();



//fclose 
	fclose(fp);
} 
	
