# cub3D

<p align="center">
  <img src="https://github.com/mcombeau/mcombeau/blob/main/42_badges/cub3de.png" alt="Cub3D 42 project badge"/>
</p>

Cub3D is a 42 school team project to create a dynamic view inside a 3D maze by implementing raycasting in the style of the famous Wolfenstein 3D game.


## Compile and Run

To compile, `cd` into the cloned directory and:

```shell
make
```

If library needs to adjust permissions use chmod +x.

To run the program:

```shell
./cub3d <path/to/map.cub>
```

The program takes a map file as an argument. Maps are available in the `maps` directory. There is a valid map which the program should run smoothly with, and invalid maps which the program should reject.
For example:

- `./cub3d maps/valid/subject_map.cub` should run.

- `./cub3d maps/invalid/no_color.cub` should print an error and abort.

## Controls

Controls for movement and rotation are:

- `W`: move forward
- `S`: move backward
- `A`: strafe left
- `D`: strafe right
- `left arrow`: rotate left
- `right arrow`: rotate right
