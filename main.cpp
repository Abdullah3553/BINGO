/*---------BINGO---------*/
#include "headers/Main_Functions.h"


int main(){
    //------------Global Data-----------//
    string player_name;
    int difficulty;
    Font font;
    bool playerwin;
    int compGrid[6][6]={},compGridCopy[6][6]={};
    //------------Global Data-----------//

    font.loadFromFile("font/ARLRDBD.TTF");
    if(start_window_function(player_name,difficulty,font)){

        if(GameWindow(player_name,difficulty,font,playerwin,compGrid,compGridCopy))
        while(Game_End(playerwin,font,difficulty,compGrid,compGridCopy)){
            Change_Difficulty(difficulty,font);

            for(int i=0;i<6;i++)//reset the computer grids
                for(int j=0;j<6;j++){
                    compGrid[i][j]=0;
                    compGridCopy[i][j]=0;
                }

            if(!GameWindow(player_name,difficulty,font,playerwin,compGrid,compGridCopy))break;
        }

    }

    return 0;
}
