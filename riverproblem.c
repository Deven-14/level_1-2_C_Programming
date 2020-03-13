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
	Hobbit team_member[4];  // 4 hobbit team members are present, instead of team_member1, team_member 2,...i made it an array
	int st; //time to cross for each hobbit team
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
int find_next_pair_to_travel(int i,int j,int k,int *z,int n,int hob_r[*z],Hobbit_team t[n],Hobbit_pairs p)
{
    p.a.speed=t[i].team_member[j].speed;
    p.b.speed=t[i].team_member[k].speed;
    hob_r[*z]=p.a.speed;
    hob_r[*z++]=p.b.speed;
    *z+=2;
    return p.b.speed;
}
int hobbits_who_reached(int *z,int hob_r[*z],Hobbit_pairs p)
{
    int j,k;
    for(j=0;j<*z;j++)
        if(hob_r[j]==p.b.speed)
        if(hob_r[j]==p.b.speed)
            k=j;
    return k;
}
int find_which_hobbit_returns(int i,int n,int *z,Hobbit_team t[n],int hob_r[*z],Hobbit_pairs p)
{
    int hobbit_returning,j,l;
    hobbit_returning=hob_r[0];
    for(j=0;j<4;j++)
        if(hob_r[j]<hobbit_returning)
        {
            hobbit_returning=hob_r[j];
            l=j;
        }
    for(j=l;j<*z;j++)
        hob_r[j]=hob_r[j+1];
    *z--;
    return hobbit_returning;
}
void t_func(int i,int n,Hobbit_team t[n],int *z,int hob_r[*z],int b_cross[5],Hobbit_pairs p,int all_t_val_each_team[100])
{
    int j,k,l,m,s,q,r1,r2,y,x=0,t_c=0; //,l=0
    for(j=0;j<4;j++)
        for(k=j+1;k<4;k++)
        {
            b_cross[0]=find_next_pair_to_travel(i,j,k,z,n,hob_r,t,p);
            b_cross[1]=find_which_hobbit_returns(i,n,z,t,hob_r,p);
            //l+=2;
            r1=hobbits_who_reached(z,hob_r,p);
            for(l=0;l<4;l++)
                for(m=l+1;m<4;m++)
                {
                    if(hob_r[r1]!=t[i].team_member[l].speed && hob_r[r1]!=t[i].team_member[m].speed)
                    {
                        b_cross[3]=find_next_pair_to_travel(i,l,m,z,n,hob_r,t,p);
                        b_cross[4]=find_which_hobbit_returns(i,n,z,t,hob_r,p);
                        //l+=2;
                        r2=hobbits_who_reached(z,hob_r,p);
                    }
                    for(s=0;s<4;s++)
                        for(q=s+1;q<4;q++)
                            if(hob_r[r1]!=t[i].team_member[s].speed && hob_r[r1]!=t[i].team_member[q].speed && hob_r[r2]!=t[i].team_member[s].speed && hob_r[r2]!=t[i].team_member[q].speed)
                                b_cross[5]=find_next_pair_to_travel(i,s,q,z,n,hob_r,t,p);
                    for(y=0;y<5;y++)
                        t_c+=b_cross[y];
                    all_t_val_each_team[x]=t_c;
		    x++;
                    //l++;
                }
        }
}
int copmpute_st(int i,int n,int *z,int b_cross[5],int hob_r[*z],Hobbit_team t[n],Hobbit_pairs p)
{
    int m,all_t_val_each_team[100];
    t_func(i,n,t,z,hob_r,b_cross,p,all_t_val_each_team);
    t[i].st=all_t_val_each_team[0];
    for(m=0;m<*z;m++)
    {
        if(all_t_val_each_team[m]<t[i].st)
            t[i].st=all_t_val_each_team[m];
    }
    return t[i].st;
}
void compute_st_all_t(int n,int *z,Hobbit_team t[n],Hobbit_pairs p,int hob_r[*z],int b_cross[5],int st_all_t[n])
{
    int i;
    for(i=0;i<n;i++)
    {
        st_all_t[i]=copmpute_st(i,n,z,b_cross,hob_r,t,p);
    }
}
void output_st_all_t(int n,int st_all_t[n])
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",st_all_t[i]);
}
int main()
{
	int n=get_no_teams();
	Hobbit_team t[n];
	Hobbit_pairs p;
	int b_cross[5];
	int z=0;
	int hob_r[z];
	int st_all_t[n];
	input_hobbit_teams(n,t);
	compute_st_all_t(n,&z,t,p,hob_r,b_cross,st_all_t);
	output_st_all_t(n,st_all_t);
	return 0;
}
