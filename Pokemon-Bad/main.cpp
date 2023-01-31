/**
* @author JonnyT-chocomint, yujiroo & Penguinoucy
*/

//Dear Mrs Strong. Currently non dmg moves do nothing. However, we hope you enjoy the current state of our game! (Miiinimum viable proooducttt :D)

#include "pokemon.h" // this will also include moves.h, & basefunctions.h

//global variables go here
string choice; //variable for input
string choice2; //vfi
string pn; //player name
string pn2; //second player's name
array<Move*, 2> titForTat; //Pokemon 1 and 2's moves
array<Move*, 2> blankForTat;
string mstatus; //move status for type advantages
int finalDamage = 0; //final value of damage after taken into consideration of atk/def/buffs/type advantage
array<Pokemon *, 3> firstPlayerMon; //player 1's pokemon
array<Pokemon *, 3> secondPlayerMon; //player 2's pokemon
array<Pokemon*, 3> basic; // the default team
set<string> blankSet; // a blank set to emepty existing sets

/**
 * Prints the title screen for the game. This will be the first screen the user sees.
 */
void title() {
string blocks; //prints block art from txt file
ifstream file("pokemonTitle.txt");
while (getline (file, blocks)) {
  // Output the text from the file
  cout << blocks << "\n";
}
  file.close();
}

/**
 * Prints the instructions for the game.
 */
void instructions() {
  typeOutFast("Welcome to the (potential) world of Pokemon! Right now, you are in the wonderful Badolas region, the only region with the unique phenomenon they call \"Omni\" moves! A unique set of moves which reliably have no strenghts and weaknesses. But now... both the region's champion and legendary pokemon known as \'Berserker\' are in danger as for a mysterious reason, only one of them are seen at a given time. They also mysteriously refuse to elaborate the situation when asked. The world needs YOU to save the Badolas region. \nIn this world, you can choose between 2 marvelous adventures! Take on the Elite 4 and Champion in Victory Road. \nOR...\nTake on other trainers in multiplayer! Now that you have finished reading the instructions...");
  //allow me to do this yujiro and kevin
}


class Player {
  private:
    string playerName;
    string currentMon;
    Pokemon *activemon;
    array<Pokemon*, 3> pkmn;
    int faintedpkmn;
    string swap;
    int debt;
  public:
  Player(string pn, string cp, Pokemon *p, array<Pokemon*, 3> team, int f, string s, int d) {
    this->playerName = pn;
    this->currentMon = cp;
    this->activemon = p;
    this->pkmn = team;
    this->faintedpkmn = f;
    this->swap = s;
    this->debt = d;
    }

  /**
 * getter method for the player name
 *
 * @return the player name
 */ 
  string getName() {
    return this->playerName;
  }

  /**
 * getter method for current pokemon
 * @return the current pokemon
 */ 
  string getCurrentMon() {
    return this->currentMon;
  }

  /**
 * getter method for the active pokemon
 * @return the active pokemon
 */ 
  Pokemon *getActiveMon() {
    return this->activemon;
  }

  /**
 * getter method for the player's party
 * @return the player's party
 */ 
  array<Pokemon*, 3> getPkmn() {
    return this->pkmn;
  }

  /**
 * getter method for a fainted pokemon
 * @return the fainted pokemon
 */ 
  int getFaintedMon() {
    return this->faintedpkmn;
  }

  /**
 * getter method for the swapped pokemon
 * @return the swap
 */ 
  string getSwap() {
    return this->swap;
  }

  /**
 * getter method for 
 * @return the debt
 */ 
  int getDebt() {
    return this->debt;
  }


  /**
  * setter method for player name
  * @param player name as a string
  */
  void setName(string pn) {
      this->playerName = pn;
  }

  /**
  * setter method for current pokemon
  * @param current pokemon as a string
  */
  void setCurrentMon(string cp) {
    this->currentMon = cp;
  }

  /**
  * setter method for current pokemon
  * @param current pokemon as a string
  */
  void setActiveMon(Pokemon *lilbuddy) {
    this->activemon = lilbuddy;
  }

  /**
  * setter method for the fainted pokemon
  * @param fainted pokemon as a string
  */
  void setFaintedMon(int f) {
    this->faintedpkmn = f;
  }

  /**
  * updates the number of fainted pokemon
  * @param fainted pokemon as an integer
  */
  void changeFaintedMon(int f) {
    this->faintedpkmn += f;
  }

  /**
  * setter method for the swapped pokemon
  * @param swapped pokemon as a string
  */
  void setSwap(string s) {
    this->swap = s;
  }

  /**
  * setter method for
  * @param debt as an integer
  */
  void setDebt(int d) {
    this->debt = d;
  }

  /**
  * setter method for pokemon team
  * @param an array of pokemon
  */
  void setPkmn(array<Pokemon*, 3> replacement) {
    this->pkmn = replacement;
  }

};

/**
* function for damage calculation
* 
* @param attack, damage, defence of enemy, receiving pokemon's type, move type
* @return the total damage dealt
*/
int damageCalculation(int userAttack, int moveDamage, int enemyDefence, string enemyType, string moveType, int accuracy) {
  //hashmap functionality: The key is the type of the opposing pokemon and the value is a set of types that are either weak or strong against the key type
  unordered_map<string, set<string>> weaknesses = {{"Fire",  {"Water", "Ground", "Rock"}}, {"Water", {"Grass", "Electric", "Dragon"}}, {"Grass", {"Fire", "Flying", "Poison", "Bug", "Steel", "Ice"}}}; //hashmap for weaknesses
  unordered_map<string, set<string>> resistances = {{"Fire",  {"Grass", "Fire", "Bug", "Ice", "Steel", "Fairy"}}, {"Water", {"Steel", "Fire", "Water", "Ice"}}, {"Grass", {"Ground", "Water", "Grass", "Electric"}}}; //hashmap for resistances
  srand(time(NULL));
  if (1 + (rand() % 100) < accuracy) {
  if (moveDamage == 0) { //if the move does no damage, set move status to no effect
    finalDamage = 0;
    mstatus = "noEffect";
  } 
  else if (weaknesses[enemyType].count(moveType) >= 1) { //if in the value for enemyType, count the number of types that match the set and if it is more or equal to 1, this if statement is true
    finalDamage = 2 * (userAttack + moveDamage - enemyDefence);
    mstatus = "superEffective"; //update string initalized at the beginning of the program to mstatus
  }
  else if (resistances[enemyType].count(moveType) >= 1) { //if in the value for enemyType, count the number of types that match the set and if it is more or equal to 1, this if statement is true
    finalDamage = 0.5 * (userAttack + moveDamage - enemyDefence);
    mstatus = "notVeryEffective";
  } else { //if there are no type advantages and attack still does damage, this if statement is true
    finalDamage = userAttack + moveDamage - enemyDefence;
    mstatus = " ";
  }
    }
  else {
    finalDamage = 0;
    mstatus = "miss";
  }
  return finalDamage; //return final damage after type calculations as an int
}
  
/**
* function to update the HPs of Pokemon & perform attacks
* 
* @param attacking pokemon, receivning pokemon, move
*/
void afterMath(Pokemon *pokemonAttacker, Pokemon *pokemonVictim, Move *move, Player *playerAttacker, Player *playerVictim, int maxhp) {
  if (pokemonAttacker->getHp() > 0) {
    if (move->getDamageValue() > 0) {
      int damage = 0;
      damage = damageCalculation(pokemonAttacker->getAtk(), move->getDamageValue(), pokemonVictim->getDef(), pokemonVictim->getType(), capitalize(move->getType()), move->getAccuracy());
      pokemonVictim->setHp(pokemonVictim->getHp() - damage);
      typeOutFast(pokemonAttacker->getName());
      typeOutFast(" used ");
      typeOutFast(move->getName());
      cout << "!" << endl;
      cout << "---" << endl;
      if (mstatus == "superEffective") {
        typeOutFast("It's super effective!"); //type message for if the move is super effective
        cout << endl;
      }
      else if (mstatus == "notVeryEffective") {
        typeOutFast("It's not very effective..."); //type message for if the move is not very effective
        cout << endl;
      }
      else if (mstatus == "noEffect") {
        typeOutFast("It had no effect..."); //type message for if the move has no effective
        cout << endl;
      }
      else if (mstatus == "miss") {
        cout << pokemonVictim->getName();
        typeOutFast(" avoided the attack!");
        cout << endl;
      }
      else {
        cout << "";
      }
      typeOut(pokemonAttacker->getName());
      typeOut(" dealt ");
      cout << damage;
      typeOut(" damage to ");
      typeOut(pokemonVictim->getName());
      typeOut("!");
      cout << endl;
      if (pokemonVictim->getHp() <= 0) {
        pokemonVictim->setHp(0);
        playerVictim->changeFaintedMon(1);
        playerVictim->setSwap("yes");
        playerVictim->setDebt(0);
        typeOut(pokemonVictim->getName());
        typeOut(" fainted ");
        cout << endl;
      }      
    }

    if (move->getStatus() == "attackBoost") {
      typeOut(pokemonAttacker->getName());
      typeOut(" boosted their attack! ");
      cout << endl;
      typeOut(pokemonAttacker->getName());
      typeOut("\'s attack raised from ");
      cout << pokemonAttacker->getAtk();
      typeOut(" to ");
      cout << pokemonAttacker->getAtk() * 1.5 << endl;
      pokemonAttacker->setAtk(pokemonAttacker->getAtk() * 1.5);
    }

    if (move->getStatus() == "defenceBoost") {
      typeOut(pokemonAttacker->getName());
      typeOut(" boosted their defence! ");
      cout << endl;
      typeOut(pokemonAttacker->getName());
      typeOut("\'s defence raised from ");
      cout << pokemonAttacker->getDef();
      typeOut(" to ");
      cout << pokemonAttacker->getDef() * 1.5 << endl;
      pokemonAttacker->setDef(pokemonAttacker->getDef() * 1.5);
    }

    if (move->getStatus() == "speedBoost") {
      typeOut(pokemonAttacker->getName());
      typeOut(" boosted their speed! ");
      cout << endl;
      typeOut(pokemonAttacker->getName());
      typeOut("\'s speed raised from ");
      cout << pokemonAttacker->getSpd();
      typeOut(" to ");
      cout << pokemonAttacker->getSpd() * 1.5 << endl;
      pokemonAttacker->setSpd(pokemonAttacker->getSpd() * 1.5);
    }
    
    if (move->getHealing() > 0) {
      if (pokemonAttacker->getHp() + move->getHealing() >= maxhp) {
        pokemonAttacker->setHp(maxhp);
        typeOut(pokemonAttacker->getName());
        typeOut(" restored ");
        cout << move->getHealing();
        typeOut(" HP!");
        cout << endl;
      } else {
        pokemonAttacker->setHp(pokemonAttacker->getHp() + move->getHealing());
        typeOut(pokemonAttacker->getName());
        typeOut(" restored ");
        cout << move->getHealing();
        typeOut(" HP!");
        cout << endl;
      }
    }
  } 
}

/**
* Function to show pokemon's health bar
* 
* @param the active pokemon, damager taken as an integer
*/
void pokemonHealth(Pokemon *tempPokemon, int maxHp) {
  int percentageHp = tempPokemon->getHp() * 100 / maxHp;
  cout << tempPokemon-> getName() << ": ";
  if (tempPokemon->getHp() != 0) {
    for (int i = 0; i < percentageHp; i += 10) {
      cout << "⬜"; //health remaining/regained
    }
    for (int i = 0; i < 100 - percentageHp; i += 10) {
      cout << "🟥"; //health lost
    }
    cout << "[" << tempPokemon->getHp() << "/" << maxHp << "] HP\n---" << endl;
  }
  else if (tempPokemon->getHp() == 0) {
    cout << " HP: FAINTED" << endl;
  }
}

void printMoves(string moveName1, string moveName2, string moveName3, string moveName4) {
  for (int i = 0; i < moveName1.size(); i++) {
    //int spaces = ;
  }
  cout << " __________________" << endl;
  cout << "|" << moveName1 << "|" << endl;
  cout << " ------------------" << endl;
}

/**
* Given two moves and 2 pokemon, determine which pokemon attacks first
* 
* @param array of two moves, first pokemon, second pokemon
*/
void movePart1(array<Move*, 2> twoMoves, Pokemon *pokemon1, Pokemon *pokemon2, Player *player1, Player *player2, int maxhp1, int maxhp2) {
  int fasterMon;
  fasterMon = 0;
  if (pokemon1->getSpd() > pokemon2->getSpd()) {
    fasterMon = 1;
  } else if (pokemon1->getSpd() < pokemon2->getSpd()) {
    fasterMon = 2;
  } else {
    fasterMon = 1;
  }

  if (player1->getSwap() != "yes" && player2->getSwap() != "yes") {
    if (fasterMon == 1) {
        cout << "---" << endl;
        cout << pokemon1->getName() << " attacked first" << endl;
        afterMath(pokemon1, pokemon2, twoMoves[0], player1, player2, maxhp1);
        pokemonHealth(pokemon2, maxhp2);
        cout << endl;
        if (pokemon2->getHp() > 0) {
        cout << "\n---\n" << pokemon2->getName() << " attacked second" << endl;
        afterMath(pokemon2, pokemon1, twoMoves[1], player2, player1, maxhp2);
        pokemonHealth(pokemon1, maxhp1);    
        }  
      } else { 
      cout << "---" << endl;
      cout << pokemon2->getName() << " attacked first" << endl;
      afterMath(pokemon2, pokemon1, twoMoves[1], player2, player1, maxhp2);
      pokemonHealth(pokemon1, maxhp1); //I think this works
      if (pokemon1->getHp() > 0) {
      cout << "\n---\n" << pokemon1->getName() << " attacked second" << endl;
      afterMath(pokemon1, pokemon2, twoMoves[0], player1, player2, maxhp1);
      pokemonHealth(pokemon2, maxhp2); //I think this works    
      }    
    }
  }
}

/**
 * void function to print pokemon with their type, name, and stats
 */
void printPokedex() {
  cout << "                  ______________________________"<< endl;
  cout << "                /  THE BADOLAS REGION'S POKEDEX  \\" << endl;               
  cout << "               /     Available Pokemon to use     \\" << endl;
  cout << " ----------------------------------------------------------------" << endl;
  for (int i = 0; i < numberOfPokemon; i++) {
    int numSpaces = 15 - updatedPokedex[i].getName().length() - updatedPokedex[i].getType().length();
    cout << "|  -> " << updatedPokedex[i].getName() << " (" << updatedPokedex[i].getType() << ") {Hp: " << updatedPokedex[i].getHp() << ", Atk: " << updatedPokedex[i].getAtk() << ", Def: " << updatedPokedex[i].getDef() << ", Speed: " << updatedPokedex[i].getSpd() << "}";
    for (int j = 0; j < numSpaces; j++) { 
      cout << " ";
    }
    cout << "  |" << endl;
  }
  cout << " ----------------------------------------------------------------" << endl;
}


/**
 * Initiates a single-player pokemon battle by prompting for user input to select a pokemon from their team. //unfinished? 
 */
void battle(Player *player1, Pokemon *p1, Pokemon *p2, Pokemon *p3, Pokemon *b1, Pokemon *b2, Pokemon *b3) {
  string choicei;
  string choice;
  string choice2;
  choicei = "";
  choice = "";
  choice2 = "";
  while (true) {
    typeOut("Choose which pokemon to send out [");
    cout << player1->getFaintedMon() + 1;
    typeOut("/3]");
    cout << endl;
    sleep(250);
    typeOutFast("Enter your choice: ");
    cout << endl;
    cin >> choicei;
    choice = capitalize(choicei);
    if (choice == p1->getName()) {
      typeOut(p1->getName());
      typeOut(" is ready for battle!");
      cout << endl;
      break;
    } else if (choice == p2->getName()) {
      typeOut(p2->getName());
      typeOut(" is ready for battle!");
      cout << endl;
      break;
    } else if (choice == p3->getName()) {
      typeOut(p3->getName());
      typeOut(" is ready for battle!");
      cout << endl;
      break;
    }
    else {
      typeOut("That is not a Pokemon you have in your party. Please try again: ");
      cout << endl;
      continue;
    }
    if (choice == "P") {
        printPokedex();
        typeOut("This is the end of the Pokedex, so...");
        continue; //allows user to select a new option
        cout << endl;
      }
  } 

  player1->setCurrentMon(choice);
  player1->setName(pn);

  cout << endl << "---" << endl << player1->getName() << " sent out " << player1->getCurrentMon() << "!" << endl << "---" << endl << endl;

  choicei = "";
  choice = "";
  choice2 = "";
}

/**
 * Lets the player choose their move
 */
void chooseMove(Player* player, int number) {
    cout << "\n";
    typeOutFast(player->getName());
    typeOutFast(", choose one of ");
    typeOutFast(player->getCurrentMon());
    typeOutFast("'s moves");
    cout << endl;
    for (int i = 0; i < 4; i++) {
      cout << "[" << player->getActiveMon()->getMoveSet()[i]->getName() << "] "; //prints to player all 4 of their moves
    }
    cout << endl;
    typeOutFast("If you'd like to view a description of these moves, Enter 'm'");
    cout << endl;
    typeOutFast("If you'd like to swap your pokemon. Enter 's'");
    cout << endl;
    choice = "";
    while (choice != capitalize(player->getActiveMon()->getMoveSet()[0]->getName()) && choice != capitalize(player->getActiveMon()->getMoveSet()[1]->getName()) && choice != capitalize(player->getActiveMon()->getMoveSet()[2]->getName()) && choice != capitalize(player->getActiveMon()->getMoveSet()[3]->getName())) {
      getline(cin >> ws, choice); //getline() allows for spaces from input
      ////>> ws ensures it waits for user input instead of taking in space
      choice.erase(remove(choice.begin(), choice.end(), ' '), choice.end()); //removes spaces from input
      choice = capitalize(choice); //capitalizes input
        if (choice == "M") {
          moveStats(player->getActiveMon());       
          } else if (choice == "S") {
          player->setSwap("yes");
          player->setDebt(1);
          return;
          }
      if (choice != capitalize(player->getActiveMon()->getMoveSet()[0]->getName()) && choice != capitalize(player->getActiveMon()->getMoveSet()[1]->getName()) && choice != capitalize(player->getActiveMon()->getMoveSet()[2]->getName()) && choice != capitalize(player->getActiveMon()->getMoveSet()[3]->getName()) && choice != "M") {
            typeOutFast("\"");
            typeOutFast(choice);
            typeOutFast("\" ");
            typeOutFast("is not a Move. Please try again: ");
            cout << endl;     
          }
    }

    if (choice == capitalize(player->getActiveMon()->getMoveSet()[0]->getName())) {
      titForTat[number] = player->getActiveMon()->getMoveSet()[0];
    } else if (choice == capitalize(player->getActiveMon()->getMoveSet()[1]->getName())) {
      titForTat[number] = player->getActiveMon()->getMoveSet()[1];
    } else if (choice == capitalize(player->getActiveMon()->getMoveSet()[2]->getName())) {
      titForTat[number] = player->getActiveMon()->getMoveSet()[2];  
    } else if (choice == capitalize(player->getActiveMon()->getMoveSet()[3]->getName())) {
      titForTat[number] = player->getActiveMon()->getMoveSet()[3];
    } 

    typeOutFast(capitalize(player->getActiveMon()->getName()));
    typeOutFast(" will use ");
    typeOutFast(choice);
    cout << endl << endl;
    choice = "";
}

/**
 * Function to choose pokemon from party
 */
void iChooseYou(Player *player, Pokemon *p1, Pokemon *p2, Pokemon *p3) {
  string choicei;
  string choice;
  string choice2;
  choicei = "";
  choice = "";
  choice2 = "";
  while (true) {
    cout << pn << ", choose which pokemon to send out [" << player->getFaintedMon() + 1 << "/3]" << endl;
    typeOutFast("If you'd like to view the Pokedex again, Enter 'p'");
    cout << endl;
    cout << "-> " << p1->getName() << endl << "-> " << p2->getName() << endl << "-> " << p3->getName() << endl;
    sleep(250);
    typeOutFast("Enter your choice: ");
    cout << endl;
    cin >> choicei;
    choice = capitalize(choicei);
    if (choice == p1->getName()) {
      if (p1->getHp() <= 0) {
        typeOut(p1->getName());
        typeOut(" fainted! ");
        cout << endl;
        typeOut(player->getName());
        typeOut(" please choose another pokemon");
        cout << endl;
        continue;
      }
      typeOut(p1->getName());
      typeOut(" is ready for battle!");
      cout << endl;
      player->setActiveMon(p1);
      break;
    } else if (choice == p2->getName()) {
        if (p2->getHp() <= 0) {
        typeOut(p2->getName());
        typeOut(" fainted! ");
        cout << endl;
        typeOut(player->getName());
        typeOut(" please choose another pokemon");
        cout << endl;
        continue;
      }
      typeOut(p2->getName());
      typeOut(" is ready for battle!");
      cout << endl;
      player->setActiveMon(p2);
      break;
    } else if (choice == p3->getName()) {
        if (p3->getHp() <= 0) {
        typeOut(p3->getName());
        typeOut(" is downed! ");
        cout << endl;
        typeOut(player->getName());
        typeOut(" please choose another pokemon");
        cout << endl;
        continue;
      }
      typeOut(p3->getName());
      typeOut(" is ready for battle!");
      cout << endl;
      player->setActiveMon(p3);
      break;
    }
    else {
      typeOut("That is not a Pokemon you have in your party. Please try again: ");
      cout << endl;
      continue;
    }
    if (choice == "P") {
        printPokedex();
        typeOut("This is the end of the Pokedex, so...");
        continue;
        cout << endl;
      }
  }
  player->setCurrentMon(choice);
  choicei = "";
  choice = "";
  choice2 = "";
}

/**
 * Initiates a multiplayer pokemon battle by prompting for user input to select a pokemon from their team. //unfinished? 
 */
void playerBattle(Player *player1, Pokemon *p1, Pokemon *p2, Pokemon *p3, Player *player2, Pokemon *b1, Pokemon *b2, Pokemon *b3) {
  string choicei;
  string choice;
  string choice2;
  choicei = "";
  choice = "";
  choice2 = "";
  while (true) {
    cout << pn << ", choose which pokemon to send out [" << player1->getFaintedMon() + 1 << "/3]" << endl;
    typeOutFast("If you'd like to view the Pokedex again, Enter 'p'");
    cout << endl;
    cout << "-> " << p1->getName() << endl << "-> " << p2->getName() << endl << "-> " << p3->getName() << endl;
    sleep(250);
    typeOutFast("Enter your choice: ");
    cout << endl;
    cin >> choicei;
    choice = capitalize(choicei);
    if (choice == p1->getName()) {
      typeOut(p1->getName());
      typeOut(" is ready for battle!");
      cout << endl;
      player1->setActiveMon(p1);
      break;
    } else if (choice == p2->getName()) {
      typeOut(p2->getName());
      typeOut(" is ready for battle!");
      cout << endl;
      player1->setActiveMon(p2);
      break;
    } else if (choice == p3->getName()) {
      typeOut(p3->getName());
      typeOut(" is ready for battle!");
      cout << endl;
      player1->setActiveMon(p3);
      break;
    }
      else {
      typeOut("That is not a Pokemon you have in your party. Please try again: ");
      cout << endl;
      continue;
    }
    if (choice == "P") {
        printPokedex();
        typeOut("This is the end of the Pokedex, so...");
        continue;
        cout << endl;
      }
  } 

  player1->setCurrentMon(choice);
  player1->setName(pn);

  choicei = "";
  choice = "";
  choice2 = "";

  while (true) {
    typeOut(pn2);
    typeOut(", choose which pokemon to send out [");
    cout << player2->getFaintedMon() + 1;
    typeOut("/3]");
    cout << endl;
    typeOutFast("If you'd like to view the Pokedex again, Enter 'p'");
    cout << endl;
    cout << "-> " << b1->getName() << endl << "-> " << b2->getName() << endl << "-> " << b3->getName() << endl;
    sleep(250);
    typeOutFast("Enter your choice: ");
    cout << endl;
    cin >> choicei;
    choice = capitalize(choicei);
    if (choice == b1->getName()) {
      typeOut(b1->getName());
      typeOut(" is ready for battle!");
      cout << endl;
      player2->setActiveMon(b1);
      break;
    } else if (choice == b2->getName()) {
      typeOut(b2->getName());
      typeOut(" is ready for battle!");
      cout << endl;
      player2->setActiveMon(b2);
      break;
    } else if (choice == b3->getName()) {
      typeOut(b3->getName());
      typeOut(" is ready for battle!");
      cout << endl;
      player2->setActiveMon(b3);
      break;
    }
    else {
      typeOut("That is not a Pokemon you have in your party. Please try again: ");
      cout << endl;
      continue;
    }
    if (choice == "P") {
        printPokedex();
        typeOut("This is the end of the Pokedex, so...");
        continue;
        cout << endl;
      }
  } 

  player2->setCurrentMon(choice);
  player2->setName(pn2);

  choicei = "";
  choice = "";
  choice2 = "";

  cout << endl << "---" << endl << player1->getName() << " sent out " << player1->getCurrentMon() << "!" << endl << player2->getName() << " sent out " << player2->getCurrentMon() << "!" << endl << "---" << endl << endl;

  int maxhp1 = player1->getActiveMon()->getHp();
  int maxhp2 = player2->getActiveMon()->getHp();

  while(true) { //prints the movesset for pokemon


  titForTat = blankForTat;

   chooseMove(player1, 0);
   chooseMove(player2, 1);
    movePart1(titForTat, player1->getActiveMon(), player2->getActiveMon(), player1, player2, maxhp1, maxhp2);
    
    if (player1->getFaintedMon() == 3) { //changed else if to if
      cout << player2->getName() << " has defeated " << player1->getName() << "!" << endl;
      cout << player2->getName() << " WON!" << endl;
      break;
    } 
    else if (player2->getFaintedMon() == 3) {
      cout << player1->getName() << " has defeated " << player2->getName() << "!" << endl;
      cout << player1->getName() << " WON!" << endl;
      break;
    } 
    if (player1->getSwap() == "yes") {
      iChooseYou(player1, player1->getPkmn()[0], player1->getPkmn()[1], player1->getPkmn()[2]);
        player1->setSwap("no");
        maxhp1 = player1->getActiveMon()->getHp();
      if (player1->getDebt() == 1) {
        afterMath(player2->getActiveMon(), player1->getActiveMon(), titForTat[1], player2, player1, maxhp2);
        pokemonHealth(player1->getActiveMon(), maxhp1);
        player1->setDebt(0);
      }    
    } else if (player2->getSwap() == "yes") {
      iChooseYou(player2, player2->getPkmn()[0], player2->getPkmn()[1], player2->getPkmn()[2]);
      player2->setSwap("no");
      maxhp2 = player2->getActiveMon()->getHp();
    }
    if (player2->getDebt() == 1) {
      afterMath(player1->getActiveMon(), player2->getActiveMon(), titForTat[0], player1, player2, maxhp1);
       pokemonHealth(player2->getActiveMon(), maxhp2);
      player2->setDebt(0);
    }  
  }
  return;
}

int condition = 0;
array<Pokemon*, 3> replacement;

/**
 * Function that checks for duplicates
 */
void dupe(Player *player, Pokemon *pkmn, int i, int identity) {
    for (int j = 0; j < replacement.size(); j++) {
    if (replacement[j] == pkmn) {
      typeOut(player->getName());
      typeOut(" already has ");
      typeOut(capitalize(pkmn->getName()));
      typeOut(" in their party");
      cout << endl;
      condition = 1;
      }
    }
      if (condition != 1) {
        if (identity == 1) {       
          firstPlayerMon[i]->setHp(pkmn->getHp());
          firstPlayerMon[i]->setAtk(pkmn->getAtk());
          firstPlayerMon[i]->setDef(pkmn->getDef());
          firstPlayerMon[i]->setSpd(pkmn->getSpd());
          firstPlayerMon[i]->setMoveSet(pkmn->getMoveSet());
          firstPlayerMon[i]->setName(pkmn->getName());
          firstPlayerMon[i]->setType(pkmn->getType());
          replacement[i] = firstPlayerMon[i];
        } else if (identity == 2) {
          secondPlayerMon[i]->setHp(pkmn->getHp());
          secondPlayerMon[i]->setAtk(pkmn->getAtk());
          secondPlayerMon[i]->setDef(pkmn->getDef());
          secondPlayerMon[i]->setSpd(pkmn->getSpd());
          secondPlayerMon[i]->setMoveSet(pkmn->getMoveSet());
          secondPlayerMon[i]->setName(pkmn->getName());
          secondPlayerMon[i]->setType(pkmn->getType());
          replacement[i] = secondPlayerMon[i];
        }
        cout << player->getName();
        cout << " added ";
        cout << capitalize(pkmn->getName());
        cout << " to the party";
        cout << endl;
        sleep(500);
      } else {
          condition = 0;
        }
}

/**
 * Function that asks the user to choose their pokemon.
 */
void choosemon(Player *player, int identity) {
  set<string> validPokemon;
  validPokemon = blankSet;
  for (int i = 0; i < numberOfPokemon; i++) {
    validPokemon.insert(capitalize(updatedPokedex[i].getName()));
  }
    replacement[0] = not_a_pokemon;
    replacement[1] = not_a_pokemon;
    replacement[2] = not_a_pokemon;
    condition = 0;
    choice = "";
    printPokedex();
    typeOutFast(player->getName());
    typeOutFast(", select 3 pokemon from the pokedex by typing out all your choices and seperating them with a space: ");
    cout << endl;
    for (int i = 0; i < 3; i++) {
      choice = "";
      while (validPokemon.count(choice) == 0) {
      cin >> choice;
      choice = capitalize(choice);
      if (validPokemon.count(choice) == 0) {
        typeOut("\"");
        typeOut(choice);
        typeOut("\" ");
        typeOut("is not a pokemon. Please try again: ");
        cout << endl;
      }
      }
      for (int j = 0; j < numberOfPokemon; j++) {
        if (choice == capitalize(simplePokedex[j]->getName())) {
          dupe(player, simplePokedex[j], i, identity);
        }
      }
      
      if (replacement[i] == not_a_pokemon) {
        i -= 1;
      }
    }
  player->setPkmn(replacement);
  choice = "";
}

/**
 * Prompts user to select and swap a new move with respect to their pokemon's type with one of the existing 4 moves that the player is currently using. This will be called every round.
 */
void drawMove() {
  
}//idea: after every round, randomly draw a new move from the moves class(learnable by the respected pokemon) and give the player a choice to swap one of the 4 moves w the new move. 

/**
 * Description of the game goes here.
 *
 * @return 0 if successful, 1 if successful
 */
int main() {
  string invalidInp = "That is not a valid option trainer. Please try again.";
  title();
    cout << "\n-- VERSION 1.0.0 --" << endl; //x.y.z where a change in x indicates a major change, a change in y indicates a minor change, and a change in z represents a minor bug fix/patch. Since we are in the development phase, let y be major and z be minor. I figured using semantic versioning will help us keep track of who is making what changes when we're outside of school. << endl; 
  cout << endl; //temporary (remove this)
  cout << "Enter \'i\' to view instructions\nEnter \'s\' to start" << endl;

// to make duplicates of the same class

firstPlayerMon[0] = pkmn11;
firstPlayerMon[1] = pkmn12;
firstPlayerMon[2] = pkmn13;

secondPlayerMon[0] = pkmn21;
secondPlayerMon[1] = pkmn22;
secondPlayerMon[2] = pkmn23;

basic[0] = bulbasaur;
basic[1] = charmander;
basic[2] = squirtle;

Player *player1 = new Player("no name", "Not_a_pokemon", not_a_pokemon, basic, 0, "no", 0);
  choice = "";
  while (choice != "I" && choice != "S") {
    cin >> choice;
    choice = capitalize(choice);
    if (choice != "I" && choice != "S") {
      for (int i = 0; invalidInp[i] != '\0'; i++) {
      cout << invalidInp[i] << flush;
      sleep(50);
      if(invalidInp[i] == ' ') 
      {
       sleep(1); 
      }
    }
      cout << endl;
    }
    }

  while (choice == "I") {
  if (choice == "I") {
    instructions();
    cout << "\nEnter \'i\' to view instructions again\nEnter \'s\' to start" << endl;
    cin >> choice;
    choice = capitalize(choice);
  }
    }
    
  if (choice == "S") {
    typeOut("This is where your Pokemon journey begins...");
    sleep(250);
    cout << endl;
    typeOut("Now trainer...");
    sleep(500);
    cout << endl;
    typeOut("Please enter your username: ");
    cout << endl;
    getline(cin >> ws, pn);
    player1->setName(pn);
    typeOut(player1->getName()); 
    typeOut(" has been registered!");
    cout << endl;
    cout << "-- Enter your choice of play: --\nEnter \'s'\ for single-player mode \nEnter \'m'\ for multiplayer mode \nEnter \'p'\ to view the Pokedex." << endl;
    choice2 = "";
    while(choice2 != "S" && choice2 != "M" && choice2 != "P") {
      cin >> choice2;
      choice2 = capitalize(choice2);
      if (choice2 != "M" && choice2 != "S" && choice2 != "P") {
        for (int i = 0; invalidInp[i] != '\0'; i++) {
          cout << invalidInp[i] << flush;
          sleep(50);
         if(invalidInp[i] == ' ') 
          {
           sleep(1); 
          }
    }
      cout << endl;
    }
  }

  while (choice2 == "S")
    { //looped this because we don't have single player :c
    if (choice2 == "S") {
      typeOut("This is where the sussy single-player begins...");
      cout << endl;
      sleep(100);
      typeOut("Sorry trainer, single-player was not added to the game...");
      cout << endl;
      typeOut("Please choose a different choice of play: ");
      cout << endl;
      cin >> choice2;
      choice2 = capitalize(choice2);
      }
        }

  if (choice2 == "P") {
    printPokedex();
    typeOut("Enter your choice of play: ");
    cout << endl;
    while (choice2 != "M" && choice2 != "S") {
      cin >> choice2;
      choice2 = capitalize(choice2);
    }
  }

  if (choice2 == "M") {
    typeOut("You chose multiplayer!");   
    cout << endl;
      Player *player2 = new Player("no name", "Not_a_pokemon", not_a_pokemon, basic, 0, "no", 0);
      typeOut("Trainer 2, please enter your username: ");
      cout << endl;
      getline(cin >> ws, pn2);
      player2->setName(pn2);
      typeOut(player2->getName()); 
      typeOut(" has been registered!");
      cout << endl;
      choosemon(player1, 1);
      choosemon(player2, 2);
    //choose pokemon on each team here (feature in progress)
  choice = "";
  choice2 = "";
    playerBattle(player1, player1->getPkmn()[0], player1->getPkmn()[1], player1->getPkmn()[2], player2, player2->getPkmn()[0], player2->getPkmn()[1], player2->getPkmn()[2]); 
  }
    }
  return 0;
}