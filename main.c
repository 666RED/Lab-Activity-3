#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define NumberOfVehicle 10

typedef struct vehicle{
    char platNumber[8];
    double parkingDuration;
}vehicle;

typedef struct node{
    vehicle data;
    struct node *nextptr;
}node;

vehicle car;
node *head=NULL;

void input();
void output();
node* getNewNode(vehicle);

int main(){
    input();
    output();
}

void input(){
    for(int i = 0; i < NumberOfVehicle; i++){
        printf("\n%d) Enter vehicle plate number : ", i + 1);
        scanf("%s", &car.platNumber);
        do{
            printf("Enter parking duration (hours): ");
            scanf("%lf", &car.parkingDuration);
            if(car.parkingDuration <= 0){
                printf("The parking duration should not less than or equal to 0.\n");
            }
        }while(car.parkingDuration <= 0);
        fflush(stdin);
        node* temp1 = getNewNode(car);
        if(head == NULL){
            head = temp1;
        }else{
            node*temp2 = head;
            while(temp2->nextptr != NULL){
                temp2 = temp2->nextptr;
            }
            temp2->nextptr = temp1;
        }
    }
}

void output(){
    node* temp = head;
    int i = 1;
    printf("\n\nOUTPUT:\n\n");
    while(temp != NULL){
        printf("\n%d) Vehicle plate number : %s", i, temp->data.platNumber );
        printf("\nParking duration (hours): %.2lf (%.2lf)", temp->data.parkingDuration, ceil(temp->data.parkingDuration));
        printf("\nTotal parking charges (RM) : %.2lf\n", ceil(temp->data.parkingDuration) * 6);
        temp = temp->nextptr;
        i++;
    }
}

node* getNewNode(vehicle car){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = car;
    temp->nextptr = NULL;
    return temp;
}
