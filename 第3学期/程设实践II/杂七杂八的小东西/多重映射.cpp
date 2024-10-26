#include <iostream>
#include <map>
using namespace std;
int main (void) {
    multimap<string, int> msi;
    msi.insert (make_pair ("�ŷ�", 80));
    msi.insert (make_pair ("����", 70));
    msi.insert (make_pair ("����", 60));
    msi.insert (make_pair ("�ŷ�", 50));
    msi.insert (make_pair ("����", 40));
    msi.insert (make_pair ("����", 30));
    typedef multimap<string, int>::
        iterator IT;
    for (IT it = msi.begin (); it !=
        msi.end (); ++it)
        cout << it->first << "��"
            << it->second << endl;
    cout << "--------" << endl;
    pair<IT, IT> res = msi.equal_range (
        "�ŷ�");
    int sum = 0;
    for (IT it = res.first; it !=
        res.second; ++it)
        sum += it->second;
    cout << "�ŷɣ�" << sum << endl;
    return 0;
}
