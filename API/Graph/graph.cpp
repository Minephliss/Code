#include "c_graph.h"
#include <fstream>
using namespace std;
int main()
{
    fstream fin("input2");
    Graph G(cin);
    CC cc(G);
    G.print(cout);
    cout << cc.rcount() << " components\n";
    for (int c = 0; c < cc.rcount(); c++, cout << endl)
        for (int i = 0; i < G.rV(); i++)
            if (cc.rid(i) == c)
                cout << i << ' ';

    Cycle cycle(G);
    if (cycle.rcycle())
        cout << "Cycled." << endl;
    else
        cout << "Uncycled" << endl;

    TwoColor tc(G);
    if (tc.isColors())
        cout << "Is two-color" << endl;
    else
        cout << "Isn't two-color" << endl;

    /*
    int start, target;
    fstream fin("input");
    Graph G(cin);
    G.print(cout);
    cout << "start and target\n";
    cin >> start >> target;
    Search search(G, start, (SearchMode)BFS);
    search.printPath(target, cout);
    */
    /*   cout << "SelfLoops: " << G.number0SelfLoops() << endl;
    int v;
    cin >> v;
    cout << G.degree(v) << endl;
    vector<int> node = G.radj(v);
    for (int w = 0; w < node.size(); w++)
	cout << node[w] << ' ';
    cout << endl;
    cout << "maxDegree is: " << G.maxDegree() << endl;*/
    return 0;
}
