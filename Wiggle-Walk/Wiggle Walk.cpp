#include <iostream>

int main()
{
    //Declaring variables
    int T,N,R,C,r,c;
    int i,j,k,l,m,n;

    //Input no of test cases
    ///std::cout<<"Enter no of Test Cases:";
    std::cin>>T;

    //Array for storing result
    int result[T][2];

    //Operation of each test case
    for(i=0;i<T;i++)
    {
        //Input no of rows columns etc
        //std::cout<<"Enter no Commands,No of Rows,Columns,Current Row,Column:";
        std::cin>>N>>R>>C>>r>>c;

        //Making and initialisation of grid
        int grid[R][C];
        for(j=0;j<R;j++)
        {
            for(k=0;k<C;k++)
            {
                grid[j][k]=0;
            }
        }

        //Marking of current row and column
        grid[r-1][c-1]=1;

        //Input command series
        char command[N];
        //std::cout<<"Enter Commanad series:";
        for(l=0;l<N;l++)
        {
            std::cin>>command[l];
        }

        //Calculating final position
        for(m=0;m<N;m++)
        {
            switch(command[m])
            {
                case 'N':
                again_n:
                r--;
                if(grid[r-1][c-1]==0)
                {
                    grid[r-1][c-1]=1;
                    break;
                }else
                {
                    goto again_n;
                }
                break;

                case 'S':
                again_s:
                r++;
                if(grid[r-1][c-1]==0)
                {
                    grid[r-1][c-1]=1;
                    break;
                }else
                {
                    goto again_s;
                }
                break;

                case 'E':
                again_e:
                c++;
                if(grid[r-1][c-1]==0)
                {
                    grid[r-1][c-1]=1;
                    break;
                }else
                {
                    goto again_e;
                }
                break;

                case 'W':
                again_w:
                c--;
                if(grid[r-1][c-1]==0)
                {
                    grid[r-1][c-1]=1;
                    break;
                }else
                {
                    goto again_w;
                }
                break;
            }
        }

        /*Storing result into array*/
        result[i][0]=r;
        result[i][1]=c;
    }

    //Displaying result
    for(n=0;n<T;n++)
    {
        std::cout<<"Case#"<<n+1<<": "<<result[n][0]<<" "<<result[n][1]<<std::endl;
        std::cout<<std::endl;
    }

    //getch();

    return(0);
}
