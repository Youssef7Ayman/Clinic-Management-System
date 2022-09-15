/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
**************************************************** ______________________________________ ************************************************************************************************
****************************************************|                                      |************************************************************************************************
****************************************************|  SW FOR  : Clinic Management System  |************************************************************************************************
****************************************************|                                      |************************************************************************************************
****************************************************|  BY      : Youssef Ayman Mohamed     |************************************************************************************************
****************************************************|                                      |************************************************************************************************
****************************************************|  DATE    : 9/Sep/2022                |************************************************************************************************
****************************************************|                                      |************************************************************************************************
****************************************************|  VERSION : V1.0                      |************************************************************************************************
****************************************************|______________________________________| ***********************************************************************************************             
****************************************************                                        ************************************************************************************************
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

//*******************************************************************************************


                                          /*--------------------------------------------------------------------------------*/
//								**** Included Libiraries & Files (START) ***										  

# include <stdio.h>
# include "STD_TYPES.h"
# include <stdlib.h>

//								**** Included Libiraries & Files (End) ***										  
                                          /*--------------------------------------------------------------------------------*/
										  
										  
										  
//*******************************************************************************************



                                          /*--------------------------------------------------------------------------------*/
//						**** STRUCTS definitions , Global STRUCTS & Global Variables  (START) ***										  
										  
	

//*****************************************
typedef struct NODE
{
	u16 name[15];
	u8 age;
	u8 gender[10];
	u32 id;
	u8 flag;
	struct NODE *Next;
}pt_node;
//*****************************************
pt_node head;
u32 ListLength = 0;
u32 ListLength2 = 0;
u8 s=0;
//*****************************************
typedef struct RESERVATION
{
	u32 reserve_id;
	u8 time[15];
	struct RESERVATION *reserve_Next;
	
}res_slot;  
//*****************************************                
res_slot slot1={0,"2pm-2:30pm",NULL};
res_slot slot2={0,"2:30pm-3pm",NULL};
res_slot slot3={0,"3pm-3:30pm",NULL};
res_slot slot4={0,"4pm-4:30pm",NULL};
res_slot slot5={0,"4:30pm-5pm",NULL};
//*****************************************


//						**** STRUCTS definitions , Global STRUCTS & Global Variables  (END) ***										  
                                          /*--------------------------------------------------------------------------------*/



//*******************************************************************************************


                                          /*--------------------------------------------------------------------------------*/
//									**** Prototypes (START) ***										  


//*********************************************************
u8 CHOOSE_MODE (void);
//*********************************************************
u8 ADMIN_PASSWORD_LOGIN (void);
//*********************************************************
u8 ADD_PATIENT (u16 N_AME[],u8 A_GE,u8 G_ENDER[],u32 I_D);
//*********************************************************
void PrintLinkedList(void);
//*********************************************************
void EDIT_PATIENT (u32 edit_id);
//*********************************************************
void PRINT_AVAILABLE_SLOTS (void);
//*********************************************************
void DOCTOR_RESERVATION (u32 R_ESID);
//*********************************************************
void CANCEL_RESERVATION (void);
//*********************************************************
void VIEW_PATIENT (void);
//*********************************************************
void VIEW_RESERVATION (void);
//*********************************************************


//								    **** Prototypes (END) ***	
                                          /*--------------------------------------------------------------------------------*/
									  

//*******************************************************************************************


                                          /*--------------------------------------------------------------------------------*/
//								**** Main Function (START) ***										  
										  
void main(void)

{
    printf("******************************************************************************************************************************************************************************************************************\n");
    printf("******************************************************************************************************************************************************************************************************************\n");
    printf("******************************************************************************** ______________________________________ ******************************************************************************************\n");
    printf("********************************************************************************|                                      |******************************************************************************************\n");
    printf("********************************************************************************|  SW FOR  : Clinic Management System  |******************************************************************************************\n");
    printf("********************************************************************************|                                      |******************************************************************************************\n");
    printf("********************************************************************************|  BY      : Youssef Ayman Mohamed     |******************************************************************************************\n");
    printf("********************************************************************************|                                      |******************************************************************************************\n");
    printf("********************************************************************************|  DATE    : 9/Sep/2022                |******************************************************************************************\n");
    printf("********************************************************************************|                                      |******************************************************************************************\n");
    printf("********************************************************************************|  VERSION : V1.0                      |******************************************************************************************\n");
    printf("********************************************************************************|______________________________________|******************************************************************************************\n");
    printf("********************************************************************************                                        ******************************************************************************************\n");
    printf("******************************************************************************************************************************************************************************************************************\n");
    printf("******************************************************************************************************************************************************************************************************************\n\n\n");
    	
	u8 MODE,KEY1,KEY2,AGE,GENDER[10],FLAG,ret,EXIT=0,aORo;
	u16 NAME[15];
	u32 ID,EDIT_ID,RESID,CANRESID;

	printf("\t\t\t\t\t\t***************************************************************************************************************************\n\n");
	printf("\nNOTES :-        \t\t\t\t\t\t\t{  Maximize The Command Window To Be Able To Recognize The Whole Design  } \n------\n\n");
	printf("\n1 - YOU MUST BE SENSITIVE TO EACH WORD AND KEY \n");
	printf("\n2 - Take in Your Consideration each CAPITAL , SMALL Letters and SPACES !\n");
	printf("\n3 - FOR EXAMPLE ---> ADMIN Mode PRESS ' A ': [ A ] NOT [ a ]\n\n");
	printf("\t\t\t\t\t\t***************************************************************************************************************************\n\n\n");



	while (EXIT==0)
	{
		u8 ExitFlag1=0,ExitFlag2=0;

		MODE=CHOOSE_MODE();
		if (MODE=='S')
		{
			printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t-------------------------------\n");
			printf("\t\t\t\t\t\t\t\t\t\t\t ! * Program will Shut Down * !\n");
			printf("\t\t\t\t\t\t\t\t\t\t\t-------------------------------\n\n\n");

			printf(" * THANK YOU , \n   GOOD BYE  ! \n\n");
			printf(" ---------------\n\n\n");
			printf("\t\t\t\t\t\t***************************************************************************************************************************\n\n");
			printf("\t\t\t\t\t\t\t**********************************************************************************************************\n\n");
			printf("\t\t\t\t\t\t\t\t******************************************************************************************\n\n\n\n\n");

			EXIT++;
		}
		else if (MODE=='A')
		{
			while (1)
			{
				FLAG=ADMIN_PASSWORD_LOGIN ();
				if (FLAG==1)
				{
					break;
				}
				else
				{

					while (ExitFlag1 == 0)
					{
						printf("\n\n------------------------------------------------------------\n\n");
						printf(" - To Add new Patient record         ------------> PRESS (1)\n\n");
						printf(" - To Edit Patient record            ------------> PRESS (2)\n\n");
						printf(" - To Reserve a slot with the Doctor ------------> PRESS (3)\n\n");
						printf(" - To Cancel reservation             ------------> PRESS (4)\n\n");
						printf(" - To Return to Home Page            ------------> PRESS (5)\n\n");
						printf("------------------------------------------------------------\n\n\n\n");

						printf("Please press your Target key : ");
						scanf("%d",&KEY1);
						if (KEY1==1 || KEY1==2 || KEY1==3 || KEY1==4 || KEY1==5)
						{
							switch (KEY1)
							{
							case 1:
							{
								printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t----------------------------\n");
								printf("\t\t\t\t\t\t\t\t\t\t\t 1 - Add new Patient record \n");
								printf("\t\t\t\t\t\t\t\t\t\t\t----------------------------\n\n\n");

								printf("----------------------------------------------------------------------------------------------------------\n");
								printf(" * During Writing The Name : USE [-] 'minus sign' Instead of [space] between The FIRST & THE SECOND NAME .\n");
								printf("----------------------------------------------------------------------------------------------------------\n\n\n");


								printf(" - Name   : ");
								scanf("%s",NAME);
								printf(" - Age    : ");
								scanf("%d",&AGE);
								printf(" - Gender : ");
								scanf("%s",GENDER);
								printf(" - ID     : ");
								scanf("%d",&ID);

								ret=ADD_PATIENT (NAME,AGE,GENDER,ID);
								if (ret==1)
								{
									printf("\nPatient is Added successfully ,\nThank You !\n");
									printf("--------------------------------------------\n\n\n");
								}
								break;

							}
							case 2:
							{
								printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t--------------------------\n");
								printf("\t\t\t\t\t\t\t\t\t\t\t\t 2 - Edit Patient record \n");
								printf("\t\t\t\t\t\t\t\t\t\t\t\t--------------------------\n\n\n");


								printf("Please enter your ID : ");
								scanf("%d",&EDIT_ID);
								EDIT_PATIENT (EDIT_ID);
								break;
							}
							case 3:
							{
								printf("\n\n\n\t\t\t\t\t\t\t\t\t\t-----------------------------------\n");
								printf("\t\t\t\t\t\t\t\t\t\t 3 - Reserve a slot with the Doctor \n");
								printf("\t\t\t\t\t\t\t\t\t\t-----------------------------------\n\n\n");

								printf("------------------------------------------------------------------------------------------------------------------------------\n");
								printf(" * IN RESERVATION SLOT : Type the TIME with your hand from the available SLOTS considering the specified Format [eg. 6pm-7:30pm ]\n\n");
								printf(" * You Can Also COPY The Time From The Available SLOTS , Then PAST it in The RESERVATION SLOT . \n");
								printf("------------------------------------------------------------------------------------------------------------------------------\n\n\n");

								if (s==0)
								{
									printf("The Available SLOTS :-\n");
									printf("-------------------\n\n");
									printf("SLOT 1 : %s \nSLOT 2 : %s \nSLOT 3 : %s \nSLOT 4 : %s \nSLOT 5 : %s \n\n\n",slot1.time,slot2.time,slot3.time,slot4.time,slot5.time);
									s++;
								}
								else
								{
									PRINT_AVAILABLE_SLOTS ();
								}

								printf("RESERVATION ID : ");
								scanf("%d",&RESID);

								DOCTOR_RESERVATION (RESID);
								PRINT_AVAILABLE_SLOTS ();
								break;
							}
							case 4:
							{
								printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t--------------------------\n");
								printf("\t\t\t\t\t\t\t\t\t\t\t\t 4 - Cancel reservation \n");
								printf("\t\t\t\t\t\t\t\t\t\t\t\t--------------------------\n\n\n");

								CANCEL_RESERVATION ();
								break;
							}
							case 5:
							{
								printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t--------------------------\n");
								printf("\t\t\t\t\t\t\t\t\t\t\t\t 5 - Return to Home Page \n");
								printf("\t\t\t\t\t\t\t\t\t\t\t\t--------------------------\n\n\n");

								printf(" * Your ORDER are being executed .......  \n \t\tGOOD BYE  ! \n");
								printf("--------------------------------------------------\n\n\n\n");
								ExitFlag1=1;
								break;
							}

							}
						}
						else
						{
							printf("\nInvalid KEY  , Try Again ! \n");
							printf("----------------------------\n\n");
						}

					}

				}

				break;
			}
		}
		else if (MODE=='U')
		{
			while (1)
			{

				printf("\n-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
				printf("\t\t\t\t\t\t\t\t\t\t\t WELCOME IN USER MODE  \n");

				printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n\n");

						while (ExitFlag2 == 0)
						{
							printf("\n-----------------------------------------------------\n\n");
							printf("To View patient record PRESS  ------------> PRESS (1)\n\n");
							printf("To View today reservations    ------------> PRESS (2)\n\n");
							printf("To Return to Home Page PRESS  ------------> PRESS (3)\n\n");
							printf("-----------------------------------------------------\n\n\n\n");

							printf("Please press your Target key : ");
							scanf("%d",&KEY2);
							if (KEY2==1  ||  KEY2==2  || KEY2==3)
							{
								switch (KEY2)
								{
								case 1:
								{
									printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t--------------------------\n");
									printf("\t\t\t\t\t\t\t\t\t\t\t\t 1 - View patient record \n");
									printf("\t\t\t\t\t\t\t\t\t\t\t\t--------------------------\n\n\n");

									printf("--------------------------------------------------------------------------------------\n");
									printf(" * To View all the Patients records ------------> PRESS (a) { Abbreviation for (all)  } \n\n");
									printf(" * To View only one Patient record  ------------> PRESS (o) { Abbreviation for (only) }\n");
									printf("--------------------------------------------------------------------------------------\n\n");
									printf("Please enter Your Choice : ");
									u8 brk=0;
									while (brk==0)
									{
										scanf(" %c",&aORo);
										if (aORo=='o')
										{
											VIEW_PATIENT ();
											brk=1;
											break;
										}
										else if (aORo=='a')
										{
											PrintLinkedList();
											brk=1;
											break;
										}
										else 
										{
											printf("\n\nInvalid Choice ! , Try Again : ");

										}

									}
									break;

								}
								case 2:
								{
									printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t----------------------------\n");
									printf("\t\t\t\t\t\t\t\t\t\t\t\t 2 - View today reservations \n");
									printf("\t\t\t\t\t\t\t\t\t\t\t\t----------------------------\n\n\n");

									VIEW_RESERVATION ();
									break;
								}
								case 3:
								{
									printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t--------------------------\n");
									printf("\t\t\t\t\t\t\t\t\t\t\t\t 3 - Return to Home Page \n");
									printf("\t\t\t\t\t\t\t\t\t\t\t\t--------------------------\n\n\n");

									printf(" * Your ORDER are being executed .......  \n \t\tGOOD BYE  ! \n");
									printf("--------------------------------------------------\n\n\n\n");
									ExitFlag2=1;
									break;
								}
								}
							}
							else
							{
								printf("\nInvalid KEY  , Try Again ! \n");
								printf("----------------------------\n\n\n");
							}
						}
				break;
			}		
		}
		else
		{
			printf("\nInvalid KEY  , Try Again ! \n");
			printf("----------------------------\n\n\n");
		}

	}	

}

//									**** Main Function (END) ***										   
						/*--------------------------------------------------------------------------------*/



//**********************************************************************************************************


						/*--------------------------------------------------------------------------------*/
//								   **** Functions Implementation (START) ***										   




u8 CHOOSE_MODE(void)
{
	u8 mode;
	printf("\t\t\t\t\t\t\t\t\t\t    [ * Clinic Management System * ] \n");
	printf("\t\t\t\t\t\t\t\t\t\t   ----------------------------------\n\n\n\n\n");


	printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t WELCOME IN HOME PAGE \n\n\n");

	printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n\n");

	printf("\n\t\t\t\t\t\t\t\t-------------------------------------------------------------------------\n\n");
	printf("\n\t\t\t\t\t\t\t\t\t\t FOR ADMIN Mode      : PRESS the Letter 'A' \n");
	printf("\n\t\t\t\t\t\t\t\t\t\t FOR USER Mode       : PRESS the Letter 'U' \n");
	printf("\n\t\t\t\t\t\t\t\t\t\t FOR SHUT DOWN Mode  : PRESS the Letter 'S' \n\n");
	printf("\n\t\t\t\t\t\t\t\t-------------------------------------------------------------------------\n\n");

	printf("Please enter the Mode  ----->  ");
	scanf(" %c",&mode);	
	return mode;
}
//**********************************************************************************************************
u8 ADMIN_PASSWORD_LOGIN (void)
{
	u8 i=0,flag=0;
	u32 pass,key;

	printf("\nFOR LOGIN :- \n---------\n\n");
	printf("Please enter the Password  ----->  ");

	while (1)
	{
		scanf("%d",&pass);

		if (pass==1234)
		{
			printf("\nCorrect Password . \n");
			printf("-------------------\n");

			printf("\n\n-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
			printf("\t\t\t\t\t\t\t\t\t\t\t WELCOME IN ADMIN MODE  \n");

			printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n\n");

			break;
		}
		else if (i<2)
		{
			printf("Incorrect Password ! , Try again : ");
			i++;
		}
		else
		{
			printf("Password Incorrect for 3 consecutive times , SORRY NO MORE TRIES !\n\n");
			flag=1;
			break;
		}
	}
	return flag;

}
//**********************************************************************************************************
u8 ADD_PATIENT (u16 N_AME[],u8 A_GE,u8 G_ENDER[],u32 I_D)
{
	u8 i,count=1,count1=0,count2=0;

	if (ListLength == 0)
	{
		for (i=0;i<10;i++)
		{
			head.name[i]=N_AME[i] ;
			head.gender[i]=G_ENDER[i] ;
		}
		head.age=A_GE ;
		head.id=I_D ;
		head.flag=0;

		head.Next  = NULL;


	}


	else
	{
		pt_node *last;


		pt_node *new = (pt_node*) malloc(sizeof(pt_node));


		for (i=0;i<10;i++)
		{
			new->name[i]=N_AME[i] ;

			new->gender[i]=G_ENDER[i] ;
		}
		new->age=A_GE ;
		new->id=I_D ;
		new->flag=0 ;

		new -> Next  = NULL;

		last = &head;


		while( (last -> Next) != NULL )
		{
			if (last->id!=new->id)
			{
				last = (last -> Next);
			}
			else
			{
				count1=1;
				break;
			}
		}


		if (last->id!=new->id)
		{
			last -> Next = new;
		}
		else
		{	
			count2=1;	
		}

		if (count1==1 || count2==1)
		{
			printf("\n\nThe entered ID is unaccepted , It already exists ! \n");
			printf("-----------------------------------------------------\n\n\n");
			count=0;
		}


	}

	ListLength++;
	return count;

}
//**********************************************************************************************************
void EDIT_PATIENT (u32 edit_id)
{
	u8 f=0;
	pt_node *editlast;
	editlast = &head;
	while( editlast!= NULL )
	{
		if (editlast->id==edit_id)
		{
			f=1;
			printf("\n\n - NEW Name   : ");
			scanf("%s",editlast->name);
			printf(" - NEW Age    : ");
			scanf("%d",&editlast->age);
			printf(" - NEW Gender : ");
			scanf("%s",editlast->gender);

			printf("\nPatient is Edited successfully ,\nThank You !\n");
			printf("--------------------------------------------\n\n\n\n");

			break;
		}
		editlast = (editlast -> Next);	
	}
	if (f==0)
	{
		printf("\nThe ID does not exist ! \n");
		printf("------------------------\n\n\n");
	}

}
//**********************************************************************************************************
void PRINT_AVAILABLE_SLOTS (void)
{
	u8 num=1,f=0;
	res_slot *PTR=&slot1;
	printf("The Available SLOTS :-\n");
	printf("-------------------\n\n");
	while (PTR!= NULL)
	{
		if (PTR->reserve_id==0)
		{
			printf("SLOT %d : %s \n",num,PTR->time);
			f++;
		}
		PTR=PTR->reserve_Next;
		num++;
	}
	if (f==0)
	{
		printf("\nSORRY : ALL the SLOTS are RESERVED , There is no available SLOT ! \n\n");

	}
	printf("--------------------------------------------------------------------\n\n\n");


}
//**********************************************************************************************************
void DOCTOR_RESERVATION (u32 R_ESID)
{	
	u8 num=1,i,Time[15],FLAG3=0,j=1;

	res_slot *ptr1 =(res_slot*) malloc(sizeof(res_slot));
	ptr1=&slot1;
	res_slot *ptr2 =(res_slot*) malloc(sizeof(res_slot));
	ptr2=&slot2;
	res_slot *ptr3 =(res_slot*) malloc(sizeof(res_slot));
	ptr3=&slot3;
	res_slot *ptr4 =(res_slot*) malloc(sizeof(res_slot));
	ptr4=&slot4;
	res_slot *ptr5 =(res_slot*) malloc(sizeof(res_slot));
	ptr5=&slot5;

	ptr1->reserve_Next=ptr2;
	ptr2->reserve_Next=ptr3;
	ptr3->reserve_Next=ptr4;
	ptr4->reserve_Next=ptr5;
	ptr5->reserve_Next=NULL;

	pt_node *PTR=&head;

	while (PTR!=NULL)
	{
		if (PTR->id==R_ESID && R_ESID!=0)
		{
			printf("\nThe ID exists For : \n");
			printf("------------------\n\n");
			printf("Patient Number %d :-\n\n", j);
			printf(" - Name : %s \n",PTR -> name);
			printf(" - ID   : %d \n\n",PTR -> id);

			if (PTR->flag==0)
			{
				printf("* NOW , %s is Ready to Reserve a SLOT :- \n",PTR -> name);
				printf("------------------------------------------\n\n\n");

				FLAG3=1;
				ListLength2++;
				break;
			}
			else
			{
				printf("* BUT , %s has already Reserved a SLOT !! \n",PTR -> name);
				printf("------------------------------------------\n\n\n");

				FLAG3=2;
				break;
			}


		}
		j++;
		PTR=PTR->Next;

	}

	if (FLAG3==1)
	{	

		while (1)
		{
			printf("RESERVATION SLOT : ");
			scanf("%s",Time);

			if ((ptr1->time[0]==Time[0]) && (ptr1->time[1]==Time[1]))
			{
				ptr1->reserve_id=R_ESID;
				PTR->flag=1;
				printf("\nSLOT 1 is Reserved successfully ,\nThank You ! \n");
				printf("------------------------------------\n\n\n");break;
			}
			else if ((ptr2->time[0]==Time[0]) && (ptr2->time[1]==Time[1]))
			{
				ptr2->reserve_id=R_ESID;
				PTR->flag=1;
				printf("\nSLOT 2 is Reserved successfully ,\nThank You ! \n");
				printf("------------------------------------\n\n\n");break;
			}
			else if ((ptr3->time[0]==Time[0]) && (ptr3->time[1]==Time[1]))
			{
				ptr3->reserve_id=R_ESID;
				PTR->flag=1;
				printf("\nSLOT 3 is Reserved successfully ,\nThank You ! \n");
				printf("------------------------------------\n\n\n");break;
			}
			else if ((ptr4->time[0]==Time[0]) && (ptr4->time[1]==Time[1]))
			{
				ptr4->reserve_id=R_ESID;
				PTR->flag=1;
				printf("\nSLOT 4 is Reserved successfully ,\nThank You ! \n");
				printf("------------------------------------\n\n\n");break;
			}
			else if ((ptr5->time[0]==Time[0]) && (ptr5->time[1]==Time[1]))
			{
				ptr5->reserve_id=R_ESID;
				PTR->flag=1;
				printf("\nSLOT 5 is Reserved successfully ,\nThank You ! \n");
				printf("------------------------------------\n\n\n");break;
			}
			else
			{
				printf("\nInvalid SLOT time , Try Again ! \n");
				printf("---------------------------------\n\n\n");


			}
		}
	}
	else if (FLAG3==0)
	{
		printf("\nThe ID does not exist ! \n");
		printf("------------------------\n\n\n");

	}
}
//**********************************************************************************************************
void CANCEL_RESERVATION (void)
{
	if (ListLength2>0)
	{
		u8 num=1,yes=0;
		u32 canResID;
		res_slot *PTR=&slot1;
		pt_node *PTR2=&head;

		printf("RESERVATION ID : ");
		scanf("%d",&canResID);
		while (PTR2 != NULL)
		{
			if (PTR2->id==canResID)
			{
				PTR2->flag=0;
				break;
			}
			PTR2=PTR2->Next;
		}

		while (PTR != NULL)
		{
			if (PTR->reserve_id==canResID)
			{
				PTR->reserve_id=0;
				printf("\nRESERVATION of SLOT %d is Cancelled successfully ,\nThank You ! \n",num);
				printf("-------------------------------------------------\n\n\n");
				yes=1;
				break;
			}
			PTR=PTR->reserve_Next;
			num++;
		}
		if (yes==1)
		{
			PRINT_AVAILABLE_SLOTS ();
		}
		else
		{
			printf("\nThere is no Reservation with this ID ! \n");
			printf("---------------------------------------\n\n\n");

		}

	}
	else
	{
		printf("THERE is no Initial RESERVATIONS\nYou must reserve for at least one Patient to a certain SLOT to be able to CANCEL A RESERVATION !! \n");
		printf("-----------------------------------------------------------------------------------------------------------------------------------\n\n\n");

	}
}
//**********************************************************************************************************
void VIEW_PATIENT (void)
{
	u8 i=1,f=0;
	u32 userID;
	pt_node*Last = NULL;
	Last=&head;
	if (ListLength > 0)
	{
		printf("\n\nUSER ID : ");
		scanf("%d",&userID);

		while (Last!= NULL)
		{
			if (Last->id==userID)
			{
				printf("\n\n------------------------------------------\n");
				printf("\n\n* Patient Number %d :-\n", i);
				printf(" ------------------\n\n");
				printf(" - Name   : %s \n",Last -> name);
				printf(" - Age    : %d \n",Last -> age);
				printf(" - Gender : %s \n",Last -> gender);
				printf(" - ID     : %d \n\n",Last -> id);
				printf("------------------------------------------\n\n\n");
				f=1;
				break;
			}
			i++;
			Last = Last -> Next;

		}

		if (f==0)
		{
			printf("\nThe ID does not exist ! \n");
			printf("------------------------\n\n\n");
		}
	}



	else
	{
		printf("\nEmpty Patient Records ! \n");
		printf("------------------------\n\n\n");
	}


}
//**********************************************************************************************************
void VIEW_RESERVATION (void)
{
	u8 num=1,check=0;
	res_slot *PTR=&slot1;
	printf("\nTODAY RESERVATIONS :- \n");
	printf("-------------------\n\n\n");

	while (PTR!= NULL)
	{
		if (PTR->reserve_id!=0)
		{
			printf("--------------------------------------\n");
			printf(" * Patient ID       : %d \n",PTR->reserve_id);
			printf(" * Reserved SLOT %d  : %s \n",num,PTR->time);
			printf("--------------------------------------\n\n");
			check=1;
		}
		PTR=PTR->reserve_Next;
		num++;

	}
	if (check==0)
	{
		printf("THERE is not any RESERVATIONS ! \n");
		printf("--------------------------------\n");
	}
	printf("\n\n");


}
//**********************************************************************************************************	
void PrintLinkedList(void)
{
	if (ListLength > 0)
	{
		pt_node*Last = NULL;
		Last=&head;
		u32 i = 1;

		while (Last!= NULL)
		{

			printf("\n------------------------------------------\n");
			printf("* Patient Number %d :- \n", i);
			printf(" ------------------\n\n");
			printf(" - Name   : %s \n",Last -> name);
			printf(" - Age    : %d \n",Last -> age);
			printf(" - Gender : %s \n",Last -> gender);
			printf(" - ID     : %d \n",Last -> id);
			printf("------------------------------------------\n");

			i++;
			Last = Last -> Next;
		}
		printf("\n\n");
	}

	else
	{
		printf("\nEmpty Patient Records ! \n");
		printf("------------------------\n\n\n");
	}

}

//								 **** Functions Implementation (END) ***										   
					/*--------------------------------------------------------------------------------*/



//**********************************************************************************************************
