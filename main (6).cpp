#include <iostream>
#include <vector>

using namespace std;

void feltolt(vector<vector<double> >& napok, int s, int o) {
    for(int i = 0; i < s; i++) {
        vector<double> temp;
        double m[s][o];
        for(int j = 0; j < o; j++) {
            cin >> m[i][j];
            temp.push_back(m[i][j]);
        }
    napok.push_back(temp);
    }
}
void sorokatRendez(vector<vector<double> >& napok, int sor, int oszlop){
    for(int i = 0; i < sor; i++) {
        for(int j = 0; j < oszlop-1; j++) {
            for(int k = j+1; k < oszlop; k++) {
                if (napok[i][j]>napok[i][k]) {
                    int temp=napok[i][j];
                    napok[i][j]=napok[i][k];
                    napok[i][k]=temp;
                }
            }
        }
    }

}
void atlag(vector<vector<double> > napok, vector<double>& aktLegtobb, int sor, int oszlop) {
    int db;
    for(int i = 0; i < sor; i++) {
    db = 1;
        for(int j = 0; j < oszlop; j++) {
            if(napok[i][j] == napok[i][j+1]) {
               aktLegtobb.push_back(napok[i][j]);
                db++;
            }
        }
    }
}
void melegebbNapok(vector<vector<double> > napok, vector<double> atlagNap, vector<int>& holMennyi, int sor, int oszlop) {
    int db;
    for(int i = 0; i < sor; i++) {
    db = 0;
        for(int j = 0; j < oszlop; j++) {
            int k = i;
            while(k < atlagNap.size() && atlagNap[k] > napok[i][j]) {
            cout <<"AtlagNap: "<<atlagNap[k] << endl;
                if(napok[i][j] < atlagNap[k]) {
                cout << endl <<"napok: "<<napok[i][j] << endl;
                    db++;
                    k++;
                   break;
                }
            }
        }
    holMennyi.push_back(db);
    }
}
int holLegtobb(vector<int> holMennyi) {
    int mh = holMennyi[0];

    for(int i = 0; i < holMennyi.size(); i++) {
        if(holMennyi[i] > holMennyi[mh]) {
            mh = i+1;
        }
    }

    return mh;
}

int main()
{
    int sor,oszlop;

    cin >> sor >> oszlop;

    vector<vector<double> >napok;
    vector<double> melyNapok;
    vector<double> felettiNapok;
    vector<double> atlagNap;
    vector<int> atlagMelegebb;
    vector<int> atlagHidegebb;

    feltolt(napok, sor, oszlop);
    sorokatRendez(napok, sor, oszlop);
    cout << endl;

    atlag(napok,melyNapok,sor, oszlop);

    for(int i = 0; i < melyNapok.size(); i++) {
        if(melyNapok[i] != melyNapok[i+1]) {
            atlagNap.push_back(melyNapok[i]);
        }
    }

    melegebbNapok(napok,atlagNap,atlagMelegebb,sor,oszlop);

    for(int i = 0; i < atlagMelegebb.size(); i++) {
        cout << atlagMelegebb[i] << " ";
    }

    return 0;
}
