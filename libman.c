/*Library Management*/


//Packages
#include <stdio.h>
#include<ctype.h>
#include<string.h>
#include <stdlib.h>

//Function Declaration
void clean_stdin();
void rules();
void admin_Login();
void addBook();
void showAllBook();
void searchBook();
void removeBook();
void updateBook();


//Structure for Books

typedef struct addBook
{
	char title[20];
    char author[20];
    int page;
    float price;
}Book;

Book *book;      //Global Book type Pointer

int count=0;   //Global Count Variable
int size;        //Global Variable for Dynamic Memory Allocation


//Main Function
void main()
{
	char space;
	printf("\t\t\t\tLIBRARY \n");

	printf("  \n  ");
	printf("\t\t\tWELCOME\n\n");
	

// calling of admin_Login() function     
	admin_Login();                 

	printf("Enter Total NO. of Books you Want to Add in LIBRARY : ");
	     scanf("%d",&size);

 //Create Book Array Dynamic using size input by User
        
         book = (Book*) malloc(sizeof(Book)*size);
 //Selecting Choice of User   
     do                                                   // to repeat
  {

    //system("cls");
    printf("\n 1.Add Book \n 2.Show All Book \n 3.Search Book \n 4.Remove Book \n 5.Update Book \n 6.Rules\n 7.EXIT\n");		  
    printf("\nEnter your choice : ");
	int choice;
	scanf("%d",&choice);
	  switch (choice)
	  {
	  case 1:
	        addBook();
		  break;
	  case 2:
	        showAllBook();
	      break;
	  case 3:
	        searchBook();
	      break;
	  case 4:
	        removeBook();
	      break;
	  case 5:
	        updateBook();
	      break;
	  case 6:
	        rules();
		  break;	
	  case 7:
	        return;			  	  	  	  
	  default:
	        printf("\tYou Entered The Wrong Choice");
		  break;
	  }
	  printf("\n\t\t\t\t Press Enter to continue");
    	 scanf("%c",&space);
 }while(1);
	  
}


//Admin login and Password checking
void admin_Login()
{

}


// List Rules to be followed in Libary
void rules()
{
	printf("\t\t\t\t\tLIBARY RULES AND REGULATIONS  \n");
	printf("\t\t\t\t---------------------------------\n");
	printf("\n\n\n");
	printf("\t\t\t\t\t\tOPENING HOURS  \n");
	printf("\n\n");
	printf("\t\t\t\tMonday - Friday  08:00AM to 10:00PM\n");
	printf("\t\t\t\tSaturday         09:00AM to 06:00PM\n");
    printf("\t\t\tThe libary is closed on Sundays and all public holidays\n");
	printf("\n\n");
	printf("\t\t\t\t\t\tDISCIPLINE  \n");
	printf("\n\n");
	printf("\tAll users must observe total silence in the library and its enviroment at all times\n");
	printf("\tAll users are required to show their Library IDs to the security officer upon entrance to the library\n");
	printf("\tUse of mobiles phones is strictly prohibited in the library\n");
	printf("\tAll bags,cases,folders etc. must be left in the luggage area outside the library.\n");
	printf("\tUsers are not allowed to leave their baggage overnight in the library. The library shall not take any responsibility for loss of personal property or book already signed out to a user.\n");
	printf("\n\n");
	printf("\t\t\t\t\tDAMAGE/LOSS OF LIBRARY MATERIALS   \n");
	printf("\n\n");
	printf("\tAll users will be held responsible for any damage or loss of library materials in their possession and wll be required to meet the cost of replacement and processing\n");
	printf("\tUsers must ensure that the books they borrow are in good condition to avoid being held responsible for any damage noted while returning the books\n");
	printf("\tLost books must be reported to the librarian immediately and replaced or paid for within 30 days\n");
	printf("\tLost library books that are recovered, must be handed to the librarian as they remain the property of college library\n");
	printf("\n\n");
	printf("\t\t\t\t\t\tOVERDUE CHARGES/FINES  \n");
	printf("\n\n\n");
	printf("\t\t\t\t\tUPTO 5 DAYS      Re 1 PER DAY\n");
	printf("\t\t\t\t\tNEXT 5 DAYS      Rs 2 PER DAY\n");
	printf("\t\t\t\t\tNEXT 10 DAYS     Rs 4 PER DAY\n");
	printf("\t\t\t\t\tABOVE THAT       Rs 5 PER DAY\n");
	printf("\n\n\n");
	printf(" \t\t\t\t\t\tTHANK YOU    \n");

	
	
}
//Function to Add new Books
void addBook()
{
	system("clear");
	printf("\n\t\t\t\t******Add New Book Detail******\n");

	printf("\n\t\t\t\tEnter Book Title : ");
	clean_stdin();
	gets(book[count].title);

	printf("\n\t\t\t\tEnter Book Author : ");
	//clean_stdin();
	gets(book[count].author);
    printf("\n\t\t\t\tEnter Book Price :");
	scanf("%f",&book[count].price);
	printf("\n\t\t\t\tEnter Book Page : ");
	scanf("%d",&book[count].page);
	
	count++;

}

//Function to Show All Books Record
 void showAllBook()
 {
 	int i;
 	//system("cls");
 	printf("\n\n\t\t\t\t@@@@@@@@@@@@@@ Books Detail @@@@@@@@@@@");
 	printf("\n\n\t---------------------------------------------------------------------------------");
    printf("\n\t\t Book Title \t\t Book Author \t\t Book Price \t\t Book Pages");
    printf("\n\n\t---------------------------------------------------------------------------------\n");

    for(i=0;i< count;i++)
    { 
		printf("\t%d).",i+1);
    	printf("\t\t %s",book[i].title);
    	printf("\t\t\t %s",book[i].author);
    	printf("\t\t\t %f",book[i].price);
    	printf(" \t\t %d\n",book[i].page);

    }


 }
 //Function to search for a book by Title
void searchBook()
{
	char btitle[10];
	int i;
	printf("Enter Book Title to be Search: ");
	clean_stdin();
	gets(btitle);
	for(i=0;i<count;i++)
	{
		if(strcasecmp(book[i].title,btitle)==0)
		{
			//system("cls");
			printf("\n\n\t\t######### Book Details ########");
			printf("\n\n\t\t Book Title : %s",book[i].title);
			printf("\n\t\t Book Author : %s",book[i].author);
			printf("\n\t\t Book Price : %f",book[i].price);
			printf("\n\t\t Book Page : %d",book[i].page);
		}
			
		else
		{
			printf("The above title book is not present \n");
		}

		
	}
} 

//Function to remove Book by Title

void removeBook()
{
	char btitle[10];
	int i,j;
	Book *temp;
	printf("\n Enter Book Title to be Removed :");
	clean_stdin();
	gets(btitle);
	for(i=0;i<count;i++)
	{
		if(strcasecmp(book[i].title,btitle)==0)
		{
			//stem("cls");
			printf("\n\n\t\t ######## Remove Book Detail ########");
			printf("\n\n\t\t\t Book Title : %s",book[i].title);
			printf("\n\t\t Book Author  : %s",book[i].author);
			printf("\n\t\tBook Price    : %f",book[i].price);
			printf("\n\t\t Book Page    : %d\n",book[i].page);

			for(j=i;j<count-1;j++)
			{
				book=book+1;

			}
			count--;
			return;

		}

		else
		{
			printf("The above title book is not present \n");
		}
	

	}
	
}


//Functon to Update Book by Title
 
  void updateBook()
  {
  	char btitle[10];
  	int i,j;
  	Book temp;
  	printf("\n Enter Book Title to be Removed :");
	  clean_stdin();
  	gets(btitle);
  	 for(i =0; i<count;i++)
  	 {
  	 	if(strcasecmp(book[i].title,btitle)==0)
  	 	{
  	 		//system("cls");
  	 		printf("\n\n\t\t ######## Book Detail ########");
			printf("\n\n\t\t\t Book Title : %s",book[i].title);
			printf("\n\t\t Book Author  : %s",book[i].author);
			printf("\n\t\tBook Price    : %f",book[i].price);
			printf("\n\t\t Book Page    : %d\n",book[i].page);
            
            
            printf("\n\n\t\t ######## Add Book Detail ########");
            printf("\nEnter Book Title : ");
            gets(book[i].title);
            printf("\nEnter Book Author :");

            clean_stdin();
            gets(book[i].author);
            printf("\n Enter Book Price :");
            scanf("%f",&book[i].price);
            printf("\n Enter Book Page :");
            scanf("%d",&book[i].page);

  	 	}
		   else
		{
			printf("The above title book is not present \n");
		}
  	 
  	 }
  }

void clean_stdin()
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}