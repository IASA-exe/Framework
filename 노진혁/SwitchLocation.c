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
    int k,l;
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
    int f1a,f1b,f2a,f2b,s1a,s1b,s2a,s2b;
    printf("바꿀 첫 번째 영역을 입력하세요! 크기 순으로 입력하세요!");
    scanf("%d %d %d %d",&f1a,&f1b,&f2a,&f2b);
    printf("바꿀 두 번째 영역을 입력하세요!\n단, 기술력의 한계로 같은 넓이를 입력해야 한답니다!");
    scanf("%d %d %d %d",&s1a,&s1b,&s2a,&s2b);

    color temp[1010][1010] = {0};
    for(k=f1a;k<f2a;k++)
    {
        for(l=f1b;l<f2b;l++)
        {
            temp[k][l].b = in[k][l].b;
            temp[k][l].g = in[k][l].g;
            temp[k][l].r = in[k][l].r;
        }
    }
    for(k=s1a;k<s2a;k++)
    {
        for(l=s1b;l<s2b;l++)
        {
            in[k-s1a+f1a][l-s1b+f1b].b = in[k][l].b;
            in[k-s1a+f1a][l-s1b+f1b].g = in[k][l].g;
            in[k-s1a+f1a][l-s1b+f1b].r = in[k][l].r;
        }
    }
    for(k=f1a;k<f2a;k++)
    {
        for(l=f1b;l<f2b;l++)
        {
            in[k-f1a+s1a][l-f1b+s1b].b = temp[k][l].b;
            in[k-f1a+s1a][l-f1b+s1b].b = temp[k][l].b;
            in[k-f1a+s1a][l-f1b+s1b].b = temp[k][l].b;
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

     for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    OutArr[i, j].r = InArr[i, j].g;
                    OutArr[i, j].g = InArr[i, j].b;
                    OutArr[i, j].b = InArr[i, j].r;
                }
            }

    return 0;
}
