  /**
* @author JonnyT-chocomint, yujiroo & Penguinoucy
*/

#include "moves.h"

//everything pokemon goes here
class Pokemon {
  private:
    int hp;
    int atk;
    int def;
    int spd;
    array<Move*, 4>  moveSet;
    string type;
    string name;
  public:
  Pokemon(int h, int a, int d, int s, Move *m1, Move *m2, Move *m3, Move *m4, string t, string n) {
    this->hp = h;
    this->atk = a;
    this->def = d;
    this->spd = s;
    this->moveSet[0] = m1;
    this->moveSet[1] = m2;
    this->moveSet[2] = m3;
    this->moveSet[3] = m4;
    this->type = t;
    this->name = n;
  }
  int getHp() {
    return this->hp;
  }
  int getAtk() {
    return this->atk;
  }
  int getDef() {
    return this->def;
  }
  int getSpd() {
    return this->spd;
  }
  string getType() {
    return this->type;
  }
  string getName() {
    return this->name;
  }
  array<Move*, 4> getMoveSet() {
    return this->moveSet;
  }

  //array<Move*, 4> getMoveStats() {
    //return this-> 
  //}

  void setHp(int h) {
    this->hp = h;
  }
  void setAtk(int a) {
    this->atk = a;
  }
  void setName(string n) {
    this->name = n;
  }
  void setSpd(int s) {
    this->spd = s;
  }
  void setDef(int d) {
    this->def = d;
  }
  void setType(string t) {
    this->type = t;
  }
  void setMoveSet(array<Move*, 4> ms) {
    this->moveSet = ms;
  }
};

//hp, atk, def, spd, array of moves, types
//all stats are based off the original pokemon game stats
//hp is increased by 700% from the original
//**pokemon #1
Pokemon *bulbasaur = new Pokemon(315, 49, 49, 65, touchGrass, copium, tackle, absorb, "Grass", "Bulbasaur"); //45, 49, 49, 65 <- base stats from game
  //**pokemon #2
Pokemon *charmander = new Pokemon(273, 52, 43, 65, stab, torch, inferno, steroids, "Fire", "Charmander"); //39, 52, 43, 65 <- base stats from game
  //**pokemon #3
Pokemon *squirtle = new Pokemon(308, 48, 65, 50, stab, waterGun, hydroPump, tackle, "Water", "Squirtle"); //44, 48, 65, 50 <- base stats from game
  //STATS IN PROGRESS
  //**pokemon #4
Pokemon *chikorita = new Pokemon(315, 49, 65, 45, touchGrass, tackle, tackle, vineWhip, "Grass", "Chikorita"); //45, 49, 65, 45 <- base stats from game
  //**pokemon #5
Pokemon *cyndaquil = new Pokemon(273, 52, 43, 65, stab, torch, tackle, steroids, "Fire", "Cyndaquil"); //39, 52, 43, 65 <- base stats from game
  //**pokemon #6
Pokemon *totodile = new Pokemon(350, 65, 64, 43, stab, waterGun, aquaTail, tackle, "Water", "Totodile"); //50, 65, 64, 43 <- base stats from game
  //**pokemon #7
Pokemon *treecko = new Pokemon(280, 45, 35, 70, touchGrass, stab, tackle, vineWhip, "Grass", "Treeko"); //40, 45, 35, 70 <- base stats from game
  //**pokemon #8
Pokemon *torchic = new Pokemon(315, 60, 40, 45, stab, torch, tackle, steroids, "Fire", "Torchic"); //45, 60, 40, 45 <- base stats from game
  //**pokemon #9
Pokemon *mudkip = new Pokemon(350, 70, 50, 40, stab, waterGun, aquaTail, tackle, "Water", "Mudkip"); //50, 70, 50, 40 <- base stats from game
  //**pokemon #10
Pokemon *turtwig = new Pokemon(385, 68, 64, 31, touchGrass, stab, tackle, vineWhip, "Grass", "Turtwig"); //55, 68, 64, 31 <- base stats from game
  //**pokemon #11
Pokemon *chimchar = new Pokemon(308, 58, 44, 61, stab, torch, tackle, steroids, "Fire", "Chimchar"); //44, 58, 44, 61 <- base stats from game
  //**pokemon #12
Pokemon *piplup = new Pokemon(371, 51, 53, 40, stab, waterGun, aquaTail, tackle, "Water", "Piplup"); //53, 51, 53, 40 <- base stats from game
  //**pokemon #13
Pokemon *snivy = new Pokemon(315, 45, 55, 63, touchGrass, stab, tackle, vineWhip, "Grass", "Snivy"); //45, 45, 55, 63 <- base stats from game
  //**pokemon #14
Pokemon *tepig = new Pokemon(455, 63, 45, 45, inferno, torch, tackle, steroids, "Fire", "Tepig"); //65, 63, 45, 45 <- base stats from game
  //**pokemon #15
Pokemon *oshawott = new Pokemon(385, 55, 45, 45, stab, waterGun, aquaTail, tackle, "Water", "Oshawott"); //55, 55, 45, 45 <- base stats from game
  //**pokemon #16
Pokemon *chespin = new Pokemon(392, 61, 65, 38, stab, waterGun, aquaTail, tackle, "Grass", "Chespin"); //56, 61, 65, 38 <- base stats from game
  //**pokemon #17
Pokemon *fennekin = new Pokemon(280, 45, 40, 60, ember, torch, inferno, tackle, "Fire", "Fennekin"); //40, 45, 40, 60 <- base stats from game
  //**pokemon #18
Pokemon *froakie = new Pokemon(308, 48, 65, 50, stab, waterGun, aquaTail, tackle, "Water", "Froakie"); //44, 48, 65, 50 <- base stats from game
  //**pokemon #19
Pokemon *rowlet = new Pokemon(476, 55, 55, 42, touchGrass, stab, tackle, vineWhip, "Grass", "Rowlet"); //68, 55, 55, 42 <- base stats from game
  //**pokemon #20
Pokemon *litten = new Pokemon(315, 65, 40, 70, stab, torch, tackle, steroids, "Fire", "Litten"); //45, 65, 40, 70 <- base stats from game
  //**pokemon #21
Pokemon *popplio = new Pokemon(350, 54, 54, 40, stab, waterGun, aquaTail, tackle, "Water", "Popplio"); //50, 54, 54, 40 <- base stats from game
  //**pokemon #22
Pokemon *grookey = new Pokemon(350, 65, 50, 65, touchGrass, stab, tackle, vineWhip, "Grass", "Grookey"); //50, 65, 50, 65 <- base stats from game
  //**pokemon #23
Pokemon *scorbunny = new Pokemon(350, 71, 40, 69, stab, torch, tackle, steroids, "Fire", "Scorbunny"); //50, 71, 40, 69 <- base stats from game
  //**pokemon #24
Pokemon *sobble = new Pokemon(350, 40, 40, 70, stab, waterGun, aquaTail, tackle, "Water", "Sobble"); //50, 40, 40, 70 <- base stats from game
  //**pokemon #25
Pokemon *sprigatito = new Pokemon(280, 61, 54, 65, touchGrass, stab, tackle, vineWhip, "Grass", "Sprigatito"); //40, 61, 54, 65 <- base stats from game
  //**pokemon #26
Pokemon *fuecoco = new Pokemon(469, 45, 59, 36, stab, torch, tackle, steroids, "Fire", "Fuecoco"); //67, 45, 59, 36 <- base stats from game
  //**pokemon #27
Pokemon *quaxly = new Pokemon(385, 65, 45, 50, stab, waterGun, aquaTail, tackle, "Water", "Quaxly"); //55, 65, 45, 50 <- base stats from game
Pokemon *berserker = new Pokemon(203, 81, 35, 68, omniBlast, fury, torch, harden, "Fire", "Berserker"); //55, 65, 45, 50 <- base stats from game
Pokemon *not_a_pokemon = new Pokemon(0, 0, 0, 0, stab, stab, stab, stab, "", "Not_a_pokemon"); // This is used in the dupe function

// to make duplicates of the same class
Pokemon *pkmn11 = new Pokemon(0, 0, 0, 0, stab, stab, stab, stab, "", "Pkmn11"); 
Pokemon *pkmn12 = new Pokemon(0, 0, 0, 0, stab, stab, stab, stab, "", "Pkmn12");
Pokemon *pkmn13 = new Pokemon(0, 0, 0, 0, stab, stab, stab, stab, "", "Pkmn13");
Pokemon *pkmn21 = new Pokemon(0, 0, 0, 0, stab, stab, stab, stab, "", "Pkmn21");
Pokemon *pkmn22 = new Pokemon(0, 0, 0, 0, stab, stab, stab, stab, "", "Pkmn22");
Pokemon *pkmn23 = new Pokemon(0, 0, 0, 0, stab, stab, stab, stab, "", "Pkmn23");

int numberOfPokemon = 28;
Pokemon updatedPokedex[28] = {*bulbasaur, *charmander, *squirtle, *chikorita, *cyndaquil, *totodile, *treecko, *torchic, *mudkip, *turtwig, *chimchar, *piplup, *snivy, *tepig, *oshawott, *chespin, *fennekin, *froakie, *rowlet, *litten, *popplio, *grookey, *scorbunny, *sobble, *sprigatito, *fuecoco, *quaxly, *berserker};

Pokemon *simplePokedex[28] = {bulbasaur, charmander, squirtle, chikorita, cyndaquil, totodile, treecko, torchic, mudkip, turtwig, chimchar, piplup, snivy, tepig, oshawott, chespin, fennekin, froakie, rowlet, litten, popplio, grookey, scorbunny, sobble, sprigatito, fuecoco, quaxly, berserker};

/**
 * Takes a string and returns true or false based on if input is one of the pokemon in the pokedex
 */

//damage, healing, accuracy, pp (uses), status effect, type
void moveStats(Pokemon *pokemon) {
  for (int i = 0; i < 4; i++) {
    //print each move set's damage value, healing value, 
  cout << capitalize(pokemon->getMoveSet()[i]->getName()) << pokemon->getMoveSet()[i]->getDescription() << endl;
  }
}
