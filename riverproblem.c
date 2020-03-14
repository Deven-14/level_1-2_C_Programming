#include<stdio.h>
struct hobbit
{
	int speed; //attribute of hobbit is speed
};
typedef struct hobbit Hobbit;
struct hobbit_team   //hobbit team consist of 2 attributes, hobbits and time to cross by that team
{
	int n;// if we have to accept number of hobbits in a team, then next line will be Hobbit team[n];
    Hobbit team_member[4];  // 4 hobbit team members are present, instead of team_member1, team_member 2,...i made it an array
	int st_crs; //time to cross for each hobbit team
};
typedef struct hobbit_team Hobbit_team;
struct hobbit_pairs
{
	Hobbit a;
	Hobbit b;
};
typedef struct hobbit_pairs Hobbit_pairs;
int get_no_teams()
{
	int n;
	scanf("%d",&n);
	return n;
}
void input_hobbit_teams(int n,Hobbit_team t[n])
{
    int i;
    for(i=0;i<n;i++)
	scanf("%d%d%d%d",&t[i].team_member[0].speed,&t[i].team_member[1].speed,&t[i].team_member[2].speed,&t[i].team_member[3].speed);
	printf("%d,%d,%d,%d\n",t[i].team_member[0].speed,t[i].team_member[1].speed,t[i].team_member[2].speed,t[i].team_member[3].speed);
}
void create_pairs(int i,int n,Hobbit_team t[n],Hobbit_pairs p[])
{
    int j,k,l=0;
    for(j=0;j<t[i].n;j++)
        for(k=j+1;k<t[i].n;k++)
        {
            p[l].a.speed=t[i].team_member[j].speed;
            p[l].b.speed=t[i].team_member[k].speed;
            l++;
        }
    int a;
    for(a=0;a<l;a++)
    {
        printf("%d %d,",p[a].a.speed,p[a].b.speed);
    }
    printf("\n");
}
void hobbits_reached(int hob_r[4],int k,Hobbit_pairs p[])
{
    hob_r[1]=p[k].a.speed;
    hob_r[2]=p[k].b.speed;
    printf("%d,%d,hob_1,hob_2\n",hob_r[1],hob_r[2]);
}
void remove_hobbit_who_reached(int i,int n,int r,Hobbit_team t[n])
{
    int a,b;
    for(a=0;a<t[i].n;a++)
    {
        if(r==t[i].team_member[a].speed)
            b=a;
    }
    for(a=b;a<t[i].n;a++)
        t[i].team_member[a].speed=t[i].team_member[a+1].speed;
    t[i].n--;
    for(a=0;a<t[i].n;a++)
        printf("%d,",t[i].team_member[a].speed);
    printf("removed hobbits\n");
}
void adding_hobbit_who_came_back(int hob_return,int i,int n,Hobbit_team t[n])
{
    int a,b=0; //if hob returning is 0 th element
    for(a=0;a<t[i].n;a++)
    {
        if(hob_return>t[i].team_member[a].speed)
            b=a+1;
    }
    for(a=t[i].n-1;a>=b;a--)  // **** a--;
        t[i].team_member[a+1].speed=t[i].team_member[a].speed;
    t[i].team_member[b].speed=hob_return;
    t[i].n++;
}
int find_which_hobbit_returns(int i,int n,Hobbit_team t[n],int hob_r[4],int *r1,int *r2)
{
    int hobbit_returning,j,l=0;// l=0 is needed because if the if statement if not true at all,i.e hob_returning is hob_r[0], then j will be assigned some random value
    hobbit_returning=hob_r[0];  //don't put l=0 in if else statement as the for loop continues even after l is assigned a value and checks until the last possible case
    for(j=0;j<3;j++)            // and obviously don't put it after the if statement because it'll then take for all loops l=0;
        if(hob_r[j]<hobbit_returning)
        {
            hobbit_returning=hob_r[j];
            l=j;
        }
    adding_hobbit_who_came_back(hobbit_returning,i,n,t);
    printf("%d,%d,l,hob_returning\n",l,hobbit_returning);
    int a;
    for(a=0;a<3;a++)
        printf("%d,",hob_r[a]);
    printf("hob_r\n");
    for(j=l;j<3;j++)
        hob_r[j]=hob_r[j+1];
    *r1=hob_r[0];
    *r2=hob_r[1]; //have to be pointers
    printf("%d,%d,r1,r2\n",hob_r[0],hob_r[1]);
    return hobbit_returning;
}
int compute_t_crs(int n,int i,int l,int b_crs[5],int hob_r[4],int all_t_val[18],Hobbit_team t[n],Hobbit_pairs p1[6],Hobbit_pairs p3[3],Hobbit_pairs p5[1])
{
    int j,k,t_crs,r1=0,r2=0;
    create_pairs(i,n,t,p1);
    for(j=0;j<6;j++)
    {
        r1=hob_r[0]=b_crs[0]=p1[j].b.speed;// as t1<=t2<=t3<=t4
        t[i].n=4;
        remove_hobbit_who_reached(i,n,r1,t);
        printf("%d r1\n",r1);
        b_crs[1]=p1[j].a.speed;
        create_pairs(i,n,t,p3);
        for(k=0;k<3;k++)
        {
            b_crs[2]=p3[k].b.speed;
            hobbits_reached(hob_r,k,p3);
            b_crs[3]=find_which_hobbit_returns(i,n,t,hob_r,&r1,&r2);
            t[i].n=4; //for every loop it should become back to what it was
            remove_hobbit_who_reached(i,n,r1,t);
            remove_hobbit_who_reached(i,n,r2,t);
            create_pairs(i,n,t,p5);
            b_crs[4]=p5[0].b.speed;
            t_crs=b_crs[0]+b_crs[1]+b_crs[2]+b_crs[3]+b_crs[4];
            printf("%d,%d,%d,%d,%d,b_crs\n",b_crs[0],b_crs[1],b_crs[2],b_crs[3],b_crs[4]);
            all_t_val[l]=t_crs;
            l++;
        }
    }
    int a;
    for(a=0;a<l;a++)
        printf("%d,",all_t_val[a]);
    printf("all_t_val\n");
    return l;
}
void compute_st(int n,int i,int b_crs[5],int hob_r[4],Hobbit_team t[n],Hobbit_pairs p1[6],Hobbit_pairs p3[3],Hobbit_pairs p5[1])
{
    int m,l=0,all_t_val[18]; // l=0 it's needed because in the next input the loop should start again
    l=compute_t_crs(n,i,l,b_crs,hob_r,all_t_val,t,p1,p3,p5);
    t[i].st_crs=all_t_val[0];
    for(m=0;m<l;m++)
    {
        if(all_t_val[m]<t[i].st_crs)
            t[i].st_crs=all_t_val[m];
    }
    printf("st_crs %d\n",t[i].st_crs);
}
void compute_st_all_T(int n,Hobbit_team t[n],int hob_r[4],Hobbit_pairs p1[6],Hobbit_pairs p3[3],Hobbit_pairs p5[1],int b_crs[5],int st_all_T[n])
{
    int i;
	for(i=0;i<n;i++)
	{
	    t[i].n=4;
		compute_st(n,i,b_crs,hob_r,t,p1,p3,p5);
		st_all_T[i]=t[i].st_crs;
	}
}
void output_st_all_T(int n,int st_all_T[n])
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",st_all_T[i]);
}
int main()
{
    int n=get_no_teams();
	Hobbit_team t[n];
	Hobbit_pairs p1[6],p3[3],p5[1];
	int b_crs[5]; //bridge crossing time
	int hob_r[4]; //hobbits who reached
	int st_all_T[n]; //shortest time of all teams
	input_hobbit_teams(n,t);
	compute_st_all_T(n,t,hob_r,p1,p3,p5,b_crs,st_all_T);
	output_st_all_T(n,st_all_T);
	return 0;
}
