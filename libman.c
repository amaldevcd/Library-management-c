/*Library Management*/


//Packages
#include <stdio.h>
#include<ctype.h>
#include<string.h>
#include <stdlib.h>
#include<time.h>


//Function Declaration
void clean_stdin();
void rules();
void admin_Login();
void addBook();
void showAllBook();
void searchBook();
void removeBook();
void updateBook();
void userRegistration();
void showAlluser();
void takeBook();
void returnBook();
void searchUser();

//Structure for Books
typedef struct addBook
{
	char title[35];
    char author[35];
    int page;
    float price;
	int takenBook;
}Book;

//Structure for User
typedef struct addUser
{
	char name[20];
	long phoneNo;
	long idNo;
	int submitdate ,submitmonth,submityear;

}User;

Book *book;      //Global Book type Pointer
User *user;      //Global  User type Pointer 
int countBook=0;   //Global Count Variable Book
int sizeBook=2;        //Global Variable for Dynamic Memory Allocation Book
int countUser=0;   //Global Count Variable User
int sizeUser=2;        //Global Variable for Dynamic Memory Allocation User
int idcounter=1001;  //For id 



//Main Function
void main()
{ 
	char space;
	printf("\t\t\t\tLIBRARY \n");

	printf("  \n  ");
	printf("\t\t\t\tWELCOME\n");
	

// calling of admin_Login() function     
	admin_Login();                 

	 printf("\n\t\t\tEnter the CHOICE\n");
	 printf("\n\t\t1).ADMIN\t\t2).USER\n\t\t\t\t");
	 int choice1;
	 scanf("%d",&choice1);

 //Create Book Array Dynamic using size input by User 
        
         book = (Book*) malloc(sizeof(Book)*sizeBook);

 //Create User Array Dynamic using size input by User
         user = (User*) malloc(sizeof(User)*sizeUser);

    int rechoice=1;
 //Selecting Choice of User   
     do                                                   // to repeat
  {    
     if(rechoice==0)
	 {
		printf("\n\t\t\tEnter the CHOICE\n");
	    printf("\n\t\t1).ADMIN\t\t2).USER\n\t\t\t\t");
	    scanf("%d",&choice1); 
	 } 
    		  
    
	
	if(choice1 == 1)
	{   
		printf("\n\t 1.Add Book \n\t 2.Show All Book \n\t 3.Search Book \n\t 4.Remove Book \n\t 5.Update Book \n\t 6.Rules\n\t 7.user reg\n\t 8.showusers\n\t 9.Search User");
		printf("\nEnter your choice \n");
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
	        userRegistration();
	      break;
	   case 8:
	        showAlluser();
	      break;
       case 9:
	        searchUser();
			break;
	    default:
	        printf("\tYou Entered The Wrong Choice");
		  break;			

	  }
	}
	if(choice1==2)
	{
	  printf("\n\t\t\t\t\t 1.Take Book\n\t\t\t\t\t 2.Return Book\n\t\t\t\t\t 3.Show All Book \n\t\t\t\t\t 4.Search Book \n\t\t\t\t\t 5.Rules\n");
	  printf("Enter your choice \n");
	  int choice;
	  scanf("%d",&choice);
	  switch (choice)
	  {
	   case 1:
		     takeBook();
		  break;	   		  	  	  	  
	    
	   case 2:
		     returnBook();
		  break;
	   case 3:
	        showAllBook();
	      break;
	  case 4:
	        searchBook();
	      break;  
      case 5:
	        rules();
	        break;
	  default:
	        printf("\tYou Entered The Wrong Choice");
		  break;
	  }
	}  
	 /* printf("\n\t\t\t\t Press Enter to continue");
    	scanf("%c",&space);*/
	  printf("\n\t\t press 0 to go back to ADMIN or USER choice or to Continue press 1\n");
	    scanf("%d",&rechoice);
	  
	 
 }while(1);

}


//Admin login and Password checking
void admin_Login()
{
   printf("Please Log in \n");
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
	printf("******Add New Book Detail******\n");

	printf("Enter Book Title :");
	clean_stdin();
	gets(book[countBook].title);

	printf("Enter Book Author :");
	gets(book[countBook].author);
    printf("Enter Book Price :");
	scanf("%f",&book[countBook].price);
	printf("Enter Book Page : ");
	scanf("%d",&book[countBook].page);
	
	countBook++;

}

//Function to Show All Books Record
 void showAllBook()
 {
 	int i;
 	system("clear");
 	printf("\n\n\t\t@@@@@@@@@@@@@@ Books Detail @@@@@@@@@@@");
 	printf("\n\n\t\t----------------------------------------");
    printf("\n\t\t Book Title \t\t Book Author \t\t Book Price \t\t Book Pages");
    printf("\n\n\t\t----------------------------------------\n");

    for(i=0;i< countBook;i++)
    {
    	printf("\t\t %s",book[i].title);
    	printf("\t\t\t %s",book[i].author);
    	printf("\t\t\t %f",book[i].price);
    	printf(" \t\t %d\n",book[i].page);

    }


 }
 //Function to search for a book by Title
void searchBook()
{
	char btitle[30];
	int i,flag=-1;
	printf("Enter Book Title to be Search: ");
	clean_stdin();
	gets(btitle);
	printf("string : %s \n",btitle);
	for(i=0;i<countBook;i++)
	{
		if(strcasecmp(book[i].title,btitle)==0)
		{
			system("clear");
			printf("\n\n\t\t######### Book Details ########");
			printf("\n\n\t\t Book Title : %s",book[i].title);
			printf("\n\t\t Book Author : %s",book[i].author);
			printf("\n\t\t Book Price : %f",book[i].price);
			printf("\n\t\t Book Page : %d",book[i].page);
			flag++;
		}
			

		
	}
	if(flag==-1)
		{
			printf("The above title book is not present \n");
		}
} 

//Function to remove Book by Title

void removeBook()
{
	char btitle[30];
	int i,j,flag=-1;
	Book *temp;
	printf("\n Enter Book Title to be Removed :");
	clean_stdin();
	gets(btitle);
	for(i=0;i<countBook;i++)
	{
		if(strcasecmp(book[i].title,btitle)==0)
		{
			system("clear");
			printf("\n\n\t\t ######## Remove Book Detail ########");
			printf("\n\n\t\t Book Title : %s",book[i].title);
			printf("\n\t\t Book Author  : %s",book[i].author);
			printf("\n\t\tBook Price    : %f",book[i].price);
			printf("\n\t\t Book Page    : %d\n",book[i].page);

			for(j=i;j<countBook-1;j++)
			{
				book=book+1;

			}
			countBook--;
			flag++;
			return;

		}	

	}
	if(flag==-1)
		{
			printf("The above title book is not present \n");
		}
	
}


//Functon to Update Book by Title
 
  void updateBook()
  {
  	char btitle[30];
  	int i,j;
  	Book temp;
  	printf("\n Enter Book Title to be Updated :");
	clean_stdin();
  	gets(btitle);
  	 for(i =0; i<countBook;i++)
  	 {
  	 	if(strcasecmp(book[i].title,btitle)==0)
  	 	{
  	 		system("clear");
  	 		printf("\n\n\t\t ######## Book Detail ########");
			printf("\n\n\t\t Book Title : %s",book[i].title);
			printf("\n\t\t Book Author  : %s",book[i].author);
			printf("\n\t\tBook Price    : %f",book[i].price);
			printf("\n\t\t Book Page    : %d\n",book[i].page);
            
            
            printf("\n\n\t\t ######## Add Book Detail ########");
            printf("\nEnter Book Title : ");
            gets(book[i].title);
            printf("\nEnter Book Author :");

            gets(book[i].author);
            printf("\n Enter Book Price :");
            scanf("%f",&book[i].price);
            printf("\n Enter Book Page :");
            scanf("%d",&book[i].page);

            return;
  	 	}
		 
  	 
  	 }
	   printf("\n\nThe above title book is not present \n");

  }
//Function to show all users
void userRegistration()
{
   system("clear");
	printf("******User Registration******\n");

	printf("\nEnter the name of User :");
	clean_stdin();
	gets(user[countUser].name);

    printf("\nEnter Phone Number of User :");
	scanf("%ld",&user[countUser].phoneNo);
	
	
 // ID generation
	 user[countUser].idNo=idcounter;
     idcounter++;
	 countUser++;
}

void showAlluser()
{
	int i;
 	// system("clear");
 	printf("\n\n\t\t@@@@@@@@@@@@@@ User Detail @@@@@@@@@@@");
 	printf("\n\n\t\t----------------------------------------");
    printf("\n\t\t user name \t\t user phoneNO \t\t idno");
    printf("\n\n\t\t----------------------------------------\n");

    for(i=0;i< countUser;i++)
    {
    	printf("\t\t %s",user[i].name);
    	printf("\t\t\t %ld",user[i].phoneNo);
    	printf("\t\t\t %ld\n",user[i].idNo);
    	

    }


}
//Function to take book by the user
void takeBook()
{
	char uname[10];
	long id;
	int i,j;
	char bname[10];
	User *temp;
	printf("\nEnter User Name : ");
	clean_stdin();
	gets(uname);
	printf("\nEnter Library ID :");
	scanf("%ld",&id);
	printf("Enter the Name of the Book : ");
	clean_stdin();
    gets(bname);
	for(i=0;i<countUser;i++)
	{    //To check if the user has reg
		if(strcasecmp(user[i].name,uname)==0&&(user[i].idNo==id))
		{   
           for(j=0;j<countBook;j++)
		   {    
			   if(strcasecmp(book[j].title,bname)==0)
			   {      
				   for(int k=j;k<countBook-1;k++)
			      {
				     book=book+1;

			       }
			        countBook--;
				// To calculate the return date	
				 time_t now;
				 time(&now);
				 struct tm *local = localtime(&now);
                  int monthDate[12]={31,28,31,30,31,30,31,31,30,31,30,31};
                  int leapmonthDate[12]={31,29,31,30,31,30,31,31,30,31,30,31};
                  int  presentDate,presentMonth,presentYear,lastDate,lastMonth,lastYear;
                  presentDate=local->tm_mday;
                  presentMonth=local->tm_mon+1;
                  presentYear=local->tm_year+1900;
				  printf("Current Date: %d-%d-%d \n",presentDate,presentMonth,presentYear);
                  if(presentYear%100==0&&presentYear%4==0)
                  {
                     if(presentDate+14>leapmonthDate[presentMonth-1])
                     {
                         lastDate=(presentDate+14)-leapmonthDate[presentMonth-1];
                         if(presentMonth+1>12)
                         {
                           lastMonth=presentMonth+1-12;
                           lastYear=presentYear+1;
                         }
                         else
                         {
                           lastMonth=presentMonth+1;
                           lastYear=presentYear;
                        }
                    }  
                  }

                 else{
                       if(presentDate+14>monthDate[presentMonth-1])
                       {
                          lastDate=(presentDate+14)-monthDate[presentMonth-1];
                          if(presentMonth+1>12)
                          {
                           lastMonth=presentMonth+1-12;
                           lastYear=presentYear+1;
                          }
                         else
                          {
                           lastMonth=presentMonth+1;
                           lastYear=presentYear;
                         }
                        }  
                    }
					user[i].submitdate=lastDate;
					user[i].submitmonth=lastMonth;
					user[i].submityear=lastYear;
                 printf("return Date: %d-%d-%d\n",lastDate,lastMonth,lastYear); 
			     
	            }
			}
			return;
		}
		
			
    }  
        printf("\n\nUser not yet Registered");
}

//Function while returning book and find if fine is there
void returnBook()
{    int days=0;
     float fine=0.0;
    char uname[10];
	long id;
	int index;
    printf("Enter username : ");

    clean_stdin();
	gets(uname);

	printf("Enter Library ID : ");
    scanf("%ld",&id);
	printf("Enter Book Title :\n");
	clean_stdin();
	gets(book[countBook].title);
    for(int i=0;i<countUser;i++)
	{
       if(strcasecmp(user[i].name,uname)==0&&(user[i].idNo==id))
	       index=i;
	}
  if(index!=0)
  {
	time_t now;
	time(&now);
	struct tm *local = localtime(&now);
    int monthDate[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int leapmonthDate[12]={31,29,31,30,31,30,31,31,30,31,30,31};
    int  presentDate,presentMonth,presentYear,lastDate,lastMonth,lastYear;
    presentDate=local->tm_mday;
    presentMonth=local->tm_mon+1;
    presentYear=local->tm_year+1900;
	printf("Current Date: %d-%d-%d \n",presentDate,presentMonth,presentYear);
    lastDate=user[index].submitdate;
	lastMonth=user[index].submitmonth;
	lastYear=user[index].submityear;
    
  //To find the no of Days
    if(presentYear<lastYear)
      { 
        int diffYear=lastYear-presentYear;
           if(diffYear>=1)
            {  if(diffYear>1)
                {
                  days=days+(diffYear-1)*365;      //If more than one Year
                   
                }
               if(presentMonth>lastMonth)
               {  
                  for(int i=presentMonth;i<12;i++)
                  {                                      
                    if(i==2){
                        if(presentYear%100==0&&presentYear%4==0)   
                        days=days+monthDate[i]+1;
                        else
                         days=days+monthDate[i];
                          }
                   days=days+monthDate[i];
                  }
                  for(int i=0;i<(lastMonth-1);i++)
                  { 
                     if(i==2){   
                        if(presentYear%100==0&&presentYear%4==0)
                        days=days+monthDate[i]+1;                    
                        else
                         days=days+monthDate[i];
                           }
                    days=days+monthDate[i];
                  }
               }
               if(presentMonth<lastMonth)
               {
                for(int i=presentMonth;i<lastMonth;i++)
                {  if(i==2){
                        if(presentYear%100==0&&presentYear%4==0)       
                        days=days+monthDate[i]+1;
                        else
                         days=days+monthDate[i];
                           }
                  days=days+monthDate[i];
                }
                
               } 
                 if(presentMonth==2){   
                        if(presentYear%100==0&&presentYear%4==0)
                          days=days+(monthDate[presentMonth-1]+1-presentDate);
                        else
                           days=days+(monthDate[presentMonth-1]-presentDate);
                       days=days+(lastDate-1);      
                 }
                 else{
                          days=days+(monthDate[presentMonth-1]-presentDate);
                          days=days+(lastDate-1);
                 }
                 
                
            }
            

         
         }
	     
  //To find the Fine
	if(days==0)
	   printf("You are on time  !NO fine for you.......");
	else if(days<=5&&days>0)
	   fine = days*1.0;
	else if(days<=10&&days>5)
	  fine =5.0+((days-5)*2.0);
    else if(days<=20&&days>10)
      fine =5.0+10.0+((days-10)*4.0);
    else if(days>20)
      fine =5.0+10.0+40.0+((days-20)*5.0);      

    printf("Fine =%f",fine);
  }	
  else
    printf("\nThe user has not yet Registered\n");

}
// Function to Search for User		
void searchUser()
{
	long num;
	printf("Enter the cell Number : ");
	scanf("%ld",&num);
	for(int i=0;i<countUser;i++)
	{
		if(num==user[i].phoneNo)
		{
			printf("\n\n\t\t@@@@@@@@@@@@@@ User Detail @@@@@@@@@@@");
		 	printf("\n\n\t\t----------------------------------------");
		    printf("\n\t\t user name \t\t user phoneNO \t\t idno");
		    printf("\n\n\t\t----------------------------------------\n");
		    printf("\t\t %s",user[i].name);
	    	printf("\t\t\t %ld",user[i].phoneNo);
	    	printf("\t\t\t %ld",user[i].idNo);
	    	break;

			return;
		}
		

	}
	printf("User not found");
}
void clean_stdin()
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

