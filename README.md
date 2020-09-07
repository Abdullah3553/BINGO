# Welcome to BINGO :D 
BINGO is a singleplayer game that depends on both luck and logical thinking and stratigical thinking. 
The game is quite simple. There are 3 different levels of difficulties. Each level of them depends on an algorithm and luck.
We will go over all of it.

# What is BINGO ? 
Bingo is a game which both the player and the computwer has a 5x5 grid filld with random ordered numbers from 1 to 25.
The player has unique sequance of numbers and it's different of the sequance that the computer has on its grid.
Simply, the player will choose a number from his grid and will mark that number as selected in both the player grid and the computer grid. 
Whenever the player complete a whole row or column with all numbers in that row or column marked as selected, the player will win a point. 
If the player reaches 5 point, then the player wins. The same process will haapen with the computer on its grid. 

# Luck vs strategies
The computer play with a specific strategy for each difficulty level. The difficulty does not only depends on the strategy that the computer is playing with, it also depeneds somehow on luck! Because, both grids( the player grid and the computer grid ) are filled with a *random* different sequance of numbers. So, if you are lucky, you will find some numbers of your grid that has been choosen by the computer (on his grid) will intersect with a row or a column that you are already tring the mark it all. So, this will help you the mark your row or column faster and that will give you an advantage. Later on, maybe you will reach 5 points before the computer. Don't forget the same process could happen when you choose your number. 

# HOW DOES IT WORK ? 
As we said before, there are 3 levels of difficulties. The first level is Easy. The algorithm for this level is easy and simple. The computer will choose the numbers of the grid randomly. So, the computer depends 100% on the luck.

The second level is Meduim. This one is a little bit smarter. On each computer turn, the computer will search in the whole grid and cehck which row or column is closer to be fully marked and will keep marking at that row or column until it's completely selected. This one depends on luck and the strategy we showed before.

The third and the last level is Hard. This level is a little bit tricky. The computer will play with same strategy we described in the Meduim level. But, the computer will try to optimize the result. Insteade of picking the a random number from the row or the column, it will check for all numbers in that row or column and pick the best number on that  row that intersects with the other columns.
For example, let's consider the following situation on the computer grid : ( x means the number is selecetd and o means that it's not selected) 


   1  2  3  4  5 
 1 o  o  o  o  x
 2 o  o  o  o  o
 3 x  x  o  x  o
 4 o  x  x  o  o
 5 o  o  o  o  x
 
 
 after applying the strategy of the Meduim level, the computer should select row number 3 as the best play. But with that addition in the *Hard* level. The best point to be selecetd in row number 3 is point number 5. Because, it will intersect with another column ( in this case column number 5 ) and the computer will be able to play on that column latter . 
That absolotly optimaizes the way that the algorithm works. Ofcourse it depends also on luck with some percentage, but this strategy is much better than the Meduim one and it gives a better results. 

# HOW DOES WE BUILD ALL OF THAT ?
SFML :) 
everythins in this game has been written in C++. We used the famous *Simple and Fast Multimedia Library* ( SFML ). 

# WHY SFML ? 
Because it's fast and simple. Also, it works with C++ and almost all members in our team know how to program with C++ very well. 

# I WANT TO PLAY TOO !
Do you want to try the game yourself ? No problem :) 
The game is already availabe. All you have to do is :
- Download the repository as a ZIP archive.  
- Unzip the archive.
- Open the project.cbp file using CodeBlocks.
- Rebuild the project.
- Hit the run button.
that's it :) pretty simple haa ? :D 

# Final Words
We'ev been working so hard on that project so, if you find any errors or you have any ideas don't be shy and contact us. :)
Thanks for reading .
