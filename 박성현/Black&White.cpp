#include<stdio.h>
FILE*fin=fopen("input.bmp", "rb");
FILE*fout=fopen("output.bmp", "wb");
struct color
{
    int b,r,g;
};
color in[1010][1010];
int n,m,b[1010][1010],g[1010][1010],r[1010][1010];
int main()
{
    int i,j,t;
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
            t=in[i][j].b+in[i][j].g+in[i][j].r;
            t/=3;
            if(t<100) t=0;
            if(t>150) t=255;
            putc(t,fout);
            putc(t,fout);
            putc(t,fout);
        }
    }
    return 0;
}
