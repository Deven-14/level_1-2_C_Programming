#include<stdio.h>
struct hobbit
{
	int speed; //attribute of hobbit is speed
};
typedef struct hobbit Hobbit;
struct hobbit_team   //hobbit team consist of 2 attributes, hobbits and time to cross by that team
{
	//int n; if we have to accept number of hobbits in a team, then next line will be Hobbit team[n];
	Hobbit team_member[4];  // 4 hobbit team members are present, instead of team_member1, team_member 2,...i made it an array
	int time_to_cross; //time to cross for each hobbit team
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
void hobbitpair_1stbridge_crossing(int n,int i,Hobbit_team t[n],Hobbit_pairs p1[6])
{
    p1[0].a.speed=t[i].team_member[1].speed;
    p1[0].b.speed=t[i].team_member[2].speed;
    p1[1].a.speed=t[i].team_member[1].speed;
    p1[1].b.speed=t[i].team_member[3].speed;
    p1[2].a.speed=t[i].team_member[1].speed;
    p1[2].b.speed=t[i].team_member[4].speed;
    p1[3].a.speed=t[i].team_member[2].speed;
    p1[3].b.speed=t[i].team_member[3].speed;
    p1[4].a.speed=t[i].team_member[2].speed;
    p1[4].b.speed=t[i].team_member[4].speed;
    p1[5].a.speed=t[i].team_member[3].speed;
    p1[5].b.speed=t[i].team_member[4].speed;
}
void hobbitpair_3rdbridge_crossing(int n,int i,int j,Hobbit_pairs t[n],Hobbit_pairs p3[3])
{
	if(j==0)
	{
		p3[0].a.speed=t[i].team_member[1].speed;
		p3[0].b.speed=t[i].team_member[3].speed;
		p3[1].a.speed=t[i].team_member[1].speed;
		p3[1].b.speed=t[i].team_member[4].speed;
		p3[2].a.speed=t[i].team_member[3].speed;
		p3[2].b.speed=t[i].team_member[4].speed;
	}
	else if(j==1||j==3)
	{
		p3[0].a.speed=t[i].team_member[1].speed;
		p3[0].b.speed=t[i].team_member[2].speed;
		p3[1].a.speed=t[i].team_member[1].speed;
		p3[1].b.speed=t[i].team_member[4].speed;
		p3[2].a.speed=t[i].team_member[2].speed;
		p3[2].b.speed=t[i].team_member[4].speed;
	}
	else
	{
		p3[0].a.speed=t[i].team_member[1].speed;
		p3[0].b.speed=t[i].team_member[2].speed;
		p3[1].a.speed=t[i].team_member[1].speed;
		p3[1].b.speed=t[i].team_member[3].speed;
		p3[2].a.speed=t[i].team_member[2].speed;
		p3[2].b.speed=t[i].team_member[3].speed;
	}
}
Hobbit_pairs hobbitpair_5thbridge_crossing(int n, int i,int j,int k,int bridge_crossing[5], Hobbit_team t[n], Hobbit_pairs p5)
{
	p5.b.speed=bridge_crossing[4];
	if(j==0)
	{
		if(k==0)
			p5.a.speed=t[i].team_member[4].speed;
		else if(k==1)
			p5.a.speed=t[i].team_member[3].speed;
		else
			p5.a.speed=t[i].team_member[1].speed;
	}
	else if(j==1 || j==3)
	{
		if(k==0)
			p5.a.speed=t[i].team_member[4].speed;
		else if(k==1)
			p5.a.speed=t[i].team_member[2].speed;
		else
			p5.a.speed=t[i].team_member[1].speed;
	}
	else
	{
		if(k==0)
			p5.a.speed=t[i].team_member[3].speed;
		else if(k==1)
			p5.a.speed=t[i].team_member[2].speed;
		else
			p5.a.speed=t[i].team_member[1].speed;
	}
	return p5; // we have to return p5 because p5 is not an array of structures and hence will not behave as call b reference
}
int compute_shortest_time_to_cross(int n,int i,int l,int bridge_crossing[5], Hobbit_team t[n],Hobbit_pairs p1[6],Hobbit_pairs p3[3],Hobbit_pairs p5)
{
    int j,k,shortest_time,allpossible_timevalues_eachloop[18];
    hobbitpair_1stbridge_crossing(n,i,t,p1);
    for(j=0;j<6;j++)
    {
        bridge_crossing[1]=p1[j].b.speed;
        bridge_crossing[2]=p1[j].a.speed;   // because the shortest time taking one comes back
        hobbitpair_3rdbridge_crossing(n,i,j,t,p3);
        for(k=0;k<3;k++)
        {
            bridge_crossing[3]=p3[k].b.speed;
            bridge_crossing[4]=(p3[k].b.speed<=p3[k].a.speed)?((p3[k].b.speed<=bridge_crossing[1])?p3[k].b.speed:bridge_crossing[1]):((p3[k].a.speed<=bridge_crossing[1])?p3[k].a.speed:bridge_crossing[1]); //because we have to check the smallest one of the 3 who have reached the other side and not b1,b2,b2,coz b2 not necessarily go in the third pair
            p5=fifthpair(n,i,j,k,bridge_crossing,t,p5);
            if(p5.a.speed>p5.b.speed)
                bridge_crossing[5]=p5.a.speed;
            else
                bridge_crossing[5]=p5.b.speed;
            t[i].time_to_cross=bridge_crossing[1]+bridge_crossing[2]+bridge_crossing[3]+bridge_crossing[4]+bridge_crossing[5];
            allpossible_timevalues_eachloop[l]=t[i].time_to_cross;
            l++;
        }
    }
    shortest_time=allpossible_timevalues_eachloop[0];
    for(i=0;i<l;i++)
    {
        if(allpossible_timevalues_eachloop[i]<shortest_time)
            shortest_time=allpossible_timevalues_eachloop[i];
    }
    return shortest_time;
}
int compute_shortest_time_to_cross_of_allteams(int n, Hobbit_team t[n], Hobbit_pairs p1[6],Hobbit_pairs p3[3],Hobbit_pairs p5,int bridge_crossing[5],int shortest_time_of_allteams[n])
{
    int i,l=0,shortest_time;
	for(i=0;i<n;i++)
	{
		shortest_time=compute_shortest_time_to_cross(i,l,n,hobbit,p1,p3,p5,bridge_crossing);
		shortest_time_of_allteams[i]=shortest_time;
		l=0; // it's needed because in the next input the loop should start again
	}
}

int main()
{
	int n=get_no_teams();
	struct hobbit h;
	struct hobbit_team t[n];
	struct hobbit_pairs p1[6],p3[3],p5;
	int bridge_crossing[5];
	int shortest_time_of_allteams[n];
	input_hobbit_teams(n,t);
	compute_shortest_time_to_cross_of_allteams(n,t,p1,p3,p5,bridge_crossing,shortest_time_of_allteams);
	output_shortest_time_of_allteams(n,shortest_time_of_allteams);
	return 0;
}



void output(int n,int shortesttime_eachloop[n])
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",shortesttime_eachloop[i]);
}
int main()
{
	int n;
	n=input_numofloops();
	int shortest_time_eachloop[n];
	int t[i].team_member[].speed6];
	int bridge_crossing[5];
	Pairs p1[6],p3[3],p5;
	shortest_time_eachloop_func(n,hobbit,p1,p3,p5,bridge_crossing,shortest_time_eachloop);
	output(n,shortest_time_eachloop);
	return 0;
}
