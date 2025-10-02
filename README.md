# Space Shooter

A classic 2D space survival game developed in C++ using the **Qt Framework** (specifically Qt Graphics View Framework). The objective is to control your spaceship and survive for as long as possible while dodging incoming space objects like asteroids and comets, striving for the highest score.

## 🚀 Features

* **Real-time Gameplay:** Continuous spawning of asteroids and comets (on separate timers).

* **Mouse Control:** Player movement is controlled via mouse tracking for smooth navigation.

* **Scoring System:** Tracks the player's score during gameplay.

* **Custom Graphics:** Utilizes a custom background and scene setup (900x720).

* **Game Over UI:** A dedicated game over screen, titled "GAME OVER," which displays the final score.

## 💻 Technology Stack

* **Language:** C++

* **Framework:** Qt (Qt Core, Qt GUI, Qt Widgets, etc.)

* **Key Qt Modules Used:** `QGraphicsScene`, `QGraphicsView`, `QTimer`.

## 🛠️ Prerequisites

To build and run this project, you need to have the following installed:

* **Qt Framework:** Version 5 or 6 (along with the necessary C++ development tools).

* **C++ Compiler:** GCC, Clang, or MSVC.

## ⚙️ Building and Running

Since this is a standard Qt project, you can use the Qt build tools (like QMake or CMake) to compile the executable.

### Using Qt Creator

1. Clone this repository:
   ``git clone https://github.com/Dani-Hamzehlouy/Space-Invader.git``

3. Open the project file (`SpaceGame.pro`) in **Qt Creator**.

4. Configure the project for your desired build kit.

5. Click the **Run** button.

### Manual Build (QMake Example)

If you are building from the command line:

1. Navigate to the project root directory.

2. Run QMake to generate the Makefile:
---
```qmake SpaceGame.pro```
---

3. Run `make` (or `nmake` on Windows) to compile the code:

4. Run the generated executable file.

## 🕹️ How to Play

1. Start the game.

2. The player ship (controlled by the `Player` class) appears at the bottom center.

3. Use your **mouse** to control the horizontal position of the ship.

4. Avoid the falling **asteroids**  and **comets**.

5. Colliding with an enemy object will trigger the **Game Over** screen.

6. Click **Play Again** to restart or **Exit**
   
