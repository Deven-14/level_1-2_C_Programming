#include<stdio.h>
struct hobbit
{
	int speed;                                                                                             //attribute of hobbit is speed
};
typedef struct hobbit Hobbit;
struct hobbit_team                                                                                         //hobbit team consist of 2 attributes, hobbits and time to cross by that team
{
	int n;                                                                                                 // no of hobbits in that team
    Hobbit team_member[4];                                                                                 // 4 hobbit team members are present, instead of team_member1, team_member 2,...i made it an array
	int st_crs;                                                                                            //time to cross for each hobbit team
};                                                                                                         // making this structure an array of structures will be the no of teams present
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
        t.team_member[i].speed=input_hobbit_speed();                                                         //***********
    return t;
}
void input_all_hob_teams(int n,Hobbit_team t[n])
{
    int i;
    for(i=0;i<n;i++)
        t[i]=input_hobbits_of_a_team();
}
void create_pairs(Hobbit_team t_A,Hobbit_pairs p[])                                                           // don't pass by reference until data is getting manipulated in that function
{
    int j,k,l=0;                                                                                              // l is a variable which increments the pair number
    for(j=0;j<t_A.n;j++)
        for(k=j+1;k<t_A.n;k++)
        {
            p[l].a.speed=t_A.team_member[j].speed;
            p[l].b.speed=t_A.team_member[k].speed;
            l++;
        }
}
void remove_hobbit(Hobbit h,Hobbit_team *t)
{
    int a,b;
    for(a=0;a<t->n;a++)
    {
        if(h.speed==t->team_member[a].speed)
        {
            b=a;
            break;
        }
    }
    for(a=b;a<t->n-1;a++)                                                                            // a<t_A->n-1 coz a+1 is there
        t->team_member[a].speed=t->team_member[a+1].speed;
    t->n--;
}
void adding_hobbit_who_came_back(Hobbit h,Hobbit_team *t_A)
{
    int a,b=0;                                                                                         //b=0; if hob returning is 0 th element
    for(a=0;a<t_A->n;a++)                                                                              // adding the hobbits in order
    {
        if(h.speed>t_A->team_member[a].speed)
            b=a+1;
    }
    for(a=t_A->n-1;a>=b;a--)                                                                            // **** a--;
        t_A->team_member[a+1].speed=t_A->team_member[a].speed;
    t_A->team_member[b].speed=h.speed;
    t_A->n++;
}
void move_pair(Hobbit_team *t_B,Hobbit_pairs p,Hobbit_team *t_A)
{
    Hobbit h;
    h.speed=t_B->team_member[t_B->n].speed=p.a.speed;                                                   //starts from t_B.n=0
    remove_hobbit(h,t_A);
    t_B->n++;                                                                                           //says 1 element present,therfore n=1
    h.speed=t_B->team_member[t_B->n].speed=p.b.speed;                                                   //saves in nth element, so n++ in the next line
    remove_hobbit(h,t_A);
    t_B->n++;                                                                                           //says 2 elements present, therefore at last says 4 elements present, i.e t_B.n=4;
}
int find_fastest_hobbit(Hobbit_team *t_B)
{
    Hobbit h_fastest;
    h_fastest.speed=t_B->team_member[0].speed;
    for(int j=0;j<t_B->n;j++)
        if(t_B->team_member[j].speed<h_fastest.speed)
        {
            h_fastest.speed=t_B->team_member[j].speed;
            break;
        }
    return h_fastest.speed;
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
    Hobbit h;
    sort(t_B);
   *t_A=*t_B;                                                                                               //*****we have to equate values, not addresses, therefore t_A=t_B is wrong here
    t_A->n=4;
    t_B->n=0;
    h.speed=t_B->team_member[0].speed=t_A->team_member[1].speed;                                            //adding 2nd hobbits back to B
    remove_hobbit(h,t_A);                                                                       //removing 2nd hobbit from A
    t_B->n++;                                                                                               //put this after removing function itself, coz t_B.n value is used in that function...
}
void find_1st_2_crossings(Hobbit_team *t_A,Hobbit_team *t_B,int b_crs[5])
{
    Hobbit_pairs p1[6];
    Hobbit h_returning;
    create_pairs(*t_A,p1);
    b_crs[0]=p1[0].b.speed;                                                                                  // as t1<=t2<=t3<=t4
    move_pair(t_B,p1[0],t_A);                                                                               //do it using these functions as 2nd hobbits has to be removed from A and put to B
    h_returning.speed=b_crs[1]=find_fastest_hobbit(t_B);
    remove_hobbit(h_returning,t_B);
    adding_hobbit_who_came_back(h_returning,t_A);
}
void find_next_3_crossing(int k,Hobbit_team *t_A,Hobbit_team *t_B,int b_crs[5])
{
    Hobbit h_returning;
    Hobbit_pairs p3[3],p5[1];
    create_pairs(*t_A,p3);
    b_crs[2]=p3[k].b.speed;
    move_pair(t_B,p3[k],t_A);
    h_returning.speed=b_crs[3]=find_fastest_hobbit(t_B);
    remove_hobbit(h_returning,t_B);
    adding_hobbit_who_came_back(h_returning,t_A);
    create_pairs(*t_A,p5);
    b_crs[4]=p5[0].b.speed;
    move_pair(t_B,p5[0],t_A);
}
void find_time_val(Hobbit_team *t_A,int time_values[3])
{
    Hobbit_team t_B;                                                                                         //team members on the other side
    t_A->n=4;
    t_B.n=0;
    int b_crs[5],k,t_crs;
    find_1st_2_crossings(t_A,&t_B,b_crs);
    for(k=0;k<3;k++)
    {
        find_next_3_crossing(k,t_A,&t_B,b_crs);
        reset_A_with_3_hobbits(t_A,&t_B);                                                                    // add the 3 hobbits back to try for different time values
        t_crs=b_crs[0]+b_crs[1]+b_crs[2]+b_crs[3]+b_crs[4];
        time_values[k]=t_crs;
    }                                                                                                        //  it should start over again
}
void find_st(Hobbit_team *t_A)                                                                               // here t2 is a formal parameter which is a pointer, to avoid confusion u can write here Hobbit_team *ptr, therefore ptr will have the address of t2
{                                                                                                            //here t2 has to be passed by reference as value is getting changed or this function has to return t2, since it's not a array it won't be passed by reference automatically
    int m,time_values[3];                                                                                    // l=0 it's needed because in the next input the loop should start again
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
	{                                                                                            //  IN COMMIT 28, core is getting dumped here, that's because we didn't assign the structure pointer an address
		find_st(&t[i]);                                                                          //****important trick
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
