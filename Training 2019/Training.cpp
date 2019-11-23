//Preprocessor directories
#include <iostream>

using namespace std;

//Function Declaration
void bblsrt( int arr[], int N );
int arraySum( int arr[], int from ,int to );

//Main Function
int main()
{
    int T, N, P;
    int i, j;

    //cout << "Enter No of Test Cases : ";
    cin >> T;

    int result[T+1];

    for( i = 1; i <= T; i++ )
    {
        //cout << "Enter Other Info : ";
        cin >> N >> P;

        int skill[N];
        int hour;

        //cout << "Enter Skill Points : ";
        for ( j = 0; j < N; j++ )
        {
            cin >> skill[j];
        }

        bblsrt( skill, N );

        int finalhour = ( P * skill[0] ) - ( arraySum( skill, 0 , (P - 1) ) );

        for( j = 1; j <= N-P; j++ )
        {
            int arrsum = arraySum( skill, j, (j + P - 1) );
            hour = ( P * skill[j] ) - arrsum;

            if( finalhour > hour )
            {
                finalhour = hour;
            }
        }

        result[i] = finalhour;
    }

    for( i = 1; i <= T; i++ )
    {
        cout << "Case #" << i << ": "<< result[i] << endl;
    }

    return 0;
}

//Function Definition
void bblsrt( int arr[], int N )
{
    int temp;
    int i, j;

    for( i = 1; i < N ; i++ )
    {
        for ( j = 0; j < N-i; j++ )
        {
            if( arr[j] < arr[j+1] )
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int arraySum( int arr[], int from, int to )
{
    int i;
    int sum = 0;

    for( i = from; i <= to; i++ )
    {
        sum += arr[i];
    }

    return sum;
}
