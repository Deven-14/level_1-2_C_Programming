#include<stdio.h>
#include<stdio.h>
struct hobbit
{
	int speed; //attribute of hobbit is speed
};
typedef struct hobbit Hobbit;
struct hobbit_team   //hobbit team consist of 2 attributes, hobbits and time to cross by that team
{
	//int n; // if we have to accept number of hobbits in a team, then next line will be Hobbit team[n];
	Hobbit team_member[n];  // 4 hobbit team members are present, instead of team_member1, team_member 2,...i made it an array
	int shortest_time_to_cross; //time to cross for each hobbit team
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
	scanf("%d%d%d%d",&t[i].team_member[1].speed,&t[i].team_member[2].speed,&t[i].team_member[3].speed,&t[i].team_member[4].speed);

}
int find_next_pair_to_travel(int i,int j,int k,int &z,int n,Hobbit_team t[n],Hobbit_pairs p)
{
    p.a.speed=t[i].team_member[j].speed;
    p.b.speed=t[i].team_member[k].speed;
    hobbits_reached[z]=p.a.speed;
    hobbits_reached[z+1]=p.b.speed;
    z+=2;
    return=p.b.speed; // as t1<=t2<=t3<=t4
}
int hobbits_who_reached(int &z,int hobbits_reached[4],Hobbit_pairs p)
{
    int j,k;
    for(j=0;j<z;j++)
        if(hobbits_reached[j]==p.b.speed)
            k=j;
    return k;
}
int find_which_hobbit_returns(int i,Hobbit_team t[n],Hobbit_pairs p,int hobbit_reached[4])
{
    int hobbit_returning,j,l;
    hobbit_returning=hobbit_reached[0];
    for(j=0;j<4;j++)
        if(hobbit_reached[j]<hobbit_returning)
        {
            hobbit_returning=hobbit_reached[j];
            l=j;
        }
    for(j=l;j<z;j++)
        hobbits_reached[j]=hobbits_reached[j+1];
    z--;
    return hobbit_returning;
}
int time_to_cross_func(int i,int n,Hobbit_team t[n],int ,int bridge_crossing[5])
{
    int j,k,l,m,p,q,r1,r2,z,time_to_cross=0; //,l=0
    for(j=0;j<4;j++)
        for(k=j+1;k<4;k++)
        {
            bridge_crossing[0]=find_next_pair_to_travel(i,j,k,n,t,p);
            bridge_crossing[1]=find_which_hobbit_returns();
            //l+=2;
            r1=hobbits_who_reached(z,hobbits_remaining,p);
            for(l=0;l<4;l++)
                for(m=l+1;m<4;m++)
                {
                    if(hobbits_reached[r1]!=)
                    bridge_crossing[3]=find_next_pair_to_travel(i,l,m,n,t,p);
                    bridge_crossing[4]=find_which_hobbit_returns();
                    //l+=2;
                    r2=hobbits_who_reached(z,hobbits_remaining,p);
                    for(p=0;p<4;p++)
                        for(q=p+1;q<4;q++)
                            bridge_crossing[5]=find_next_pair_to_travel(i,p,q,n,t,p);
                    for(z=0;z<5;z++)
                        time_to_cross+=bridge_crossing[z];
                    z=0;
                    all_possible_time_values_of_each_team[z]=time_to_cross;
                    l++;
                }
        }
    return time_to_cross;
}
int compute_shortest_time_to_cross()
{
    int x;
    for(x=0;x<4;x++)
        hobbits_remaining[x]=t[i].team_member[x].speed;

}
 /*for(l=0;l<3;l++)
                for(m=l+1;m<3;m++)
                {
                    create_hobbit_pairs(i,j,k,n,t,p);
                    bridge_crossing[3]=time_taken_by_pair_to_travel(i,z,t,p,hobbit_reached);
                    bridge_crossing[4]=find_which_hobbit_returns();
                }
            create_hobbit_pairs(i,j,k,n,t,p);
            bridge_crossing[5]=time_taken_by_pair_to_travel(i,z,t,p,hobbit_reached);
*/
void compute_shortest_time_to_cross_of_all_teams()
{
    int i;
    for(i=0;i<n;i++)
    {

    }
}
void output_shortest_time_of_all_teams(int n,int shortest_time_of_all_teams[n])
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",shortest_time_of_all_teams[i]);
}
int main()
{
	int n=get_no_teams();
	Hobbit_team t[n];
	Hobbit_pairs p1[6],p3[3],p5;
	int bridge_crossing[5];
	int z=0;
	int hobbits_reached[z];
	int shortest_time_of_all_teams[n];
	input_hobbit_teams(n,t);
	compute_shortest_time_to_cross_of_all_teams(n,t,p1,p3,p5,bridge_crossing,shortest_time_of_all_teams);
	output_shortest_time_of_all_teams(n,shortest_time_of_all_teams);
	return 0;
}

