#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "user.h"
#include "member.h"
#include "book.h"

#define ENTER 10
#define TAB 9
#define BKSP 127

int getch(void);
void login();
int user_exists(FILE *,char *);

char *hide_password(char *);
int validate_login(char *, char *);
void display_user_menu();
void display_member_menu();
void display_book_menu();
void display_issue_menu();
int main()
{

	puts("Welcome to Library Management System!\n");
	login();
	return 0;
}

void login()
{
	struct users user;
	puts("Enter your login credentials.");

	printf("Username:");
	fgets(user.username, 20, stdin);
	printf("Password:");
	
	strcpy(user.password, hide_password(user.password));
	printf("\n");
	if(validate_login(user.username, user.password) == 1)
	{
		select_menu();
	}
	else
	{
		system("clear");
		printf("Access Denied. Invalid Password or Username\n");
		login();
	}
}

int validate_login(char * username, char * password)
{
	FILE *fPtr;
	if((fPtr = fopen("userinfo.dat", "rb")) == NULL)
	{
		printf("File couldn't be located."); 
	}
	else
	{
		struct users user;
		while(!feof(fPtr))
		{
			fread(&user, sizeof(struct users),1,fPtr);
			if((strcmp(username, user.username) && strcmp(password, user.password)) == 0)
			{
				fclose(fPtr);
				return 1;
			}
		}
	}	
	fclose(fPtr);
	return 0;
}

char *hide_password(char *password)
{
	int i = 0;
	char ch; 
	while(1)
	{
		ch = getch();//get key
		
		if(ch == ENTER || ch == TAB)
		{	
			password[i] = '\0';
			break;
		}
		else if(ch == BKSP)
		{
			if(i > 0)
			{
				i--;
				printf("\b \b");
			}
		}
		else
		{
			password[i++] = ch;
			printf("* \b"); //replace password character with *
		}
	}
	return password;
}
void select_menu()
{
	int choice;
	system("clear");
	printf("Select your Choice.\n"
	"1: User Record\n"
	"2: Member Record\n"
	"3: Book Record\n"
	"4: Issue/Re-issue Book\n"
	"5: Return Book\n"
	"0: Logout\n");
	scanf("%d", &choice);
	
	switch(choice)
	{
		case 0:
			system("clear");
			system("exit");
			break;
		case 1:
			display_user_menu();
			break;
		case 2:
			display_member_menu();
			break;
		case 3:
			display_book_menu();
			break;
		case 4:
			display_issue_menu();
			break;
		case 5:
			printf("Book return");
			break;		
		default:
			printf("Invalid Selection!\n");
			select_menu();
			break;
	}
	
	
}
/* reads from keypress, doesn't echo */
int getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}
