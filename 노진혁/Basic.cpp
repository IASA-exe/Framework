#include<stdio.h>
FILE*fin=fopen("input.txt", "rb");
FILE*fout=fopen("output.bmp", "wb");
struct Pixel
{
    int b,r,g,a;
};
Pixel InArr[1010][1010];
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
            InArr[i][j].b=getc(fin);
            InArr[i][j].g=getc(fin);
            InArr[i][j].r=getc(fin);
        }
    }//don't touch!
    //put your code
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            putc(InArr[i][j].b,fout);
            putc(InArr[i][j].g,fout);
            putc(InArr[i][j].r,fout);
        }
    }
    return 0;
}
