

namespace Photo_Retouch.UWP
{
    public partial class MainPage
    {
        public Pixel[,] ReverseFilter(Pixel[,] InArr, Pixel[,] OutArr, int row, int col)
        {
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    OutArr[i, j].r = InArr[i, j].g;
                    OutArr[i, j].g = InArr[i, j].b;
                    OutArr[i, j].b = InArr[i, j].r;
                }
            }
            return OutArr;
        }

        public Pixel[,] SwitchLocationFilter(Pixel[,] InArr, Pixel[,] OutArr, int row, int col, int f1a, int f1b, int f2a, int f2b, int s1a, int s1b, int s2a, int s2b,int k,int l)
        {
            scanf("%d %d %d %d", &f1a, &f1b, &f2a, &f2b);
            scanf("%d %d %d %d", &s1a, &s1b, &s2a, &s2b);

            color temp[1010][1010] = {0};
    for(k=f1a;k<f2a;k++)
    {
        for(l=f1b;l<f2b;l++)
        {
            temp[k][l].b = InArr[k] [l].b;
            temp[k][l].g = InArr[k] [l].g;
            temp[k][l].r = InArr[k] [l].r;
        }
}
    for(k=s1a;k<s2a;k++)
    {
        for(l=s1b;l<s2b;l++)
        {
            InArr[k-s1a+f1a] [l-s1b+f1b].b = InArr[k] [l].b;
            InArr[k-s1a+f1a] [l-s1b+f1b].g = InArr[k] [l].g;
            InArr[k-s1a+f1a] [l-s1b+f1b].r = InArr[k] [l].r;
        }
    }
    for(k=f1a;k<f2a;k++)
    {
        for(l=f1b;l<f2b;l++)
        {
            InArr[k-f1a+s1a] [l-f1b+s1b].b = temp[k][l].b;
            InArr[k-f1a+s1a] [l-f1b+s1b].b = temp[k][l].b;
            InArr[k-f1a+s1a] [l-f1b+s1b].b = temp[k][l].b;
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
            return OutArr;
        }
    }
}
