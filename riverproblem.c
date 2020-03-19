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
    int hob_speed;
    scanf("%d",&hob_speed);
    return hob_speed;
}
Hobbit_team input_hobbits_of_a_team()
{
    int i;
    Hobbit_team t;
    for(i=0;i<4;i++)
        t.team_member[i].speed=input_hobbit_speed();                                         //***********
    return t;
}
void input_all_hob_teams(int n,Hobbit_team t[n])
{
    int i;
    for(i=0;i<n;i++)
        t[i]=input_hobbits_of_a_team();
}
void create_pairs(Hobbit_team *t_A,Hobbit_pairs p[])                                     // don't pass by reference until data is getting manipulated in that function
{
    int j,k,l=0;                                                                          // l is a variable which increments the pair number
    for(j=0;j<t_A->n;j++)
        for(k=j+1;k<t_A->n;k++)
        {
            p[l].a.speed=t_A->team_member[j].speed;
            p[l].b.speed=t_A->team_member[k].speed;
            l++;
        }
}
void remove_hobbit_who_reached(Hobbit_team *t_B,Hobbit_team *t_A)
{
    int a,b;
    for(a=0;a<t_A->n;a++)
    {
        if(t_B->team_member[t_B->n].speed==t_A->team_member[a].speed)
            b=a;
    }
    for(a=b;a<t_A->n-1;a++)                                                                 // a<t_A->n-1 coz a+1 is there
        t_A->team_member[a].speed=t_A->team_member[a+1].speed;
    t_A->n--;
}
void adding_hobbit_who_came_back(int hob_return,Hobbit_team *t_A)
{
    int a,b=0;                                                                              //b=0; if hob returning is 0 th element
    for(a=0;a<t_A->n;a++)
    {
        if(hob_return>t_A->team_member[a].speed)
            b=a+1;
    }
    for(a=t_A->n-1;a>=b;a--)                                                                          // **** a--;
        t_A->team_member[a+1].speed=t_A->team_member[a].speed;
    t_A->team_member[b].speed=hob_return;
    t_A->n++;
}
void remove_hobbit_pair_which_reached(Hobbit_team *t_B,int p_num,Hobbit_pairs p[],Hobbit_team *t_A)
{
    t_B->team_member[t_B->n].speed=p[p_num].a.speed;                                                  //starts from t_B.n=0
    remove_hobbit_who_reached(t_B,t_A);
    t_B->n++;                                                                                         //makes this t_B.n=1
    t_B->team_member[t_B->n].speed=p[p_num].b.speed;
    remove_hobbit_who_reached(t_B,t_A);
}
int find_which_hobbit_returns(Hobbit_team *t_A,Hobbit_team *t_B)
{
    int hobbit_returning,j,l=0;                                                                     // l=0 is needed because if the if statement if not true at all,i.e hob_returning is hob_r[0], then j will be assigned some random value
    hobbit_returning=t_B->team_member[0].speed;                                                     //don't put l=0 in if else statement as the for loop continues even after l is assigned a value and checks until the last possible case
    for(j=0;j<t_B->n;j++)                                                                           // and obviously don't put it after the if statement because it'll then take for all loops l=0;
        if(t_B->team_member[j].speed<hobbit_returning)
        {
            hobbit_returning=t_B->team_member[j].speed;
            l=j;
        }
    adding_hobbit_who_came_back(hobbit_returning,t_A);
    for(j=l;j<t_B->n;j++)
        t_B->team_member[j].speed=t_B->team_member[j+1].speed;
    t_B->n--;
    return hobbit_returning;
}
void put_back_all_hob_to_check_diff_cases(Hobbit_team *t_A,Hobbit_team *t_B)
{
    int a,b,temp;
    for(a=0;a<t_B->n-1;a++)
        for(b=a+1;b<t_B->n;b++)                                                                           //<t_B,n-1 coz a+1 is there
        {
            if(t_B->team_member[a].speed>t_B->team_member[b].speed)
            {
                temp=t_B->team_member[a].speed;
                t_B->team_member[a].speed=t_B->team_member[b].speed;
                t_B->team_member[b].speed=temp;
            }
        }
    for(a=0;a<4;a++)
        t_A->team_member[a].speed=t_B->team_member[a].speed;
    t_A->n=4;
    t_B->n=0;
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
void find_time_val(Hobbit_team *t_A,int time_values[3])
{
    Hobbit_team t_B;                                                                    //team members on the other side
    t_A->n=4;
    t_B.n=0;
    Hobbit_pairs p[6];
    int b_crs[5],j,k,m=0,p_num,t_crs;                                                    //bridge crossing time
    for(k=0;k<3;k++)                                                                     // m is incrementing the b_crossing value for every loop
    {                                                                                    // hob_r_pos is the position of the hobbit who reached the other side
        for(j=0;j<3;j++)
        {
            create_pairs(t_A,p);
            p_num=find_pair_no(k,j);
            b_crs[m]=p[p_num].b.speed;                                                   // as t1<=t2<=t3<=t4
            remove_hobbit_pair_which_reached(&t_B,p_num,p,t_A);                         //p_num*********
            if(j!=2)
                b_crs[m+1]=find_which_hobbit_returns(t_A,&t_B);                         //we use this instead of add_hob because add_hob func is called in find hob func
            m+=2;
            t_B.n++;
        }
        put_back_all_hob_to_check_diff_cases(t_A,&t_B);                                     // add all the hobbits back to try for different time values
        t_crs=b_crs[0]+b_crs[1]+b_crs[2]+b_crs[3]+b_crs[4];
        time_values[k]=t_crs;
        m=0;                                                                             //  it should start over again
    }
}
void find_st(Hobbit_team *t_A)                                                        // here t2 is a formal parameter which is a pointer, to avoid confusion u can write here Hobbit_team *ptr, therefore ptr will have the address of t2
{                                                                                        //here t2 has to be passed by reference as value is getting changed or this function has to return t2, since it's not a array it won't be passed by reference automatically
    int m,time_values[3];                                                                // l=0 it's needed because in the next input the loop should start again
    find_time_val(t_A,time_values);
    t_A->st_crs=time_values[0];
    for(m=0;m<3;m++)
    {
        if(time_values[m]<t_A->st_crs)
            t_A->st_crs=time_values[m];
    }
}
void find_st_all_teams(int n,Hobbit_team t[n],int st_all_teams[n])
{
    int i;
	for(i=0;i<n;i++)
	{
		find_st(&t[i]);                                                                 //  IN COMMIT 28, core is getting dumped here, that's because we didn't assign the structure pointer an address
		st_all_teams[i]=t[i].st_crs;
	}
}
void output_st_all_teams(int n,int st_all_teams[n])
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",st_all_teams[i]);
}
int main()
{
    int n=get_no_teams();
	Hobbit_team t[n];
	int st_all_teams[n];                                                                          //shortest time of all teams
	input_all_hob_teams(n,t);
	find_st_all_teams(n,t,st_all_teams);
	output_st_all_teams(n,st_all_teams);
	return 0;
}
