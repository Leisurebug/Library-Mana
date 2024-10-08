#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
struct book //creating structure of book
{
 char name[30];
 char author[30];
  int id;
 struct book *next;
};
struct student //creating structure of student
{
 char name[30];
 char email[20];
 char book[20];
 char a[30];
 int id;
 struct student *next;
};
struct book *start_lib=NULL;
struct student *start=NULL;
struct book *initialize_lib(struct book *);
struct student *book_issue(struct student *);
struct student *book_return(struct student *);
struct book *diplay_lib(struct book *);
struct book *delete_book(int);
struct book *add_book(char [],char [],int);
void add_new_book();
void display(struct student *);
void greetings();
void main_menu();
int main()
{
 start_lib=initialize_lib(start_lib);
 greetings();
 main_menu();
 return 0;
}
void greetings() //displaying the library
{
 printf("\n\n");
 printf("\t\t\t --------------------------------------\n");
 printf("\t\t\t |                                    |\n");
 printf("\t\t\t |     ---------------------------    |\n");
 printf("\t\t\t |     WELCOME TO STUDENT LIBRARY     |\n");
 printf("\t\t\t |     ---------------------------    |\n");
 printf("\t\t\t |                                    |\n");
 printf("\t\t\t |                                    |\n");
 printf("\t\t\t |     Konankunte,Karnataka,India     |\n");
 printf("\t\t\t |     Email: rvitmlib@gmail.com      |\n");
 printf("\t\t\t |    Contact:8800991010,8800992020   |\n");
 printf("\t\t\t |                                    |\n");
 printf("\t\t\t --------------------------------------\n");
 printf("\n\n\t\t\t Press any key to continue: ");
 getch();
}
void main_menu() //displaying menu of library
{
 int choice;
 do
 {
 printf("\n\n");
 printf("\n\t\t\t\t*****************\n");
 printf("\n\t\t\t\t MAIN MENU: ");
 printf("\n\t\t\t\t 1.ISSUE OF BOOKS ");
 printf("\n\t\t\t\t 2.RETURN OF BOOKS ");
 printf("\n\t\t\t\t 3.DISPLAY STUDENT DETAILS ");
 printf("\n\t\t\t\t 4.ADD NEW BOOK TO THE LIBRARY ");
 printf("\n\t\t\t\t 5.EXIT\n ");
 printf("\n\t\t\t\t*****************\n");
 printf("\n\t\t\t\t Enter your choice: ");
 scanf("%d",&choice);
 switch(choice)
 {
 case 1:
 {
 start=book_issue(start);
 break;
 }
 case 2:
 {
 start=book_return(start);
 break;
 }
 case 3:
 {
 display(start);
 break;
 }
 case 4:
 {
 add_new_book();
 break;
  }
 case 5:
 {
 exit(1);
 }
 default:
 {
 printf("\n\t\t\t\t ...Invalid Option!...\n");
 printf("\n\t\t\t\t Press any key to try again: ");
 getch();
 }
 }
 }
 while(choice!=5);
}
struct book *initialize_lib(struct book *start) // Initializing the library
{
 struct book *ptr,*new_book1,*new_book2,*new_book3,*new_book4,*new_book5;
 new_book1=(struct book *)malloc(sizeof(struct book));
 new_book1->next=NULL;
 start_lib=new_book1;
 strcpy(new_book1->name,"The Forest of Enchantments");
 strcpy(new_book1->author,"Chitra Banerjee Divakaruni");
 new_book1->id=101;
 ptr=new_book1;
 new_book2=(struct book*)malloc(sizeof(struct book));
 new_book2->next=NULL;
 strcpy(new_book2->name,"The Far Field");
 strcpy(new_book2->author,"Madhuri Vijay");
 new_book2->id=102;
 ptr->next=new_book2;
 ptr=new_book2;
 new_book3=(struct book*)malloc(sizeof(struct book));
 new_book3->next=NULL;
 strcpy(new_book3->name,"Latitudes of Longing");
 strcpy(new_book3->author,"Shubhangi Swarup");
 new_book3->id=103;
 ptr->next=new_book3;
 ptr=new_book3;
 new_book4=(struct book*)malloc(sizeof(struct book));
 new_book4->next=NULL;
 strcpy(new_book4->name,"Paper Moon ");
 strcpy(new_book4->author,"Rehana Munir");
 new_book4->id=104;
 ptr->next=new_book4;
 ptr=new_book4;
 new_book5=(struct book*)malloc(sizeof(struct book));
 new_book5->next=NULL;
 strcpy(new_book5->name,"The Unlikely Adventures of the Shergill Sisters ");
 strcpy(new_book5->author,"Balli Kaur Jaswal");
 new_book5->id=105;
 ptr->next=new_book5;
 return start_lib;
 }
struct student *book_issue(struct student *start) //issuing the books to the students
{
 struct book *ptr;
 struct student *ptr2,*new_student;
 int i=1,id,flag=0;
 if(start_lib==NULL)
 {
 printf("\n\t\t\t\t No books left in the library to issue!\n\t\t\t\t Sorry for the inconvenience!\n");
 }
 else
 {
 system("cls");
 ptr=start_lib;
 printf("\n\t****** Books Available: *******\n");
 while(ptr!=NULL)
 {
 printf("\n\t_________________\n");
 printf("\n\t Book %d",i);
 printf("\n\t Book Title: %s",ptr->name);
 printf("\n\t Name of Author: %s",ptr->author);
 printf("\n\t Book ID: %d",ptr->id);
 printf("\n\t_________________\n");
 ptr=ptr->next;
 i++;
 }
 printf("\n\n\t Enter the Book ID: ");
 scanf("%d",&id);
 ptr=start_lib;
 while(ptr!=NULL)
 {
 if(ptr->id==id)
 {
 flag=1;
 break;
 }
 ptr=ptr->next;
 }
 if(flag==1)
 {
 ptr=start_lib;
 while(ptr->id!=id)
 {
 ptr=ptr->next;
 }
 new_student=(struct student *)malloc(sizeof(struct student));
 printf("\n\t Enter Student Details:\n ");
 printf("\n\t Enter your Name: ");
 scanf("%s",new_student->name);
 printf("\n\t Enter your Email: ");
 scanf("%s",new_student->email);
 strcpy(new_student->book,ptr->name);
 strcpy(new_student->a,ptr->author);
 new_student->id=ptr->id;
 new_student->next=NULL;
 printf("\n\t Issue of Book ID %d done successfully!\n",new_student->id);
 printf("\n\n\t*****************\n");
 if(start==NULL)
{
 start=new_student;
 }
 else
 {
 ptr2=start;
 while(ptr2->next!=NULL)
 {
 ptr2=ptr2->next;
 }
 ptr2->next=new_student;
 }
 start_lib=delete_book(new_student->id);
 printf("\n\n\t Press any key to go to the main menu: ");
 getch();
 system("cls");
 }
 else
 {
 printf("\n\t\t ...Invalid Option!...\n");
 printf("\n\t\t Press any key to try again: ");
 getch();
 system("cls");
 }
 }
 return start;
}
struct student *book_return(struct student *start) // return of the book
{
    struct student *ptr,*preptr;
 char bookname[30],authorname[30];
 int flag=0,id,identity,c=0,d=1;
 printf("\n\n\t****** Books Submission: *******\n");
 printf("\n\n\t Enter your Book ID: ");
 scanf("%d",&identity);
 ptr=start;
 while(ptr!=NULL)
 {
 if(ptr->id==identity)
 {
 flag=1;
 break;
 }
 ptr=ptr->next;
 }
 if(flag==1)
 {
 ptr=start;
 /*while(ptr!=NULL)
 {
 c++;
 ptr=ptr->next;
 }
 ptr=start;*/
 while(ptr->id!=identity)
 {
 d++;
 ptr=ptr->next;
 }
ptr=start;
 if( d==1 )
 {
 printf("\n\t_________________\n");
 printf("\n\t Student Name: %s",start->name);
 printf("\n\t Student Email: %s",start->email);
 printf("\n\t Name of Book Issued: %s",start->book);
 printf("\n\t_________________\n");
 printf("\n\n\t Return of Book ID %d done successfully!\n",identity);
 printf("\n\n\t*****************\n");
 strcpy(bookname,start->book);
 strcpy(authorname,start->a);
 id=start->id;
 start=start->next;
 free(ptr);
 add_book(bookname,authorname,id);
 }
 else
 {
 ptr=start;
 while(ptr->id!=identity)
 {
 preptr=ptr;
 ptr=ptr->next;
 }
 printf("\n\t_________________\n");
 printf("\n\t Student Name: %s",ptr->name);
 printf("\n\t Student Email: %s",ptr->email);
 printf("\n\t Name of Book Issued: %s",ptr->book);
 printf("\n\t Book ID: %d",ptr->id);
 printf("\n\t_________________\n");
 strcpy(bookname,ptr->book);
 strcpy(authorname,ptr->a);
 id=ptr->id;
 preptr->next=ptr->next;
 free(ptr);
 add_book(bookname,authorname,id);
 }
 printf("\n\t Thank you! \n\t Do visit again! ");
 printf("\n\n\t Press any key to go to the main menu: ");
 getch();
 system("cls");
 }
 else
 {
 printf("\n\tSorry the book doesn't exist! Please recheck the entered ID");
 printf("\n\t\t\t\t Press any key to try again: ");
 getch();
 system("cls");
 }
 return start;
}
void display(struct student *start) //student details displaying function
{
 struct student *ptr;
 ptr=start;
 while(ptr!=NULL)
 {
 printf("\n\t***** Details of Students: ******\n");
  printf("\n\t_________________\n");
 printf("\n\t\t Student Name: %s",ptr->name);
 printf("\n\t\t Student Email: %s",ptr->email);
 printf("\n\t\t Name of Book Issued: %s",ptr->book);
 printf("\n\t\t Book ID: %d",ptr->id);
 printf("\n\t_________________\n");
 printf("\n\n\t*****************\n");
 ptr=ptr->next;
 }
 printf("\n\n\t Press any key to go to the main menu: ");
 getch();
 system("cls");
}
struct book *delete_book(int id) //deleting book on issue
{
 struct book *ptr,*preptr;
 int c=0;
 ptr=start_lib;
 while(ptr!=NULL)
 {
 c++;
 ptr=ptr->next;
 }
 if(c==1)
 {
 ptr=start_lib;
 start_lib=NULL;
 free(ptr);
 }
 else if(start_lib->id==id)
 {
 ptr=start_lib;
 start_lib=start_lib->next;
 free(ptr);
 }
 else
 {
 ptr=start_lib;
 while(ptr->id!=id)
 {
 preptr=ptr;
 ptr=ptr->next;
 }
 preptr->next=ptr->next;
 free(ptr);
 }
 return start_lib;
}
struct book *add_book(char bookname[30],char authorname[30],int id) //adding book on return
{
 struct book *ptr,*new_book;
 new_book=(struct book *)malloc(sizeof(struct book));
 strcpy(new_book->name,bookname);
 strcpy(new_book->author,authorname);
 new_book->id=id;
 new_book->next=NULL;
 if(start_lib==NULL)
 {
 start_lib=new_book;
 }
 else
 {
 ptr=start_lib;
 while(ptr->next!=NULL)
 {
 ptr=ptr->next;
 }
 ptr->next=new_book;
 }
 return start_lib;
}
void add_new_book() //adding new books to the library
{
 char bookName[30];
 char authorName[30];
 int bookId;
 printf("\n\tEnter the details of the new book:\n");
 // Input book details
 printf("\tEnter the name of the book: ");
 scanf("%s", bookName);
 printf("\tEnter the name of the author: ");
 scanf("%s", authorName);
 printf("\tEnter the ID of the book: ");
 scanf("%d", &bookId);
  // Add the book to the library
 start_lib = add_book(bookName, authorName, bookId);
 printf("\n\tNew book added to the library successfully!\n");
 printf("\n\t\t Press any key to try again: ");
 getch();
 system("cls");
}
