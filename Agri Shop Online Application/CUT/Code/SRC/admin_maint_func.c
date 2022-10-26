#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Asoa_header.h"
#include "validations.c"
/*******************************************************************************************
 *
 *   *FUNCTION NAME  :  farmer_registrtion
 *
 *   *DESCRIPTION    :  This functions is used here for registration  and to add the new farmer 
 *                        by the farmer or by the Admin respectively.
 *
 *   *RETURNS        :  No Returns
 *
 *******************************************************************************************/

int farmer_registration()                              //farmer registration function starts here.
{
	if((new=(ft*)calloc(1,sizeof(ft)))==NULL)
	{
		printf("\nMemory Allocation failed\n");
		return EXIT_FAILURE;
	}
	while(1)
	{
		printf("----------  WELCOME TO FARMER RESGISTRATION  ----------");
		while(1)
		{
			printf("\nEnter farmer aadhar no:  ");
			scanf("%lld", &new->farmerAadhar);
			if(validate_aadhar(new->farmerAadhar))
				continue;
			break;
		}
		if(start)
		{
			for(ptr=start;(ptr) && ptr->farmerAadhar!=new->farmerAadhar;ptr=ptr->next);
			if(ptr)
			{
				printf("\naadhar no %lld is duplicte\n",new->farmerAadhar);
				return EXIT_FAILURE;
			}
			else
				break;
		}
		break;
	}
	while(1)
	{
		printf("Enter farmerName:  ");
		scanf("%s",new->farmerName);
		if(validate_name(new->farmerName))
			continue;
		break;
	}
	while(1)
	{
		printf("Enter phoneno:  ");
		scanf("%lld", &new->phoneno);
		if(validate_phoneno(new->phoneno))
			continue;
		break;
	}
	while(1)
	{
		printf("Enter password: ");
		scanf("%s",new->password);
		if(validate_password(new->password))
			continue;
		break;
	}
	printf("Enter any one category from the below given.\n");
	printf("    1.Fruits\n    2.Vegetables\n    3.Food Grains\n");
	while(1)
	{
		printf("Enter Choice:  ");
		scanf("%d", &new->choice);
		if(new->choice==1)
		{
			strcpy( new->category,"Fruits");
		}
		else if(new->choice==2)
		{
			strcpy(new->category,"Vegetable");
		}
		else if(new->choice==3)
		{
			strcpy(new->category,"food Grains");
		}
		else 
		{
			printf("INVALID CHOICE....");
			printf("Enterchoice between 1-3");
			continue;
		}
		break;
	}
	int res;
	while(1)
	{
		printf("\nEnter the no.of items to supply:  ");
		scanf("%d",&res);
		new->code=res;
		if(res<1 || res>4)
		{
			printf("\n NUMBER OF ITEMS TO SUPPLY SHOULD BETWEEN 1 TO 4.");
			continue;
		}
		else
		{

			for(int i=0;i<res;i++)
			{
				printf("enter the item name:  ");
				scanf("%s",new->item[i]);
				printf("enter the quantity for item: ");
				scanf("%d",&new->quantity[i]);
				printf("enter the price for item: ");
				scanf("%d",&new->price[i]);
			}
		}
		break;
	}
	if(!start)
	{
		start=new;
		new->next=NULL;
	}
	else if(new->farmerAadhar<start->farmerAadhar)
	{
		new->next=start;
		start=new;
	}
	else
	{
		for(ptr=start;(ptr) && ptr->farmerAadhar<new->farmerAadhar;prev=ptr,ptr=ptr->next);
		prev->next=new;
		new->next=ptr;
	}

	return EXIT_SUCCESS;
}                                                               //farmer registration ends here.


/*******************************************************************************************
 *
 *   *FUNCTION NAME  :  edit_farmer_details
 *
 *   *DESCRIPTION    :  This functions is used here to edit the datas of the farmer by the fsrmer
 *                        or by the Admin after the registration process.
 *
 *   *RETURNS        :  No Returns
 *
 *******************************************************************************************/

int edit_farmer_details()                                       //edit farmer details function starts here.
{
	if(!start)
	{
		printf("\n Empty List\n");
		return EXIT_FAILURE;
	}
	long long int aadharno;
	while(1)
	{
		printf("\nEnter aadharno for editing: ");
		scanf("%lld",&aadharno);
		if(validate_aadhar(aadharno))
			continue;
		break;
	}
	for(ptr=start;(ptr) && ptr->farmerAadhar!=aadharno;ptr=ptr->next);
	if(!ptr)
	{
		printf("\nAadharno %lld not found\n",aadharno);
		return EXIT_FAILURE;
	}
	printf("Enter new name, new phoneno and password. \n");
	scanf("%s %lld %s",&ptr->farmerName,&ptr->phoneno,&ptr->password);
	printf("Enter any one category from the below given.");
	printf("    1.Fruits\n    2.Vegetables\n    3.Food Grains\n");
	scanf("%d", &ptr->choice);
	if(ptr->choice==1)
	{
		strcpy(ptr->category,"Fruits");
	}
	else if(ptr->choice==2)
	{
		strcpy(ptr->category,"Vegetables");
	}
	else if(ptr->choice==3)
	{
		strcpy(ptr->category,"foodgrains");
	}
	else
	{
		printf("INVALID CHOICE");
	}
	int res;
	printf("Enter no.of items  to supply: ");
	scanf("%d",&res);
	if(res<1 || res>4)
	{
		printf("\nNo. of items should lie between 1 to 4.\nPlease enter your choice  between 1-4.");

	}
	else
	{
		for(int i=0;i<res;i++)
		{
			printf("Enter the item name: ");
			scanf("%s",ptr->item[i]);
			printf("Enter the quantity of the item: ");
			scanf("%d",&ptr->quantity[i]);
			printf("Enter the price of the item: ");
			scanf("%d",&ptr->price[i]);
		}
	}
	return EXIT_SUCCESS;
}                                                      //edit farmer details function ends here.


/*******************************************************************************************
 *
 *   *FUNCTION NAME  :  show_farmer
 *
 *   *DESCRIPTION    :  This functions is used here to displays the datas of the farmer by the fsrmer
 *                        or by the Admin.
 *
 *   *RETURNS        :  No Returns
 *
 *******************************************************************************************/

int show_farmer()                                              //show farmer function starts here....
{
	if(!start)
	{
		printf("\n Empty List\n");
		return EXIT_FAILURE;
	}

	printf("\nAADHAR NO.     NAME      PHONE NO.    PASSWORD    CATEGORY    ITEM_NAME    QUANTITY   PRICE  \n");
	for(ptr=start;(ptr);ptr=ptr->next) 
	{
		for(int i=0;i<ptr->code;i++)
		{
			printf("\n%3lld    %5s    %6ld  %10s  %12s   %15s  %20d  %20d   \n",ptr->farmerAadhar,ptr->farmerName,ptr->phoneno,ptr->password,ptr->category,ptr->item[i],ptr->quantity[i],ptr->price[i]);
		}
	}
	return EXIT_SUCCESS;
}                                                              //show farmer function ends here....


/*******************************************************************************************
 *
 *   *FUNCTION NAME  :  delete_farmer_data
 *
 *   *DESCRIPTION    :  This functions is used here to delete the datas of the farmer by the Admin.
 *
 *   *RETURNS        :  No Returns
 *
 *******************************************************************************************/

int delete_farmer_data()					        //delete farmer function starts here....
{
	if(!start)
	{
		printf("\nEmpty List\n");
		return EXIT_FAILURE;
	}
	int aAadharNo;
	while(1)
	{
		printf("\nEnter the Aadhar number for deleting-");
		scanf("%d",&aAadharNo);
  		if(validate_aadhar(aAadharNo))
			continue;
		break;
	}
	if(aAadharNo==start->farmerAadhar)
	{
		ptr=start;
		start=start->next;
		free(ptr);
	}
	else
	{
		for(ptr=start;(ptr) && ptr->farmerAadhar!=aAadharNo;prev=ptr,ptr=ptr->next);
		if(!ptr)
		{
			printf("\nAadhar number %d is not found\n",aAadharNo);
			return EXIT_FAILURE;
		}
		prev->next=ptr->next;
		free(ptr);     
	}
	return EXIT_SUCCESS;
}                                                                             //delete farmer function nds here.....


/*******************************************************************************************
 *
 *   *FUNCTION NAME  :  farmer_to_list
 *
 *   *DESCRIPTION    :  This functions is used here to transfer the datas of the farmer from 
 *                           the farmer file to the list.
 *
 *   *RETURNS        :  No Returns
 *
 *******************************************************************************************/

int farmer_to_list()                                                         //farmer to list function starts here....
{

	FILE *p;
	ftt f1;
	if((p=fopen("Farmer.data","rb"))==NULL)
	{
		printf("\nFile is not there to read from\n");
		return EXIT_FAILURE;
	}
	fread(&f1,sizeof(ftt),1,p);
	while(!feof(p))
	{
		if((new=(ft *)calloc(1,sizeof(ft)))==NULL)
		{
			printf("\nMemory Allocation failed\n");
			return EXIT_FAILURE;
		}
		new->farmerAadhar=f1.farmerAadhar;
		strcpy(new->farmerName,f1.farmerName);
		new->phoneno=f1.phoneno;
		strcpy(new->password,f1.password);
		strcpy(new->category,f1.category);
		new->code=f1.code;
		for(int i=0;i<f1.code;i++)
		{
			strcpy(new->item[i],f1.item[i]);
			new->quantity[i]=f1.quantity[i];
			new->price[i]=f1.price[i];
		}
		if(!start)
		{
			start = last = new;
			new->next=NULL;
		}
		else
		{
			last->next=new;
			last=new;
			new->next=NULL;
		}
		fread(&f1,sizeof(ftt),1,p);
	}
	//free(new);
	fclose(p);
	return EXIT_SUCCESS;
}                                                                            //farmer to list function ends here....

/*******************************************************************************************
 *
 *   *FUNCTION NAME  :  list_to_farmer
 *
 *   *DESCRIPTION    :  This functions is used here to transfer the datas of the farmer from 
 *                           the list to the farmer file.
 *
 *   *RETURNS        :  No Returns
 *
 *******************************************************************************************/

int list_to_farmer()                                                        //list to farmer function starts here....
{
	ftt f2;
	if(!start)
	{
		printf("\nThe List is Empty.\n");
		return EXIT_FAILURE;
	}
	FILE *p1;
	if((p1=fopen("Farmer.data","wb"))==NULL)
	{
		printf("\nFile is not there to read from\n");
		return EXIT_FAILURE;
	}
	for(ptr=start;(ptr);ptr=ptr->next)
	{
		f2.farmerAadhar=ptr->farmerAadhar;
		strcpy(f2.farmerName,ptr->farmerName);
		f2.phoneno=ptr->phoneno;
		strcpy(f2.password,ptr->password);
		strcpy(f2.category,ptr->category);
		f2.code=ptr->code;
		for(int i=0;i<f2.code;i++)
		{
			strcpy(f2.item[i],ptr->item[i]);
			f2.quantity[i]=ptr->quantity[i];
			f2.price[i]=ptr->price[i];
		}
		fwrite(&f2,sizeof(ftt),1,p1);
	}
	fclose(p1);
	//free(ptr);
	return EXIT_SUCCESS;
}                                                                                   //list to farmer function ends here....

/*******************************************************************************************
 *
 *   *FUNCTION NAME  :  registration
 *
 *   *DESCRIPTION    :  This functions is used here for the registration of the new customers 
 *                      and adding of new customers by the customer itself and by the Admin respectively.
 *
 *   *RETURNS        :  No Returns
 *
 *******************************************************************************************/

int registration()                                                      // registration function starts here....
{
	if((new1=(ct *)calloc(1,sizeof(ct)))==NULL)
	{
		printf("\n Memory allocation failed\n");
		return EXIT_FAILURE;
	}
	while(1)
	{
		while(1)
		{
			printf("Enter aadhar number-");
			scanf("%lld",&new1->customerAadhar);
			if(validate_aadhar(new1->customerAadhar))
				continue;
			break;
		}
		if(start1)
		{
			for(ptr1=start1;(ptr1) && ptr1->customerAadhar!=new1->customerAadhar;ptr1=ptr1->next1);
			if(ptr1)
			{
				printf("\n Aadhar number %lld is duplicatte\n",new1->customerAadhar);
				return EXIT_FAILURE;
			}
			else
				break;
		}
		break;
	}
	while(1)
	{
		printf("Enter the name-");
		scanf("%s",new1->customerName);
		if(validate_name(new1->customerName))
			continue;
		break;
	}
	while(1)
	{
		printf("Enter phone number-");
		scanf("%lld",&new1->phoneno);
		if(validate_phoneno(new1->phoneno))
			continue;
		break;
	}
	printf("Enter the address-");
	scanf("%s",new1->address);
	if(!start1)
	{
		start1=new1;
		new1->next1=NULL;
	}
	else if(new1->customerAadhar<start1->customerAadhar)
	{
		new1->next1=start1;
		start1=new1;
	}
	else
	{
		for(ptr1=start1;(ptr1) && ptr1->customerAadhar<new1->customerAadhar;prev1=ptr1,ptr1=ptr1->next1);
		prev1->next1=new1;
		new1->next1=ptr1;
	}
	return EXIT_SUCCESS;
}                                                                       //registration function ends here....


/*******************************************************************************************
 *
 *   *FUNCTION NAME  :  do_transaction
 *
 *   *DESCRIPTION    :  This functions is used here for the customers who needs to buy a product by 
 *                           giving the product name and the respective farmer aadhar number.
 *
 *   *RETURNS        :  No Returns
 *
 *******************************************************************************************/

int do_transaction()                                                   //do transaction function starts here...

{
	ct c1;
	char item_name[20];
	int n;
	int amt;
	int aadhar;
	if((new2=(pt *)calloc(1,sizeof(pt)))==NULL)
	{
		printf("Memory Alocation Failed");
		return EXIT_FAILURE;
	}
	printf("------WELCOME TO THE AGRI SHOP ONLINE------");
	printf("\n\nEnter your name-");
	scanf("%s",c1.customerName);
	printf("Enter the aadhar num-");
	while(1)
	{
		scanf("%lld",&new2->custAadhar);
		for(ptr1=start1;(ptr1);ptr1=ptr1->next1)
		{
			if(ptr1->customerAadhar!=new2->custAadhar)
			{
				printf("please enter valid number");
				continue;
				// return EXIT_FAILURE;
			}
			else
			{
				printf("Adhar verification has been successful\n");
				printf("---Start the shopping---\n");
				break;
			}
		}
		break;
	}
	printf("\n--------------------------------------------\n");
	printf("Enter number of items you want to buy-");
	while(1)
	{
	scanf("%d",&n);
	if(n<1 || n>3)
	{
		printf("enter the items between 1-3\n");
		continue;
	}
	else
		break;
	break;
	}
	new2->num=n;
	new2->total_cost=0;
	for(int i=0;i<n;i++)
	{
		while(1)
		{
			printf("Enter the item name you want to buy-");
			scanf("%s",new2->product[i]);
			for(ptr=start;(ptr);ptr=ptr->next)
			{
				for(int i=0;i<n;i++)
				{
					if(strcmp(ptr->item[i],new2->product[i])==0)
					{
						printf("\nAadhar    Name    Item     quantity     Unit_Price\n\n");
						printf("%lld     %s    %s     %d    %d\n",ptr->farmerAadhar,ptr->farmerName,ptr->item[i],ptr->quantity[i],ptr->price[i]);
					}
									break;
				}
			}
			printf("\n Enter the aadhar number of whose product you want to buy-");
			scanf("%lld",&new2->farmAadhar);
			for(ptr=start;(ptr);ptr=ptr->next)
			{
				for(int i=0;i<n;i++)
				{
					if((ptr->farmerAadhar==new2->farmAadhar) && (strcmp(ptr->item[i],new2->product[i])==0))
					{
						new2->amount[0]=0;
						printf("Enter the quantity you want to buy-");
						scanf("%d",&new2->qty);
						new2->cost[i]=ptr->price[i];
						new2->amount[i]=new2->amount[i]+(new2->qty*ptr->price[i]);
						ptr->quantity[i]=ptr->quantity[i]-new2->qty;
						printf("Total price is-%d\n",new2->amount[i]);
					}
					
				}
			}
			break;
		}

		new2->total_cost=new2->total_cost+new2->amount[i];	
	}
	printf("Total price of the items-%d\n",new2->total_cost);
	printf("Enter the amount to pay: ");
	scanf("%d",&amt);
	if(new2->total_cost==amt)
	{
		printf("Your Transaction is Successfull.");
	}
	if(!start2)
	{
		start2=new2;
		new2->next2=NULL;
	}
	else if(new2->custAadhar < start2->custAadhar)
	{
		new2->next2=start2;
		start2=new2;
	}
	else
	{
		for(ptr2=start2;(ptr2) && ptr2->custAadhar<new2->custAadhar;prev2=ptr2,ptr2=ptr2->next2);
		prev2->next2=new2;
		new2->next2=ptr2;
	}
	return EXIT_FAILURE;
}                                                                         //do transaction function ends here....


/*******************************************************************************************
 *
 *   *FUNCTION NAME  :  edit_customer_details
 *
 *   *DESCRIPTION    :  This functions is used here to edit the datas of the customer by the customer
 *                        or by the Admin after the registration process.
 *
 *   *RETURNS        :  No Returns
 *
 *******************************************************************************************/

int edit_customer_details()                                               //edit customer details function starts here
{
	if(!start1)
	{
		printf("\n Empty List\n");
		return EXIT_FAILURE;
	}
	long long int aadharnum;
	while(1)
	{
		printf("\nEnter aadhar number for editing-");
		scanf("%lld",&aadharnum);
		if(validate_aadhar(aadharnum))
			continue;
		break;
	}
	for(ptr1=start1;(ptr1) && ptr1->customerAadhar!=aadharnum;ptr1=ptr1->next1);
	if(!ptr1)
	{
		printf("\n Adhar num %lld not found\n",aadharnum);
		return EXIT_FAILURE;
	}
	printf("Old name is %s and phonenum is %lld\n",ptr1->customerName,ptr1->phoneno);
	printf("Enter new name and new phone number-");
	scanf("%s %lld",&ptr1->customerName,&ptr1->phoneno);
	return EXIT_SUCCESS;
}                                                                         //do transaction function ends here....


/*******************************************************************************************
 *
 *   *FUNCTION NAME  :  show_customer_details
 *
 *   *DESCRIPTION    :  This functions is used here to displays the datas of the customers by the customer
 *                        or by the Admin.
 *
 *   *RETURNS        :  No Returns
 *
 *******************************************************************************************/

int show_customer_details()                                              //show customer details function starts here.... 
{
	if(!start1)
	{
		printf("\nEmpty List\n");
		return EXIT_FAILURE;
	}
	printf("\n   AADHARNUM     NAME     PHONENUM      ADDRESS   \n");
	for(ptr1=start1;(ptr1);ptr1=ptr1->next1)
	{
		printf("\n %5lld     %10s      %3lld       %10s   ",ptr1->customerAadhar,ptr1->customerName,ptr1->phoneno,ptr1->address);

	}
	return EXIT_SUCCESS;              
}                                                                         //show customer details function ends here....


/*******************************************************************************************
 *
 *   *FUNCTION NAME  :  delete customer data
 *
 *   *DESCRIPTION    :  This functions is used here to delete the datas of the customer by the Admin.
 *
 *   *RETURNS        :  No Returns
 *
 *******************************************************************************************/

int delete_customer_data()						    //delete customer function starts here.
{
	if(!start1)
	{
		printf("\nThe List is Empty\n");
		return EXIT_FAILURE;
	}
	int aAadharNo;
	while(1)
	{
		printf("\nEnter the Aadhar number for deleting-");
		scanf("%d",&aAadharNo);
		if(validate_aadhar(aAadharNo))
			continue;
		break;
	}
	if(aAadharNo==start1->customerAadhar)
	{
		ptr1=start1;
		start1=start1->next1;
		free(ptr1);
	}
	else
	{
		for(ptr1=start1;(ptr1) && ptr1->customerAadhar!=aAadharNo;prev1=ptr1,ptr1=ptr1->next1);
		if(!ptr1)
		{
			printf("\nAadhar number %d is not found\n",aAadharNo);
			return EXIT_FAILURE;
		}
		prev1->next1=ptr1->next1;
		free(ptr1);
	}
	return EXIT_SUCCESS;
}									     //delete customers function ends here....


/*******************************************************************************************
 *
 *   *FUNCTION NAME  :  customer_to_list
 *
 *   *DESCRIPTION    :  This functions is used here to transfer the datas from the customer file  
 *                           to the list.

 *   *RETURNS        :  No Returns
 *
 *******************************************************************************************/

int customer_to_list()                                                      //customer to list function starts here....
{

	FILE *cp;
	ctt c1;
	if((cp=fopen("Customer.data","rb"))==NULL)
	{
		printf("\nFile is not present to read from\n");
		return EXIT_FAILURE;
	}
	system("clear");
	fread(&c1,sizeof(ctt),1,cp);
	while(!feof(cp))
	{
		if((new1=(ct *)calloc(1,sizeof(ct)))==NULL)
		{
			printf("\nMemory Allocation failed\n");
			return EXIT_FAILURE;
		}
		new1->customerAadhar=c1.customerAadhar;
		strcpy(new1->customerName, c1.customerName);
		new1->phoneno=c1.phoneno;
		strcpy(new1->address,c1.address);
		if(!start1)
		{
			start1 = last1 = new1;
			new1->next1=NULL;
		}
		else
		{
			last1->next1=new1;
			last1=new1;
			new1->next1=NULL;
		}
		fread(&c1,sizeof(ctt),1,cp);
	}
	//free(new1);
	fclose(cp);
	return EXIT_SUCCESS;
}

/* ---------- List to File for Customer Details----------*/
/*******************************************************************************************
 *
 *   *FUNCTION NAME  :  list_farmer
 *
 *   *DESCRIPTION    :  This functions is used here to transfer the datas of the farmer from 
 *                           the list to the farmer file.
 *
 *   *RETURNS        :  No Returns
 *
 *******************************************************************************************/

int list_to_customer()
{
	ctt c2;
	if(!start1)
	{
		printf("\nThe List is Empty.\n");
		return EXIT_FAILURE;
	}
	FILE *cp1;
	if((cp1=fopen("Customer.data","wb"))==NULL)
	{
		printf("\nFile is not present to read \n");
		return EXIT_FAILURE;
	}
	for(ptr1=start1;(ptr1);ptr1=ptr1->next1)
	{
		c2.customerAadhar=ptr1->customerAadhar;
		strcpy(c2.customerName,ptr1->customerName);
		c2.phoneno=ptr1->phoneno;
		strcpy(c2.address,ptr1->address);
		fwrite(&c2,sizeof(ctt),1,cp1);
	}
	fclose(cp1);
	//free(ptr1);
	return EXIT_SUCCESS;
}

/*******************************************************************************************
 *
 *   *FUNCTION NAME  :  list_farmer
 *
 *   *DESCRIPTION    :  This functions is used here to transfer the datas of the farmer from 
 *                           the list to the farmer file.
 *
 *   *RETURNS        :  No Returns
 *
 *******************************************************************************************/


int farmer_report()
{
	long long int aadharnum;
	if(!start2)
	{
		printf("Empty List");
		return EXIT_FAILURE;
	}
	printf("Enter The Aadhar Number of Whose Report you want: ");
	while(1)
	{
		scanf("%lld",&aadharnum);
		for(ptr2=start2;(ptr2);ptr2=ptr2->next2)
		{

			for(int i=0;i<ptr2->num;i++)
			{
				if(ptr2->farmAadhar==aadharnum)
				{
					printf("\nAADHAR NUMBER     ITEM NAME     QUANTITY      UNIT PRICE     COST\n");
					printf("     %lld          %s         %d    %d    %d\n",ptr2->farmAadhar, ptr2->product[i],ptr2->qty,ptr2->cost[i],ptr2->amount[i]);
				}
				else
				{
					printf("Enter valid Aadhar number");
					break;
				}
			}
		}
		break;
	}
	return EXIT_SUCCESS;
}

/*******************************************************************************************
 *
 *   *FUNCTION NAME  :  list_farmer
 *
 *   *DESCRIPTION    :  This functions is used here to transfer the datas of the farmer from 
 *                           the list to the farmer file.
 *
 *   *RETURNS        :  No Returns
 *
 *******************************************************************************************/

int consolidated_transaction_report()
{

	if(!start2)
	{
		printf("\nThe List is Empty\n");
		return EXIT_FAILURE;
	}
	for(ptr2=start2;(ptr2);ptr2=ptr2->next2) 
	{
		printf("\n FARMER AADHAR    CUSTOMER AADHAR  ITEM NAME    QUANTITY   UNIT PRICE    AMOUNT  \n");
		for(int i=0;i<ptr2->num;i++)
		{
			printf("\n%lld  %lld     %3s  %3d    %d     %d \n",ptr2->farmAadhar,ptr2->custAadhar,ptr2->product[i], ptr2->qty,ptr2->cost[i],ptr2->amount[i]);
		}
		printf("\n");
	}

	return EXIT_SUCCESS;
}									      //view customer function ends here.





/*******************************************************************
 *    *FUNCTION NAME	 : reports_menu
 *    
 *    *DESCRIPTION       : This function is used to view the various reports by the admin.
 *
 *    *RETURNS           : farmer_report function  - For getting the reports of a particular farmer by the admin.
 *     			   consolidated_transaction_report function  - For viewing the consolidated report on all the purchses done till then by the admin.
 *     			   back  - To go back to the main menu.
 *
 *******************************************************************/ 
int reports_menu()
{
	int ch=0;
	while(ch!=3)
	{
		printf("1.farmer report\n2.transcation report\n3.back");
		printf("\nEnter choice-");
		scanf("%d",&ch);
		switch(ch)
		{ 
			case 1: farmer_report();
				break;
			case 2: consolidated_transaction_report();
				break;
			case 3:break;
			default: printf("Invalid choice");
		}
	}
	return EXIT_SUCCESS;
}

/*******************************************************************************************
 *
 *   *FUNCTION NAME  :  list_farmer
 *
 *   *DESCRIPTION    :  This functions is used here to transfer the datas of the farmer from 
 *                           the list to the farmer file.
 *
 *   *RETURNS        :  No Returns
 *
 *******************************************************************************************/

int transaction_to_list()
{

	FILE *pr;
	ptt p1;
	if((pr=fopen("Transaction.data","rb"))==NULL)
	{
		printf("\nFile is not there to read from\n");
		return EXIT_FAILURE;
	}
	fread(&p1,sizeof(ptt),1,pr);
	while(!feof(pr))
	{
		if((new2=(pt *)calloc(1,sizeof(pt)))==NULL)
		{
			printf("\nMemory Allocation failed\n");
			return EXIT_FAILURE;
		}
		new2->farmAadhar=p1.farmAadhar;
		new2->custAadhar=p1.custAadhar;
		new2->num=p1.num;
		for(int i=0;i<new2->num;i++)
		{
			strcpy(new2->product[i],p1.product[i]);
			new2->quantity2[i]=p1.quantity2[i];
			new2->cost[i]=p1.cost[i];
			new2->amount[i]=p1.amount[i];
		}
		new2->total_cost=p1.total_cost;
		if(!start2)
		{
			start2 = last2 = new2;
			new2->next2=NULL;
		}
		else
		{
			last2->next2=new2;
			last2=new2;
			new2->next2=NULL;
		}
		fread(&p1,sizeof(ptt),1,pr);
	}
	free(new2);
	fclose(pr);
	return EXIT_SUCCESS;
}

/*******************************************************************************************
 *
 *   *FUNCTION NAME  :  list_farmer
 *
 *   *DESCRIPTION    :  This functions is used here to transfer the datas of the farmer from 
 *                           the list to the farmer file.
 *
 *   *RETURNS        :  No Returns
 *
 *******************************************************************************************/

int list_to_transaction()                                              //list to transaction function starts here.....
{
	ptt p2;
	if(!start2)
	{
		printf("\nThe List is Empty.\n");
		return EXIT_FAILURE;
	}
	FILE *pr;
	if((pr=fopen("Transaction.data","wb"))==NULL)
	{
		printf("\nFile is not there to read from\n");
		return EXIT_FAILURE;
	}
	for(ptr2=start2;(ptr2);ptr2=ptr2->next2)
	{
		p2.farmAadhar=ptr2->farmAadhar;
		p2.custAadhar=ptr2->custAadhar;
		p2.num=ptr2->num;
		for(int i=0;i<p2.num;i++)
		{
			strcpy(p2.product[i],ptr2->product[i]);
			p2.quantity2[i]=ptr2->quantity2[i];
			p2.cost[i]=ptr2->cost[i];
			p2.amount[i]=ptr2->amount[i];
		}
		p2.total_cost=ptr2->total_cost;

		fwrite(&p2,sizeof(ptt),1,pr);
	}
	fclose(pr);
	free(ptr2);
	return EXIT_SUCCESS;
}                                                                          //list to file transactionfunction ends here....

/*---------------------------------------------END OF THE FUNCTIONS FILE--------------------------------------------------------*/
