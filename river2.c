#include<stdio.h>
struct hobbit
{
	int speed;                                                                                             //attribute of hobbit is speed
};
typedef struct hobbit Hobbit;
struct hobbit_team                                                                                         //hobbit team consist of 2 attributes, hobbits and time to cross by that team
{                                                                                                          // no of hobbits in that team
    Hobbit team_member[4];                                                                                 // 4 hobbit team members are present, instead of team_member1, team_member 2,...i made it an array
	int st_crs;                                                                                            //time to cross for each hobbit team
};                                                                                                         // making this structure an array of structures will be the no of teams present
typedef struct hobbit_team Hobbit_team;
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
int find_st(Hobbit_team t)
{
    int b1,b2,c1,c2;//bridge crossing 1,2,case1, case2
    b1=t.team_member[1].speed;
    b2=t.team_member[0].speed;
    c1=t.team_member[2].speed+t.team_member[0].speed+t.team_member[3].speed;
    c2=t.team_member[3].speed+t.team_member[1].speed+t.team_member[1].speed;
    if(c1<c2)
    {
       t.st_crs=b1+b2+c1;
    }
    else
    {
       t.st_crs=b1+b2+c2;
    }
    return t.st_crs;
}
void find_st_all_teams(int n,Hobbit_team t[n],int st_all_teams[n])
{
    int i;
	for(i=0;i<n;i++)
	{
		t[i].st_crs=find_st(t[i]);                                                                          //****important trick
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
/*given t1<=t2<=t3<=t4
 so b0 and b1 is fixed, because the shortest way is :
 eg: 1 2 5 10->(1,2) go, 1 comes back then (5,10)in this case (it could be the other 2 possibilities for other teams,this method gives shortest time) and then 2 comes back and (1,2) finally goes.
 now t1,t3,t4 are remaining, possible pairs are(t1,t3),(t1,t4),(t3,t4),so b2 can be t3 or t4
 and if b2=t3, then b3=t1 (fastest one) and b4=t4 ( (t4,t1), will be remaining at last)
 and if b2=t4, then b3= (t1 or t3) depending on which pair is sent,
               if b3=t1 then b4=t3
               and if b3=t2 ( (t3,t4)if passed ) then b4=t2 ((t2,t1)remaining)
        b2=b3,b3=t1,b4=t4 is same as b2=t4,b3=t1,b4=t3
 therefore should check if(t3+t1+t4>t4+t2+t2) */
