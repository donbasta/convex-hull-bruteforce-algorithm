#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>
#include <cmath>
// #include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

//KAMUS

//KONSTANTA
//Maksimal nilai absis dan ordinat
const long long MAX = 1e3;

//ADT TITIK
struct Point {
    long long X;
    long long Y;
    Point() : X(0), Y(0) {}
    Point(const long long& x, const long long& y) : X(x), Y(y) {}
    bool operator<(const Point& q) const {return (X<q.X || (X==q.X && Y<q.Y));}
    bool operator!=(const Point& q) const {return (X!=q.X || Y!=q.Y);}
    bool turn_right(Point q, Point r){
        long long cek = (X*q.Y+q.X*r.Y+r.X*Y)-(Y*q.X+q.Y*r.X+r.Y*X);
        return (cek<0);
    }
    bool collinear(Point q, Point r){
        long long cek = (X*q.Y+q.X*r.Y+r.X*Y)-(Y*q.X+q.Y*r.X+r.Y*X);
        return (cek==0);
    }
    bool on_segment(Point q, Point r){
        long long x1 = r.X-X;
        long long x2 = q.X-X;
        long long y1 = r.Y-Y;
        long long y2 = q.Y-Y;
        long long det = x1*y2-x2*y1;
        return (det==0 && x1*x2<=0 && y1*y2<=0);
    }
} ;

//VARIABEL
int banyak_titik;
int titik_kanan;
int titik_segaris;
bool point_on_segment;
std::vector<Point> points;
std::vector< std::pair<Point,Point> > convex_hull;
std::map<Point, Point> next;
std::map< std::pair<int,int>, bool> side;

//PROSEDUR GENERATOR TITIK ACAK
void generate_titik(int N){
    //KAMUS LOKAL
    Point P;
    int x,y;
    int current_picked = 0;
    std::map<Point, bool> picked;
    //ALGORITMA
    srand(time(NULL));
    while(current_picked < N){
        x = rand()%(2*MAX-1)-MAX;
        y = rand()%(2*MAX-1)-MAX;
        P = Point(x,y);
        if (!picked[P]){
            picked[P] = true;
            points.push_back(P);
            current_picked++;
        }
    }
}

void output_titik(){
    //KAMUS LOKAL
    int boundary = (int) convex_hull.size();
    Point P0, P;
    int current = 0;
    //ALGORITMA
    std::cout << "Terdapat " << boundary << " titik yang membentuk convex hull pada himpunan titik yang dibangkitkan.\n";
    std::cout << "Titik-titik yang membentuk convex hull tersebut dalam urutan searah jarum jam adalah:\n";
    P0 = P = convex_hull[0].first;
    while(current < boundary){
        std::cout << P.X << ' ' << P.Y << '\n';
        P = next[P];
        current++;
    }
    if(P != P0) {std::cout << P.X << ' ' << P.Y << '\n';}
}

//PROGRAM UTAMA
int main(){

    std::cin >> banyak_titik;
    // generate_titik(banyak_titik);
    
    //MANUAL INPUT FOR DEBUG
    for(int i=0; i<banyak_titik; i++){
        long long x,y;
        std::cin >> x >> y;
        Point P = Point(x,y);
        points.push_back(P);
    }

    //ALGORITMA PENCARIAN CONVEX HULL
    for(int i=0; i<banyak_titik; i++){
        for(int j=0; j<banyak_titik; j++){
            if(i!=j){
                point_on_segment = false;
                titik_kanan = 0;
                titik_segaris = 0;
                for(int k=0; k<banyak_titik; k++){
                    if(k!=i && k!=j){
                        if ( points[i].turn_right(points[j],points[k]) ){
                            titik_kanan++;
                        }
                        if ( points[i].collinear(points[j],points[k]) ){
                            titik_segaris++;
                            if( points[k].on_segment(points[i],points[j]) ){
                                point_on_segment = true;
                            }
                        }
                    }
                } 
                if(titik_kanan + titik_segaris == banyak_titik-2){
                    if(!point_on_segment && !side[std::make_pair(j,i)] ){
                        convex_hull.push_back( std::make_pair(points[i],points[j]));
                        next[points[i]] = points[j];
                        side[std::make_pair(i,j)] = true;
                    }
                }
            }
        }
    }

    output_titik();

    // //OUTPUT CONVEX SIDES FOR DEBUGGING
    // for(auto i : convex_hull){
    //     std::cout << i.first.X << ' ' << i.first.Y << ' ' << i.second.X << ' ' << i.second.Y << '\n';
    // }

}