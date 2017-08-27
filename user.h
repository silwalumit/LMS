void select_menu();
void add_user();
struct users {
	char username[20];
	char password[20];		
};

void display_user_menu()
{
	int choice;
	system("clear");
	printf("Select your Choice.\n"
	"1: Add User\n"
	"2: Edit User\n"
	"3: Delete User\n"
	"4: Go Back\n"
	"0: Logout\n");
	scanf("%d", &choice);
	switch(choice)
	{
		case 1:
			add_user();
			break;
		case 2:
			break;
		case 3: 
			break;
		case 4:
			select_menu();
			break;	
		case 0:
			system("clear");
			system("exit");
			break;
		default:
			printf("Invalid Selection!\n");
			display_user_menu();
			break;
	}
}

int user_exists(FILE * fPtr, char *username){
	struct users user;
	rewind(fPtr);
	while(!feof(fPtr)){
		fread(&user, sizeof(struct users), 1, fPtr);
		if((strcmp(user.username, username)) == 0)
		{
			return 1;
		}
	}
	return 0; 
}

void add_user(){
	
		struct users user;
		char choice;
		system("clear");
		FILE *fPtr;
		if((fPtr = fopen("userinfo.dat", "rb")) == NULL)
		{
			printf("File couldn't be located."); 
		}
		else
		{
			do{			
				puts("Enter username and password.");
				printf("Username:");		
				scanf("%s", user.username);
				if(user_exists(fPtr, user.username))		
				{
					printf("User already exists. Please Choose another.\n");
					add_user(fPtr);
				}
				else
				{
					printf("Password:");
					scanf("%s", user.password);
					fwrite(&user, sizeof(struct users), 1, fPtr);
					printf("More? ");
					scanf(" %c", &choice);
					fflush(stdin);
				}
			}while(choice  == 'Y' || choice == 'y');
		}	
}


void delete_user()
{
	
}


