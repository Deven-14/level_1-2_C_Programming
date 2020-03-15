#include<stdio.h>
struct hobbit
{
	int speed; //attribute of hobbit is speed
};
typedef struct hobbit Hobbit;
struct hobbit_team   //hobbit team consist of 2 attributes, hobbits and time to cross by that team
{
	int n; // no of hobbits in that team
    Hobbit team_member[4];  // 4 hobbit team members are present, instead of team_member1, team_member 2,...i made it an array
	int st_crs; //time to cross for each hobbit team
};  // making this structure an array of structures will be the no of teams present
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
}
void create_pairs(Hobbit_team *t2,Hobbit_pairs p[])
{
    int j,k,l=0;
    for(j=0;j<t2->n;j++)
        for(k=j+1;k<t2->n;k++)
        {
            p[l].a.speed=t2->team_member[j].speed;
            p[l].b.speed=t2->team_member[k].speed;
            l++;
        }
}
void remove_hobbit_who_reached(int r,Hobbit_team *t2)
{
    int a,b;
    for(a=0;a<t2->n;a++)
    {
        if(r==t2->team_member[a].speed)
            b=a;
    }
    for(a=b;a<t2->n;a++)
        t2->team_member[a].speed=t2->team_member[a+1].speed;
    t2->n--;
}
void adding_hobbit_who_came_back(int hob_return,Hobbit_team *t2)
{
    int a,b=0; //if hob returning is 0 th element
    for(a=0;a<t2->n;a++)
    {
        if(hob_return>t2->team_member[a].speed)
            b=a+1;
    }
    for(a=t2->n-1;a>=b;a--)  // **** a--;
        t2->team_member[a+1].speed=t2->team_member[a].speed;
    t2->team_member[b].speed=hob_return;
    t2->n++;
}
void hobbit_pairs_reaching_opp_side(int hob_r[4],int l,int k,Hobbit_pairs p[],int r1,int r2,Hobbit_team *t2)
{
    r1=hob_r[1]=p[k].a.speed;
    r2=hob_r[2]=p[k].b.speed;
    remove_hobbit_who_reached(r1,t2);
    remove_hobbit_who_reached(r2,t2);
}
int find_which_hobbit_returns(Hobbit_team *t2,int hob_r[4],int *r1,int *r2)
{
    int hobbit_returning,j,l=0;// l=0 is needed because if the if statement if not true at all,i.e hob_returning is hob_r[0], then j will be assigned some random value
    hobbit_returning=hob_r[0];  //don't put l=0 in if else statement as the for loop continues even after l is assigned a value and checks until the last possible case
    for(j=0;j<4-t2->n;j++)            // and obviously don't put it after the if statement because it'll then take for all loops l=0;
        if(hob_r[j]<hobbit_returning)
        {
            hobbit_returning=hob_r[j];
            l=j;
        }
    adding_hobbit_who_came_back(hobbit_returning,t2);
    for(j=l;j<4-t2->n;j++)
        hob_r[j]=hob_r[j+1];
    *r1=hob_r[0];
    *r2=hob_r[1]; //have to be called by reference
    return hobbit_returning;
}
void put_back_3_hob_to_check_all_cases(int temp,int i,int n,Hobbit_team t[n],Hobbit_team *t2)
{
    int a;
    for(a=0;a<4;a++)
        t2->team_member[a].speed=t[i].team_member[a].speed;
    t2->n=4;
    remove_hobbit_who_reached(temp,t2);
}
int compute_t_crs(int i,int n,Hobbit_team t[n],int l,int all_t_val[18],Hobbit_team *t2)
{
    Hobbit_pairs p1[6],p3[3],p5[1];
    int b_crs[5]; //bridge crossing time
	int hob_r[4]; //hobbits who reached
    int j,k,hob_r_pos,m,t_crs,temp,r1=0,r2=0; // ***r1 and r2 are temporary variables which store the values of hob which "are on" the opp side, temp is just a temporary variable that stores the values of the 1st hob who remained on the other side(reached the other side)
    create_pairs(t2,p1);
    for(j=0;j<6;j++)
    {
        temp=hob_r[0]=b_crs[0]=p1[j].b.speed;// as t1<=t2<=t3<=t4
        hob_r_pos=0;
        hobbit_pairs_reaching_opp_side(hob_r,hob_r_pos,j,p1,r1,r2,t2);
        b_crs[1]=find_which_hobbit_returns(t2,hob_r,&r1,&r2); //we use this instead of add hob because add hob func is called in find hob func
        create_pairs(t2,p3);
        for(k=0;k<3;k++)
        {
            b_crs[2]=p3[k].b.speed;
            hob_r_pos=1;
            hobbit_pairs_reaching_opp_side(hob_r,hob_r_pos,k,p3,r1,r2,t2);
            b_crs[3]=find_which_hobbit_returns(t2,hob_r,&r1,&r2);
            create_pairs(t2,p5);
            for(m=0;m<1;m++)
            {
                b_crs[4]=p5[m].b.speed;
                hob_r_pos=2;
                hobbit_pairs_reaching_opp_side(hob_r,hob_r_pos,m,p5,r1,r2,t2);
            }
            put_back_3_hob_to_check_all_cases(temp,i,n,t,t2); // add the 3 hobbits back to try for different time values
            t_crs=b_crs[0]+b_crs[1]+b_crs[2]+b_crs[3]+b_crs[4];
            all_t_val[l]=t_crs;
            l++;
        }
        adding_hobbit_who_came_back(temp ,t2); //to check all cases we add this back
    }
    return l;
}
void compute_st(int i,int n,Hobbit_team t[n],Hobbit_team *t2)
{
    int m,l=0,all_t_val[18]; // l=0 it's needed because in the next input the loop should start again
    l=compute_t_crs(i,n,t,l,all_t_val,t2);
    t2->st_crs=all_t_val[0];
    for(m=0;m<l;m++)
    {
        if(all_t_val[m]<t2->st_crs)
            t2->st_crs=all_t_val[m];
    }
}
void compute_st_all_T(int n,Hobbit_team t[n],int st_all_T[n])
{
    Hobbit_team *t2;
    int i,a;
	for(i=0;i<n;i++)
	{
	    t2->n=4;
	    for(a=0;a<4;a++)
            t2->team_member[a].speed=t[i].team_member[a].speed;
		compute_st(i,n,t,t2);
		st_all_T[i]=t2->st_crs;
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
	int st_all_T[n]; //shortest time of all teams
	input_hobbit_teams(n,t);
	compute_st_all_T(n,t,st_all_T);
	output_st_all_T(n,st_all_T);
	return 0;
}
