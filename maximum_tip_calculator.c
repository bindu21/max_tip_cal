/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
struct deemo
{
    int xi;
    int yi;
};

int absolute(int x,int y)
{
    if (x==y)
    return 0;
    if(x>y)
    return(x-y);
    else
    return(y-x);
}
void sort_array(struct deemo arr[100],int n)
{
    int i=0,j=0;
    struct deemo temp;
    temp.xi=0;
    temp.yi=0;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(absolute(arr[i].xi,arr[i].yi) < absolute(arr[j].xi,arr[j].yi))
            {
                temp.xi = arr[i].xi;
                temp.yi = arr[i].yi;
                arr[i].xi = arr[j].xi;
                arr[i].yi = arr[j].yi;
                arr[j].xi = temp.xi;
                arr[j].yi = temp.yi;
            }
        }
    }
}
int call_func(int n,int x,int y,int arrx[100],int arry[100])
{
    int i = 0,j=0,temp_num = n,sum =0,picked = 0;
    int p=0,index =0;
    struct deemo demo[100];
    for(i=0;i<n;i++)
    {
        demo[i].xi = arrx[i];
        demo[i].yi = arry[i];
    }
    sort_array(demo,n);
    i=0;
    j=0;
    sum =0;
    for(p=0;p<n;p++)
    {
        if(i==x)
        {
            sum += demo[p].yi;
            j++;
        }
        else if(j==y)
        {
            sum += demo[p].xi;
            i++;
        }
        else if(demo[p].xi > demo[p].yi)
        {
            sum += demo[p].xi;
            i++;
        }
        else
        {
            sum += demo[p].yi;
            j++;
        }
    }
    return sum;
}
int main() {
	//code
	int test_case=0,n=0,x=0,y=0;
	int final;
	int arrx[100];
	int arry[100];
	int i=0,j=0;
	memset(arrx,0,100);
	memset(arry,0,100);
	scanf("%d",&test_case);
	for(i=0;i<test_case;i++)
	{
	    scanf("%d %d %d",&n,&x,&y);
	    for(j=0;j<n;j++)
	    {
	    scanf("%d",&arrx[j]);
	    }
	    for(j=0;j<n;j++)
	    {
	         scanf("%d",&arry[j]);
	    }
	    final = call_func(n,x,y,arrx,arry);
	    printf("%d\n",final);
	  	}
	return 0;
}
