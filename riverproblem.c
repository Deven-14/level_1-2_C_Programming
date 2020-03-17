#include<stdio.h>
struct hobbit
{
	int speed;                                                         //attribute of hobbit is speed
};
typedef struct hobbit Hobbit;
struct hobbit_team                                                    //hobbit team consist of 2 attributes, hobbits and time to cross by that team
{
	int n;                                                            // no of hobbits in that team
    Hobbit team_member[4];                                            // 4 hobbit team members are present, instead of team_member1, team_member 2,...i made it an array
	int st_crs;                                                       //time to cross for each hobbit team
};                                                                    // making this structure an array of structures will be the no of teams present
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
int input_hobbit_speed()
{
    int hob;
    scanf("%d",&hob);
    return hob;
}
Hobbit_team input_hobbits_of_a_team()
{
    int i;
    Hobbit_team t;
    for(i=0;i<4;i++)
        t.team_member[i].speed=input_hobbit_speed();
    return t;
}
void input_all_hob_teams(int n,Hobbit_team t[n])
{
    int i;
    for(i=0;i<n;i++)
        t[i]=input_hobbits_of_a_team();
}
void create_pairs(Hobbit_team t2,Hobbit_pairs p[])               // don't pass by reference until data is getting manipulated in that function
{
    int j,k,l=0;                                                 // l is a variable which increments the pair number
    for(j=0;j<t2.n;j++)
        for(k=j+1;k<t2.n;k++)
        {
            p[l].a.speed=t2.team_member[j].speed;
            p[l].b.speed=t2.team_member[k].speed;
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
    int a,b=0;                                                                //b=0; if hob returning is 0 th element
    for(a=0;a<t2->n;a++)
    {
        if(hob_return>t2->team_member[a].speed)
            b=a+1;
    }
    for(a=t2->n-1;a>=b;a--)                                                    // **** a--;
        t2->team_member[a+1].speed=t2->team_member[a].speed;
    t2->team_member[b].speed=hob_return;
    t2->n++;
}
void hobbit_pairs_reaching_opp_side(int hob_r[4],int l,int p_num,Hobbit_pairs p[],Hobbit_team *t2)
{
    hob_r[l]=p[p_num].a.speed;
    hob_r[l+1]=p[p_num].b.speed;
    remove_hobbit_who_reached(p[p_num].a.speed,t2);
    remove_hobbit_who_reached(p[p_num].b.speed,t2);
}
int find_which_hobbit_returns(Hobbit_team *t2,int hob_r[4])
{
    int hobbit_returning,j,l=0;                                                    // l=0 is needed because if the if statement if not true at all,i.e hob_returning is hob_r[0], then j will be assigned some random value
    hobbit_returning=hob_r[0];                                                     //don't put l=0 in if else statement as the for loop continues even after l is assigned a value and checks until the last possible case
    for(j=0;j<4-t2->n;j++)                                                         // and obviously don't put it after the if statement because it'll then take for all loops l=0;
        if(hob_r[j]<hobbit_returning)
        {
            hobbit_returning=hob_r[j];
            l=j;
        }
    adding_hobbit_who_came_back(hobbit_returning,t2);
    for(j=l;j<4-t2->n;j++)
        hob_r[j]=hob_r[j+1];
    return hobbit_returning;
}
void put_back_all_hob_to_check_all_cases(int i,Hobbit_team t[i],Hobbit_team *t2)
{
    int a;
    for(a=0;a<4;a++)
        t2->team_member[a].speed=t[i].team_member[a].speed;
    t2->n=4;
}
int find_pair_no(int k, int j)
{
    int p_num;
    switch(j)
    {
        case 0:
            p_num=0;
            break;
        case 1:
            if(k==0)                                                          //includes k=0 case
                p_num=0;
            else if(k==1)
                p_num=1;
            else
                p_num=2;
            break;
        default:                                                                // j=2 case
            p_num=0;
    }
    return p_num;
}
void compute_all_possible_t_val(int i,Hobbit_team t[i],int all_t_val[3],Hobbit_team *t2)
{
    Hobbit_pairs p[6];
    int b_crs[5],hob_r[4],j,k,m=0,p_num,hob_r_pos=0,t_crs;                                   //hobbits who reached  //bridge crossing time
    for(k=0;k<3;k++)                                                                         // m is incrementing the b_crossing value for every loop
    {                                                                                         // hob_r_pos is the position of the hobbit who reached the other side
        for(j=0;j<3;j++)
        {
            create_pairs(*t2,p);
            p_num=find_pair_no(k,j);
            b_crs[m]=p[p_num].b.speed;                                                          // as t1<=t2<=t3<=t4
            hobbit_pairs_reaching_opp_side(hob_r,hob_r_pos,p_num,p,t2);                        //p_num*********
            if(j!=2)
                b_crs[m+1]=find_which_hobbit_returns(t2,hob_r);                                 //we use this instead of add_hob because add_hob func is called in find hob func
            m+=2;
            hob_r_pos++;
        }
        put_back_all_hob_to_check_all_cases(i,t,t2);                                         // add all the hobbits back to try for different time values
        t_crs=b_crs[0]+b_crs[1]+b_crs[2]+b_crs[3]+b_crs[4];
        all_t_val[k]=t_crs;
        hob_r_pos=m=0;                                                                         //  it should start over again
    }
}
void compute_st(int i,Hobbit_team t[i],Hobbit_team *t2)                                 // here t2 is a formal parameter which is a pointer, to avoid confusion u can write here Hobbit_team *ptr, therefore ptr will have the address of t2
{                                                                                             //here t2 has to be passed by reference as value is getting changed or this function has to return t2, since it's not a array it won't be passed by reference automatically
    int m,all_t_val[3];                                                                      // l=0 it's needed because in the next input the loop should start again
    compute_all_possible_t_val(i,t,all_t_val,t2);
    t2->st_crs=all_t_val[0];
    for(m=0;m<3;m++)
    {
        if(all_t_val[m]<t2->st_crs)
            t2->st_crs=all_t_val[m];
    }
}
void compute_st_all_T(int n,Hobbit_team t[n],int st_all_T[n])
{
    Hobbit_team t2;
    int i,a;
	for(i=0;i<n;i++)
	{
	    t2.n=4;                                                                                 //  IN COMMIT 28, core is getting dumped here, that's because we didn't assign the structure pointer an address
	    for(a=0;a<4;a++)
            t2.team_member[a].speed=t[i].team_member[a].speed;
		compute_st(i,t,&t2);
		st_all_T[i]=t2.st_crs;
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
	int st_all_T[n];                                                                          //shortest time of all teams
	input_all_hob_teams(n,t);
	compute_st_all_T(n,t,st_all_T);
	output_st_all_T(n,st_all_T);
	return 0;
}
