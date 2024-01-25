# So_Long project
## How To Use Libft
1. Copy and paste the following in shell
```
git clone https://github.com/Lucabhm/So_Long.git
```
2. cd inside the so_long directory and use the following command to compile the files
```
make
```
3. use this syntax to execute the Program
```
./so_long <map file>
```
4. if you want to compile the bonus part use
```
make bonus
```
5. to execute the bonus part use this syntax
```
./so_long_bonus <map file>
```
## Instruction
 You must create a basic 2D game in which a dolphin
escapes Earth after eating some fish.  Instead of
a dolphin, fish, and the Earth, you can use any
character, any collectible and any place you want.
## Mandatory part
### Game
+ The player’s goal is to collect every collectible present on the map, then escape chosing the shortest possible route.
+ The W, A, S, and D keys must be used to move the main character.
+ The player should be able to move in these 4 directions: up, down, left, right.
+ The player should not be able to move into walls.
+ At every move, the current number of movements must be displayed in the shell.
+ You have to use a 2D view (top-down or profile).
+ The game doesn’t have to be real time.
+ Although the given examples show a dolphin theme, you can create the world you want.
### Graphic management
+ Your program has to display the image in a window.
+ The management of your window must remain smooth (changing to another window, minimizing, and so forth).
+ Pressing ESC must close the window and quit the program in a clean way.
+ Clicking on the cross on the window’s frame must close the window and quit the program in a clean way.
+ The use of the images of the MiniLibX is mandatory.
### Map
+ The map has to be constructed with 3 components: walls, collectibles, and free space.
+ The map can be composed of only these 5 characters:
  - 0 for an empty space,
  - 1 for a wall,
  - C for a collectible,
  - E for a map exit,
  - P for the player’s starting position.
+ The map must contain 1 exit, at least 1 collectible, and 1 starting position to be valid.
+ The map must be rectangular.
+ The map must be closed/surrounded by walls. If it’s not, the program must return an error.
+ You have to check if there’s a valid path in the map.
+ You must be able to parse any kind of map, as long as it respects the above rules.
+ If any misconfiguration of any kind is encountered in the file, the program must exit in a clean way, and return "Error\n" followed by an explicit error message of your choice.
## Images
![8C55CF4E-A603-4D5D-BDCD-7F4AB1A749CF](https://github.com/Lucabhm/So_Long/assets/144374574/22c1373e-ab5d-4781-867e-cd2fc5f35fc4)
![C8734BA9-1ECE-4F86-80C5-537236B87C14_4_5005_c](https://github.com/Lucabhm/So_Long/assets/144374574/acb9d9ec-b7ec-4201-84a0-a64c026b46b7)
## My Result
![0B15A534-0349-4F5F-BB22-C6C798B7D727](https://github.com/Lucabhm/So_Long/assets/144374574/4ee04e82-5f66-4e1d-b03c-41e6d72bcaa1)
