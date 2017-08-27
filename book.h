struct book{
};

void display_book_menu()
{
	int choice;
	system("clear");
	printf("Select your Choice.\n"
	"1: Add Book\n"
	"2: Edit Book\n"
	"3: Delete Book\n"
	"4: View Books\n"
	"5: Go Back\n"
	"0: Logout\n");
	scanf("%d", &choice);
	switch(choice)
	{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
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

void display_issue_menu()
{
	int choice;
	system("clear");
	printf("Select your Choice.\n"
	"1: Issue Book\n"
	"2: Re-issue Book\n"
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
