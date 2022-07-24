#include <stdio.h>
#include<unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include<math.h>


int board[36][36];

void * check_r(void* i,void* j,void* k,void *n);


void * check_c(void * i,void* j,void* k,void *n);


void * check_s(void * i,void* j,void* k, void *n);

pthread_t thread_rows, thread_cols, thread_1, thread2, thread3, thread4, thread5, thread6, thread7, thread8, thread9;


 void readPuzzle(char *fname , int n) {
	
	ifstream fin(fname);
	if (!fin) {
        errorExit("Could not open the file for reading.");
    }
	
	for (int row=0; row<n; row++) {
		for (int column=0; column<n; column++) {
			fin >> board[row][column];
		}
	}
	fin.close();
}
int solve(int **board, int n)
{
	int i,j,k;
	for(i=0;i<n;i++)
    {
    	for(j=0;j<n;j++)
    	{	
    		if(board[i][j]==0)
    		{
    			for(k=1;k<=n;k++)
    			{
    				
if((pthread_create(&thread_rows, NULL,check_r ,(void*) i,(void *)j,(void*)k, (void*)n))
  &&
  (pthread_create(&thread_cols,NULL, check_c ,(void*) i,(void *)j,(void*)k, (void*)n))&&
  
(pthread_create(&thread_1,NULL, check_c ,(void*) i,(void *)j,(void*)k, (void*)n)))
    				{
    					board[i][j]=k;
    					if(solve(board,n))
    					return 1;
    					else
    					board[i][j]=0;
    					
    				}
    			}
    			return 0;
    			
    		}
    		
    	}
    }
return 1;
}
pthread_join(thread_rows);
pthread_join(thread_cols);
pthread_join(thread1);

    

int main(int argc, char *argv[])
{
    int n,i,k,j;
    scanf("%d",&n);
    readpuzzle(argv[1],n);
    solve(board,n);
    return 0;
}

void * check_r(void* i,void* j,void* k, void *n){
    int r,c,num,m,size;
    r=(int)i;
    c=(int)j;
    size=(int)n;
    num=(int)k;
    for(m=0;m<size;m++)
    {
    	if(board[m][c]==num )
    	{
    		return (void*) 0;
    	}
    }
    
    return (void*)1;
    
}

void * check_c(void* i,void* j,void* k, void *n){
    int r,c,num,m,size;
    r=(int)i;
    c=(int)j;
    num=(int)k;
    size=(int)n;
    for(m=0;m<size;m++)
    {
    	if(board[r][m]==num)
    	{
		return (void*) 0;
    	}
    }
    		return (void*) 1;
}

void * check_s(void *i, void* j, void* k, void* n) {
    int r,c,num,p,q,size;
    r=(int)i;
    c=(int)j;
    num=(int)k;
    size=(int)n;
    for (int p = 0; p < sqrt(size); p++)
        for (int q = 0; q < sqrt(size); q++)
            if (board[p + r][q + c] ==num)
                return (void*)0;
                
                return (void*)1;
}

