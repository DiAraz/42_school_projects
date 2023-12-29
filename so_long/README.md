# so_long

<p align="center">
  <img src="https://github.com/DiAraz/DiAraz/blob/main/42_badges/so_longe.png"/>
</p>

## Description

so_long project is focused on developing a 2D game that can be interacted with using a keyboard.
The player has to collect all the collectibles and chose the nearest exit.


![so_long_cropped](https://github.com/DiAraz/42_school_projects/assets/128155906/c07730ea-d420-48e3-b6c7-f607a888ff0d)

## Usage

Git clone the repository and cd into it. Then use ```make``` to compile.

Then run it with :

```shell
./so_long <valid_map>
```

For example :

```shell
./so_long maps/valid/map3.ber
```

## The Game

- The player’s goal is to collect every collectible present on the map, then escape choosing the shortest possible route.
- The W, A, S, and D keys (or arrow keys) must be used to move the main character.
- The player should be able to move in these 4 directions: up, down, left, right.
- The player should not be able to move into walls.
- At every move, the current number of movements must be displayed in the shell.
- You have to use a 2D view (top-down or profile).

## Maps

- The map has to be constructed with 3 components: walls, collectibles, and free space.
- The map can be composed of only these 5 characters:
	- 0 for an empty space,
	- 1 for a wall,
	- C for a collectible,
	- E for a map exit,
	- P for the player’s starting position.
- The map must contain 1 exit, at least 1 collectible, and 1 starting position to be valid.
- Here is a simple valid map:

![map](https://github.com/DiAraz/42_school_projects/assets/128155906/92345705-d815-4a35-a9c7-8ad832904145)
- The map must be rectangular.
- The map must be closed/surrounded by walls. If it’s not, the program must return an error.
- You have to check if there’s a valid path in the map.
- You must be able to parse any kind of map, as long as it respects the above rules.
- Map file has to be *.ber 