#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Node.h"
#include "Queue.h"

int main(int argc , char **argv) {
    NodePtr headPtr=NULL;
    NodePtr tailPtr=NULL;
    
    Queue q;
    q.headPtr=NULL;
    q.tailPtr=NULL;
    q.size=0;

    int i, order, customer_no = 1;
    int price, cash;

    for(i=1; i<argc; i++){
        if(strcmp(argv[i],"x")==0){
            // กรณีลูกค้าจ่ายเงิน (Dequeue)
            if(q.size > 0){
                order = dequeue_struct(&q);
                
                printf("My order is %d\n", order);
                printf("Customer no: %d\n", customer_no++);
                
                switch(order) {
                    case 1:
                        printf("Ramen\n");
                        price = 200;
                        break;
                    case 2:
                        printf("Somtum\n");
                        price = 20;
                        break;
                    case 3:
                        printf("Fried Chicken\n");
                        price = 100;
                        break;
                    default:
                        printf("No Menu\n");
                        price = 0;
                        break;
                }

                if(price > 0) {
                    printf("You have to pay %d\n", price);
                    
                    int total_paid = 0;
                    do {
                        printf(":Cash:");
                        scanf("%d", &cash);
                        total_paid += cash;
                        
                        if(total_paid < price) {
                        }
                    } while(total_paid < price);

                    printf("Thank you\n");
                    if(total_paid > price) {
                        printf("Change is:%d\n", total_paid - price);
                    }
                }
                printf("===============================\n");

            } else {
                printf("The queue is empty\n");
            }
        }
        else {
            enqueue_struct(&q, atoi(argv[i]));
        }
    }

    printf("There are %d ppl left in the queue\n", q.size);

    printf("Clearing queue...\n");
    while(q.size > 0){
        dequeue_struct(&q);
    }

    return 0;
}