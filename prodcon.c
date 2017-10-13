#include<stdio.h>

int mutex=1,full=0,empty=3,x=0;

int wait(int sem){
    sem-=1;
    return sem;
}

int signal(int sem){
    sem+=1;
    return sem;
}

void producer(){
    mutex=wait(mutex);
    full=signal(full);
    empty=wait(empty);
    x++;
    printf("\nProducer produces the item %d",x);
    mutex=signal(mutex);
}

void consumer(){
    mutex=wait(mutex);
    full=wait(full);
    empty=signal(empty);
    printf("\nConsumer consumes item %d",x);
    x--;
    mutex=signal(mutex);
}

void main(){
    int ch;

    printf("\n1.Producer\n2.Consumer\n3.Exit");
    do{
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            if((mutex==1)&&(empty!=0))
                producer();
            else
                printf("Buffer is full.");
            break;

            case 2:
            if((mutex==1)&&(full!=0))
                consumer();
            else
                printf("Buffer is empty.");
            break;

            case 3:
            break;

            default:
            printf("Wrong Choice.");
        }
    }while(ch!=3);
}
