#include <stdio.h>
#include <stdlib.h>
#include "keyword.h"

int is_whitespace(char c)
{
	if (c == ' '  || c == '\t' || c == '\n' || c == '\r' || c == '('  || c == ')' )
	{	return 1; // 공백글자다.
		return 0; // 유의미한 글자다.	
	}
}	

int fget_word(FILE *fp, char *word)
{
	char c;
	int cnt;

	while( (c=fgetc(fp)) != EOF)//유의미한 글자가 나올때까지 입력된 글자 버림 반복  
	{	
		if(is_whitespace(c)==0)
		{
			break;
		}
	}

	if(c == EOF)//최초 읽은 문자가 마지막일 때  
	{
		return 0; 
	} 
	
	//유의미한 글자저장 
	cnt = 0;  
	word[cnt++] = c; //아까 읽은 첫글자 입력  
	word[cnt]='\0';		//혹시 뒤에서 못 읽을 수 있으므로  

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
	scanf("%s", name); //&를 붙이면 안된다.
	 
//fopen
	fp=fopen(name, "r"); //읽기모드로 파일 열기 ->r 
	
//error handling (방어코드)
	if(fp==NULL)
	{
		printf("ERROR! check the file name : %s\n",name);
		return -1; //비정상적인 종료를 의미한다. 
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
	
