#include<stdio.h>
#include<stdlib.h>
#include<math.h>
FILE*fin=fopen("input.bmp","rb");
FILE*fout=fopen("output.bmp", "wb");
int n,m;
struct color
{
    int r,b,g;
};
color in[1010][1010];
int main()
{
    int i,j;
    double x,y,z;
    scanf("%d %d",&n,&m);
    for(i=1;i<=54;i++)
    {
        putc(getc(fin),fout);
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            in[i][j].b=getc(fin);
            in[i][j].g=getc(fin);
            in[i][j].r=getc(fin);
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            x=(double)abs((i-n/2))/n;
            y=(double)abs(j-m/2)/m;
            z=x*x+y*y;
            if(z>0.35)
            {
                in[i][j].b=in[i][j].b*(0.5-z)*20/3;
                in[i][j].g=in[i][j].g*(0.5-z)*20/3;
                in[i][j].r=in[i][j].r*(0.5-z)*20/3;
            }
            putc(in[i][j].b,fout);
            putc(in[i][j].g,fout);
            putc(in[i][j].r,fout);
        }
    }
}
