/*---------BINGO---------*/
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<iostream>
#include"Button.h"
#include "Textbox.h"
using namespace std;
using namespace sf;

void Show_Error_Window(){
    RenderWindow Error_Window(VideoMode(350, 200), "Warning!!", Style::Close);
    Error_Window.setPosition(Vector2i(150, 100));

    sf::Font font;
    Text text, text2;
    font.loadFromFile("ARLRDBD.TTF");
    //------ Text(Sentence) section --------//
    text.setPosition({45, 90});
    text.setStyle(sf::Text::Bold);
    text.setCharacterSize(20);
    text.setColor(sf::Color::White);
    text.setString("Choose the difficulty first.");
    text.setFont(font);
    //------ End_OF_Text section ------//

    //------ Text2(Warning ward) Section ------//
    text2.setPosition({110, 40});
    text2.setCharacterSize(25);
    text2.setStyle(sf::Text::Bold);
    text2.setFont(font);
    text2.setColor(sf::Color::White);
    text2.setString("Warning !!\n");
    //------- End_Of_Text2 section --------//

    //-------- Texture --------//
    Texture Ok_btn_Texture;
    Ok_btn_Texture.loadFromFile("Ok_btn.png");
    Ok_btn_Texture.setSmooth(true);
    //------- EndOfTexture-------//

    /*------- Ok_Button Section ----------*/
    Button Ok_btn(&Ok_btn_Texture);
    Ok_btn.setPosition({145, 150});
    /*------End_Of_Ok_Button section------*/

    while(Error_Window.isOpen()){
        Event event;
        while(Error_Window.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                Error_Window.close();
             if(event.type == sf::Event::MouseButtonPressed){
                if(Ok_btn.mosuein(Error_Window)){
                    Ok_btn.setScale({0.9, 0.9});
                }
            }else if(event.type == sf::Event::MouseButtonReleased){
                 if(Ok_btn.mosuein(Error_Window)){
                     Ok_btn.setScale({1, 1});
                     Error_Window.close();
                 }
             }
        }
        Error_Window.clear();
        Error_Window.draw(text);
        Error_Window.draw(text2);
        Ok_btn.drawTo(Error_Window);
        Error_Window.display();
    }
}
int main(){
    //-------- start window data -------//
    RenderWindow start_window(VideoMode(700,700),"Start Window",Style::Close);
    start_window.setPosition(Vector2i(0,0));
    Texture background_texture,start_btn_texture;
//    background_texture.loadFromFile("full_window.jpg");// to test positions
    background_texture.loadFromFile("background.jpg");
    start_btn_texture.loadFromFile("start_btn.png");
    RectangleShape background;
    background.setTexture(&background_texture);
    background.setPosition(0,0);
    background.setSize(Vector2f(background_texture.getSize()));
    Button start_btn(&start_btn_texture);
    start_btn.setPosition({240, 196});
//    start_btn.setBackColor(Color(255,255,255,100));

    //----------- Easy_btn section ------------//
    Texture Easy_btn_Texture;
    Easy_btn_Texture.loadFromFile("easy_btn_np.png");
    Button Easy_btn(&Easy_btn_Texture);
    Easy_btn.setPosition({31, 365});
    bool Changed_Easy_byn = 0;
    //----------- End_Of_Easy_Btn section --------//

    // ---------- Medium_btn section ------------//
    Texture Medium_btn_Texture;
    Medium_btn_Texture.loadFromFile("meduim_btn_np.png");
    Button Medium_btn(&Medium_btn_Texture);
    Medium_btn.setPosition({30, 480});
    bool Changed_Medium_btn = 0;
    //---------- End_of_Medium_btn section ---------//

    //---------- Hard_brn section ----------------//
    Texture Hard_btn_Texture;
    Hard_btn_Texture.loadFromFile("hard_btn_np.png");
    Button Hard_btn (&Hard_btn_Texture);
    Hard_btn.setPosition({30, 590});
    bool Changed_Hard_btn = 0;
    //----------- End_Of_Hard_Btn section ----------//
//    sf::SoundBuffer sb;
//    sb.loadFromFile("Error.wav");
//    sf::Sound sound;
//    sound.setBuffer(sb);

    while(start_window.isOpen()){//strat window loop
        Event ev;
        while(start_window.pollEvent(ev))
            switch (ev.type) {//even handle switch case
            case Event::Closed:
                start_window.close();break;
            case Event::MouseButtonPressed://to know the positions on the screen
                cout<<Mouse::getPosition(start_window).x<<" "<<Mouse::getPosition(start_window).y<<endl;
                if(start_btn.mosuein(start_window)) {
                    if(!Changed_Hard_btn && !Changed_Medium_btn && !Changed_Easy_byn) {
//                        sound.play();
                        Show_Error_Window();
                    }
                    else {
                        start_btn.setScale({0.9, 0.9});
                    }
                }
                else if(Easy_btn.mosuein(start_window)) {
                    if (!Changed_Hard_btn && !Changed_Medium_btn)
                        Easy_btn.setScale({0.9, 0.9});
                }
                else if(Medium_btn.mosuein(start_window)) {
                    if(!Changed_Easy_byn && !Changed_Hard_btn)
                        Medium_btn.setScale({0.9, 0.9});
                }
                else if(Hard_btn.mosuein(start_window)){
                    if(!Changed_Easy_byn && !Changed_Medium_btn)
                        Hard_btn.setScale({0.9, 0.9});
                }
                break;
            case Event::MouseButtonReleased:
                if(start_btn.mosuein(start_window))
                    start_btn.setScale({1,1});
                else if(Easy_btn.mosuein(start_window)) {
                    if(!Changed_Easy_byn && !Changed_Medium_btn && !Changed_Hard_btn) {
                        Easy_btn.setScale({1, 1});
                        Easy_btn_Texture.loadFromFile("easy_btn_p.png");
                        Changed_Easy_byn = 1;
                    }else{
                        Easy_btn.setScale({1, 1});
                        Easy_btn_Texture.loadFromFile("easy_btn_np.png");
                        Changed_Easy_byn = 0;
                    }
                }else if(Medium_btn.mosuein(start_window)){
                    if(!Changed_Medium_btn && !Changed_Hard_btn && !Changed_Easy_byn){
                        Medium_btn.setScale({1, 1});

                        Medium_btn_Texture.loadFromFile("meduim_btn_p.png");
                        Changed_Medium_btn = 1;
                    } else{
                        Medium_btn.setScale({1, 1});
                        Medium_btn_Texture.loadFromFile("meduim_btn_np.png");
                        Changed_Medium_btn = 0;
                    }
                }else if(Hard_btn.mosuein(start_window)){
                    if(!Changed_Hard_btn && !Changed_Medium_btn && !Changed_Easy_byn){
                        Hard_btn.setScale({1, 1});
                        Hard_btn_Texture.loadFromFile("hard_btn_p.png");
                        Changed_Hard_btn = 1;
                    }else{
                        Hard_btn.setScale({1, 1});
                        Hard_btn_Texture.loadFromFile("hard_btn_np.png");
                        Changed_Hard_btn = 0;
                    }
                }
                break;
            }
        start_window.draw(background);
        start_btn.drawTo(start_window);
        Easy_btn.drawTo(start_window);
        Medium_btn.drawTo(start_window);
        Hard_btn.drawTo(start_window);
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