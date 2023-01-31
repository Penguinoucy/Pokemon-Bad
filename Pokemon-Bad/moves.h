/**
* @author JonnyT-chocomint, yujiroo & Penguinoucy
*/

#include "basefunctions.h"

class Move {
  private:
    int damageValue;
    int healing;
    int accuracy;
    int pp;
    array <int, 4> moveStats;
    string status;
    string type;
    string name;
    string description;
  public:
  Move(int dv, int hl, int ac, int p, string sus, string typ, string n, string d) {
    this->damageValue = dv; 
    this->healing = hl;
    this->accuracy = ac;
    this->pp = p;
    this->status = sus;
    this->type = typ;
    this->name = n;
    this->description = d;
  }

    /**
 * getter method for the damage value of the move
 * @return the damage value
 */ 
  int getDamageValue() {
    return this->damageValue;
  }

  /**
 * getter method for the healing value of the move
 * @return the healing value
 */ 
  int getHealing() {
    return this->healing;
  }

  /**
 * getter method for the accuracy of the move
 * @return the accuracy
 */ 
  int getAccuracy() {
    return this->accuracy;
  }

  /**
 * getter method for the pp value of the move
 * @return the pp
 */ 
  int getPp() {
    return this->pp;
  }

  /**
 * getter method for the status of the move
 * @return the status
 */ 
  string getStatus() {
    return this->status;
  }

  /**
 * getter method for the type of the move
 * @return the type
 */ 
  string getType() {
    return this->type;
  }

  /**
 * getter method for the name of the move
 * @return the name
 */ 
  string getName() {
    return this->name;
  }

  /**
 * getter method for the description of the move
 * @return the description
 */ 
  string getDescription() {
    return this->description;
  }

   /**
  * setter method for the damage value of the move
  * @param a damage value integer
  */
  void setDamageValue(int dv) {
    this->damageValue = dv;
  }

  /**
  * setter method for the healing value of the move
  * @param an healing value integer
  */
  void setHealing(int hl) {
    this->healing = hl;
  }

  /**
  * setter method for the accuracy of the move
  * @param accuracy as an integer out of 100
  */
  void setAccuracy(int ac) {
    this->accuracy = ac;
  }

  /**
  * setter method for the pp of the move
  * @param pp as an integer
  */
  void setPp(int p) {
    this->pp = p;
  }

  /**
  * setter method for the status of the move
  * @param the status as a string
  */
  void setStatus(string sus) {
    this->status = sus;
  }

  /**
  * setter method for move's type
  * @param the type as a string
  */
  void setType(string typ) {
    this->status = typ;
  }

  /**
  * setter method for the name of the move
  * @param the name as a string
  */
  void setName(string n) {
    this->name = n;
  }

  /**
  * setter method for the description of the move
  * @param the description as a string
  */
  void setDescription(string d) {
    this->description = d;
  }
};


//we should just use the original names guys
//damage, healing, accuracy, pp (uses), status effect, type, name, description
//all move stats are based off the original pokemon game stats with some minor adjustments based off of our judgement for balancing
//all fire type atk moves go here:
Move *torch = new Move(40, 0, 100, 20, "","fire", "Torch", "{Damage: 40, Accuracy: 100%, PP: 20, Type: Fire}");
Move *ember = new Move(40, 0, 100, 20, "","fire", "Ember", "{Damage: 40, Accuracy: 100%, PP: 20, Type: Fire}");
Move *inferno = new Move(110, 0, 50, 5, "","fire", "Inferno", "{Damage: 110, Accuracy: 50%, PP: 5, Type: Fire}");
//all water type atk moves go here:
Move *aquaJet = new Move(40, 0, 100, 20, "priority", "water", "AquaJet", "{Damage: 40, Accuracy: 100%, PP: 20, Status: Priority, Type: Water}");
Move *waterGun = new Move(40, 0, 100, 25, "", "water", "WaterGun", "{Damage: 40 Accuracy: 100% PP: 25, Type: Water}");
Move *aquaTail = new Move(40, 0 , 100, 30, "", "water", "AquaTail", "{Damage: 40, Accuracy: 100% PP: 30, Type: Water}");
Move *bubbleBeam = new Move(65, 0, 100, 20, "", "water", "BubbleBeam", "{Damage: 65, Accuracy: 100%, PP: 20, Type: Water}");
Move *hydroPump = new Move(110, 0, 80, 5, "", "water", "HydroPump", "{Damage: 110, Accuracy: 80%, PP: 5, Type: Water}");
//
//all normal type atk moves go here:
Move *tackle = new Move(40, 0, 95, 30, "", "normal", "Tackle", "{Damage: 40, Accuracy: 95%, PP: 30, Type: Normal}");
Move *quickAttack = new Move(30, 0, 100, 30, "priority", "normal", "QuickAttack", " {Damage: 30, Accuracy: 100%, PP:30, Status: Priority, Type: Normal}");
Move *stab = new Move(45, 0, 90, 20, "","omni", "Stab", " {Damage: 45, Accuracy: 100%, PP: 20, Type: Omni}");
//all grass type atk moves go here:
Move *touchGrass = new Move(60, 0, 100, 10, "","grass", "TouchGrass", " {Damage: 60, Accuracy: 100%, PP: 10, Type: Grass}");
Move *vineWhip = new Move (40, 0 , 100, 25, "", "grass", "VineWhip", " {Damage: 40, Accuracy: 100%, PP: 25, Type: Grass}");
Move *absorb = new Move(20, 10, 100, 25, "", "grass", "Absorb", " {Damage: 20, Healing: 10, Accuracy: 100%, PP: 25, Type: Grass}");
Move *seedBomb = new Move(80, 0, 100, 15, "", "grass", "SeedBomb", " {Damage: 80, Accuracy: 100%, PP: 15, Type: Grass}");
//all poison type atk moves go here:
Move *acid = new Move(40, 0, 100, 20, "", "poison", "Acid", " {Damage: 40, Accuracy: 100%, PP: 20, Type: Poison}");
//Move *
//all flying type atk moves go here:
//all other moves go here:
Move *copium = new Move(0, 50, 100, 20, "", "omni", "Copium", " {Healing: 30, Accuracy: 100%, PP: 20, Status: Burn, Type: Omni}"); 
//typeless? INTRODUCING OMNI TYPE!
Move *vent = new Move(0, 0, 100, 20, "protect", "omni", "Vent","{Accuracy: 100%, PP: 20, Status: Protect, Type: Omni}");
Move *steroids = new Move(0, 0, 100, 20, "attackBoost","omni", "Steroids", " {Accuracy: 100%, PP: 20, Status: AttackUp, Type: Omni}");
Move *omniBlast = new Move(200, 0, 30, 5, "","omni", "OmniBlast", " {Damage: 200, Accuracy: 30%, PP: 5, Type: Omni}");
Move *harden = new Move(0, 0, 100, 20, "defenceBoost","rock", "Harden", " {Accuracy: 100%, PP: 20, Status: DefenceUp, Type: Omni}");
Move *quickly = new Move(0, 0, 100, 20, "speedBoost","omni", "Quickly", " {Accuracy: 100%, PP: 20, Status: SpeedUp, Type: Omni}");
Move *endure = new Move(0, 100, 100, 20, "", "omni", "Endure", " {Healing: 100, Accuracy: 100%, PP: 20, Status: Burn, Type: Omni}");
Move *fury = new Move(10, 10, 100, 20, "attackBoost", "fire", "Fury", "{Damage: 10, Accuracy: 100%, PP: 20, Type: Fire}");
