/*---------BINGO---------*/
#include <SFML/Graphics.hpp>
#include"Button.h"
#include "Textbox.h"
#include"ComputerLevels.h"
using namespace sf;

void Show_Error_Window(Font &font){
    RenderWindow Error_Window(VideoMode(350, 200), "Warning!!", Style::None);

    Vector2i center(350-175,350 - 100);
    Error_Window.setPosition(center);
    Text text, text2;
    //------ Text(Sentence) section --------//
    text.setPosition({45, 90});
    text.setStyle(sf::Text::Bold);
    text.setCharacterSize(20);
    text.setFillColor(Color::Black);
    text.setString("Choose the difficulty first.");
    text.setFont(font);
    //------ End_OF_Text section ------//

    //------ Text2(Warning ward) Section ------//
    text2.setPosition({110, 40});
    text2.setCharacterSize(25);
    text2.setStyle(sf::Text::Bold);
    text2.setFont(font);
    text2.setFillColor(sf::Color::Black);
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

            if(event.type == sf::Event::MouseButtonPressed){
                if(Ok_btn.ismousein(Error_Window)){
                    Ok_btn.setScale({0.9, 0.9});
                }
            }else if(event.type == sf::Event::MouseButtonReleased){
                if(Ok_btn.ismousein(Error_Window)){
                    Ok_btn.setScale({1, 1});
                    Error_Window.close();
                }
            }
        }
        Error_Window.clear(Color(127,127,127));
        Error_Window.draw(text);
        Error_Window.draw(text2);
        Ok_btn.drawTo(Error_Window);
        Error_Window.display();
    }
}

void Change_Difficulty(int &difficulty,Font &font){
    //-------data elements area-------//
    RenderWindow window(VideoMode(400,100),"",Style::None);
    Text txt;
        //-------Texture area-------//
    Texture easy_tex,medium_tex,hard_tex;
    easy_tex.loadFromFile("Change_Difficulty/easy.png");
    medium_tex.loadFromFile("Change_Difficulty/medium.png");
    hard_tex.loadFromFile("Change_Difficulty/hard.png");

        //-------Texture area-------//
    Button easy(&easy_tex),
    medium(&medium_tex),
    hard(&hard_tex);
    Vector2i center(350-200,350 - 50);
    //-------data elements area-------//

    //-------settings area-------//
    window.setPosition(center);
    txt.setString("Choose the Difficulty");
    txt.setCharacterSize(36);
    txt.setFont(font);
    txt.setFillColor(Color::Black);
    txt.setPosition({16,16});
    easy.setPosition({20, 67});
    medium.setPosition({150,67});
    hard.setPosition({295,67});
    //-------settings area-------//
    while(window.isOpen()){
        Event event;
        while(window.pollEvent(event)){
            if(event.type==Event::MouseButtonPressed) {
                cout << Mouse::getPosition(window).x << " " << Mouse::getPosition(window).y << endl;
                if(easy.ismousein(window)){
                    easy.setScale({0.9,0.9});
                }
                else if(medium.ismousein(window)){
                    medium.setScale({0.9,0.9});
                }
                else if(hard.ismousein(window)){
                    hard.setScale({0.9,0.9});
                }
            }
            else if(event.type==Event::MouseButtonReleased){
                if(easy.ismousein(window)){
                    easy.setScale({1,1});
                    difficulty=1;
                    window.close();
                }
                else if(medium.ismousein(window)){
                    medium.setScale({1,1});
                    difficulty=2;
                    window.close();
                }
                else if(hard.ismousein(window)){
                    hard.setScale({1,1});
                    difficulty=3;
                    window.close();
                }
            }
        }
        window.clear(Color(127,127,127));
        window.draw(txt);
        easy.drawTo(window);
        medium.drawTo(window);
        hard.drawTo(window);
        window.display();
    }

}

bool Game_End(bool playerwin,Font &font,int &difficulty,int compGrid[6][6],int compGridCopy[6][6]){
    //-------data elements area-------//
    RenderWindow window(VideoMode(400,200),"",Style::None);
    Vector2i center(350-200,350 - 100);
    window.setPosition(center);
    Text txt;
        /*--------texture area--------*/
    Texture exit_tex,again_tex,show_grid_tex;
    exit_tex.loadFromFile("Game_End/Exit.png");
    again_tex.loadFromFile("Game_End/play_again.png");
    show_grid_tex.loadFromFile("Game_End/show_com_grid.png");
        /*--------texture area--------*/
    Button exit(&exit_tex),
    again(&again_tex),
    show_com_grid;
    bool exit_pressed=0;
    //-------data elements area-------//

    //-------settings area-------//
    exit.setPosition({308,144});
    again.setPosition({18 ,144});
    if(!playerwin){
        show_com_grid.setPosition({150,126});
        show_com_grid.setTexture(&show_grid_tex);
    }
    font.loadFromFile("ARLRDBD.TTF");
    txt.setFont(font);
    txt.setFillColor(Color::Black);
    txt.setCharacterSize(36);
    txt.setPosition({100,20});
    if(playerwin){
        txt.setString("Good Job :)\nYou Won !");
    }
    else{
        txt.setString("Good Game :)\n You Lost !");
    }
    //-------settings area-------//


    while(window.isOpen()){
        Event event;

        while(window.pollEvent(event)){
            if(event.type==Event::MouseButtonPressed){
                if(exit.ismousein(window)){
                    exit.setScale({0.9,0.9});
                }
                else if(again.ismousein(window)){
                    again.setScale({0.9,0.9});
                }
                else if(show_com_grid.ismousein(window)){
                    show_com_grid.setScale({0.9,0.9});
                }
            }
            if(event.type==Event::MouseButtonReleased){
                cout<<Mouse::getPosition(window).x<<" "<<Mouse::getPosition(window).y<<endl;
                if(exit.ismousein(window)){
                    exit.setScale({1,1});
                    exit_pressed=1;
                    window.close();
                }
                else if(again.ismousein(window)){
                    again.setScale({1,1});
                    window.close();
                    cout<<"Play again\n";
                }
                else if(show_com_grid.ismousein(window)){
                    show_com_grid.setScale({1,1});
                    cout<<"Show Computer Grid\n";
                    PrinT(compGrid);
                    RenderWindow compGrid_window(VideoMode(514,506),"Computer Grid",Style::Close);
                    RectangleShape grid;
                    Texture grid_tex;
                    vector<vector<Button>>grid_txt;
                    vector<Button>tmp_btn;
                    int xPos = 28, yPos = 25;
                    for(int i=0;i<5;i++)
                    {
                        int xTemp=xPos;
                        tmp_btn.clear();
                        for(int j=0;j<5;j++){
                            tmp_btn.push_back(Button(to_string(compGridCopy[i][j]),{89,89},20,Color::White,Color::Black));
                        }
                        grid_txt.push_back(tmp_btn);
                        for(int j=0;j<5;j++){
                            if(compGrid[i][j]==0)
                                grid_txt[i][j].setBackColor(Color::Magenta);
                            grid_txt[i][j].setPosition(Vector2f(xTemp,yPos));
                            grid_txt[i][j].setFont(font);
                            xTemp += 92;
                        }
                        yPos += 92;

                    }
                    grid_tex.loadFromFile("Game_End/empty_grid.png");
                    grid.setSize({514,506});
                    grid.setTexture(&grid_tex);
                    while(compGrid_window.isOpen()){
                        Event event;
                        while(compGrid_window.pollEvent(event)){
                            if(event.type==Event::Closed)
                                compGrid_window.close();
                            else if(event.type==Event::MouseButtonPressed)
                                cout<<Mouse::getPosition(compGrid_window).x<<" "<<Mouse::getPosition(compGrid_window).y<<endl;
                        }
                        compGrid_window.draw(grid);
                        for(int i=0;i<5;i++)
                            for(int j=0;j<5;j++)
                                grid_txt[i][j].drawTo(compGrid_window);
                        compGrid_window.display();
                    }
                }
            }
        }
        window.clear(Color(127,127,127));
        exit.drawTo(window);
        again.drawTo(window);
        if(!playerwin)
            show_com_grid.drawTo(window);
        window.draw(txt);
        window.display();
    }
    if(exit_pressed)
        return 0;
    return 1;
}

bool GameWindow(string &player_name,int &difficulty,Font &font,bool &playerwin,int compGrid[6][6],int compGridCopy[6][6]){

    //---------data elements area--------//
    RenderWindow GameWindow(VideoMode(700, 700), "Let's Play !!", Style::Close);
    Texture GameWindow_Back_Gound, Score_Stack;
    vector< vector<Button> > v;
    vector<Button> temp;
    RectangleShape Main_window_Back_Ground, Score_Stack_Rec;
    vector< vector<bool> >btns_click(5,vector<bool>(5,false));
    Text turn;
    bool playerturn=1,playerWins=0,compWins=0,drawbtn=0;
    long long time = 4e8;
    int playerGrid[6][6]={},playerPoints=0,compPoints=0;
    pair<int,int>tmp,tmp2;
    //-----------data elements area--------//

    //--------data elements settings-------//
    GameWindow.setPosition(Vector2i(0, 0));
    font.loadFromFile("ARLRDBD.TTF");
    GameWindow_Back_Gound.loadFromFile("main_page/main_page.jpg");
    Score_Stack.loadFromFile("main_page/stack_empty.PNG");
    Score_Stack_Rec.setTexture(&Score_Stack);
    Score_Stack_Rec.setPosition(Vector2f(543, 462));
    Score_Stack_Rec.setSize({155,198});
    Main_window_Back_Ground.setTexture(&GameWindow_Back_Gound);
    Main_window_Back_Ground.setSize(Vector2f(GameWindow_Back_Gound.getSize()));
    turn.setCharacterSize(25);
    turn.setFont(font);
    turn.setFillColor(Color::White);
    turn.setPosition({409,35});

    /*-------Grids settings-----------*/
    filltheGrid(playerGrid);
         for( int i=0;i<1e7;i++);//for randomized grids
    filltheGrid(compGrid);
    PrinT(playerGrid);

    cout<<endl;

    PrinT(compGrid);
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            compGridCopy[i][j]=compGrid[i][j];

    /*-------Grids settings-----------*/

    /*-------setting the position of the buttons-------*/
    int xPos = 40, yPos = 202;
    for(int i = 0 ; i < 5 ; ++i){
        int xTemp = xPos;
        temp.clear();
        for(int j = 0; j < 5 ; ++j) {
            string s = to_string(playerGrid[i][j]);
            temp.push_back(Button(s, Vector2f(89, 89), 20, Color::White, Color::Black));
        }
        v.push_back(temp);
        for(int k = 0; k < 5; ++k){
            v[i][k].setPosition(Vector2f(xTemp, yPos));
            v[i][k].setFont(font);
            xTemp += 92;
        }
        yPos += 92;
    }
    /*-------setting the position of the buttons-------*/
    //--------data elements settings-------//

    while(GameWindow.isOpen()){// the game window main loop
        Event event;
        while(GameWindow.pollEvent(event)){

            if(event.type == Event::Closed) {
                GameWindow.close();
            }else if(event.type == sf::Event::MouseButtonPressed){
               // sf::Vector2i localPosition = sf::Mouse::getPosition(GameWindow);//for testing
               // cout << localPosition.x << " " << localPosition.y << endl;//for testing
                for(int i = 0; i < 5; ++i){
                    for(int j = 0; j < 5; ++j)
                        if(v[i][j].ismousein(GameWindow)&&!btns_click[i][j]&&playerturn){
                            v[i][j].setBackColor(Color::Magenta);
                            btns_click[i][j]=1;
                           // cout<<"Clicked"<<endl;
                            playerturn=false;

                            for(int l=0;l<5;l++){
                                bool ch=0;
                                for(int k=0;k<5;k++){
                                    if(compGrid[l][k]==playerGrid[i][j]){
                                        compGrid[l][k]=0;
                                        if(compGrid[l][5]!=-1)
                                            compGrid[l][5]++;
                                        if(compGrid[5][k]!=-1)
                                            compGrid[5][k]++;

                                        ch=1;
                                        break;
                                    }
                                }
                                if(ch)break;
                            }

                            playerGrid[i][j]=0;

                            if(playerGrid[i][5]!=-1)
                                playerGrid[i][5]++;
                            if(playerGrid[5][j]!=-1)
                                playerGrid[5][j]++;



                            pointsCont(playerPoints,playerGrid);
                            pointsCont(compPoints,compGrid);
                            cout<<playerPoints<<" <- player\n";
                            cout<<compPoints<<" <- computer\n";
                            if(compPoints==5&&!playerWins)compWins=1;

                            switch (playerPoints) {
                                case 1:
                                    Score_Stack.loadFromFile("main_page/stack_1.PNG");
                                    break;
                                case 2:
                                    Score_Stack.loadFromFile("main_page/stack_2.PNG");
                                    break;
                                case 3:
                                    Score_Stack.loadFromFile("main_page/stack_3.PNG");
                                    break;
                                case 4:
                                    Score_Stack.loadFromFile("main_page/stack_4.PNG");
                                    break;
                                case 5:
                                    Score_Stack.loadFromFile("main_page/stack_5_win.PNG");
                                    if(!compWins)
                                        playerWins=1;
                                    break;
                            }
                            Score_Stack_Rec.setTexture(&Score_Stack);
                        }
                }
                cout<<"Player : \n";
                //PrinT(playerGrid);
                for(int i=0;i<6;i++){
                    for(int j=0;j<6;j++)
                        cout<<playerGrid[i][j]<<" ";
                    cout<<endl;
                }
                cout<<endl<<"Computer : \n";
                //PrinT(compGrid);
                for(int i=0;i<6;i++){
                    for(int j=0;j<6;j++)
                        cout<<compGrid[i][j]<<" ";
                    cout<<endl;
                }
                cout<<endl;
            }
        }
        if(playerturn){
            turn.setString(player_name+"'s Turn");
        }else{
            turn.setString("Opponent is playing...");
            if(difficulty==1)
            {
               tmp = PlayEasy(compGrid);
            }
            else if(difficulty==2)
            {
                tmp = PlayMedium(compGrid);
            }
            else {
               tmp =  PlayHard(compGrid);
            }

            cout<<tmp.first<<" "<<tmp.second<<endl;

            for(int l=0;l<5;l++){
                bool ch=0;
                for(int k=0;k<5;k++){
                    if(compGrid[tmp.first][tmp.second]==playerGrid[l][k]){
                        playerGrid[l][k]=0;
                        if(playerGrid[l][5]!=-1)
                            playerGrid[l][5]++;
                        if(playerGrid[5][k]!=-1)
                            playerGrid[5][k]++;
                        ch=1;
                        tmp2.first=l;tmp2.second=k;
                        break;
                    }
                }
                if(ch)break;
            }

            compGrid[tmp.first][tmp.second]=0;
            if( compGrid[tmp.first][5]!=-1)
                compGrid[tmp.first][5]++;
            if( compGrid[5][tmp.second]!=-1)
                compGrid[5][tmp.second]++;


            pointsCont(playerPoints,playerGrid);
            pointsCont(compPoints,compGrid);
            if(compPoints==5&&!playerWins)compWins=1;
            if(playerPoints==5&&!compWins)playerWins=1;

            cout<<"Player : \n";
            //PrinT(playerGrid);
            for(int i=0;i<6;i++){
                for(int j=0;j<6;j++)
                    cout<<playerGrid[i][j]<<" ";
                cout<<endl;
            }
            cout<<endl<<"Computer : \n";
            //PrinT(compGrid);
            for(int i=0;i<6;i++){
                for(int j=0;j<6;j++)
                    cout<<compGrid[i][j]<<" ";
                cout<<endl;
            }
            cout<<endl;

        }



        GameWindow.draw(Main_window_Back_Ground);
        GameWindow.draw(Score_Stack_Rec);
        for(int i = 0 ; i < 5 ; ++i)
            for(auto it : v[i])
                it.drawTo(GameWindow);
        GameWindow.draw(turn);
        if(drawbtn){
            drawbtn=0;
            btns_click[tmp2.first][tmp2.second]=1;
            v[tmp2.first][tmp2.second].setBackColor(Color::Magenta);
        }
        GameWindow.display();
        if(!playerturn) {
            for (int i = 0; i < time; i++);
            playerturn=true;
        drawbtn=1;
            switch (playerPoints) {
                case 1:
                    Score_Stack.loadFromFile("main_page/stack_1.PNG");
                    break;
                case 2:
                    Score_Stack.loadFromFile("main_page/stack_2.PNG");
                    break;
                case 3:
                    Score_Stack.loadFromFile("main_page/stack_3.PNG");
                    break;
                case 4:
                    Score_Stack.loadFromFile("main_page/stack_4.PNG");
                    break;
                case 5:
                    Score_Stack.loadFromFile("main_page/stack_5_win.PNG");
                    if(!compWins)
                        playerWins=1;
                    break;
            }
            Score_Stack_Rec.setTexture(&Score_Stack);
        }
        if(playerWins) { playerwin = 1;return 1; }
        else if(compWins) { playerwin = 0; return 1;}
    }

    return 0;
}


string nameEnter(Font &font,string player_name){//A function to take the user enter his/her name as an input
    /*--------text box data elements---------*/
    RenderWindow txtbox(VideoMode(400,100),"Enter the Name",Style::None);
    Textbox name(27,Color::White,true);
    Text t1;
    Vector2i center(350-200,VideoMode::getDesktopMode().height/2 - 50);
    Texture ok_tex,cancel_tex;
    //-------Texture area---------//
    ok_tex.setSmooth(true);
    cancel_tex.setSmooth(true);
    ok_tex.loadFromFile("Ok_btn.png");
    cancel_tex.loadFromFile("cancel_btn.png");
    //-------Texture area---------//

    Button ok(&ok_tex),cancel(&cancel_tex);
    /*--------text box data elements---------*/

    ok.setPosition({347, 75});
    cancel.setPosition({272,75});
    t1.setFont(font);
    t1.setFillColor(Color::Black);
    t1.setString("Enter Your Name :");
    t1.setCharacterSize(18);
    t1.setPosition({0,0});
    txtbox.setPosition(center);
    name.setPosition({0,25});
    name.setFont(font);
    name.setLimit(true,20);
    while(txtbox.isOpen()){
        Event e;
        while(txtbox.pollEvent(e))
            if(e.type==Event::TextEntered)
                name.typedOn(e);
            else if(e.type==Event::MouseButtonPressed)
            {
                //  cout<<Mouse::getPosition(txtbox).x<<" "<<Mouse::getPosition(txtbox).y<<endl;
                if(ok.ismousein(txtbox)){
                    ok.setScale({0.9, 0.9});
                }
                else if(cancel.ismousein(txtbox)){
                    cancel.setScale({0.9, 0.9});
                }
            }
            else if (e.type==Event::MouseButtonReleased){
                if(ok.ismousein(txtbox)){
                    ok.setScale({1, 1});
                    txtbox.close();
                }
                else if(cancel.ismousein(txtbox)){
                    cancel.setScale({1, 1});
                    return player_name;
                }
            }
        txtbox.clear(Color(127,127,127));
        txtbox.draw(t1);
        name.drawTo(txtbox);
        ok.drawTo(txtbox);
        cancel.drawTo(txtbox);
        txtbox.display();
    }
    player_name =name.getText();
    return player_name;
}

bool start_window_function(string &player_name,int &difficulty,Font &font){
    //-------- start window data -------//
    RenderWindow start_window(VideoMode(700,700),"Start Window",Style::Close);
    start_window.setPosition(Vector2i(0,0));
    Texture background_texture,start_btn_texture;
    // background_texture.loadFromFile("full_window.jpg");// to test positions
    background_texture.loadFromFile("background.jpg");
    start_btn_texture.loadFromFile("start_btn.png");
    /*--------Texture area------*/

    /*--------Data area------*/
    RectangleShape background;
    Button start_btn(&start_btn_texture);
    bool isstart=false , error=false;
    /*--------Data area------*/
    //-------- start window data -------//

    /*-------- Setting up data elements -------*/
    start_window.setPosition(Vector2i(0,0));
    //background_texture.loadFromFile("full_window.jpg");// to test positions
    background.setTexture(&background_texture);
    background.setPosition(0,0);
    background.setSize(Vector2f(background_texture.getSize()));
    start_btn.setPosition({240, 196});
    font.loadFromFile("ARLRDBD.TTF");
//    start_btn.setBackColor(Color(255,255,255,100));

    //----------- Easy_btn section ------------//
    Texture Easy_btn_Texture;
    Easy_btn_Texture.loadFromFile("easy_btn_np.png");
    Button Easy_btn(&Easy_btn_Texture);
    Easy_btn.setPosition({31, 365});
    bool Changed_Easy_byn = false;
    //----------- End_Of_Easy_Btn section --------//

    // ---------- Medium_btn section ------------//
    Texture Medium_btn_Texture;
    Medium_btn_Texture.loadFromFile("meduim_btn_np.png");
    Button Medium_btn(&Medium_btn_Texture);
    Medium_btn.setPosition({30, 480});
    bool Changed_Medium_btn = false;
    //---------- End_of_Medium_btn section ---------//

    //---------- Hard_brn section ----------------//
    Texture Hard_btn_Texture;
    Hard_btn_Texture.loadFromFile("hard_btn_np.png");
    Button Hard_btn (&Hard_btn_Texture);
    Hard_btn.setPosition({30, 590});
    bool Changed_Hard_btn = false;
    //----------- End_Of_Hard_Btn section ----------//

    while(start_window.isOpen()){//strat window loop
        Event ev;
        if(isstart){//to check if Start button is pressed or not
            isstart=false;
            player_name = nameEnter(font,player_name);
            if(!player_name.empty())start_window.close();
        }else if(error){
            Show_Error_Window(font);
            error =false;
        }

        while(start_window.pollEvent(ev))
            switch (ev.type) {//even handle switch case
                case Event::Closed:
                    start_window.close();return 0 ;break;
                case Event::MouseButtonPressed://to know the positions on the screen
                    //  cout<<Mouse::getPosition(start_window).x<<" "<<Mouse::getPosition(start_window).y<<endl;
                    if(start_btn.ismousein(start_window))
                        start_btn.setScale({0.9,0.9});

                    else if(Easy_btn.ismousein(start_window)) {
                        if (!Changed_Hard_btn && !Changed_Medium_btn)
                            Easy_btn.setScale({0.9, 0.9});
                    }
                    else if(Medium_btn.ismousein(start_window)) {
                        if(!Changed_Easy_byn && !Changed_Hard_btn)
                            Medium_btn.setScale({0.9, 0.9});
                    }
                    else if(Hard_btn.ismousein(start_window)){
                        if(!Changed_Easy_byn && !Changed_Medium_btn)
                            Hard_btn.setScale({0.9, 0.9});
                    }
                    break;
                case Event::MouseButtonReleased:
                    if(start_btn.ismousein(start_window)) {
                        start_btn.setScale({1, 1});
                        if(Changed_Easy_byn||Changed_Hard_btn||Changed_Medium_btn)
                            isstart=true;
                        else
                            error =true;}
                    else if(Easy_btn.ismousein(start_window)) {
                        if(!Changed_Easy_byn && !Changed_Medium_btn && !Changed_Hard_btn) {
                            Easy_btn.setScale({1, 1});
                            Easy_btn_Texture.loadFromFile("easy_btn_p.png");
                            Changed_Easy_byn = true;
                        }else{
                            Easy_btn.setScale({1, 1});
                            Easy_btn_Texture.loadFromFile("easy_btn_np.png");
                            Changed_Easy_byn = false;
                        }
                    }else if(Medium_btn.ismousein(start_window)){
                        if(!Changed_Medium_btn && !Changed_Hard_btn && !Changed_Easy_byn){
                            Medium_btn.setScale({1, 1});

                            Medium_btn_Texture.loadFromFile("meduim_btn_p.png");
                            Changed_Medium_btn = true;
                        } else{
                            Medium_btn.setScale({1, 1});
                            Medium_btn_Texture.loadFromFile("meduim_btn_np.png");
                            Changed_Medium_btn = false;
                        }
                    }else if(Hard_btn.ismousein(start_window)){
                        if(!Changed_Hard_btn && !Changed_Medium_btn && !Changed_Easy_byn){
                            Hard_btn.setScale({1, 1});
                            Hard_btn_Texture.loadFromFile("hard_btn_p.png");
                            Changed_Hard_btn = true;
                        }else{
                            Hard_btn.setScale({1, 1});
                            Hard_btn_Texture.loadFromFile("hard_btn_np.png");
                            Changed_Hard_btn = false;
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
    /*--------select difficulty---------*/
    if(Changed_Easy_byn)difficulty=1;
    else if(Changed_Medium_btn)difficulty=2;
    else difficulty =3;
    //cout<<"ENDED"<<endl;//for testing
    /*--------select difficulty---------*/
    return 1;
}

int main(){
    //------------Global Data-----------//
    string player_name;
    int difficulty;
    Font font;
    bool playerwin;
    int compGrid[6][6]={},compGridCopy[6][6]={};
    //------------Global Data-----------//
    font.loadFromFile("ARLRDBD.TTF");
    if(start_window_function(player_name,difficulty,font)){
        if(GameWindow(player_name,difficulty,font,playerwin,compGrid,compGridCopy))
        while(Game_End(playerwin,font,difficulty,compGrid,compGridCopy)){
            Change_Difficulty(difficulty,font);
            for(int i=0;i<6;i++)
                for(int j=0;j<6;j++){
                    compGrid[i][j]=0;
                    compGridCopy[i][j]=0;
                }
            if(!GameWindow(player_name,difficulty,font,playerwin,compGrid,compGridCopy))break;
        }

    }



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