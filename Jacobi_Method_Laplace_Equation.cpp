
#include <bits/stdc++.h>
using namespace std;

const int N = 4;

int gaussJacobi(double u[4][4], int max_itr, double tol)
{
    double old_u[4][4];

    int itr = 0;
    double max_diff = tol + 1.0;

    while(itr < max_itr && max_diff > tol)
    {
        max_diff = 0.0;

        // Store previous iteration values
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
                old_u[i][j] = u[i][j];
        }

        // Calculate new values using old values only
        for(int i = 1; i < N-1; i++)
        {
            for(int j = 1; j < N-1; j++)
            {
                u[i][j] = 0.25 * (
                    old_u[i-1][j] + old_u[i+1][j] +
                    old_u[i][j-1] + old_u[i][j+1]
                );

                double diff = fabs(u[i][j] - old_u[i][j]);

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

    // Boundary conditions
    for(int i = 0; i < N; i++)
        u[0][i] = 12.4;
u[0][0]=u[0][3]=0;
    int itr = gaussJacobi(u, 1000, 1e-6);

    cout << fixed << setprecision(6);

    cout << "\nJacobi Method - Laplace Equation\n";
    cout << "Five Point Finite Difference Method\n\n";

    if(itr == -1)
    {
        cout << "Solution did not converge!\n";
        return 0;
    }

    cout << "Convergence : Successful\n";
    cout << "Iterations  : " << itr << endl;
    cout << "Tolerance   : " << 1e-6 << endl;

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
