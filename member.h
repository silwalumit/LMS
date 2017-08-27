
struct members {
			
};

void display_member_menu()
{
	int choice;
	system("clear");
	printf("Select your Choice.\n"
	"1: Students\n"
	"2: Teachers\n"
	"3: Go Back\n"
	"0: Logout\n");
	scanf("%d", &choice);
	switch(choice)
	{
		case 1:
			break;
		case 2:
			break;
		case 3:
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
