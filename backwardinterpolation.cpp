
#include <iostream>
#include <conio.h>
using namespace std;

class NewtonBackward
{
public:
    void askN();
    void askX();
    void askF();
    void askXX();
    void forwardTable();
    void calcP();
    void findH();
    void findS();
private:
    double XX, x[10] , f[10][10] , p[10],diff[5][5],P1;
    int n;
    double h,s;

};

void NewtonBackward::askX()
{
    cout << endl;
    for(int i = 0; i<n; i++ )
    {
        cout << "ENter X[" << i  << "] : ";
        cin >> x[i];
    }
    cout << endl;
}

void NewtonBackward::askF()
{

    for(int j = 0; j<n; j++ )
    {
        cout << "ENter F[" << j  << "] : ";
        cin >> f[0][j];
    }
    cout << endl;
}
void NewtonBackward::askXX()
{

    cout << "Enter X for which the value is to be found: ";
    cin >> XX;
}

void NewtonBackward::forwardTable()
{
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j< n-i;j++)
        {
            f[i][j] = (f[i-1][j+1]-f[i-1][j]);
        }
    }
    cout << endl;
    cout << "Sn\tXi\tf(Xi)\t";
    for(int i = 0; i <n-1;i++)
    {
        cout << i+1 << " diff\t";
    }
    cout << endl;
    for(int i = 0; i < n; i++)
    {
         cout <<i+1 <<"\t" << x[i]<< "\t";
        for(int j = 0; j< n-i;j++)
        {
            cout  << f[j][i] << "\t";
        }
        cout << endl;
    }
}

void NewtonBackward::findH()
{
    h = x[1] - x[0];
}
void NewtonBackward::findS()
{
    s = (XX - x[n-1])/h;
}
void NewtonBackward::calcP()
{
    findH();
    findS();

    P1 = f[0][n-1];
    for(int i = 1;i<n;i++)
    {
        double k = s;
        for(int j = 1; j<i;j++)
        {
            k *= (s+j) * 1/(j+1);
        }
        k*=f[i][n-i-1];
        P1 += k ;

    }
    cout <<endl << "The value of P" << n-1 << "(" << XX << "): "  <<P1 << endl << endl;
}

void NewtonBackward::askN()
{
    cout << "Enter the number of values: ";
    cin >> n;
}
int main()
{

    NewtonBackward d1;
    d1.askN();
    d1.askX();
    d1.askF();
    d1.askXX();
    d1.forwardTable();
    d1.calcP();

}


