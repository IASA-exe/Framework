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
            if(in[i][j].b<100) in[i][j].b=in[i][j].b/2;
            if(in[i][j].g<100) in[i][j].g=in[i][j].g/2;
            if(in[i][j].r<100) in[i][j].r=in[i][j].r/2;
            if(in[i][j].b>200) in[i][j].b=in[i][j].b/2+128;
            if(in[i][j].g>200) in[i][j].g=in[i][j].g/2+128;
            if(in[i][j].r>200) in[i][j].r=in[i][j].r/2+128;
            putc(in[i][j].b,fout);
            putc(in[i][j].g,fout);
            putc(in[i][j].r,fout);
        }
    }
    return 0;
}
