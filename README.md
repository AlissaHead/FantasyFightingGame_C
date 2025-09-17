# FantasyFightingGame
This is an ongoing passion project of a simple command-line-based battle arena game written in C++. The game allows two players to select characters and engage in turn-based combat.

## Features
- Player vs Player combat.
- Different character classes with unique abilities.
- In-game shop for buying weapons, armor, and potions.
- Player statistics tracking.
  
## How to Play
1. Clone the repository to your local machine.
2. Open the project in your preferred C++ development environment.
3. Compile and run the main.cpp file.
4. Follow the on-screen instructions to play the game.

## Classes
### Player
- Represents a player in the game.
- Contains attributes like name, health points, attack power, etc.
- Defines methods for combat, shopping, and using items.
### Character
- Base class for different character classes (e.g., Warrior, Mage).
- Contains virtual methods for abilities and item usage.
### Inventory
- Manages the player's inventory of items (weapons, armor, potions).
- Allows adding and removing items.
### Potions
- Represents a potion item.
- Contains attributes like name, effect, price, etc.
- Defines methods for applying the potion's effect.
  
## Usage
- Choose your characters and start the game.
- During combat, select abilities or items when prompted.
- Use the in-game shop to upgrade your character between rounds.

## Contributing
If you'd like to contribute to this project, please follow these steps:

1. Fork the repository.
2. Create a new branch for your feature (git checkout -b feature-name).
3. Make your changes and commit them (git commit -m 'Description of changes').
4. Push the branch to your fork (git push origin feature-name).
5. Create a pull request on the original repository.
