#include "c_dgraph.h"

int main()
{
    DiGraph G(cin);
    G.print(cout);
    SCC scc(G);
    scc.print(cout, G);
    return 0;
}
