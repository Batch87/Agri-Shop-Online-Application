/*********************************************************************
 *    *FILENAME			:     main.c
 *
 *    *DESCRIPTION              :     This file defines the functions that consists of various subfunctions to perform various operations.
 *
 *    *REVISION HISTORY         :      
 *        
 *           DATE               NAME                REASON
 *
 *
 *
 *******************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "../header/header.h"
#include "../src/func.c"
/*******************************************************************
 *    *FUNCTION NAME	 : farmer
 *    
 *    *DESCRIPTION       : This function is used to performs various operations in the farmer database by receiving choices from the user.
 *
 *    *RETURNS           : farmer_registration function  - For registering the new farmer users.
 *     			   edit_farmer_details_function  - For editing the details of the existing farmer.
 *     			   show_farmer function  - For viewing the datails of all the farmers.
 *     			   back  - To go back to the main menu.
 *
 *******************************************************************/
int farmer()
{
        int ch=0;
	system("clear");
        while(ch!=4)
        {
                printf("\n");
		printf("\n\n---------------------   WELCOME TO FARMER MENU   ----------------------------------\n");
                printf("1.farmer registration\n2.edit farmer details\n3.Show farmer details\n4.Back\n");
 printf("\nEnter choice-");
                scanf("%d",&ch);
                switch(ch)
                {
                        case 1: farmer_registration();
                               break;
                   	case 2: edit_farmer_details();
			       break;
                        case 3: show_farmer();
			       break;
			case 4:break;
                        default: printf("Invalid choice\n");
                }
		system("read a");
	system("clear");
        }
        return EXIT_SUCCESS;
}
/*******************************************************************
 *    *FUNCTION NAME	 : customer
 *    
 *    *DESCRIPTION       : This function is used to performs various operations in the customer database by receiving choices from the user.
 *
 *    *RETURNS           : customer_registration function  - For registering the new customer users.
 *     		           do_transaction function  - For loging in and making the purchace.
 *     			   edit_customer_details_function  - For editing the details of the existing customer.
 *     			   show_customer function  - For viewing the datails of all the customers.
 *     			   back  - To go back to the main menu.
 *
 *******************************************************************/     			   
int customer()
{
        int ch=0;
	system("clear");
        while(ch!=5)
        {
                printf("\n");
		printf("\n\n----------------------   WELCOME TO CUSTOMER MENU   ---------------------------------\n");
                printf("1.Customer registration\n2.do transaction\n3.Edit customer details\n4.View customer details\n5.Back\n");
                printf("\nEnter choice-");
                scanf("%d",&ch);
                switch(ch)
                {
                        case 1: registration();
                               break;
                        case 2: do_transaction();
                               break;
                        case 3: edit_customer_details();
                               break;
                        case 4: show_customer_details();
			       break;
			case 5:break;
                        default: printf("Invalid choice\n");
                }
		system("read a");
	system("clear");
        }
        return EXIT_SUCCESS;
}
/*******************************************************************
 *    *FUNCTION NAME	 : admin
 *    
 *    *DESCRIPTION       : This function is used to performs various operations that has to be performed by the admin.
 *
 *    *RETURNS           : file_maintenance function  - For maintaining the details of both the farmers and customers by the admin.
 *     			   report function  - For viewing the different reports by receiving the choice from the admin.
 *     			   back  - To go back to the main menu.
 *
 *******************************************************************/     			   
int admin()
{
        int ch=0;
	system("clear");
        while(ch!=4)
        {
                printf("\n");
		printf("\n\n-----------------------   WELCOME TO ADMIN MENU   --------------------------------\n");
                printf("1.Menu for Farmer\n2.Menu for Customer\n3.Menu for Reports\n4.Back\n");
                printf("\nEnter choice-");
                scanf("%d",&ch);
                switch(ch)
                {
                     case 1: farmer_menu();
  			    break;
                     case 2: customer_menu();
                             break;
		     case 3: reports_menu();
			     break;
                     case 4:break;
                     default: printf("Invalid choice");
                }
	system("read a");
	system("clear");
        }
        return EXIT_SUCCESS;
}
/*******************************************************************
 *    *FUNCTION NAME	 : farmer_menu
 *    
 *    *DESCRIPTION       : This function is used to performs various maintenance operations on farmer data by admin.
 *
 *    *RETURNS           : add_farmer_details function  - For adding the new farmer user by admin.
 *     			   edit_farmer_details function  - For editing the details of the existing farmer by admin.
 *     			   view_farmer_details function  - For viewing the datails of all the farmers by admin.
 *     			   delete_farmer_details function  - For deleting the details of the farmers by admin.
 *                         back  - To go back to the main menu.
 *
 *******************************************************************/     			   

int farmer_menu()
{
        int ch=0;
	system("clear");
        while(ch!=5)
        {
                printf("\n");
		printf("\n\n-----------------------   WELCOME ADMIN TO FARMER MENU   --------------------------------\n");
                printf("1.add farmer details\n2.edit farmer details\n3.view farmer details\n4.delete farmer details\n5.back\n");
                printf("\nEnter choice-");
                scanf("%d",&ch);
                switch(ch)
                {
                        case 1:
				farmer_registration();
				break;
                        case 2: edit_farmer_details();
			       break;
			case 3:
				show_farmer();
				break;
                        case 4: delete_farmer_data();
                               break;
		        case 5: break;
                        default: printf("Invalid choice");
                }
		system("read a");
	system("clear");
        }
	//system ("clear");
        return EXIT_SUCCESS;
}
/*******************************************************************
 *    *FUNCTION NAME	 : customer_menu
 *    
 *    *DESCRIPTION       : This function is used to performs various maintenance operations on customer data by admin.
 *
 *    *RETURNS           : add_customer_details function  - For adding the new customer user by admin.
 *     			   edit_customer_details function  - For editing the details of the existing customer by admin.
 *     			   view_customer_details function  - For viewing the details of all the customers by admin.
 *     			   delete_customer_details function  - For deleting the details of the customers by admin.
 *     			   back  - To go back to the main menu.
 *
 *******************************************************************/     			   
int customer_menu()
{
        int ch=0;
	system("clear");

        while(ch!=5)
        {
                printf("\n");
		printf("\n\n--------------------   WELCOME ADMIN TO CUSTOMER MENU   -------------------------------\n");
                printf("\n1.add customer details\n2.edit customer details\n3.view customer details\n4.delete customer details\n5.back\n");
                printf("\nEnter choice-");
                scanf("%d",&ch);
                switch(ch)
                {
		        case 1: registration();
                               break;
                        case 2: edit_customer_details();
			       break;
                        case 3: show_customer_details();
                               break;
                        case 4: delete_customer_data();
                               break;
                        case 5:break;
                        default: printf("Invalid choice");
                }
		system("read a");
	system("clear");
	}
                return EXIT_SUCCESS;
}
/*******************************************************************
 *    *FUNCTION NAME	 : main
 *    
 *    *DESCRIPTION       : This function calls all the other functions thathas to be perform various operations by taking choices from the user.
 *
 *    *RETURNS           : farmer function
 *     			   customer function
 *     			   admin function
 *     			   exit - To exitthe main function.
 *
 *******************************************************************/    
int main()
{
        int ch=0;
	farmer_to_list();
	customer_to_list();
	transaction_to_list();
	system("clear");
        while(ch!=4)
        {
		printf("\n");
		printf("\n\n---------------------   WELCOME TO ASOA   -----------------------------------\n");
                printf("1.Farmer\n2.Customer\n3.Admin\n4.Exit\n");
                printf("\nEnter choice-");
                scanf("%d",&ch);
                switch(ch)
                {
                        case 1: farmer();
                               break;
                        case 2: customer();
                               break;
                        case 3: admin();
                               break;
                        case 4:break;
                        default: printf("\nInvalid choice\n");
                }
        }
	list_to_farmer();
	list_to_customer();
	list_to_transaction();
	system("read a");
	system("clear");
	printf("\n\n\n--------    THANK YOU FOR USING ASOA    --------\n\n\n");
        return EXIT_SUCCESS;
}

/*-------------------------------------------END OF THE MAIN MENU----------------------------------------------------------------*/




