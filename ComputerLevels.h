#include <bits/stdc++.h>
using namespace std;


int  getRand(vector<int> v){
    int  idx = rand()%v.size();
    vector<int>v2;
    for (int i = 0; i < v.size(); ++i) {
        v2.push_back(v[i]);
    }
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(v2.begin(), v2.end(), default_random_engine(seed));
    return v2.back();
}

pair <int, int> PlayEasy(int g[6][6]){
    vector <pair<int, int>> v;
    int indx;
    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            if (g[i][j]) v.push_back(make_pair(i, j));
        }
    }
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(v.begin(), v.end(), default_random_engine(seed));
    return v.back();
}

pair<int,int> PlayMedium(int g[6][6]){
    set<pair<int,int>> s ;
    for (int i = 0; i < 5 ; ++i) {
        int r=5;
        int c=5;
        for (int j = 0; j <5 ; ++j) {
            if (!g[i][j])r--;//count non zero for row i
            if (!g[j][i])c--;//count non zero for col i
        }
        if (r!=0)
            s.insert(make_pair(r,i));//row i => idx=i;
        if (c!=0)
            s.insert(make_pair(c,i+5));// col i => idx=i+5;
    }
    int  x =(*s.begin()).first;// get min row/col value
    vector<int> v;
    while (!s.empty()){
        if ((*s.begin()).first==x){
            v.push_back((*s.begin()).second);// take all rows/cols have the min value
        } else break;
        s.erase(s.begin());
    }
    int  idx =getRand(v);// get one random from min rows/cols
    if (idx<5){// if it's row
        v.clear();
        // get random idx in the taken row
        for (int i = 0; i <5 ; ++i) {
            if (g[idx][i])
                v.push_back(i);
        }
        int y = getRand(v);
        return {idx,y};
    }
    else{// if it's col
        idx-=5;
        v.clear();
        // get random index in the taken col
        for (int i = 0; i <5 ; ++i) {
            if (g[i][idx])
                v.push_back(i);
        }
        int y = getRand(v);
        return {y,idx};
    }
}

pair<int,int> PlayHard(int g[6][6]){
    set<pair<pair<int,int>,pair<int,int>>> s;// Rem col , Rem row , i , j

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {// loop for every point
            if (!g[i][j])
                continue;
            int r =0;
            int c =0;
            for (int k = 0; k < 5; ++k) { // count rem for the row and the col of the cell.(intersection)
                if (g[i][k]){
                    r++;
                }
                if (g[k][j]){
                    c++;
                }
            }
            s.insert({{min(r,c),max(r,c)},{i,j}});
        }
    }
    vector<int> ids ;
    vector<pair<int,int>> points;
    pair<int,int> min = (*s.begin()).first;
    while (!s.empty()){
        if(min==(*s.begin()).first){
            ids.push_back(ids.size());
            points.push_back((*s.begin()).second);
        }
        else break;
        s.erase(s.begin());
    }

    int bestRandomEver= getRand(ids);
    return points[bestRandomEver];
}

void filltheGrid(int g[6][6]) {
    vector<int> v;
    for (int i = 1; i <= 25; ++i) {
        v.push_back(i);
    }

    for (int i = 0; i < 5; ++i) {
        vector<int> v;
        for (int i = 1; i <= 25; ++i) {
            v.push_back(i);
        }

        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
                shuffle(v.begin(), v.end(), default_random_engine(seed));
                g[i][j] = v.back();
                v.pop_back();
//            remove(v.begin(),v.end(),g[i][j]);
//            v.pop_back();
            }
        }
    }
}

void PrinT(int g[6][6]){
    for (int i = 0; i < 5; ++i) {

        for (int j = 0; j < 5; ++j) {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
}//Printing the grid

void pointsCont(int &points,int grid[6][6]){
    for(int i=0;i<5;i++)
    {
        if(grid[i][5]==5) {
            points++;
            grid[i][5]=-1;
        }
        if(grid[5][i]==5) {
            points++;
            grid[5][i]=-1;
        }
    }
}
