
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const int N = 4;

int gaussSiedal(double u[4][4], int max_itr, double tol)
{
    int itr = 0;
    double max_diff = tol + 1.0;

    while(itr < max_itr && max_diff > tol)
    {
        max_diff = 0.0;

        for(int i = 1; i < N-1; i++)
        {
            for(int j = 1; j < N-1; j++)
            {
                double old_val = u[i][j];

                u[i][j] = 0.25 * (
                    u[i-1][j] + u[i+1][j] +
                    u[i][j-1] + u[i][j+1]
                );

                double diff = fabs(u[i][j] - old_val);

                if(diff > max_diff)
                    max_diff = diff;
            }
        }

        itr++;
    }

    if(max_diff > tol)
        return -1;

    return itr;
}

int main()
{
    double u[4][4] = {0};

    // Boundary condition
    for(int i = 0; i < N; i++)
        u[0][i] = 12.4;
u[0][0]=u[0][3]=0;
    double tol = 1e-6;

    int itr = gaussSiedal(u, 1000, tol);

    cout << fixed << setprecision(6);

    if(itr == -1)
    {
        cout << "Solution did not converge!";
        return 0;
    }

    cout << "\nGauss-Seidel Method - Laplace Equation\n";
    cout << "Five Point Finite Difference Method\n\n";

    cout << "Convergence : Successful\n";
    cout << "Iterations  : " << itr << endl;
    cout << "Tolerance   : " << tol << endl;

    cout << "\nFinal Solution Matrix:\n";

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            cout << setw(10) << u[i][j];

        cout << endl;
    }

    cout << "\nCenter Value u(2,2) = " << u[2][2] << endl;

    return 0;
}
