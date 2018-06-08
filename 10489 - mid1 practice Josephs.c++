#include <stdio.h>
#include <stdlib.h>

#define N 100000
typedef struct man {
    int id;
    struct man* next;
} man;
char prime[N];
void check(void);
int main(void)
{

//    freopen("test.txt","r",stdin);
    int n, m, i, j, remain;
    man *head, *curr, *tmp;


check();

    while(scanf("%d",&n)==1){

    /* using circular linked list*/
    head = (man*)malloc(sizeof(man));
    curr = head;
    curr->id = 1;
    for(i=2; i<=n; i++){
        curr->next = (man*)malloc(sizeof(man));
        curr = curr->next;
        curr->id = i;
    }
    curr->next = head;
    curr = head;
    remain = n;
    j=0;
    while(remain>1){

             while(prime[j]!=1&&j<N)
            {
                j++;
            }
            if(j>remain)
                m=j%remain;
            else
                m=j;




        for(i=1;i<m;i++){
            tmp = curr;
            curr = curr->next;
        }
        tmp->next = curr->next;
        free(curr);
        curr = tmp->next;
        remain --;
        prime[j]=0;
    }

    printf("%d\n",curr->id);
     free(curr);
     check();
    }

    return 0;
}
void check(void)
    {
        long long i,j;
        for (i=0; i<N; i++)
        prime[i] = 1;

    prime[0] = 0;
    prime[1] = 0;

   for ( i=2; i<N; i++)
        if (prime[i])
            // 刪掉質數i的倍數，從兩倍開始。保留原本質數。
            for ( j=i*i; j<N; j+=i)
                prime[j] = 0;
    }

/*192.168.136.1*//*CSY103062316*/
