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
void showAllBookAdmin();
void showAllBookUser();
void searchBook();
void removeBook();
void removeUser();
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
	system("clear");
	char space;
	printf("\n\n\n\033[1;36m\t\t\tWELCOME TO LIBRARY \033[0m\n");


// calling of admin_Login() function     
	// admin_Login();                 

	 printf("\n\t\t\033[1;37mLogin as..\n");
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
	 	printf("\033[1;37m");
		printf("\n\t\t\tEnter the CHOICE : ");
	    printf("\n\t\t1).ADMIN\t\t2).USER\n\t\t\t\t");
	    scanf("%d",&choice1); 
	    printf("\033[0m");
	 } 
    if(rechoice==2)		  
          break;
	
	if(choice1 == 1)
	{   
		printf("\033[1;37m");
		printf("\n\t 1.Add Book \n\t 2.Show All Book \n\t 3.Search Book \n\t 4.Remove Book \n\t 5.Update Book \n\t 6.Rules\n\t 7.user reg\n\t 8.showusers\n\t 9.Search User\n\t 10.Remove User\n");
		printf("\nEnter your choice : ");
	    int choice;
	    scanf("%d",&choice);
	  switch (choice)
	  {
	  case 1:
	        addBook();
		  break;
	  case 2:
	        showAllBookAdmin();
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
	   case 10:
	        removeUser();
			 break; 		
	    default:
	        printf("\t\033[1;31mYou Entered The Wrong Choice\033[0m");
		  break;			

	  }
	  printf("\033[1;37m");
	}
	if(choice1==2)
	{
	  printf("\n\t\t\t\t\t \033[1;37m1.Take Book\n\t\t\t\t\t 2.Return Book\n\t\t\t\t\t 3.Show All Book \n\t\t\t\t\t 4.Search Book \n\t\t\t\t\t 5.Rules\n");
	  printf("Enter your choice :\033[0m");
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
	        showAllBookUser();
	      break;
	  case 4:
	        searchBook();
	      break;  
      case 5:
	        rules();
	        break;
	  default:
	        printf("\t\033[1;31mYou Entered The Wrong Choice\033[0m");
		  break;
	  }
	}  
	 /* printf("\n\t\t\t\t Press Enter to continue");
    	scanf("%c",&space);*/
	  printf("\n\n\n\t\033[0;33mPress 0 to go back, 1 to continue and 2 to exit\033[0m\n\t");
	    scanf("%d",&rechoice);
	    system("clear");
	  
	printf("\033[0m"); 
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
	printf("\t\t\t\t\t \033[1;36mLIBARY RULES AND REGULATIONS\033[0m  \n");
	printf("\t\t\t\t--------------------------------------------\n");
	printf("\n\n\n");
	printf("\t\t\t\t\t\t\033[1;37mOPENING HOURS \033[0m \n");
	printf("\n");
	printf("\t\t\t\tMonday - Friday  08:00AM to 10:00PM\n");
	printf("\t\t\t\tSaturday         09:00AM to 06:00PM\n");
    printf("\t\t\tThe libary is closed on Sundays and all public holidays\n");
	printf("\n\n\n");
	printf("\t\t\t\t\t\t\033[1;37mDISCIPLINE \033[0m \n");
	printf("\n");
	printf("\t# All users must observe total silence in the library and its enviroment at all times\n");
	printf("\t# All users are required to show their Library IDs to the security officer upon entrance to the library\n");
	printf("\t# Use of mobiles phones is strictly prohibited in the library\n");
	printf("\t# All bags,cases,folders etc. must be left in the luggage area outside the library.\n");
	printf("\t# Users are not allowed to leave their baggage overnight in the library. The library shall not take any responsibility for loss of personal property or book already signed out to a user.\n");
	printf("\n\n\n");
	printf("\t\t\t\t\t\033[1;37mDAMAGE/LOSS OF LIBRARY MATERIALS \033[0m  \n");
	printf("\n");
	printf("\t# All users will be held responsible for any damage or loss of library materials in their possession and wll be required to meet the cost of replacement and processing\n");
	printf("\t# Users must ensure that the books they borrow are in good condition to avoid being held responsible for any damage noted while returning the books\n");
	printf("\t# Lost books must be reported to the librarian immediately and replaced or paid for within 30 days\n");
	printf("\t# Lost library books that are recovered, must be handed to the librarian as they remain the property of college library\n");
	printf("\n\n");
	printf("\t\t\t\t\t\t\033[1;37mOVERDUE CHARGES/FINES \033[0m \n");
	printf("\n");
	printf("\t\t\t\t\tUPTO 5 DAYS      Re 1 PER DAY\n");
	printf("\t\t\t\t\tNEXT 5 DAYS      Rs 2 PER DAY\n");
	printf("\t\t\t\t\tNEXT 10 DAYS     Rs 4 PER DAY\n");
	printf("\t\t\t\t\tABOVE THAT       Rs 5 PER DAY\n");
	printf("\n\n");
	printf(" \t\t\t\t\t\tTHANK YOU    \n");

	
	
}
//Function to Add new Books
void addBook()
{
	system("clear");
	
	printf("\n\t\t\t\t********** \033[1;36mAdd New Book Detail\033[0m \033[1;37m**********\n");

	printf("\tEnter Book Title : ");
	clean_stdin();
	gets(book[countBook].title);

	printf("\tEnter Book Author : ");
	gets(book[countBook].author);
    printf("\tEnter Book Price : ");
	scanf("%f",&book[countBook].price);
	printf("\tEnter Book Page : ");
	scanf("%d",&book[countBook].page);
	printf("\033[0m\n");
	printf("\t\033[1;32m%s added successfully...\033[0m",book[countBook].title);
	countBook++;
	



}

//Function to Show All Books Record
 void showAllBookUser()
 {  system("clear");
 	int i;
 	
 	printf("\033[1;37m\n\n\t\t@@@@@@@@@@@@@@@@ \033[0m\033[1;32mBooks Detail\033[0m \033[1;37m @@@@@@@@@@@@@@@@");
 	printf("\n\n\t\t------------------------------------------------------------------------------------");
    printf("\n\t\t Book Title \t\t Book Author \t\t Book Price \t\t Book Pages\033[0m");
    printf("\n\n\t\t------------------------------------------------------------------------------------\n");

    for(i=0;i< countBook;i++)
    {  
		 if(book[i].takenBook!=1)
	    {
    	printf("\t\t %s",book[i].title);
    	printf("\t\t\t %s",book[i].author);
    	printf("\t\t\t %f",book[i].price);
    	printf(" \t\t %d\n",book[i].page);
		}
    }


 }
 void showAllBookAdmin()
 {  system("clear");
 	int i;
 	
 	printf("\n\n\n\n\t\t\t\t\t@@@@@@@@@@@@@@@@ \033[1;32mBooks Detail\033[0m \033[1;37m @@@@@@@@@@@@@@@@@@");
 	printf("\n\n\t\t-------------------------------------------------------------------------------------");
    printf("\n\n\t\t Book Title \t\t Book Author \t\t Book Price \t\t Book Pages\033[0m");
    printf("\n\n\t\t--------------------------------------------------------------------------------------\n");

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
{   system("clear");
	char btitle[30];
	int i,flag=-1;
	printf("\t\t\033[1;37mEnter Book Title to be Search: ");
	clean_stdin();
	gets(btitle);
	
	for(i=0;i<countBook;i++)
	{
		if(strcasecmp(book[i].title,btitle)==0)
		{
			
			printf("\n\n\t\t######### \033[1;32mBooks Detail\033[0m \033[1;37m########");
			printf("\n\n\t\t Book Title : %s",book[i].title);
			printf("\n\t\t Book Author : %s",book[i].author);
			printf("\n\t\t Book Price : %f",book[i].price);
			printf("\n\t\t Book Page : %d",book[i].page);
			printf("\033[0m");
			flag++;
		}
			

		
	}
	if(flag==-1)
		{
			printf("\n\t\t\033[1;31mThe above title book is not present! \033[0m\n");
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
			printf("\n\n\t\t ######## \033[1;31mRemove Book Detail\033[0m \033[1;37m########");
			printf("\n\n\t\t Book Title : %s",book[i].title);
			printf("\n\t\t Book Author  : %s",book[i].author);
			printf("\n\t\tBook Price    : %f",book[i].price);
			printf("\n\t\t Book Page    : %d\n",book[i].page);
			printf("\033[0m");
			printf("\n\n\t\t \033[1;32mBook successfully removed\033[0m");

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
			printf("\n\n\n\t\033[1;31mThe above  book is not found\033[0m \n");
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
  	 		printf("\n\n\t\t############ \033[1;35mBook Detail\033[0m ############");
			printf("\n\n\t\t Book Title : %s",book[i].title);
			printf("\n\t\t Book Author  : %s",book[i].author);
			printf("\n\t\tBook Price    : %f",book[i].price);
			printf("\n\t\t Book Page    : %d\n",book[i].page);
            
            
            printf("\n\n\t\t ######## \033[1;36mAdd Book NEW Detail\033[0m ########");
            printf("\n\tEnter Book Title : ");
            gets(book[i].title);
            printf("\n\tEnter Book Author : ");

            gets(book[i].author);
            printf("\n\tEnter Book Price : ");
            scanf("%f",&book[i].price);
            printf("\n\tEnter Book Page : ");
            scanf("%d",&book[i].page);

            return;
  	 	}
		 
  	 
  	 }
	   printf("\n\n\t\t\033[1;31mThe above title book is not present \033[0m\n");

  }
//Function to show all users
void userRegistration()
{
   system("clear");
	printf("\t\t\t********* \033[1;32mUser Registration\033[0m \033[1;37m ******\n");

	printf("\n\tEnter the name of User : ");
	clean_stdin();
	gets(user[countUser].name);

    printf("\n\tEnter Phone Number of User : ");
	scanf("%ld",&user[countUser].phoneNo);
	
	
 // ID generation
	 user[countUser].idNo=idcounter;
	 printf("\033[0m");
	 printf("\n\t\t\033[1;32mUSER have successfully been Registred\n");
	printf("\t\tUser's Library ID : %ld\n\033[0m",user[countUser].idNo);
     idcounter++;
	 countUser++;
	
}
//Funcrion to display all the users Registered
void showAlluser()
{
	int i;
 	 system("clear");
 	printf("\n\n\t\t@@@@@@@@@@@@@@ \033[1;32mUser Detail\033[0m\033[1;37m @@@@@@@@@@@");
 	printf("\n\n\t\t--------------------------------------------------------------------------------");
    printf("\n\t\t user name \t\t user phoneNO \t\t\t idno");
    printf("\n\n\t\t--------------------------------------------------------------------------------\033[0m\n");

    for(i=0;i< countUser;i++)
    {
    	printf("\t\t %s",user[i].name);
    	printf("\t\t\t %ld",user[i].phoneNo);
    	printf("\t\t\t %ld\n",user[i].idNo);
    	

    }


}
//Function to take book by the user
void takeBook()
{   system("clear");
	char uname[10];
	long id;
	int i,j;
	char bname[10];
	User *temp;
	printf("\033[1;37m\n\t\tEnter User Name : ");
	clean_stdin();
	gets(uname);
	printf("\n\t\tEnter Library ID : ");
	scanf("%ld",&id);
	printf("\n\n\t\tEnter the Name of the Book : ");
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
				     
                      book[j].takenBook=1;
			       }
			        
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
				printf("\n\n\t\t@@@@@@@@@@@@@@ \033[1;32mLEND BOOK\033[0m @@@@@@@@@@@");
				 printf("\n\n\t\t\033[1;32m%s have succesfully taken the book\033[0m",user[i].name);	
				 printf("\n\n\t\tBook issued Date: %d-%d-%d \n",presentDate,presentMonth,presentYear);	
                 printf("\n\t\tBook return Date: %d-%d-%d\n",lastDate,lastMonth,lastYear); 
			     printf("\033[0m");
	            }
			}
			return;
		}
		
			
    }  
        printf("\t\t\n\n\033[1;31mUser not yet Registered.\033[0m Contact admin for new registration");
}

//Function while returning book and find if fine is there
void returnBook()
{  
	system("clear");
	  int days=0;
     float fine=0.0;
    char uname[10];
	long id;
	int index;
    printf("\n\n\n\t\tEnter username : ");

    clean_stdin();
	gets(uname);

	printf("\t\t\n\nEnter Library ID : ");
    scanf("%ld",&id);
	printf("\n\n\t\tEnter Book Title : ");
	clean_stdin();
	gets(book[countBook].title);
    for(int i=0;i<countUser;i++)
	{   
       if(strcasecmp(user[i].name,uname)==0&&(user[i].idNo==id))
	       index=i;
		   book[i].takenBook=0;
	}
  if(index>=0)
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
	printf("\n\n\t\tCurrent Date: %d-%d-%d \n",presentDate,presentMonth,presentYear);
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
       printf("\n\n\t\t\033[01;37m@@@@@@@@@@@@@@\033[0m\033[0;32m RETURN BOOK\033[0m @@@@@@@@@@@");
	  printf("\n\n\t\t\033[1;32m%s have succesfull returned the book\033[0m \n",user[index].name);   
  //To find the Fine
	if(days==0)
	   printf("\t\t\033[01;37mYou are on time  !NO fine for you.......\n");
	else if(days<=5&&days>0)
	   fine = days*1.0;
	else if(days<=10&&days>5)
	  fine =5.0+((days-5)*2.0);
    else if(days<=20&&days>10)
      fine =5.0+10.0+((days-10)*4.0);
    else if(days>20)
      fine =5.0+10.0+40.0+((days-20)*5.0);      
    printf("\t\tNo of days user is late : %d \n",days);
    printf("\t\tFine for late return of book : %f \n\033[m",fine);
  }	
  else
    printf("\n\n\t\t\033[1;31mThe user has not yet Registered. Contact admin\033[0m\n");

}
// Function to Search for User		
void searchUser()
{  system("clear");
	long num;
	printf("\n\n\tEnter the cell Number : ");
	scanf("%ld",&num);
	for(int i=0;i<countUser;i++)
	{
		if(num==user[i].phoneNo)
		{
			printf("\n\n\t\t@@@@@@@@@@@@@@ \033[1;32mUser Detail\033[0m @@@@@@@@@@@");
		 	printf("\n\n\t\t--------------------------------------------------------------");
		    printf("\n\t\t user name \t\t user phoneNO \t\t idno");
		    printf("\n\n\t\t--------------------------------------------------------------\n");
		    printf("\t\t %s",user[i].name);
	    	printf("\t\t %ld",user[i].phoneNo);
	    	printf("\t\t %ld",user[i].idNo);
			return;
		}
		

	}
	printf("\n\t\033[1;31mUser not found\033[0m");
}

void removeUser()
{ 
	system("clear");
	char uname[30];
	long phoneNO;
	int i,j;
	Book *temp;
	printf("\n\tEnter User Name to be Removed :");
	clean_stdin();
	gets(uname);
	printf("\n\tEnter User Phone NO :");
    scanf("%ld",&phoneNO);
	for(i=0;i<countUser;i++)
	{
		if((strcasecmp(user[i].name,uname)==0)&&(user[i].phoneNo==phoneNO))
		{
			system("clear");
			printf("\n\n\t\t ######## \033[1;31mRemove USER Detail\033[0m\033[1;37m ########");
			printf("\n\n\t\t User name : %s",user[i].name);
			printf("\n\t\t User Phone no  : %ld",user[i].phoneNo);
			printf("\n\t\t User id no   : %ld",user[i].idNo);
			printf("\033[0m");
			printf("\n\n  \t\t\033[1;31mUser successfully removed\033[0m");

			for(j=i;j<countUser-1;j++)
			{
				user=user+1;

			}
			countUser--;
			
			return;

		}	

	}

			printf("\n\t\033[1;31mUser not found\033[0m \n");
	
}
void clean_stdin()
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

