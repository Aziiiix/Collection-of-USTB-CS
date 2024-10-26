#include <iostream>
#include <map>
using namespace std;
int main (void) {
    multimap<string, int> msi;
    msi.insert (make_pair ("ÕÅ·É", 80));
    msi.insert (make_pair ("ÕÔÔÆ", 70));
    msi.insert (make_pair ("¹ØÓğ", 60));
    msi.insert (make_pair ("ÕÅ·É", 50));
    msi.insert (make_pair ("ÕÔÔÆ", 40));
    msi.insert (make_pair ("¹ØÓğ", 30));
    typedef multimap<string, int>::
        iterator IT;
    for (IT it = msi.begin (); it !=
        msi.end (); ++it)
        cout << it->first << "£º"
            << it->second << endl;
    cout << "--------" << endl;
    pair<IT, IT> res = msi.equal_range (
        "ÕÅ·É");
    int sum = 0;
    for (IT it = res.first; it !=
        res.second; ++it)
        sum += it->second;
    cout << "ÕÅ·É£º" << sum << endl;
    return 0;
}
