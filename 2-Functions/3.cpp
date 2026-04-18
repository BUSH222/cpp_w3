#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Task: Game Character Management System
// Write all required functions to pass the test cases in main()

// Enum for character class (determines base stats)
enum CharacterClass {
    Warrior,    // High health, medium damage
    Mage,       // Low health, high damage
    Rogue,      // Medium health, high dodge
    Paladin     // Medium health, high defense
};

// Enum for character status conditions
enum Status {
    Healthy,
    Poisoned,
    Cursed,
    Blessed
};

// Struct representing a game character
struct Character {
    string name;
    int level;
    int health;
    int maxHealth;
    int mana;
    int attack;
    int defense;
    CharacterClass charClass;
    Status status;
};

// ============================================
// 1. Create a character with initial stats based on class (pass by value, return by value)
// Takes: name, CharacterClass
// Returns: Character struct with appropriate initial stats
Character createCharacter(string name, CharacterClass classType) {
    Character warrior = {name, 1, 100, 100, 50, 15, 8, Warrior, Healthy};
    Character mage =    {name, 1, 60,  60,  50, 20, 4, Mage, Healthy};
    Character rogue =   {name, 1, 80,  80,  50, 18, 6, Rogue, Healthy};
    Character paladin = {name, 1, 90,  90,  50, 12, 12, Paladin, Healthy};
    switch (classType){
        case Warrior: return warrior;
        case Mage: return mage;
        case Rogue: return rogue;
        case Paladin: return paladin;

    }
    // Warrior: 100 health, 15 attack, 8 defense
    // Mage: 60 health, 20 attack, 4 defense
    // Rogue: 80 health, 18 attack, 6 defense
    // Paladin: 90 health, 12 attack, 12 defense
    // All start at level 1, 50 mana, Healthy status
};

// ============================================
// 2. Print character details using const reference (pass by reference, doesn't modify)
// Takes: const Character reference
// Returns: void (prints to console)
void printCharacter(const Character& c) {
    cout << 
    "Name: " << c.name << 
    "\nLevel: "<< c.level << 
    "\nHealth: " << c.health << "/" << c.maxHealth << 
    "\nMana: " << c.mana <<
    "\nATK/DEF " << c.attack << "/" << c.defense << endl;
    switch (c.charClass){
        case Warrior: cout << "Class: Warrior" << endl; break;
        case Mage: cout << "Class: Mage" << endl; break;
        case Rogue: cout << "Class: Rogue" << endl; break;
        case Paladin: cout << "Class: Paladin" << endl; break;
    }
    switch (c.status){
        case Healthy: cout << "Healthy" << endl; break;
        case Poisoned: cout << "Poisoned" << endl; break;
        case Cursed: cout << "Cursed" << endl; break;
        case Blessed: cout << "Blessed" << endl; break;
    }
    // TODO: Implement
    // Print name, level, health/maxHealth, mana, attack, defense
    // Print class name (use switch or if-else)
    // Print status
    // Example output format:
    // Name: Aragorn | Level: 1 | Class: Warrior
    // Health: 100/100 | Mana: 50 | Attack: 15 | Defense: 8 | Status: Healthy
};

// ============================================
// 3. Take damage with defense calculation (modify by reference)
// Takes: Character reference, damage amount
// Returns: void (modifies health)
// Damage is reduced by (defense / 2), minimum 1 damage taken
void takeDamage(Character& c, int damage) {
    int actualDamage = max(1, damage-c.defense/2);
    if (c.status == Poisoned) {
        c.health -= actualDamage;
        c.health -= 5;
    } else {
        c.health -= actualDamage;
    }
    // TODO: Implement
    // Calculate: actualDamage = max(1, damage - defense/2)
    // Reduce health by actualDamage
    // If poisoned status, lose 5 extra health
};

// ============================================
// 4. Heal character (modify by reference)
// Takes: Character reference, heal amount
// Returns: void (modifies health)
void healCharacter(Character& c, int healAmount) {
    if (healAmount >= c.maxHealth-c.health){
        c.health = c.maxHealth;
    } else {
        c.health += healAmount;
    }
    // TODO: Implement
    // Increase health up to maxHealth (don't exceed)
};

// ============================================
// 5. Apply status condition using pointer (pass by pointer, modify)
// Takes: Character pointer, Status
// Returns: void (modifies status)
void applyStatus(Character* c, Status s) {
    c->status = s;
    // TODO: Implement
    // Set character's status to new status
};

// ============================================
// 6. Level up character (modify by reference)
// Takes: Character reference
// Returns: void (modifies level, stats)
void levelUp(Character& c) {
    c.level += 1;
    c.health += 10;
    c.health = c.maxHealth;
    c.mana += 5;
    c.attack += 2;
    c.defense += 1;
    // TODO: Implement
    // Increase level by 1
    // Increase maxHealth by 10, and set health to maxHealth
    // Increase mana by 5
    // Increase attack by 2
    // Increase defense by 1
};

// ============================================
// 7. Compare two characters by strength using const references (overload version)
// Takes: two const Character references
// Returns: int (-1 if c1 < c2, 0 if equal, 1 if c1 > c2)
// Compare by: (attack + defense) score
int compareCharacters(const Character& c1, const Character& c2) {
    int strength1 = c1.attack + c1.defense;
    int strength2 = c2.attack + c2.defense;
    if (strength1 < strength2){
        return -1;
    } else if (strength1 == strength2){
        return 0;
    } else {
        return 1;
    }
    // TODO: Implement
    // Calculate strength = attack + defense for each
    // Return comparison result
};

// ============================================
// 8. Calculate total damage output using pointer and recursion
// Takes: Character pointer, enemy pointer
// Returns: int (total damage)
// Include status effects: Blessed increases damage by 20%, Cursed reduces by 10%
int calculateTotalDamage(const Character* attacker, const Character* defender) {
    double base_damage = (*attacker).attack;
    switch ((*attacker).status){
        case 2: base_damage *= 0.9; break;
        case 3: base_damage *= 1.2; break;
    };

    base_damage -= (*defender).defense;
    (base_damage < 5)? base_damage = 5: base_damage = base_damage;
    return static_cast<int>(base_damage);
    // TODO: Implement
    // Base damage = attacker's attack
    // Apply status modifier to attacker
    // Reduce by defender's defense (minimum base damage of 5)
    // Return final damage value
};

// ============================================
// 9. Swap two characters using pointers
// Takes: two Character pointers
// Returns: void (swaps the entire character objects)
void swapCharacters(Character* c1, Character* c2) {
    Character c_temp;
    c_temp = *c1;
    *c1 = *c2;
    *c2 = c_temp;
    // TODO: Implement
    // Swap all member values between c1 and c2
};

// ============================================
// 10. Reset character to full health and remove status (modify by reference)
// Takes: Character reference
// Returns: void (modifies health and status)
void resetCharacter(Character& c) {
    c.health = c.maxHealth;
    c.status = Healthy;
    // TODO: Implement
    // Set health to maxHealth
    // Set status to Healthy
};

// ============================================
// MAIN TEST CASES - Do NOT modify
// ============================================
int main() {
    cout << "=== Character Management System ===" << endl << endl;

    // Test 1: Create different characters
    cout << "Test 1: Creating characters..." << endl;
    Character warrior = createCharacter("Aragorn", Warrior);
    Character mage = createCharacter("Gandalf", Mage);
    cout << "Created Warrior and Mage" << endl << endl;

    // Test 2: Print character details
    cout << "Test 2: Print warrior details:" << endl;
    printCharacter(warrior);
    cout << endl;

    // Test 3: Take damage with defense
    cout << "Test 3: Warrior takes 20 damage..." << endl;
    takeDamage(warrior, 20);  // 20 - 8/2 = 16 damage
    cout << "Health after damage: " << warrior.health << " (Expected: 84)" << endl << endl;

    // Test 4: Heal character
    cout << "Test 4: Heal warrior by 30..." << endl;
    healCharacter(warrior, 30);
    cout << "Health after healing: " << warrior.health << " (Expected: 100)" << endl << endl;

    // Test 5: Apply status condition
    cout << "Test 5: Apply Blessed status to mage..." << endl;
    applyStatus(&mage, Blessed);
    cout << "Mage status updated" << endl << endl;

    // Test 6: Level up
    cout << "Test 6: Level up warrior twice..." << endl;
    levelUp(warrior);
    levelUp(warrior);
    cout << "Warrior level: " << warrior.level << " (Expected: 3)" << endl;
    cout << "Warrior health: " << warrior.health << "/" << warrior.maxHealth 
         << " (Expected: 120/120)" << endl << endl;

    // Test 7: Compare characters
    cout << "Test 7: Compare warrior vs mage strength..." << endl;
    int comparison = compareCharacters(warrior, mage);
    if (comparison > 0) cout << "Warrior is stronger" << endl;
    else if (comparison < 0) cout << "Mage is stronger" << endl;
    else cout << "Equal strength" << endl;
    cout << endl;

    // Test 8: Calculate damage with status effects
    cout << "Test 8: Calculate damage (Blessed mage attacks warrior)..." << endl;
    int damage = calculateTotalDamage(&mage, &warrior);
    cout << "Damage dealt: " << damage << " (Blessed increases by 20%)" << endl << endl;

    // Test 9: Swap characters
    cout << "Test 9: Swap warrior and mage..." << endl;
    Character tempWarrior = warrior;
    swapCharacters(&warrior, &mage);
    cout << "After swap - warrior name: " << warrior.name << " (Expected: Gandalf)" << endl;
    cout << "After swap - mage name: " << mage.name << " (Expected: Aragorn)" << endl << endl;
    
    // Restore for next test
    swapCharacters(&warrior, &mage);

    // Test 10: Reset character
    cout << "Test 10: Poison warrior and then reset..." << endl;
    applyStatus(&warrior, Poisoned);
    takeDamage(warrior, 15);
    cout << "After poison damage - Health: " << warrior.health 
         << " Status: " << (warrior.status == Poisoned ? "Poisoned" : "Other") << endl;
    resetCharacter(warrior);
    cout << "After reset - Health: " << warrior.health << "/" << warrior.maxHealth
         << " Status: " << (warrior.status == Healthy ? "Healthy" : "Other") << endl;

    return 0;
}

// Implement all 10 functions above this line
