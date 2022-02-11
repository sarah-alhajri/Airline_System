#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

    enum F{fseat=1,Meal_price1=300, Luggage1=100, Ticket_price1=1000};
    enum B{bseat=11,Meal_price2=200, Luggage2=150, Ticket_price2=500};
    enum E{eseat=31,Meal_price3=50, Luggage3=200, Ticket_price3=200};



     struct PassengerInfo {
        char f_name[6];
        char l_name[6];
        int s_no;
        char meal;
        int add_lug;};
        typedef struct PassengerInfo p;

    struct Flight {
    int Id;
    char destination[5];
    p *pas[3];// f,b,e
    int noF,noB,noE;// to set seatNo
    int Counter;
};
void printFlight(struct Flight* , int );
//////////////
int main() {
struct Flight array[3];
//int d;
for (int i = 0; i < 3; i++) {
    array[i].Counter=0;
    array[i].noF = 0 ;
    array[i].noB = 0 ;
    array[i].noE = 0 ;
    array[i].pas[0] = (p*) malloc( 10 * sizeof(p*) );
    array[i].pas[1] = (p*) malloc( 20 * sizeof(p*) );
    array[i].pas[2] = (p*) malloc( 120 *sizeof(p*) );

    printf("Enter flight #%d id: \n", i+1);
    scanf("%d",  &array[i].Id);

    printf("Enter flight destination\n" );
    scanf(" %s", &array[i].destination);
    int nump;
    printf("How many passengers?\n" );
    scanf("%d", &nump);
    while(nump>150){
    printf("The system can store the names of at most 150 passengers for each flight\n");
    printf("How many passengers ? ");
    scanf("%d" , &nump);
    }
    array[i].Counter+=nump;

// start read passenger information
    for (int j=0; j< nump; j++) {
        p pa;
        char class;
printf("Enter passenger #%d class:\n", j+1);
scanf(" %c", &class );

printf("Enter passenger first name:\n");
scanf("%s",pa.f_name );

printf("Enter passenger last name:\n");
scanf("%s",pa.l_name );

printf("With meal [Y/N]?\n");
scanf(" %c",&pa.meal );


printf("Enter number of additional luggage(s)?\n");
scanf("%d",&pa.add_lug );

    switch (class) {
        case 'F':
        case 'f':
        pa.s_no = (array[i].noF + fseat );//set number of seat
        array[i].pas[0][array[i].noF]=pa ;//put p in pas list
        array[i].noF++;
        break;

        case 'B':
        case 'b':
        pa.s_no = (array[i].noB + bseat );//set number of seat
        array[i].pas[1][array[i].noB]=pa; //put p in pas list
        array[i].noB++;
        break;

        case 'E':
        case 'e':
        pa.s_no = (array[i].noE + eseat );//set number of seat
        array[i].pas[2][array[i].noE]=pa; //put p in pas list
        array[i].noE++;
        break;
    }//end switch

}// end j for loop
}//end i for loop
int id ;
printf("Enter the id of the flight you would like to view its passengers' info: " );
scanf("%d" , &id);

printFlight( array ,id ) ;
//free dynamic location
for (int i = 0; i < 3; i++) {
    free(array[i].pas[0]);
    free(array[i].pas[1]);
    free(array[i].pas[2]);
}
return 0;
}// end int main

void printFlight(struct Flight* array , int id ){

    int index;
    for (int i = 0; i < 3; i++){
    if(array[i].Id==id){
    index=i;
    break;}
    else{
        if(i==3){
        printf("No flight with the specified id\n");
        return;}}}

if(array[index].Counter==0){
    printf("The flight has no registered passengers\n");
return;}


if(!(array[index].noF==0))
printf("Number of first class passengers %d :\n",array[index].noF );

for (int j = 0; j < array[index].noF; j++) {// First class
if(tolower(array[index].pas[0][j].f_name[0])=='s'){
char* isMeal=((tolower(array[index].pas[0][j].meal))=='y'? ", order meal":"");
int lug=array[index].pas[0][j].add_lug;
int f=strcmp(isMeal,"");
int mealp= (f==0? 0: Meal_price1);

printf("%s %s set on seat ",array[index].pas[0][j].f_name,array[index].pas[0][j].l_name);
printf("no. %d  %s  ",array[index].pas[0][j].s_no, ((tolower(array[index].pas[0][j].meal))=='y'? ", order meal":""));
if(lug!=0)
printf(", with %d additional luggage,total ticket price is:%d\n",array[index].pas[0][j].add_lug,(lug*Luggage1)+(Ticket_price1)+(mealp) );
else
printf(",total ticket price is:%d\n",(lug*Luggage1)+(Ticket_price1)+(mealp) );

}
}

if(!(array[index].noB==0))
printf("Number of Business class passengers %d :\n",array[index].noB );
for (int j = 0; j < array[index].noB; j++) {// Business class
if(tolower(array[index].pas[1][j].f_name[0])=='s'){
char* isMeal=((tolower(array[index].pas[1][j].meal))=='y'? ", order meal":"");
int lug=array[index].pas[1][j].add_lug;
int f=strcmp(isMeal,"");
int mealp= (f==0? 0: Meal_price2);

printf("%s %s set on seat ",array[index].pas[1][j].f_name,array[index].pas[1][j].l_name);
printf("no. %d  %s  ",array[index].pas[1][j].s_no, ((tolower(array[index].pas[1][j].meal))=='y'? ", order meal":""));
if(lug!=0)
printf(", with %d additional luggage,total ticket price is:%d\n",array[index].pas[1][j].add_lug,(lug*Luggage2)+(Ticket_price2)+(mealp) );
else
printf(" ,total ticket price is:%d\n",(lug*Luggage2)+(Ticket_price2)+(mealp) );

}}

    if(!(array[index].noE==0))
    printf("Number of Economic class passengers %d :\n",array[index].noE );
    for (int j = 0; j < array[index].noE; j++) {// Economic class

    if(tolower(array[index].pas[2][j].f_name[0])=='s'){

    char* isMeal=((tolower(array[index].pas[2][j].meal))=='y'? ", order meal":"");
    int lug=array[index].pas[2][j].add_lug;
    int f=strcmp(isMeal,"");
    int mealp= (f==0? 0: Meal_price3);

    printf("%s %s set on seat ",array[index].pas[2][j].f_name,array[index].pas[2][j].l_name);
    printf("no. %d  %s  ",array[index].pas[2][j].s_no, ((tolower(array[index].pas[2][j].meal))=='y'?  ", order meal":""));
    if(lug!=0)
    printf(", with %d additional luggage,total ticket price is:%d\n",array[index].pas[2][j].add_lug,(lug*Luggage3)+(Ticket_price3)+(mealp) );
    else
    printf(",total ticket price is:%d\n",(lug*Luggage3)+(Ticket_price3)+(mealp) );}}



}// method end
