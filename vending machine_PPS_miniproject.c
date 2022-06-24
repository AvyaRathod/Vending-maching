#include<stdio.h>

void ShowMenu(void){
	printf("---------------------- \n");
    printf("MENU: ");
    printf("\n\n");
    printf("1. Water");   	  			printf("\t\t\t1.00 TL\n");
    printf("2. Coke");        			printf("\t\t\t\t1.20 TL\n");
    printf("3. Diet Coke");   			printf("\t\t\t1.20 TL\n");
    printf("4. Iced Tea");    			printf("\t\t\t1.00 TL\n");
    printf("5. Swiss Chocolate");		printf("\t\t1.50 TL\n");
    printf("6. Candy");					printf("\t\t\t0.95 TL\n");
    printf("7. Chips");					printf("\t\t\t2.50 TL\n");
    printf("8. Bubble Gum");			printf("\t\t\t1.50 TL\n");
    printf("9. Turkish Delight");		printf("\t\t2.00 TL\n");
    printf("\n\n");
 
 
}
int DisplayErrorMessage(float price,float deposit,int selection,int amount[]){
	int err;
	
	if(amount[selection]<-1){
		printf("Error! Insufficient amount of selected item! Take your money back!\n");
		return 0;
}

	else if(selection>9 || selection==0 || selection<-1){
		printf("Error! Invalid selection! \n");
		return 0;
	}
	else if(deposit<price){
		
		printf("Error! Insufficient amount of money! Take your money back!\n");
		return 0;
		}
	else 
		return 1;}

void MakeSelection(int *selection,float *deposit,int amount[],float *income,float *price){

	int err=0,select;
	float depo;
    printf("Enter amount of money: ");
    scanf("%f",deposit);
    printf("Select an item: ");
    scanf("%d",selection);
switch(*selection){
	case 1:*price=1.00;break;
	case 2:*price=1.20;break;
	case 3:*price=1.20;break;
	case 4:*price=1.00;break;
	case 5:*price=1.50;break;
	case 6:*price=0.95;break;
	case 7:*price=2.50;break;
	case 8:*price=1.50;break;
	case 9:*price=2.00;break;
	}
	
	select=*selection;
	depo=*deposit;
while(err==0){ /*it prevents errors to change income and deposit*/
	err=DisplayErrorMessage(*price,depo,select,amount);
	if(err==0){
		printf("Enter amount of money: ");
    	scanf("%f",&depo);
    	printf("Select an item: ");
    	scanf("%d",&select);
	}
}
	*deposit=depo;
	*selection=select;
switch(*selection)
{
    case 1:
		*deposit=*deposit-1.00;amount[0]=amount[0]-1;*income=*income+1.00;break;
   	case 2:
		*deposit=*deposit-1.20;amount[1]=amount[1]-1;*income=*income+1.20;break;
   	case 3:      
   		*deposit=*deposit-1.20;amount[2]=amount[2]-1;*income=*income+1.20;break;
   	case 4:
		*deposit=*deposit-1.00;amount[3]=amount[3]-1;*income=*income+1.00;break;
   	case 5:
    	*deposit=*deposit-1.50;amount[4]=amount[4]-1;*income=*income+1.50;break;
    case 6:
   		*deposit=*deposit-0.95;amount[5]=amount[5]-1;*income=*income+0.95;break;
	case 7:
		*deposit=*deposit-2.50;amount[6]=amount[6]-1;*income=*income+2.50;break;
	case 8:
		*deposit=*deposit-1.50;amount[7]=amount[7]-1;*income=*income+1.50;break;
	case 9:
		*deposit=*deposit-2.00;amount[8]=amount[8]-1;*income=*income+2.00;break;	
}
	
}
	



void ReturnChange(float deposit,int coins[]){
	
	float x,temp;
	temp=deposit;
	printf("Get your item! Change: %.2f TL\n",temp);
	for(;temp>=0.0;temp=temp-x)
		
		if(temp>=1.0 && coins[0]>0){
			x=1.0;
			coins[0]=coins[0]-1;
	}
		else if(temp>=0.5 && coins[1]>0){
			x=0.5;
			coins[1]=coins[1]-1;
		}
		else if(temp>=0.20 && coins[2]>0){
			x=0.20;
			coins[2]=coins[2]-1;			
		}
		else if(temp>=0.10 && coins[3]>0){
			x=0.10;
			coins[3]=coins[3]-1;
		}
		else if(temp>=0.05 && coins[4]>0){
			x=0.05;
			coins[4]=coins[4]-1;			
		}
}

void Maintance(int amount[],int coins[],float income){
	int pin;
	printf("Enter pin code: ");
	scanf("%d",&pin);
	if(pin==1234){
		printf("\nDAILY REPORT\nNumber of items left:\n1. Water:%d\n2. Coke:%d\n3. Diet Coke:%d\n4. Iced Tea:%d\n5. Swiss Chocolate:%d\n6. Candy:%d\n7. Chips:%d\n8. Bubble Gum:%d\n9. Turkish Delight:%d\n",amount[0],amount[1],amount[2],amount[3],amount[4],amount[5],amount[6],amount[7],amount[8]);
		printf("\nNumber of coins left:");
		printf("\n1 TL: %d left \n0.5 TL: %d left \n0.20 TL: %d left \n0.10 TL: %d left \n0.05 TL: %d left",coins[0],coins[1],coins[2],coins[3],coins[4]);
		printf("\nNet income: %.2f TL",income);
		printf("\nAll items in the vending machine are restocked");	}
	else
		printf("Wrong pin code!");
}


		
			
int main(){
	int selection=10,amount[9]={10,10,10,10,10,10,10,10,10},coins[5]={10,10,10,10,10}; /*amounts stars from water to delight - coins starts from 1 tl to 0.05 tl*/
	float deposit,income,price;
	
	ShowMenu();
	while(selection!=-1){ /*it keeps repeats until user selects selection as -1 which is maintance*/
	MakeSelection(&selection,&deposit,amount,&income,&price);
	
	if(selection!=-1)
		ReturnChange(deposit,coins);
}
	Maintance(amount,coins,income);
	
	
	
	return 0;
}