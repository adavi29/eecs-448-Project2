#include "Player.h"
#include <time.h>
Player::Player()
{

}
Player::Player(int shipNums,string name)
  {
      numShips = shipNums;
      ownShips = new Ship[shipNums];
      for (int i = 1; i <= shipNums; i++)
      {
        Ship tempShip(i);
        ownShips[i-1] = tempShip;
      }
      placeShips();
      namee = name;
  }
Player::~Player()
{
  delete[] ownShips;
}
Board Player::getBoard(char choice)
{
  if(choice == 'o')//if choice is own board, return own board.
  {
    return(ownBoard);
  }
  else //if choice is enemy board, return enemy board.
  {
    return(enemyBoard);
  }

}
void Player::placeShips()
  {
    string tempOrient = "$";
    string tempCoord = "";
    for(int i = 0; i < numShips; i++)
    {
      int xVal =0;
      int yVal =0;
      bool validX = true;
      bool validY = true;
      do
      {
        cout<<"Placing Ship of Size: "<<(i+1);
        while (tempOrient != "h" && tempOrient != "v")
        {
        cout<<"\nPlease input an orientation (v for Vertical or h for Horizontal): ";
        cin>>tempOrient;
        if (tempOrient != "h" && tempOrient != "v")
          {
            cout<<"Pick a valid option this time.\n";
          }
        }
        ownShips[i].setOrientation(tempOrient);
      validX = true;
      validY = true;
      char xTemp = ' ';
      string playerShot = "";
      bool validInput= 1;
      do
      {
      LOOP:cout<<"Input a position for the front of the ship: ";
      cin >> playerShot;
      validInput= 1;
        try
        {
          xTemp = tolower(playerShot.at(0));
          yVal = playerShot.at(1);
        }
        catch(...)
        {
          cout<<"Position must be in format: 'a1'\n";
          validInput = 0;
        }
      }while(validInput == 0);
          switch (xTemp)
      	{
                 case 'a':
      		xVal = 0;
      		break;
      	         case 'b':
      		xVal = 1;
      		break;
                 case 'c':
      		xVal = 2;			//switch block tcout <<"\nstart of player constructor.\n";ransforms first char in input string from the player into integer value.
      		break;
      	         case 'd':
      		xVal = 3;
      		break;
                 case 'e':
      		xVal = 4;
      		break;
      	         case 'f':
      		xVal = 5;
      		break;
                 case 'g':
      		xVal = 6;
      		break;
      	         case 'h':
      		xVal = 7;
      		break;
      	         default:
      		cout <<"X Position Out of Bounds!\n";
          validX = false;
      		break;
        }
          switch (yVal)
      	{
                 case '1':
      		yVal = 0;
      		break;
      	         case '2':
      		yVal = 1;
      		break;
                 case '3':
      		yVal = 2;			//switch block transforms second char into integer value for grid.
      		break;
      	         case '4':
      		yVal = 3;
      		break;
                 case '5':
      		yVal = 4;
      		break;
      	         case '6':
      		yVal = 5;
      		break;
                 case '7':
      		yVal = 6;
      		break;
      	         case '8':
      		yVal = 7;
      		break;
      	         default:
      		cout <<"Y Position Out of Bounds!\n";
          validY = false;
      		break;
      	}
        if(tempOrient == "v")
        {
          if (yVal + i + 1 > 8)
          {
            cout<<"Ship out of bounds!\n";
            validY = false;
          }
          else
          {
            for(int k =0; k<i+1; k++)
            {
              try
              {
                if(ownBoard.getPos(yVal+k,xVal) == 's')
                {
                  cout<<"\nCannot Stack Ships!\n";
                  goto LOOP;
                }
                ownBoard.setPos(yVal+k,xVal,'s');
              } catch (const exception& e) {cout << "an error occured on ship place" << e.what() << endl;}
            }
          }
        }
        else if (tempOrient == "h")
        {
          if (xVal + i + 1 > 8)
          {
            cout<<"Ship out of bounds!\n";
            validX = false;
          }
          else
          {
            for(int k =0; k<i+1; k++)
            {
              try
              {
                if(ownBoard.getPos(yVal,xVal+k) == 's')
                {
                  cout<<"\nCannot Stack Ships!\n";
                  goto LOOP;
                }
                ownBoard.setPos(yVal,xVal+k,'s');
              } catch (const exception& e) {cout << "an error occured on ship place" << e.what() << endl;}
            }
          }
        }
        tempOrient = 'n'; //sets tempOrient to meaningless val for while loop.
      }
      while (!validX || !validY);
      ownShips[i].setPositions(xVal, yVal);
      ownBoard.printBoard();

    }
  }
bool Player::fireShot(int row, int col, Player &target)
{
    if(target.getBoard('o').getPos(col,row) == 's') //where s represents a ships presence. 'o represents the targets "ownBoard"'
    {
        target.receiveHit(row, col);
        enemyBoard.setPos(col,row, 'h');//h represents a ship turned into a hit
        return true;
    }
    else if(target.getBoard('o').getPos(col,row) == '|')// '|' represents empty water
    {
      enemyBoard.setPos(col,row,'m');//m represents a miss that landed in water.
      return false;
    }
    return false;
}

void Player::receiveHit(int xPos, int yPos)
{
ownBoard.setPos(yPos, xPos, 'h');
  for (int i = 0; i < numShips; i++)
  {
    if (ownShips[i].coordCheck(xPos, yPos))
    {
      ownShips[i].addHit();
      break;
    }
  }
}

bool Player::isDead()
{
  bool tempDead = true;
  for (int i = 0; i < numShips; i++)
  {

    if (ownShips[i].isSunk() == false)
    {
      tempDead = false;
    }
  }
  return tempDead;
}
string Player::getName()
{
    return(namee);
}


Player::Player(int shipNums, int aiDifficulty, string aiName)
{
    m_aiDifficulty=aiDifficulty;
    namee=aiName;
    numShips = shipNums;
    ownShips = new Ship[shipNums];
    for (int i = 1; i <= shipNums; i++)
    {
        Ship tempShip(i);
        ownShips[i-1] = tempShip;
    }
    //now we need to place the ships
    placeAiShips();
    /*if(aiDifficulty==1) //only allow user input 1,2 or 3
    {
        
    }
    else if(aiDifficulty==2)
    {
        
    }
    else if(aiDifficulty==3)
    {
        //aiHard(enemyBoard)
    }
    else //if aiDifficulty = $%#(any other char)
    {
      cout<<"please input number in (1,2,3)";  
    }*/
}

int Player::getAiDifficulty()
{
    return(m_aiDifficulty);
}

void Player::placeAiShips()
{
  string tempOrient = "$";
  string tempCoord = "";
  for(int i = 0; i < numShips; i++)
  {
    int xVal =0;
    int yVal =0;
    bool validX = true;
    bool validY = true;
    do
    {
      //cout<<"Placing Ship of Size: "<<(i+1);
      while (tempOrient != "h" && tempOrient != "v")
      {
      //cout<<"\nPlease input an orientation (v for Vertical or h for Horizontal): ";
      tempOrient = randVorH();  //cin>>tempOrient;
      if (tempOrient != "h" && tempOrient != "v")
        {
          //cout<<"Pick a valid option this time.\n";
        }
      }
      ownShips[i].setOrientation(tempOrient);
    validX = true;
    validY = true;
    char xTemp = ' ';
    string playerShot = "";
    bool validInput= 1;
    do
    {
    LOOP://cout<<"Input a position for the front of the ship: ";
    playerShot = randAtoF() + rand0to7();//cin >> playerShot;
    validInput= 1;
      try
      {
        xTemp = tolower(playerShot.at(0));
        yVal = playerShot.at(1);
      }
      catch(...)
      {
        //cout<<"Position must be in format: 'a1'\n";
        validInput = 0;
      }
    }while(validInput == 0);
        switch (xTemp)
      {
               case 'a':
        xVal = 0;
        break;
               case 'b':
        xVal = 1;
        break;
               case 'c':
        xVal = 2;			//switch block tcout <<"\nstart of player constructor.\n";ransforms first char in input string from the player into integer value.
        break;
               case 'd':
        xVal = 3;
        break;
               case 'e':
        xVal = 4;
        break;
               case 'f':
        xVal = 5;
        break;
               case 'g':
        xVal = 6;
        break;
               case 'h':
        xVal = 7;
        break;
               default:
        //cout <<"X Position Out of Bounds!\n";
        validX = false;
        break;
      }
        switch (yVal)
      {
               case '1':
        yVal = 0;
        break;
               case '2':
        yVal = 1;
        break;
               case '3':
        yVal = 2;			//switch block transforms second char into integer value for grid.
        break;
               case '4':
        yVal = 3;
        break;
               case '5':
        yVal = 4;
        break;
               case '6':
        yVal = 5;
        break;
               case '7':
        yVal = 6;
        break;
               case '8':
        yVal = 7;
        break;
               default:
        //cout <<"Y Position Out of Bounds!\n";
        validY = false;
        break;
      }
      if(tempOrient == "v")
      {
        if (yVal + i + 1 > 8)
        {
          //cout<<"Ship out of bounds!\n";
          validY = false;
        }
        else
        {
          for(int k =0; k<i+1; k++)
          {
            try
            {
              if(ownBoard.getPos(yVal+k,xVal) == 's')
              {
                //cout<<"\nCannot Stack Ships!\n";
                goto LOOP;
              }
              ownBoard.setPos(yVal+k,xVal,'s');
            } catch (const exception& e) {/*cout << "an error occured on ship place" << e.what() << endl;*/}
          }
        }
      }
      else if (tempOrient == "h")
      {
        if (xVal + i + 1 > 8)
        {
          //cout<<"Ship out of bounds!\n";
          validX = false;
        }
        else
        {
          for(int k =0; k<i+1; k++)
          {
            try
            {
              if(ownBoard.getPos(yVal,xVal+k) == 's')
              {
                //cout<<"\nCannot Stack Ships!\n";
                goto LOOP;
              }
              ownBoard.setPos(yVal,xVal+k,'s');
            } catch (const exception& e) {/*cout << "an error occured on ship place" << e.what() << endl;*/}
          }
        }
      }
      tempOrient = 'n'; //sets tempOrient to meaningless val for while loop.
    }
    while (!validX || !validY);
    ownShips[i].setPositions(xVal, yVal);
    ownBoard.printBoard();
  }
}


string Player::rand0to7()
{
    unsigned int seed=0;
    seed=time(0);
  srand(seed);
  int x = rand()%8;
  if(x == 0)
  {
    return ("1");
  }
  else if(x == 1)
  {
    return ("2");
  }
  else if(x == 2)
  {
    return ("3");
  }
  else if(x == 3)
  {
    return ("4");
  }
  else if(x == 4)
  {
    return ("5");
  }
  else if(x == 5)
  {
    return ("6");
  }
  else if(x == 6)
  {
    return ("7");
  }
  else// if(x == 7)
  {
    return ("8");
  }
}

string Player::randVorH()
{
  srand(time(0));
  int x = rand()%2;
  if( x == 0)
  {
    return "v";
  }
  else// if VorH == 1
  {
    return "h";
  }
}

string Player::randAtoF()
{
    srand(time(0));
    int x = rand()%8;
    //cout<<"x"<<x<<"..";
    if(x == 0)
    {
      return "a";
    }
    else if(x == 1)
    {
      return "b";
    }
    else if(x == 2)
    {
      return "c";
    }
    else if(x == 3)
    {
      return "d";
    }
    else if(x == 4)
    {
      return "e";
    }
    else if(x == 5)
    {
      return "f";
    }
    else if(x == 6)
    {
      return "g";
    }
    else// if(x == 7)
    {
      return "h";
    }
}

string Player::aiEasy()
{
    return("");
}
string Player::aiMedium(Board enemyBoard)
{
    return("");
}

/*
 *Hit ship every turn
 *set ai bpard randomly //done
 */
string Player::aiHard(Board enemyBoard)
{
    string Pos_x = " ";
    string Pos_y = " ";
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            if(enemyBoard.getPos(i,j)=='s')
            {
                Pos_x = NumtoStrAF(j);
                Pos_y = NumtoStr18(i);
                return (Pos_x + Pos_y);
            }
        }
    }
    if(Pos_x==" " && Pos_y==" ")//this means there is no ship on the board
    {
        return ("all sunk");//does not mean anything but the function need something to returns
    }
    else//find a ship
    {
        return ("nothing");
        //return (Pos_x + Pos_y);
    }
}

string Player::NumtoStrAF(int x)
{
    if(x == 0)
    {
      return "a";
    }
    else if(x == 1)
    {
      return "b";
    }
    else if(x == 2)
    {
      return "c";
    }
    else if(x == 3)
    {
      return "d";
    }
    else if(x == 4)
    {
      return "e";
    }
    else if(x == 5)
    {
      return "f";
    }
    else if(x == 6)
    {
      return "g";
    }
    else// if(x == 7)
    {
      return "h";
    }
}

string Player::NumtoStr18(int x)
{
    if(x == 0)
    {
      return "1";
    }
    else if(x == 1)
    {
      return "2";
    }
    else if(x == 2)
    {
      return "3";
    }
    else if(x == 3)
    {
      return "4";
    }
    else if(x == 4)
    {
      return "5";
    }
    else if(x == 5)
    {
      return "6";
    }
    else if(x == 6)
    {
      return "7";
    }
    else// if(x == 7)
    {
      return "8";
    }
}



