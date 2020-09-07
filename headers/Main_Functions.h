#include <SFML/Graphics.hpp>
#include"Button.h"
#include "Textbox.h"
#include"ComputerLevels.h"
using namespace sf;

void Show_Error_Window(Font &font){//error msg window
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
    Ok_btn_Texture.loadFromFile("start_window/Ok_btn.png");
    Ok_btn_Texture.setSmooth(true);
    //------- EndOfTexture-------//

    /*------- Ok_Button Section ----------*/
    Button Ok_btn(&Ok_btn_Texture);
    Ok_btn.setPosition({145, 150});
    /*------End_Of_Ok_Button section------*/

    while(Error_Window.isOpen()){//error window loop

        Event event;
        while(Error_Window.pollEvent(event)){//event handling loop

            if(event.type == sf::Event::MouseButtonPressed&&(event.mouseButton.button==Mouse::Left)){
                if(Ok_btn.ismousein(Error_Window)){//pressing effect
                    Ok_btn.setScale({0.9, 0.9});
                }
            }else if(event.type == sf::Event::MouseButtonReleased&&(event.mouseButton.button==Mouse::Left)){
                if(Ok_btn.ismousein(Error_Window)){//ok button function
                    Ok_btn.setScale({1, 1});
                    Error_Window.close();
                }
            }
        }
        //------drawing area------//
        Error_Window.clear(Color(127,127,127));
        Error_Window.draw(text);
        Error_Window.draw(text2);
        Ok_btn.drawTo(Error_Window);
        Error_Window.display();
        //------drawing area------//
    }
}

void Change_Difficulty(int &difficulty,Font &font){//changing the difficulty function
    //-------data elements area-------//
    RenderWindow window(VideoMode(400,100),"",Style::None);
    Text txt;

    //-------Texture area-------//
    Texture easy_tex,medium_tex,hard_tex;
    easy_tex.loadFromFile("Change_Difficulty/easy.png");
    medium_tex.loadFromFile("Change_Difficulty/medium.png");
    hard_tex.loadFromFile("Change_Difficulty/hard.png");
    //-------Texture area-------//

    Button easy(&easy_tex),medium(&medium_tex),hard(&hard_tex);
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

    while(window.isOpen()){//Change diff main loop

        Event event;
        while(window.pollEvent(event)){//event handling loop
            if(event.type==Event::MouseButtonPressed&&(event.mouseButton.button==Mouse::Left)) {//press effect

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
            else if(event.type==Event::MouseButtonReleased&&(event.mouseButton.button==Mouse::Left)){//the functions of buttons
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

        //-----drawing area-----//
        window.clear(Color(127,127,127));
        window.draw(txt);
        easy.drawTo(window);
        medium.drawTo(window);
        hard.drawTo(window);
        window.display();
        //-----drawing area------//

    }

}

bool Game_End(bool playerwin,Font &font,int &difficulty,int compGrid[6][6],int compGridCopy[6][6]){//game end function
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
    if(!playerwin){//to choose when to draw "show computer grid" button
        show_com_grid.setPosition({150,126});
        show_com_grid.setTexture(&show_grid_tex);
    }
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


    while(window.isOpen()){//end screen main loop
        Event event;

        while(window.pollEvent(event)){//event handling loop
            if(event.type==Event::MouseButtonPressed&&(event.mouseButton.button==Mouse::Left)){//clicks effect
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
            if(event.type==Event::MouseButtonReleased&&(event.mouseButton.button==Mouse::Left)){//functions of buttons
                if(exit.ismousein(window)){
                    exit.setScale({1,1});
                    exit_pressed=1;
                    window.close();
                }
                else if(again.ismousein(window)){
                    again.setScale({1,1});
                    window.close();
                }
                else if(show_com_grid.ismousein(window)){
                    show_com_grid.setScale({1,1});
                    /*-------computer grid window--------*/

                    //-----data elements-----//
                    RenderWindow compGrid_window(VideoMode(514,506),"Computer Grid",Style::Close);
                    RectangleShape grid;
                    Texture grid_tex;
                    vector<vector<Button>>grid_txt;
                    vector<Button>tmp_btn;
                    //-----data elements-----//

                    //-----settings area-----//
                    center.x = 350 - 257;
                    center.y = 350-253;
                    compGrid_window.setPosition(center);
                    int xPos = 28, yPos = 25;
                    for(int i=0;i<5;i++){//button Initialization and settings loop
                        int xTemp=xPos;
                        tmp_btn.clear();//resetting the vector
                        for(int j=0;j<5;j++){//Initialization loop
                            tmp_btn.push_back(Button(to_string(compGridCopy[i][j]),{89,89},20,Color::White,Color::Black));
                        }
                        grid_txt.push_back(tmp_btn);
                        for(int j=0;j<5;j++){//settings loop
                            if(compGrid[i][j]==0)//for picking the selected buttons
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
                    //-----settings area-----//

                    while(compGrid_window.isOpen()){//show computer grid main loop
                        Event compGrid_event;
                        while(compGrid_window.pollEvent(compGrid_event)){//event handling loop
                            if(compGrid_event.type==Event::Closed&&(compGrid_event.mouseButton.button==Mouse::Left))
                                compGrid_window.close();
                        }
                        //-------drawing area-------//
                        compGrid_window.draw(grid);
                        for(int i=0;i<5;i++)
                            for(int j=0;j<5;j++)
                                grid_txt[i][j].drawTo(compGrid_window);
                        compGrid_window.display();
                        //-------drawing area-------//
                    }
                    /*-------computer grid window--------*/
                }
            }
        }
        //-------drawing area (end screen)-------//
        window.clear(Color(127,127,127));
        exit.drawTo(window);
        again.drawTo(window);
        if(!playerwin)
            show_com_grid.drawTo(window);
        window.draw(txt);
        window.display();
        //-------drawing area (end screen)-------//

    }// end screen main loop end
    if(exit_pressed)//choose to end the game or not
        return 0;
    return 1;
}

bool GameWindow(string &player_name,int &difficulty,Font &font,bool &playerwin,int compGrid[6][6],int compGridCopy[6][6]){//the game window function

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

    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            compGridCopy[i][j]=compGrid[i][j];
    /*-------Grids settings-----------*/

    /*-------setting the position of the buttons-------*/
    int xPos = 40, yPos = 202;
    for(int i = 0 ; i < 5 ; ++i){//button Initialization and settings loop
        int xTemp = xPos;
        temp.clear();//resetting the vector
        for(int j = 0; j < 5 ; ++j) {//button Initialization loop
            string s = to_string(playerGrid[i][j]);
            temp.push_back(Button(s, Vector2f(89, 89), 20, Color::White, Color::Black));
        }
        v.push_back(temp);
        for(int k = 0; k < 5; ++k){//button settings loop
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


        while(GameWindow.pollEvent(event)){//event handling loop

            if(event.type == Event::Closed&&(event.mouseButton.button==Mouse::Left)) {
                GameWindow.close();
            }else if(event.type == sf::Event::MouseButtonPressed&&(event.mouseButton.button==Mouse::Left)){//grid buttons click effect and functions
                for(int i = 0; i < 5; ++i){
                    for(int j = 0; j < 5; ++j)
                        if(v[i][j].ismousein(GameWindow)&&!btns_click[i][j]&&playerturn){
                            v[i][j].setBackColor(Color::Magenta);
                            btns_click[i][j]=1;
                            playerturn=false;//ending the player turn

                            for(int l=0;l<5;l++){//searching 1st loop (computer grid)
                                bool ch=0;
                                for(int k=0;k<5;k++){//searching 2nd loop (computer grid)
                                    if(compGrid[l][k]==playerGrid[i][j]){//element found (computer grid)
                                        compGrid[l][k]=0;//converting the button into "pressed" state  (computer grid)

                                        //counting the pressed buttons in every row and column (computer grid)
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

                            playerGrid[i][j]=0;//converting the button into "pressed" state  (player grid)

                            //counting the pressed buttons in every row and column (player grid)
                            if(playerGrid[i][5]!=-1)
                                playerGrid[i][5]++;
                            if(playerGrid[5][j]!=-1)
                                playerGrid[5][j]++;

                            pointsCont(playerPoints,playerGrid);
                            pointsCont(compPoints,compGrid);
                            if(compPoints==5&&!playerWins)compWins=1;//checking for winner

                            switch (playerPoints) {// score counter image loader
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

            }
        }
        if(playerturn){
            turn.setString(player_name+"'s Turn");
        }
        else{//computer turn starting
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
            //tmp is a variable that pick position that should be played by the computer depending on the difficulty level

            for(int l=0;l<5;l++){//searching 1st loop ( player grid )
                bool ch=0;

                for(int k=0;k<5;k++){//searching 2nd loop ( player grid )

                    if(compGrid[tmp.first][tmp.second]==playerGrid[l][k]){//element found
                        playerGrid[l][k]=0;//converting the button into "pressed" state  (player grid)
                        //counting the pressed buttons in every row and column (player grid)
                        if(playerGrid[l][5]!=-1)
                            playerGrid[l][5]++;
                        if(playerGrid[5][k]!=-1)
                            playerGrid[5][k]++;
                        ch=1;
                        tmp2.first=l;tmp2.second=k;//storing the position of the searched element
                        break;
                    }
                }
                if(ch)break;
            }

            compGrid[tmp.first][tmp.second]=0;//converting the button into "pressed" state  (computer grid)
            //counting the pressed buttons in every row and column (computer grid)
            if( compGrid[tmp.first][5]!=-1)
                compGrid[tmp.first][5]++;
            if( compGrid[5][tmp.second]!=-1)
                compGrid[5][tmp.second]++;

            pointsCont(playerPoints,playerGrid);
            pointsCont(compPoints,compGrid);
            if(compPoints==5&&!playerWins)compWins=1;//checking for winner
            if(playerPoints==5&&!compWins)playerWins=1;//checking for winner
        }

        //------draw area------//
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
        //------draw area------//

        if(!playerturn) {
            for (int i = 0; i < time; i++);//time delay for computer's turn
            playerturn=true;
            drawbtn=1;
            switch (playerPoints) {//score counter update
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

    //-------date elements------//
    RenderWindow txtbox(VideoMode(400,100),"Enter the Name",Style::None);
    Textbox name(27,Color::White,true);
    Text t1;
    Vector2i center(350-200,VideoMode::getDesktopMode().height/2 - 50);
    Texture ok_tex,cancel_tex;

    //-------Texture area---------//
    ok_tex.setSmooth(true);
    cancel_tex.setSmooth(true);
    ok_tex.loadFromFile("start_window/Ok_btn.png");
    cancel_tex.loadFromFile("start_window/cancel_btn.png");
    //-------Texture area---------//

    Button ok(&ok_tex),cancel(&cancel_tex);
    //-------date elements------//

    //------data elements settings-------//
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
    //------data elements settings-------//

    while(txtbox.isOpen()){//name enter loop
        Event e;
        while(txtbox.pollEvent(e))//event handling loop
            if(e.type==Event::TextEntered)
                name.typedOn(e);
            else if(e.type==Event::MouseButtonPressed&&(e.mouseButton.button==Mouse::Left)){//buttons press effects

                if(ok.ismousein(txtbox)){
                    ok.setScale({0.9, 0.9});
                }
                else if(cancel.ismousein(txtbox)){
                    cancel.setScale({0.9, 0.9});
                }
            }

            else if (e.type==Event::MouseButtonReleased&&(e.mouseButton.button==Mouse::Left)){//buttons functions
                if(ok.ismousein(txtbox)){
                    ok.setScale({1, 1});
                    txtbox.close();
                }
                else if(cancel.ismousein(txtbox)){
                    cancel.setScale({1, 1});
                    return player_name;
                }
            }

        //-----drawing area------//
        txtbox.clear(Color(127,127,127));
        txtbox.draw(t1);
        name.drawTo(txtbox);
        ok.drawTo(txtbox);
        cancel.drawTo(txtbox);
        txtbox.display();
        //-----drawing area------//

    }//name enter loop end

    player_name =name.getText();
    return player_name;
}

bool start_window_function(string &player_name,int &difficulty,Font &font){//stating window main function
    RenderWindow start_window(VideoMode(700,700),"Start Window",Style::Close);
    start_window.setPosition(Vector2i(0,0));

    /*--------Texture area------*/
    Texture background_texture,start_btn_texture,how_btn_tex;
    background_texture.loadFromFile("start_window/background.jpg");
    start_btn_texture.loadFromFile("start_window/start_btn.png");
    how_btn_tex.loadFromFile("start_window/how_to_play_btn.png");
    /*--------Texture area------*/

    /*--------Data area------*/
    RectangleShape background;
    Button start_btn(&start_btn_texture),how_btn(&how_btn_tex);
    bool isstart=false , error=false;
    /*--------Data area------*/

    /*-------- Setting up data elements -------*/
    start_window.setPosition(Vector2i(0,0));
    background.setTexture(&background_texture);
    background.setPosition(0,0);
    background.setSize(Vector2f(background_texture.getSize()));
    start_btn.setPosition({240, 196});
    how_btn.setPosition(Vector2f(332,597));

    //----------- Easy_btn section ------------//
    Texture Easy_btn_Texture;
    Easy_btn_Texture.loadFromFile("start_window/easy_btn_np.png");
    Button Easy_btn(&Easy_btn_Texture);
    Easy_btn.setPosition({31, 365});
    bool Changed_Easy_btn = false;
    //----------- End_Of_Easy_Btn section --------//

    // ---------- Medium_btn section ------------//
    Texture Medium_btn_Texture;
    Medium_btn_Texture.loadFromFile("start_window/meduim_btn_np.png");
    Button Medium_btn(&Medium_btn_Texture);
    Medium_btn.setPosition({30, 480});
    bool Changed_Medium_btn = false;
    //---------- End_of_Medium_btn section ---------//

    //---------- Hard_brn section ----------------//
    Texture Hard_btn_Texture;
    Hard_btn_Texture.loadFromFile("start_window/hard_btn_np.png");
    Button Hard_btn (&Hard_btn_Texture);
    Hard_btn.setPosition({30, 590});
    bool Changed_Hard_btn = false;
    //----------- End_Of_Hard_Btn section ----------//
    /*-------- Setting up data elements -------*/

    while(start_window.isOpen()){//start window loop
        Event startW_event;
        if(isstart){//to check if Start button is pressed or not
            isstart=false;
            player_name = nameEnter(font,player_name);
            if(!player_name.empty())start_window.close();
        }else if(error){
            Show_Error_Window(font);
            error =false;
        }

        while(start_window.pollEvent(startW_event))//event handling loop
            switch (startW_event.type) {
                case Event::Closed:
                    if(startW_event.mouseButton.button==Mouse::Left) {
                        start_window.close();
                        return 0;//means that the starting elements has not been processed correctly.

                    }break;
                case Event::MouseButtonPressed://to make the "Click" Effect

                    if(start_btn.ismousein(start_window) &&(startW_event.mouseButton.button==Mouse::Left))
                        start_btn.setScale({0.9,0.9});

                    else if(Easy_btn.ismousein(start_window)&&(startW_event.mouseButton.button==Mouse::Left)) {
                        if (!Changed_Hard_btn && !Changed_Medium_btn)
                            Easy_btn.setScale({0.9, 0.9});
                    }
                    else if(Medium_btn.ismousein(start_window)&&(startW_event.mouseButton.button==Mouse::Left)) {
                        if(!Changed_Easy_btn && !Changed_Hard_btn)
                            Medium_btn.setScale({0.9, 0.9});
                    }
                    else if(Hard_btn.ismousein(start_window)&&(startW_event.mouseButton.button==Mouse::Left)){
                        if(!Changed_Easy_btn && !Changed_Medium_btn)
                            Hard_btn.setScale({0.9, 0.9});
                    }
                    else if(how_btn.ismousein(start_window)&&(startW_event.mouseButton.button==Mouse::Left)){
                        how_btn.setScale({0.9,0.9});
                    }
                    break;

                case Event::MouseButtonReleased:// to do the actual function of the button
                    if(start_btn.ismousein(start_window)&&(startW_event.mouseButton.button==Mouse::Left)) {
                        start_btn.setScale({1, 1});
                        if(Changed_Easy_btn||Changed_Hard_btn||Changed_Medium_btn)
                            isstart=true;
                        else
                            error =true;}
                    else if(Easy_btn.ismousein(start_window)&&(startW_event.mouseButton.button==Mouse::Left)) {
                        if(!Changed_Easy_btn && !Changed_Medium_btn && !Changed_Hard_btn) {
                            Easy_btn.setScale({1, 1});
                            Easy_btn_Texture.loadFromFile("start_window/easy_btn_p.png");
                            Changed_Easy_btn = true;
                        }else{
                            Easy_btn.setScale({1, 1});
                            Easy_btn_Texture.loadFromFile("start_window/easy_btn_np.png");
                            Changed_Easy_btn = false;
                        }
                    }else if(Medium_btn.ismousein(start_window)&&(startW_event.mouseButton.button==Mouse::Left)){
                        if(!Changed_Medium_btn && !Changed_Hard_btn && !Changed_Easy_btn){
                            Medium_btn.setScale({1, 1});

                            Medium_btn_Texture.loadFromFile("start_window/meduim_btn_p.png");
                            Changed_Medium_btn = true;
                        } else{
                            Medium_btn.setScale({1, 1});
                            Medium_btn_Texture.loadFromFile("start_window/meduim_btn_np.png");
                            Changed_Medium_btn = false;
                        }
                    }else if(Hard_btn.ismousein(start_window)&&(startW_event.mouseButton.button==Mouse::Left)){
                        if(!Changed_Hard_btn && !Changed_Medium_btn && !Changed_Easy_btn){
                            Hard_btn.setScale({1, 1});
                            Hard_btn_Texture.loadFromFile("start_window/hard_btn_p.png");
                            Changed_Hard_btn = true;
                        }else{
                            Hard_btn.setScale({1, 1});
                            Hard_btn_Texture.loadFromFile("start_window/hard_btn_np.png");
                            Changed_Hard_btn = false;
                        }
                    }
                    else if(how_btn.ismousein(start_window)&&(startW_event.mouseButton.button==Mouse::Left)){
                        how_btn.setScale({1,1});
                        //---how to play window creation---//

                        /*-----data area-----*/
                        RenderWindow how_window;
                        RectangleShape backg;
                        Texture backg_tex;
                        /*-----data area-----*/

                        /*-----settings area-----*/
                        how_window.create(VideoMode(700,700),"How to Play ",Style::Close);
                        how_window.setPosition({0,0});
                        backg_tex.loadFromFile("start_window/help_txt.jpg");
                        backg.setTexture(&backg_tex);
                        backg.setSize(Vector2f(700,700));
                        /*-----settings area-----*/

                        while (how_window.isOpen()){// the main window loop
                            Event how_event;
                            while(how_window.pollEvent(how_event)){
                                if(how_event.type==Event::Closed&&(how_event.mouseButton.button==Mouse::Left)){
                                    how_window.close();
                                }
                            }
                            /*----draw area----*/
                            how_window.draw(backg);
                            how_window.display();
                            /*----draw area----*/
                        }
                    }
                    break;
            }
        //-----draw area-----//
        start_window.draw(background);
        start_btn.drawTo(start_window);
        how_btn.drawTo(start_window);
        Easy_btn.drawTo(start_window);
        Medium_btn.drawTo(start_window);
        Hard_btn.drawTo(start_window);
        start_window.display();
        //-----draw area-----//
    }//the end of the start window loop

    /*--------select difficulty---------*/
    if(Changed_Easy_btn)difficulty=1;
    else if(Changed_Medium_btn)difficulty=2;
    else difficulty =3;
    /*--------select difficulty---------*/

    return 1;//means that the starting elements has been processed correctly.
}
