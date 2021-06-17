#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

vector<int> genRandom(int n, int m){
    vector<int> vec;
    for (int i=0;i<n;i++){
        int x = rand()%(m+1);
        vec.push_back(x);
    }
    return vec;
}

int * genRandom_v2(int n, int m){
    int *p;
    p =  new int[n*sizeof(int)];

    for (int i=0;i<n;i++){
        int x = rand()%(m+1);
        *(p + i) = x ;
    }
    return p;
}


int vectorReduce(const vector<int> &v1, vector<int> &v2){
    int counter = 0;
    for(size_t i = 0; i < v1.size();i++){
        for(size_t j = 0; j < v2.size();j++){
            if(v1.at(i)==v2.at(j)){
                v2.erase(v2.begin()+j);
                j--;
                counter++;
            }
        }
    }
    return counter;
}

class Game { public:
Game(const string &filename);
int neighborMines(int line, int col) const;// other methods
void show();
private:
vector<vector<char> > mines;
// other attributes
};

Game:: Game(const string &filename){
    ifstream ficheiro(filename);
    int numlines,numcols,x,y;
    char sep;
    bool found = true;
    if(ficheiro.is_open()){
        ficheiro >> numlines >> sep >> numcols;
        mines.resize(numlines);
        for(size_t n = 0; n< mines.size();n++){
            mines.at(n).resize(numcols);
        }
        for (int i=0;i<numlines;i++){
            for (int j=0;j<numcols;j++){
                if (found){
                    ficheiro >> x >> sep >> y;
                    found =false;
                }
                if(i==x && j==y){
                    found = true;
                    mines.at(i).at(j) = 'M';
                }
                else{
                    mines.at(i).at(j) = ' ';
                }
            }
        }
    }

}
int Game:: neighborMines(int line, int col) const{
    int counter = 0;
    if(mines.at(line).at(col)=='M'){
        throw runtime_error("boom");
    }
    else{
        for (int i=-1;i<2;i++){
            for (int j=-1;j<2;j++){
                if(line+i >= 0 && col+j >= 0 && line+i <= mines.size() && col+j <= mines.at(0).size() && mines.at(line+i).at(col+j) == 'M'){
                    counter++;
                }
            }
        }   
    }
    return counter;
}

void Game:: show(){
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            cout << mines.at(i).at(j) << " ";
        }
        cout << "|" << endl;
    }

}

int main(){
    Game game("teste.txt");
    cout << "____________________" << endl;
    game.show();
    cout << "--------------------" << endl;

    int x = game.neighborMines(9,0);
    cout << x << endl;
    return 0;
}