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
void create_pairs(Hobbit_team t_A,Hobbit_pairs p[])                                     // don't pass by reference until data is getting manipulated in that function
{
    int j,k,l=0;                                                                          // l is a variable which increments the pair number
    for(j=0;j<t_A.n;j++)
        for(k=j+1;k<t_A.n;k++)
        {
            p[l].a.speed=t_A.team_member[j].speed;
            p[l].b.speed=t_A.team_member[k].speed;
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
    for(a=b;a<t_A->n-1;a++)                                                                         // a<t_A->n-1 coz a+1 is there
        t_A->team_member[a].speed=t_A->team_member[a+1].speed;
    t_A->n--;
}
void adding_hobbit_who_came_back(int hob_return,Hobbit_team *t_A)
{
    int a,b=0;                                                                                      //b=0; if hob returning is 0 th element
    for(a=0;a<t_A->n;a++)
    {
        if(hob_return>t_A->team_member[a].speed)
            b=a+1;
    }
    for(a=t_A->n-1;a>=b;a--)                                                                        // **** a--;
        t_A->team_member[a+1].speed=t_A->team_member[a].speed;
    t_A->team_member[b].speed=hob_return;
    t_A->n++;
}
void move_pair(Hobbit_team *t_B,Hobbit_pairs p,Hobbit_team *t_A)
{
    t_B->team_member[t_B->n].speed=p.a.speed;                                                       //starts from t_B.n=0
    remove_hobbit_who_reached(t_B,t_A);
    t_B->n++;                                                                                       //makes this t_B.n=1
    t_B->team_member[t_B->n].speed=p.b.speed;
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
void sort(Hobbit_team *t_B)                                                                              //sorting team members of B so team B has to be passed
{
    int a,b,temp;
    for(a=0;a<t_B->n-1;a++)
        for(b=a+1;b<t_B->n;b++)                                                                          //<t_B,n-1 coz a+1 is there
        {
            if(t_B->team_member[a].speed>t_B->team_member[b].speed)
            {
                temp=t_B->team_member[a].speed;
                t_B->team_member[a].speed=t_B->team_member[b].speed;
                t_B->team_member[b].speed=temp;
            }
        }
}
void reset_A_with_3_hobbits(Hobbit_team *t_A,Hobbit_team *t_B)
{
    sort(t_B);
   *t_A=*t_B;                                                                                            //*****we have to equate values, not addresses, therefore t_A=t_B is wrong here
    t_A->n=4;
    t_B->n=0;
    t_B->team_member[0].speed=t_A->team_member[1].speed;                                                 //adding 2nd hobbits back to B
    remove_hobbit_who_reached(t_B,t_A);                                                                  //removing 2nd hobbit from A
    t_B->n++;                                                                                            //put this after removing function itself, coz t_B.n value is used in that function...
}
void find_next_3_crossing(int k,Hobbit_team *t_A,Hobbit_team *t_B,int b_crs[5])
{
    Hobbit_pairs p3[3],p5[1];
    create_pairs(*t_A,p3);
    b_crs[2]=p3[k].b.speed;
    t_B->n=1;
    move_pair(t_B,p3[k],t_A);
    b_crs[3]=find_which_hobbit_returns(t_A,t_B);
    create_pairs(*t_A,p5);
    b_crs[4]=p5[0].b.speed;
    t_B->n=2;
    move_pair(t_B,p5[0],t_A);
    t_B->n=4;                                                                           // indicating all 4 hobbits have reached, if not put t_B.n will be 3 as we take it from 0 to 3
}
void find_time_val(Hobbit_team *t_A,int time_values[3])
{
    Hobbit_team t_B;                                                                    //team members on the other side
    t_A->n=4;
    t_B.n=0;
    Hobbit_pairs p1[6];
    int b_crs[5],k,t_crs;
    create_pairs(*t_A,p1);
    b_crs[0]=p1[0].b.speed;                                                             // as t1<=t2<=t3<=t4
    t_B.n=0;
    move_pair(&t_B,p1[0],t_A);                                                          //do it using these functions as 2nd hobbits has to be removed from A and put to B
    b_crs[1]=find_which_hobbit_returns(t_A,&t_B);
    for(k=0;k<3;k++)
    {
        find_next_3_crossing(k,t_A,&t_B,b_crs);
        reset_A_with_3_hobbits(t_A,&t_B);                                               // add the 3 hobbits back to try for different time values
        t_crs=b_crs[0]+b_crs[1]+b_crs[2]+b_crs[3]+b_crs[4];
        time_values[k]=t_crs;
    }                                                                                   //  it should start over again
}
void find_st(Hobbit_team *t_A)                                                          // here t2 is a formal parameter which is a pointer, to avoid confusion u can write here Hobbit_team *ptr, therefore ptr will have the address of t2
{                                                                                       //here t2 has to be passed by reference as value is getting changed or this function has to return t2, since it's not a array it won't be passed by reference automatically
    int m,time_values[3];                                                               // l=0 it's needed because in the next input the loop should start again
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
	{                                                                                 //  IN COMMIT 28, core is getting dumped here, that's because we didn't assign the structure pointer an address
		find_st(&t[i]);                                                               //****important trick
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
