#include <iostream>
#include <fstream>
#include "Matrix.cpp"

using namespace std;

const double alpha = 0.025;

int main() {
    ifstream fin("data.in");
    int m,n;
    fin>>m>>n;
    fin.close();
    cout<<m<<" "<<n<<endl;
    Matrix data(m,n+1);
    data.load_from_file("data.in",2);

    Matrix X = data.slice(1,m,1,n);
    Matrix y = data.slice(1,m,n+1,-1);
    Matrix theta(n,1);
    theta.randomize();

    double cost_coeff = (double)1/(2*m);
    double theta_coeff = (double)alpha/m;
    for(int i=0;i<500;i++){
        theta = theta - ((X.transpose() * (X*theta - y))*theta_coeff);
        double cost = cost_coeff * ((X*theta - y).transpose()*(X*theta-y)).sum();
        cout<<cost<<endl;
    }
    cout<<endl;
    cout<<theta;

    return 0;
}