#include <stdio.h>
#include <string.h>
#include <math.h>

struct data{
 char NAME[10];
 int eat;
 int total_eaten;
};

struct compare{
 char TEAMMATE1[20];
 char TEAMMATE2[20];
 int amount_two;
};

int main(){
int N, MIN, o;
char TEAMMATE1[10], TEAMMATE2[10], TEAMMATE3[10], TEAMMATE4[10];
int mark1 = 0, mark2 = 0;

scanf("%d %d", &N, &MIN);
struct data p[N];
 for(int i = 0; i < N; i++)
    {
    scanf("%s", p[i].NAME);
    scanf("%d", &p[i].eat);
    p[i].total_eaten = p[i].eat * MIN;
    }
o = N / 2;
struct compare q[o];
for(int i =0; i < o; i++){
 scanf("%s", q[i].TEAMMATE1);
 scanf("%s", q[i].TEAMMATE2);
 q[i].amount_two = 0;
 }
for(int i = 0; i < N; i++){
   for(int j = 0; j < o; j++){
    if((strcmp(p[i].NAME,q[j].TEAMMATE1)== 0) || (strcmp(p[i].NAME, q[j].TEAMMATE2)== 0)){
        q[j].amount_two = q[j].amount_two + p[i].total_eaten;
    }
   }
}
char v_TEAMMATE1[10], v_TEAMMATE2[10];
int v_amount_two;
for(int i = 0; i < o; i++){
    for(int j = 0; j < o; j++){
        strcpy(v_TEAMMATE1, q[i].TEAMMATE1);
        strcpy(v_TEAMMATE2, q[i].TEAMMATE2);
        v_amount_two = q[i].amount_two;
        if(q[i].amount_two > q[j].amount_two){
            strcpy(q[i].TEAMMATE1,q[j].TEAMMATE1);
            strcpy(q[j].TEAMMATE1,v_TEAMMATE1);
            strcpy(q[i].TEAMMATE2,q[j].TEAMMATE2);
            strcpy(q[j].TEAMMATE2,v_TEAMMATE2);
            q[i].amount_two = q[j].amount_two;
            q[j].amount_two = v_amount_two;
        }
    }
}
printf("%s & %s Win! \n", q[0].TEAMMATE1,q[0].TEAMMATE2);
printf("Total Eaten: %d \n", q[0].amount_two);
return 0;
}
