/*---------BINGO---------*/
#include <SFML/Graphics.hpp>
#include<iostream>

using namespace std;
using namespace sf;

int main(){
    RenderWindow mainwindow(VideoMode(800, 700), "PENGO", Style::Close);
    int x=0,y=x,z=y;
    float angle = 0;
    bool rotateposs=1;
    while (mainwindow.isOpen()){//the main game loop
        mainwindow.setPosition(Vector2i(283,0));
        Event event;
        while (mainwindow.pollEvent(event)){//event collecting loop
            switch(event.type){
                case Event::Closed:
                    mainwindow.close();
                    cout<<"Close the window"<<endl;
                    break;
                
            }

        }

        mainwindow.display();
    }

    return 0;
}
