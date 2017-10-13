#include<stdio.h>
#include<time.h>
#include<unistd.h>
#define n 4

int completed = 0,i;

struct fork{
    int taken;
}ForkAvil[n];

struct philosopher{
    int left;
    int right;
}status[n];

void eat(int id){
    if(status[id].left==10 && status[id].right==10)
        printf("Philosopher %d completed his dinner\n",id+1);

    else if(status[id].left==1 && status[id].right==1){

            printf("Philosopher %d completed his dinner\n",id+1);

            status[id].left = status[id].right = 10;
            int otherFork = id-1;

            if(otherFork== -1)
                otherFork=(n-1);

            ForkAvil[id].taken = ForkAvil[otherFork].taken = 0;
            printf("Philosopher %d released fork %d and fork %d\n",id+1,id+1,otherFork+1);
            completed++;
        }
        else if(status[id].left==1 && status[id].right==0){
                if(id==(n-1)){
                    if(ForkAvil[id].taken==0){
                        ForkAvil[id].taken = status[id].right = 1;
                        printf("Fork %d taken by philosopher %d\n",id+1,id+1);
                    }
                    else{
                        printf("Philosopher %d is waiting for fork %d\n",id+1,id+1);
                    }
                }
                else{
                    int cpy = id;
                    id-=1;

                    if(id== -1)
                        id=n-1;

                    if(ForkAvil[id].taken == 0){
                        ForkAvil[id].taken = status[cpy].right = 1;
                        printf("Fork %d taken by Philosopher %d\n",id+1,cpy+1);
                    }
                    else{
                        printf("Philosopher %d is waiting for Fork %d\n",cpy+1,id+1);
                    }
                }
            }
            else if(status[id].left==0){
                    if(id==(n-1)){
                        if(ForkAvil[id-1].taken==0){
                            ForkAvil[id-1].taken = status[id].left = 1;
                            printf("Fork %d taken by philosopher %d\n",id,id+1);
                        }
                        else{
                            printf("Philosopher %d is waiting for fork %d\n",id+1,id);
                        }
                    }
                    else{
                        if(ForkAvil[id].taken == 0){
                            ForkAvil[id].taken = status[id].left = 1;
                            printf("Fork %d taken by Philosopher %d\n",id+1,id+1);
                        }
                        else{
                            printf("Philosopher %d is waiting for Fork %d\n",id+1,id+1);
                        }
                    }
        }
}

void main(){
    for(i=0;i<n;i++)
        ForkAvil[i].taken=status[i].left=status[i].right=0;

    while(completed<n){
        //sleep(500);

        for(i=0;i<n;i++)
            eat(i);
        printf("\nPhilosophers who have completed dinner : %d\n",completed);
    }

}
