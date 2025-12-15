#include<iostream>
#include<string>
using namespace std;
class myString
{
private:
    string mainstr; // 串
    int size;       // 串长度
    void GetNext(string p, int next[]);//求出next数组
    int KMPFind(string p, int pos, int next[]);//模式串匹配
public:
    myString();
    ~myString();
    void SetVal(string sp);
    int KMPFindSubstr(string p, int pos);

};
myString::myString()
{
    size = 0;
    mainstr = "";
}
myString::~myString()
{
    size = 0;
    mainstr = "";
}
void myString::SetVal(string sp)
{
    mainstr = "";
    mainstr.assign(sp);
    size = mainstr.length();
}
void myString::GetNext(string p, int next[]) {
    int m = p.size();
    next[0] = -1;
    int i = 0, j = -1;
    while (i < m - 1) {
        if (j == -1 || p[i] == p[j]) {
            next[++i] = ++j;
        }
        else {
            j = next[j];
        }
    }
}
int myString::KMPFind(string p, int pos, int next[]) {
    int m = p.size();//模式串
    int n = size;//主串
    if (pos < 0 || pos >= n || m == 0) {
        return 0;
    }
    int i = pos;
    int j = 0;
    while (i < n && j < m) {
        if (j == -1 || mainstr[i] == p[j]) {
            i++;
            j++;
        }
        else {
            j = next[j];
        }
    }
    return (j == m) ? (i - j + 1) : 0;
}
int myString::KMPFindSubstr(string p, int pos)
{
    int i;
    int L = p.length();
    int* next = new int[L];
    GetNext(p, next);
    for (i = 0; i < L; i++)
        cout << next[i] << ' ';
    cout << endl;
    int v = -1;
    v = KMPFind(p, pos, next);
    delete[]next;
    return v;
}
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string mainstr, pattern;
        getline(cin, mainstr);
        getline(cin, pattern);
        myString str;
        str.SetVal(mainstr);
        int result = str.KMPFindSubstr(pattern, 0);
        cout << result << endl;
    }
    return 0;
}
