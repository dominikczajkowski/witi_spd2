#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


class Task
{
    int p, w, d, s;

public:
    //Task(int P,int W, int D, int S):p(P),w(W),d(D),s(S) {}
    int & _p() {return p;}
    int & _w() {return w;}
    int & _d() {return d;}
    int & _s() {return s;}

};

class Machine
{
    vector<Task> tasks[11];
    vector<int> tbs;
public:
    Machine():tbs(0){}
    void load_tasks();
    void print_tasks();

private:
    int sum_witi();

};



int main()
{
    Machine m;
    m.load_tasks();
    m.print_tasks();
    return 0;
}

void Machine::load_tasks()
{
    fstream f("dane.txt");
    string header;
    int n;
    for(int j=0;j<11;j++)
    {
        f >> header >> n;
        for(int i=0;i<n;i++)
        {
            Task t;
            f >> t._p() >> t._w() >> t._d();
            t._s()=i;
            tasks[j].push_back(t);
        }
    }
    f.close();
}

void Machine::print_tasks()
{
    for(int j=0;j<11;j++)
    {
        for(int i=0;i<static_cast<int>(tasks[j].size());i++)
        {
            cout << tasks[j][i]._p() << " " << tasks[j][i]._w()<< " " << tasks[j][i]._d() << endl; ;
        }
        cout << endl;
    }
}

int Machine::sum_witi()
{
    //tbs[i]=min()
}
