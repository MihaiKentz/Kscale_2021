#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

ifstream f("kscale.in");
ofstream g("kscale.out");


int cmmdc (int nr, int nrmin){
    if (nrmin==1) return 1;
    while(nr!=nrmin)
        if(nr>nrmin)
            nr-=nrmin;
        else
            nrmin-=nr;
        return nr;
}


int main()
{
    int n, m, i, j, nr=INT_MAX, nrmin=1, k2=INT_MAX, k2min=1;
    bool B[101][101];
    f>>n>>m;
    char c;
    for(i=1; i<=n; i++)
        for(j = 1; j <= m; j++) {
            f >> c;
            B[i][j] = (c == '1');
            }

    for(j=2; j<=m; j++)
    {
        //cout<<nrmin<<" ";
        if(B[1][j-1]==B[1][j])
        {
            nrmin++;
            //cout<<B[1][j-1]<<"=="<<B[1][j];
        }

        else
        {
            if(nr!=INT_MAX)
                nr=cmmdc(nr, nrmin);
                else nr=nrmin;
            nrmin=1;
        }
    }
        if(nr!=INT_MAX)
                nr=cmmdc(nr, nrmin);
                else nr=nrmin;



    for(j=2; j<=n; j++)
    {
        //cout<<nrmin<<" ";
        if(B[j-1][1]==B[j][1])
        {
            k2min++;
            //cout<<B[1][j-1]<<"=="<<B[1][j];
        }

        else
        {
            if(k2!=INT_MAX)
                k2=cmmdc(k2, k2min);
                else k2=k2min;
            k2min=1;
        }
    }
        if(k2!=INT_MAX)
                k2=cmmdc(k2, k2min);
                else k2=k2min;
    g<<n/k2<<" ";
    g<<m/nr;
    g<<endl;
    for(i=1; i<=n; i+=k2){
        for(j=1; j<=m; j+=nr)
            g<<B[i][j];
        g<<endl;
    }

}
