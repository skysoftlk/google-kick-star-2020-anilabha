//Preprocessor Directories
#include <iostream>

using namespace std;

//Function Declaration
bool bblsrt( int arr[], int N, int X );

//Main Function
int  main()
{
    int T,N,M,Q;
    int i;

    //cout << "Enter No of Test Cases : ";
    cin >> T;

    int result[T+1];

    for ( i = 1; i <= T; i++ )
    {
        int sum = 0;
        int j,k;

        //cout << "Enter Other Info : ";
        cin >> N >> M >> Q;

        int m[M];
        int q[Q];

        //cout << "Enter Info (M) : ";
        for( j = 0; j < M; j++ )
        {
            cin >> m[j];
        }

        //cout << "Enter Info (Q) : ";
        for( j = 0; j < Q; j++ )
        {
            cin >> q[j];
        }

        for( j = 0; j < Q; j++ )
        {
            for( k = q[j]; k <= N; k += q[j] )
            {
                if( !bblsrt( m, M, k) )
                {
                    sum++;
                }
            }
        }

        result[i] = sum;
    }

    for( i = 1; i <= T; i++ )
    {
        cout << "Case #" << i <<": " << result[i] << endl;
    }
}

//Function Definition
bool bblsrt( int arr[], int N, int X )
{
    int ll = 0;
    int ul = N;
    int mid = ( ( ll + ul ) / 2 );

    while( ll < ul && arr[mid] != X )
    {
        if ( X > arr[mid] )
        {
            ll = mid + 1;
        }else
        {
             ul = mid - 1;
        }
        mid = ( ( ll + ul ) / 2 );
    }

    if ( arr[mid] == X )
        return true;
    else
        return false;
}
