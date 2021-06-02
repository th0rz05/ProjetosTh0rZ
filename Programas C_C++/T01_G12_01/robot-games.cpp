// T01_G12


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>


using namespace std;

//FUNCTION DECLARATION
/**
    Draws the title on the screen.
*/
void Title();

/**
    Reads an integer and tests if it is valid.
    @param input Integer read passed by reference.
    @return Returns 1 if the input was valid and 0 otherwise.
*/
bool readInteger(int &input);

/**
    Introduction of the program.
    @return Returns the chosen option.
*/
int Introduction();

/**
    Introduction of the program.
    @return Returns true to know when to return to menu and false if CTRL-Z
*/
bool Rules();

/**
    Asks for a maze number until a valid one is given.
    @return Returns the chosen maze's file name.
*/
string chooseMaze();

/**
    Reads a maze from a file and stores it in a vector.
    @param maze Multidimensional vector where maze is stored.
    @param maze_file Stores the name of the chosen file.
    @return 0 to return to menu, 1 to exit program, 2 if sucessfully drawn the maze.
*/
int readMaze(vector<vector<char> > &maze, string& maze_file);

/**
    Handles the text file containg the scores.
    @param maze_file The file name from the maze being used.
*/
void displayWinner(string maze_file, string finish_time);

/**
    Searches the maze for the player.
    @param player The player.
    @param maze Multidimensional vector where maze is stored.
*/
void findPlayer(struct player &player, vector<vector<char> > maze);

/**
    Changes the players coords acoording to a move.
    @param player The player.
    @param move Char that represents a movement.
    @return 1 if the move was valid and 0 otherwise.
*/
bool movePlayer(struct player &player, char move);

/**
    Rewind the players position.
    @param player The player.
    @param move Char that represents the previous movement.
*/
void rewindPlayer(struct player &player, char move);

/**
    Draws a maze.
    @param maze Multidimensional vector where maze is stored.
*/
void drawMaze(vector<vector<char> > maze);

/**
    Iterates trough the maze to store the robots information in a vector.
    @param robots Vector where all the robots are stored.
    @param maze Multidimensional vector where maze is stored.
*/
void findRobots(vector<struct robot> &robots, vector<vector<char> > maze);

/**
    Moves the robot to the position it is closest to the player.
    @param robot The robot to move.
    @param player The player.
*/
void moveRobot(struct robot &robot, struct player &player);

/**
    Moves all the robots in the maze closer to the player.
    @param robots Vector containing all the robots to be moved.
    @param player The player.
    @param maze Multidimensional vector where maze is stored.
*/
void moveAllRobots(vector<struct robot> &robots, struct player &player, vector<vector<char> > &maze);

/**
    Removes all the robots at a certain position from the vector.
    @param robots Vector containing all the robots to be moved.
    @param x x coordinate.
    @param y y coordinate.
*/
void removeRobots(vector<struct robot> &robots, int x, int y);

/**
    Resets all parameters to their default value.
    @param maze Multidimensional vector where maze is stored.
    @param robots Vector where all the robots are stored.
    @param play Stores the current display state.
    @param menu Stores the current display state.
    @param reset_time Stores the current reset time state.
*/
void restartGame(vector<vector<char> > &maze, vector<struct robot> &robots, bool &play, bool &menu, bool &reset_time);

//----------------------------------------------------------------------------------------------------------------

struct player
{
    int x;
    int y;
} player;

struct robot
{
    int id;
    int x;
    int y;
};

// MAIN FUNCTION

int main()
{
    int action;
    int result_read_maze;
    time_t time_counter;
    char move;
    bool menu = true;
    bool rules = false;
    bool play = false;
    bool reset_time = true;
    string finish_time;
    string file_name;

    vector<vector<char> > maze; //variable declaration
    vector<struct robot> robots;

    while (true)
    {
        if (menu)
        {
            Title(); // show title
            action = Introduction(); // action that the user inputs

            //test the input for the intro

            if (action == 0 || action == 3)
            {
                return 0; // end of program
            }
            if (action == 1)
            {
                menu = false;
                rules = true;
            }
            if (action == 2)
            {
                result_read_maze = readMaze(maze, file_name); // stores the option
                findPlayer(player, maze);          //stores the players coords
                findRobots(robots, maze);          //stores all the robots

                if (result_read_maze == 2)
                {
                    play = true;
                    menu = false;
                }
                else if (result_read_maze == 0)
                {
                    continue; //returns to menu
                }
                else if (result_read_maze == 1)
                {
                    return 0; // end program because ctrl-z
                }
            }
        }

        if (rules) // show the rules
        {
            if (Rules())
            {
                rules = false;
                menu = true; // return to menu
            }
            else
            {
                return 0; // end of program because of CtrL-Z
            }
        }

        if (play)
        {
            cout << "\n"; // leave space between choose maze and the draw
            drawMaze(maze);
            time_t current_time = time(nullptr);
            if (reset_time){
                time_counter = current_time;    // resets the timer
                reset_time = false;   
            }
            cout << "\n";
            findPlayer(player, maze);
            maze[player.y][player.x] = ' '; //clear the player's position so it can move

            do
            {
                cout << "Perform a movement: ";
                cin >> move;
                cin.ignore(100000, '\n');
                if (cin.fail() && cin.eof()) //check if ctrl + z was pressed
                {
                    cout << "EXIT";
                    return 0;
                }
            } while (!movePlayer(player, move)); //check if the move was valid

            
            moveAllRobots(robots, player, maze);
            if (robots.size() == 0) //checks if the player has won
            {
                maze[player.y][player.x] = 'H';
                drawMaze(maze);
                cout << "YOU WIN!!!" << endl;
                finish_time = to_string(time(nullptr)- time_counter);
                cout << "It took you " << finish_time << "s." << endl;
                displayWinner(file_name, finish_time);
                restartGame(maze, robots, play, menu,reset_time);
            }
            else if (maze[player.y][player.x] == 'r') //check for collisions with destroyed robots
            {
                cout << "\nInvalid move. You can't move to a place where a robot is!\n";
                rewindPlayer(player, move); // returns to previous position
                maze[player.y][player.x] = 'H';
            }
            else if (maze[player.y][player.x] != ' ') //check for collisions with obstacles
            {
                maze[player.y][player.x] = 'h'; // change state of player to dead
                cout << "\n";                   // leave space between choose maze and the draw
                drawMaze(maze);                 // display where the player died
                cout << "\nYOU LOST!!!\n\n";
                restartGame(maze, robots, play, menu,reset_time);
            }
            else
            {
                maze[player.y][player.x] = 'H'; //move the player in the maze
            }
        }
    }
    return 0;
}

//----------------------------------------------------------------------------------------------------------------

//FUNCTION DEFINITIONS

/**
    Draws the title on the screen.
*/
void Title()
{
    // ascii art
    cout << " _____   _____   _____   _____   _____     _____    ___    __  __   _____" << endl;
    cout << "| ___ \\ |  _  | | ___ \\ |  _  | |_   _|   |  __ \\  / _ \\  |  \\/  | |  ___|" << endl;
    cout << "| |_/ / | | | | | |_/ / | | | |   | |     | |  \\/ / /_\\ \\ | .  . | | |__" << endl;
    cout << "|    /  | | | | | ___ \\ | | | |   | |     | | __  |  _  | | |\\/| | |  __|" << endl;
    cout << "| |\\ \\  \\ \\_/ / | |_/ / \\ \\_/ /   | |     | |_\\ \\ | | | | | |  | | | |___ " << endl;
    cout << "\\_| \\_|  \\___/  \\____/   \\___/    \\_/      \\____/ \\_| |_/ \\_|  |_/ \\____/ " << endl
         << endl
         << endl;
}

/**
    Reads an integer and tests if it is valid.
    @param input Integer read passed by reference.
    @return Returns 1 if the input was valid and 0 otherwise.
*/
bool readInteger(int &input)
{
    while (1)
    {
        cin >> input;

        if (cin.fail()) // if fail
        {
            if (cin.eof()) // if ctrl-Z is pressed
            {
                cout << "EXIT";
                return 0; //exit
            }
            else // not integer
            {
                cin.clear();
                cin.ignore(100000, '\n');
                cout << "Invalid Input! Try again!\n\n";
                cout << "Option: ";
            }
        }
        else
            return 1; //input successful
    }
}

/**
    Resets all parameters to their default value.
    @param maze Multidimensional vector where maze is stored.
    @param robots Vector where all the robots are stored.
    @param play Stores the current display state.
    @param menu Stores the current display state.
    @param reset_time Stores the current reset time state.
*/
void restartGame(vector<vector<char> > &maze, vector<struct robot> &robots, bool &play, bool &menu, bool &reset_time)
{
    maze.clear(); // clear the vector
    robots.clear();
    play = false;
    menu = true; //return to the menu
    reset_time = true; // resets the timer
}

/**
    Introduction of the program.
    @return Returns the chosen option.
*/
int Introduction()
{
    int option;

    //menu
    cout << "\t\t\t\t1) RULES" << endl;
    cout << "\t\t\t\t2) PLAY" << endl;
    cout << "\t\t\t\t0) EXIT" << endl
         << endl;

    //input
    while (true)
    {
        cout << "Option: ";
        if (readInteger(option))
        {
            if (option == 0 || option == 1 || option == 2)
            {
                // input valid
                return option;
            }
            else
                cout << "Invalid Input! Try again!\n\n";
        }
        else
            return 3; //exit
    }
}

/**
    Introduction of the program.
    @return Returns true to know when to return to menu and false if CTRL-Z
*/
bool Rules()
{
    int input;

    //show all the rules
    cout << "\t\t\t\t  RULES" << endl
         << endl;
    cout << "The player is placed in a maze made up of high-voltage fences and posts.\nThere are also some interceptor robots that will try to destroy the player.";
    cout << "If the player touches the maze or any of these robots, that is the end of the game (and the player!).";
    cout << "The robots are also destroyed when they touch the fences/posts or when they collide with each other." << endl;
    cout << "Every time the player moves in any direction to a contiguous cell, each robot moves one cell closer to the new player location, in whichever direction is the shortest path.";
    cout << "The robots have no vision sensors but they have an accurate odour sensor that allows them to follow the player!" << endl;
    cout << "There is one hope: make the robots hit the maze or each other.If all of them are destroyed, the player wins." << endl
         << endl;
    cout << "In the draw of the maze:" << endl;
    cout << "* = electrical fence or post;" << endl;
    cout << "H = player (alive); h = player (dead); the player dies when he/she collides with a fence or a post, or is captured by a robot;" << endl;
    cout << "R = robot (alive); r = robot (destroyed=dead/stuck); a dead robot is one that collided with a fence or a post; a stuck robot is one that collided with another robot (alive or destroyed)" << endl
         << endl;
    cout << "The movement is indicated by typing one of the letters indicated below(the position of each letter relatively to the players position indicates the movement that the player wants to do):" << endl
         << endl;
    cout << "\t\t\tQ\t\tW\t\tE\n\t\t\tA\t players position\tD\n\t\t\tZ\t\tX\t\tC" << endl
         << endl;
    cout << "The player has the option to stay in his/her current position by typing 'S'." << endl
         << endl;
    cout << "\t\t\t\t0)Menu" << endl;

    //input
    while (true)
    {
        cout << "Option: ";

        if (readInteger(input))
        {
            if (input == 0)
                return 1;
        }
        else
            return 0; //exit
        cout << "Invalid Input! Try again!\n\n";
    }
}

/**
    Asks for a maze number until a valid one is given.
    @return Returns the chosen maze's file name.
*/
string chooseMaze()
{
    int maze_number;

    while (1) //main loop
    {
        cout << "\nChoose a maze (input 0 to return to main menu) :  ";

        if (!readInteger(maze_number))
            return "EXIT";

        string file_name;
        if (maze_number == 0)
        {
            cout << endl;  //design purposes
            return "MENU"; // return to menu
        }
        else if (maze_number < 10)
        {
            file_name = "MAZE_0" + to_string(maze_number) + ".txt"; //formats the fileName string
        }
        else
        {
            file_name = "MAZE_" + to_string(maze_number) + ".txt"; //formats the fileName string
        }

        ifstream file(file_name); //tries to open an existing file
        if (file.is_open())       //checks if the file exists
            return file_name;
        else
        {
            cout << "That maze does not exist.\n";
        }
    }
}

/**
    Reads a maze from a file and stores it in a vector.
    @param maze Multidimensional vector where maze is stored.
    @return 0 to return to menu, 1 to exit program, 2 if sucessfully drawn the maze.
*/
int readMaze(vector<vector<char> > &maze, string& file_name)
{
    char column;       //stores the column being read
    vector<char> line; //stores the line being read

    file_name = chooseMaze(); //asks the user for a maze

    if (file_name == "MENU")
    {
        return 0; // return to menu
    }
    if (file_name == "EXIT")
    {
        return 1; // exit program because ctrl-z
    }
    ifstream maze_file;
    maze_file.open(file_name); //opens the file

    int width, height; //maze dimensions

    maze_file >> height;

    maze_file.get(column);
    while (column < '0' || column > '9') //ignores the non-digit characters
        maze_file.get(column);
    maze_file.unget();

    maze_file >> width;
    maze_file.get(column); //reads '\n' so it can be ignored

    for (int i = 0; i < height; i++) //iterates the lines
    {
        line.clear();                   //resets the line
        for (int j = 0; j < width; j++) //iterates the columns
        {
            maze_file.get(column); //reads a character
            line.push_back(column); //adds it to the line vector
        }
        maze_file.get(column); //reads '\n' so it can be ignored
        maze.push_back(line);  //adds the line to the vector
    }
    return 2; // Drawn with sucess
}

/**
    Handles the text file containg the scores.
    @param maze_file The file name from the maze being used.
*/
void displayWinner(string maze_file, string finish_time)
{
    string winner;
    do 
    {
        cout << "Insert your name (max 15 characters): ";
        getline(cin,winner);
    } while (winner.size() > 15);
    winner.insert(winner.size(), 15 - winner.size(), ' '); //fill with ' '
    cout << endl;

    maze_file.insert(7, "_WINNERS");

    ofstream writing;  
    ifstream reading;

    reading.open(maze_file);
    string line;
    vector<string> scoreboard; //list of all the previous winners
    while (getline(reading, line))
    {
        if (line != "----------------------" && line != "Player         - Time")
            scoreboard.push_back(line);
    }
    reading.close();
    scoreboard.push_back(winner + "-  " + finish_time); //add the winner to the list

    for (size_t i = 0; i < scoreboard.size();i++){                 // reorder the scoreboard by time      
        for (size_t j = i + 1; j < scoreboard.size();j++){
            
            string substr1,substr2;
            int time1,time2;

            time1 = stoi(scoreboard.at(i).substr(18));       // change to integer
            time2 = stoi(scoreboard.at(j).substr(18));

            if(time2 < time1){                                  // swap if time2 less than time 1
                string temp ;
                temp = scoreboard.at(i);
                scoreboard.at(i) = scoreboard.at(j);
                scoreboard.at(j) = temp;
            } 
        }
    } 
    
    //WIP

    writing.open(maze_file);
    writing << "Player         - Time\n" << "----------------------\n";
    cout << "Player         - Time\n" << "----------------------\n";
    for (size_t i = 0; i < scoreboard.size(); i++)
    {
        writing << scoreboard[i] << endl;
        cout << scoreboard[i] << endl;
    }
    cout << endl;
    writing.close();
}

/**
    Iterates trough the maze to store the robots information in a vector.
    @param robots Vector where all the robots are stored.
    @param maze Multidimensional vector where maze is stored.
*/
void findRobots(vector<struct robot> &robots, vector<vector<char> > maze)
{
    int id = 1;
    for (int i = 0; i < (int) maze.size(); i++) //iterates the lines
    {
        for (int j = 0; j < (int) maze[i].size(); j++) //iterates the columns
        {
            if (maze[i][j] == 'R')
            {
                struct robot temp = {id, j, i};
                robots.push_back(temp);
                id++;
            }
        }
    }
}

/**
    Moves the robot to the position it is closest to the player.
    @param robot The robot to move.
    @param player The player.
*/
void moveRobot(struct robot &robot, struct player &player)
{
    if (robot.x < player.x)
        robot.x++;
    else if (robot.x > player.x)
        robot.x--;
    if (robot.y < player.y)
        robot.y++;
    else if (robot.y > player.y)
        robot.y--;
}

/**
    Moves all the robots in the maze closer to the player.
    @param robots Vector containing all the robots to be moved.
    @param player The player.
    @param maze Multidimensional vector where maze is stored.
*/
void moveAllRobots(vector<struct robot> &robots, struct player &player, vector<vector<char> > &maze)
{
    for (size_t i = 0; i < robots.size(); i++)
    {   
        maze[robots[i].y][robots[i].x] = ' ';
        moveRobot(robots[i], player);                       //moves a single robot into its new position
        if (tolower(maze[robots[i].y][robots[i].x]) == 'r') //check if it moved into another robot
        {
            maze[robots[i].y][robots[i].x] = 'r';
            removeRobots(robots, robots[i].x, robots[i].y); //remove the robots from the vector
            i--;                                            // go back in the loop
        }
        else if (maze[robots[i].y][robots[i].x] == '*')     //check if it moved into a fence
        {
            maze[robots[i].y][robots[i].x] = 'r';           //deactivate the fence
            removeRobots(robots, robots[i].x, robots[i].y); //remove the robots from the vector
            i--;                                            // go back in the loop
        }
        else
        {
            maze[robots[i].y][robots[i].x] = 'R';
        }
    }
}

/**
    Removes all the robots at a certain position from the vector.
    @param robots Vector containing all the robots to be moved.
    @param x x coordinate.
    @param y y coordinate.
*/
void removeRobots(vector<struct robot> &robots, int x, int y)
{
    for (size_t i = 0; i < robots.size(); i++)
    {
        if (robots[i].x == x && robots[i].y == y){
            robots.erase(robots.begin() + i);     
            i--;    // go back in the loop
        }
        
    }
}

/**
    Searches the maze for the player.
    @param player The player.
    @param maze Multidimensional vector where maze is stored.
*/
void findPlayer(struct player &player, vector<vector<char> > maze)
{
    for (size_t i = 0; i < maze.size(); i++) //iterates the lines
    {
        for (size_t j = 0; j < maze[i].size(); j++) //iterates the columns
        {
            if (tolower(maze[i][j]) == 'h')
                player.x = j, player.y = i;
        }
    }
}

/**
    Changes the players coords acoording to a move.
    @param player The player.
    @param move Char that represents a movement.
    @return 1 if the move was valid and 0 otherwise.
*/
bool movePlayer(struct player &player, char move)
{
    switch (tolower(move))
    {
    case 'q':
        player.x--, player.y--;
        break;
    case 'w':
        player.y--;
        break;
    case 'e':
        player.x++, player.y--;
        break;
    case 'a':
        player.x--;
        break;
    case 's':
        break;
    case 'd':
        player.x++;
        break;
    case 'z':
        player.x--, player.y++;
        break;
    case 'x':
        player.y++;
        break;
    case 'c':
        player.x++, player.y++;
        break;
    default:
        cout << "Invalid movement!" << endl
             << endl;
        return 0;
    }
    return 1;
}

/**
    Rewind the players position.
    @param player The player.
    @param move Char that represents the previous movement.
*/
void rewindPlayer(struct player &player, char move)
{
    switch (tolower(move))
    {
    case 'q':
        movePlayer(player, 'c');
        break;
    case 'w':
        movePlayer(player, 'x');
        break;
    case 'e':
        movePlayer(player, 'z');
        break;
    case 'a':
        movePlayer(player, 'd');
        break;
    case 'd':
        movePlayer(player, 'a');
        break;
    case 'z':
        movePlayer(player, 'e');
        break;
    case 'x':
        movePlayer(player, 'w');
        break;
    case 'c':
        movePlayer(player, 'q');
        break;
    default:
        break;
    }
}

/**
    Draws a maze.
    @param maze Multidimensional vector where maze is stored.
*/
void drawMaze(vector<vector<char> > maze)
{
    for (size_t i = 0; i < maze.size(); i++) //iterates the lines
    {
        for (size_t j = 0; j < maze[i].size(); j++) //iterates the columns
        {
            cout << maze[i][j];
        }
        cout << endl;
    }
}

