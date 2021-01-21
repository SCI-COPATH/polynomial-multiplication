#include <stdio.h>
#include <stdlib.h>
struct term
{
    int coef;
    int exp;
    struct term* link;
};
void polynomialRead(struct term **head){
    int num;
    struct term *newNode,*ptr;
    printf("Enter How number of terms : ");
    scanf("%d",&num);
    while(num--){
        newNode=(struct term *)malloc(sizeof(struct term));
        newNode->link=NULL;
        printf("Enter the co-eficent : ");
        scanf("%d",&newNode->coef);
        printf("Enter the exponent : " );
        scanf("%d",&newNode->exp);
        if(*head==NULL){
            *head=newNode;
            ptr=*head;
        }
        else{
            ptr->link=newNode;
            ptr=ptr->link;
        }
    }
}
void polynomialPrint(struct term *head){
    if(head==NULL){
        return ;
    }
    while (head!=NULL){
        printf("%dx^%d ",head->coef,head->exp);
        if(head->link!=NULL)
            printf(" +");
        head=head->link;
    }   
    printf("\n");
}
void polyMul(struct term *polynomial1,struct term *polynomial2,struct term **product){
    struct term *newNode,*poly1=polynomial1,*poly2=polynomial2,*ptr=*product;
    while(poly1!=NULL){
        for(poly2=polynomial2;poly2!=NULL;poly2=poly2->link){
            newNode=(struct term *)malloc(sizeof(struct term));
            newNode->link=NULL;
            if(*product==NULL)
                *product =newNode;
            newNode->exp=poly1->exp+poly2->exp;
            newNode->coef=poly1->coef*poly2->coef;
            for(ptr=*product;ptr!=NULL;ptr=ptr->link){
                if(ptr->exp==newNode->exp){
                    ptr->coef=ptr->coef+newNode->coef;
                    break;
                }
                else if(ptr->link==NULL&&ptr->exp!=newNode->exp){
                    ptr->link=newNode;
                    break;
                }
            }
        }
        poly1=poly1->link;
    }
    

}
void main(){
    struct term *poly1=NULL,*poly2=NULL,*product=NULL;
    printf("Enter the details of polynomial one \n");
    polynomialRead(&poly1);
    printf("Enter the details of polynomial Two \n");
    polynomialRead(&poly2);
    polynomialPrint(poly1);
    polynomialPrint(poly2);
    polyMul(poly1,poly2,&product);
    printf("Result is \n");
    polynomialPrint(product);
}