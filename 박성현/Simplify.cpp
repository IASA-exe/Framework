#include<stdio.h>
#include<stdlib.h>
FILE*fin=fopen("input.bmp","rb");
FILE*fout=fopen("output.bmp", "wb");
FILE*pin=fopen("palete.txt", "r");
int n,m,pn;
struct color
{
    int r,b,g;
};
color in[1010][1010],pal[1010];
void palete(int x,int y)
{
    int i,similarity[1010],mn;
    mn=0;
    similarity[0]=1010;
    for(i=1;i<=pn;i++)
    {
        similarity[i]=abs(pal[i].b-in[x][y].b);
        similarity[i]+=abs(pal[i].g-in[x][y].g);
        similarity[i]+=abs(pal[i].r-in[x][y].r);
    }
    for(i=1;i<=pn;i++)
    {
        if(similarity[mn]>similarity[i]) mn=i;
    }
    in[x][y].b=pal[mn].b;
    in[x][y].g=pal[mn].g;
    in[x][y].r=pal[mn].r;
    return;
}
int main()
{
    int i,j,temp;
    fscanf(pin,"%d",&pn);
    scanf("%d %d",&n,&m);
    for(i=1;i<=pn;i++)
    {
        fscanf(pin, "%d %d %d",&pal[i].b,&pal[i].g,&pal[i].r);
    }
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
            palete(i,j);
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            temp=in[i][j].b+in[i][j].g+in[i][j].r;
            temp/=3;
            putc(temp/2+in[i][j].b/2,fout);
            putc(in[i][j].g/2+temp/2,fout);
            putc(in[i][j].r/2+temp/2,fout);
        }
    }
}
