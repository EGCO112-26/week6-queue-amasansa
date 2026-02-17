#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Node.h"
#include "Queue.h"

int main(int argc , char **argv) {
    Queue q;
    q.headPtr = NULL;
    q.tailPtr = NULL;
    q.size = 0;

    int i, order, customer_no = 1;
    int price, cash;

    for(i = 1; i < argc; i++){
        if(strcmp(argv[i], "x") == 0){
            if(q.size > 0){
                order = dequeue_struct(&q);
                
                printf("My order is %d\n", order);
                
                printf("Cutomer no: %d\n", customer_no++); 
                
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
                    
                    while(1) {
                        printf(":Cash:");
                        
                        if(scanf("%d", &cash) != 1) break;
                        
                        if(cash >= price) {
                            printf("Thank you\n");
                            if(cash > price) {
                                printf("Change is:%d\n", cash - price); 
                            }
                            break;
                        } else {
                        }
                    }
                }
                

            } else {
                printf("The queue is empty\n");
            }
        }
        else {
            enqueue_struct(&q, atoi(argv[i]));
        }
    }
    printf("===============================\n");

    printf("There are %d ppl left in the queue\n", q.size);

    printf("Clearing queue...\n");
    while(q.size > 0){
        dequeue_struct(&q);
    }

    return 0;
}