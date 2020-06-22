/*---------BINGO---------*/
#include <SFML/Graphics.hpp>
#include<iostream>
#include"Button.h"

using namespace std;
using namespace sf;

int main(){
    //-------- start window data -------//
    RenderWindow start_window(VideoMode(700,700),"Start Window",Style::Close);
    start_window.setPosition(Vector2i(0,0));
    Texture background_texture,start_btn_texture;
    background_texture.loadFromFile("full_window.jpg");// to test positions
    //background_texture.loadFromFile("background.jpg");
    start_btn_texture.loadFromFile("start_btn.png");
    RectangleShape background;
    background.setTexture(&background_texture);
    background.setPosition(0,0);
    background.setSize(Vector2f(background_texture.getSize()));
    Button start_btn(&start_btn_texture);
    start_btn.setPosition({240, 196});
    //start_btn.setBackColor(Color(255,255,255,100));
    while(start_window.isOpen()){//strat window loop

        Event ev;
        while(start_window.pollEvent(ev))
            switch (ev.type) {//even handle switch case
            case Event::Closed:
                start_window.close();break;
            case Event::MouseButtonPressed://to know the positions on the screen
                cout<<Mouse::getPosition().x<<" "<<Mouse::getPosition().y<<endl;
                if(start_btn.mosuein(start_window))
                    start_btn.setScale({0.9,0.9});
                break;
            case Event::MouseButtonReleased:
                if(start_btn.mosuein(start_window))
                    start_btn.setScale({1,1});
            }
        start_window.draw(background);
        start_btn.drawTo(start_window);
        start_window.display();
    }
//RenderWindow mainwindow(VideoMode(800, 700), "PENGO", Style::Close);
    //mainwindow.close();

    return 0;
}

//------trash area------//
/*
 while (mainwindow.isOpen()){//the main game loop
        mainwindow.setPosition(Vector2i(283,0));
        Event event;
        while (mainwindow.pollEvent(event))//event collecting loop
            switch(event.type){//Switch case for even handling
                case Event::Closed:
                    mainwindow.close();
                    cout<<"Close the window"<<endl;
                    break;

            }

        mainwindow.display();
    }
 */