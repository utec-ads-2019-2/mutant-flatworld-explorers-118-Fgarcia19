#include <iostream>
#include <vector>
#include <string>
using namespace std;

class robot{
public:
    int x,y,maxx,maxy;
    char orientacion;
    string movimiento;
    bool lost;
    robot(int iniciox,int inicioy,char o,string movimiento,int maxx,int maxy):maxx(maxx),maxy(maxy),lost(false),x(iniciox),y(inicioy),orientacion(o),movimiento(movimiento){}
    void execute(){
        for(auto i:movimiento){
            switch(i){
                case 'R':
                    switch(orientacion){
                        case 'N':
                            orientacion='E';
                            break;
                        case 'S':
                            orientacion='W';
                            break;
                        case 'E':
                            orientacion='S';
                            break;
                        case 'W':
                            orientacion='N';
                            break;
                    }
                    break;
                case 'L':
                    switch(orientacion){
                        case 'N':
                            orientacion='W';
                            break;
                        case 'S':
                            orientacion='E';
                            break;
                        case 'E':
                            orientacion='N';
                            break;
                        case 'W':
                            orientacion='S';
                            break;
                    }
                    break;
                case 'F':
                    switch(orientacion){
                        case 'N':
                            if(x==maxx){
                                lost= true;
                                break;
                            }
                            else
                                x++;
                            break;
                        case 'S':
                            if(x==0){
                                lost= true;
                                break;
                            }
                            else
                                x--;
                            break;
                        case 'E':
                            if(y==maxy){
                                lost= true;
                                break;
                            }
                            else
                                y++;
                            break;
                        case 'W':
                            if(y==0){
                                lost= true;
                                break;
                            }
                            else
                            y--;
                            break;
                    }
                    break;
                default:
                    break;
            }
            if(lost){
                break;
            }
        }
        cout<<x<<" "<<y<<" "<<orientacion;
        if(lost){
            cout<<"LOST"<<endl;
        }

        }

//    }
};

int main() {
    int x_t,y_t,x,y;
    char ori;
    string move;
    cin>>x_t>>y_t;
    while(cin>>x>>y>>ori>>move){
        auto R=new robot(x,y,ori,move,x_t,y_t);
        R->execute();

    }
}