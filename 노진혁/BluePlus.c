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
    int i,j;
    scanf("%d %d",&n,&m);
    for(i=1;i<=54;i++)
    {
        putc(getc(fin),fout);
    }//don't touch!
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            in[i][j].b=getc(fin);
            in[i][j].g=getc(fin);
            in[i][j].r=getc(fin);
        }
    }//don't touch!
    //put your code
    for(i=1;i<=n;i++)
    {
        for(j=1;j<m;j++)
        {
            in[i][j].b+=5;
            in[i][j].g+=2;
            in[i][j].r-=1;
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            putc(in[i][j].b,fout);
            putc(in[i][j].g,fout);
            putc(in[i][j].r,fout);
        }
    }
    return 0;
}
