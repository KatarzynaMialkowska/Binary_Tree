#include <iostream>
#include <ctime>
#include <random>
#include <iomanip>
#include <sstream>
#include <stdlib.h>     /* exit, EXIT_FAILURE */



int main(int argc, char *argv[])
{
    int n, max;
    if(argc==3){
        for (int i = 1; i <= 2; i++) {
            if (!isdigit(*argv[i])) {
                 std::cout << "ARGUMENTS MUST BE NUMBER\n";
                exit(EXIT_FAILURE);
            }
        }

       std::istringstream iss1( argv[1] );
       if (iss1 >> n){}
        std::istringstream iss2( argv[2] );
       if (iss2 >> max){}

    }else{

        std::cout << "WRONG NUMBER OF ARGUMENTS\nnumber of draws<n> makximum range<max>\n";
        exit (EXIT_FAILURE);

    }

    std::uniform_int_distribution<int> dist1 ( 0, max ); 
    std::mt19937 gen ( time ( NULL ) ); // pseudo-random generator Mersenne Twister 32bit
    
    std::cout<<n<<"\n";
    for( int i = 0; i < n; i++ ) {
         std::cout << dist1(gen) << '\n';
    }
 
    return 0;
} 