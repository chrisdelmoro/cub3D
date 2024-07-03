<div id="top"></div>

<!-- PROJECT SHIELDS -->
<br/>
<p align="center">
    <img src="https://github.com/chrisdelmoro/cube3D/blob/main/resources/repo/cub3dm.png" alt="Logo" width="150" height="150">

  <p align="center">
    This project is inspired by the world-famous Wolfenstein 3D game, which was the first FPS ever. It enable us to explore ray-casting. Our goal was be to make a dynamic view inside a maze, in which the player have to find their way.
    <br/>
    <img src="https://img.shields.io/badge/Mandatory-OK-brightgreen"/>
    <img src="https://img.shields.io/badge/Bonus-OK-brightgreen"/>
    <img src="https://img.shields.io/badge/Final%20Score-110-blue"/>
  </p>
</p>


<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li><a href="#about-the-project">About The Project</a></li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
  </ol>
</details>


<!-- ABOUT THE PROJECT -->
## About The Project

The Cub3D project at École 42 is a graphics programming project that involves creating a basic 3D game using a raycasting engine. This project helps students understand key concepts in computer graphics and game development. Here are the main focus areas:

1. **Raycasting**: Students learn about the raycasting technique, which is used to create a pseudo-3D perspective by casting rays from the player's point of view to detect walls and other objects in a 2D map. This technique is similar to what was used in early 3D games like Wolfenstein 3D.

2. **Graphics Rendering**: The project requires students to render 3D scenes on a 2D screen. They learn about rendering techniques, color handling, and texture mapping to create visually appealing graphics.

3. **2D Map Handling**: Students design and manage a 2D map that represents the game world. The map includes walls, spaces, and objects that the player can interact with. The map data is used by the raycasting algorithm to determine what the player sees.

4. **Player Movement and Interaction**: Implementing player movement, including forward, backward, and rotational movement, is a key part of the project. Students also handle collision detection to prevent the player from walking through walls.

5. **MinilibX Library**: The project typically uses the MinilibX library, a simple X-Window (X11) graphics library, to handle window creation, image drawing, and keyboard input. Students learn how to use this library to manage graphical output and user interactions.

6. **Game Logic**: Basic game logic is implemented, including player controls, object interactions, and possibly simple enemy AI. This helps students understand the foundational elements of game development.

7. **Performance Optimization**: Students learn about optimizing their code to run efficiently, ensuring smooth rendering and gameplay even with the constraints of a raycasting engine.

8. **Code Structure and Organization**: Emphasis is placed on writing clean, modular, and maintainable code. Students learn to separate different parts of the game engine into distinct modules, such as rendering, input handling, and game logic.

The Cub3D project is a comprehensive introduction to 3D graphics programming, providing students with practical experience in creating a functional 3D game from scratch. It helps develop skills in graphics rendering, algorithm implementation, and game design principles.

The map prerequesites are:
1. The map needs to have a .cub extension;
2. The map can contain only valid caracters:
	* 1 to represent a wall;
	* 0 to represent empty space, or a walkable area;
	* N,S,E or W for the player’s start position and spawning orientation.
3. The map must be closed/surrounded by walls, if not the program must return an error.
4. Except for the map content, each type of element can be separated by one or more empty line(s).
5. Except for the map content which always has to be the last, each type of element can be set in any order in the file.
6. Except for the map, each type of information from an element can be separated by one or more space(s).
7. The map must be parsed as it looks in the file. Spaces are a valid part of the map and are up to you to handle. You must be able to parse any kind of map, as long as it respects the rules of the map.
8. Each element (except the map) firsts information is the type identifier (composed by one or two character(s)), followed by all specific informations for each object in a strict order such as :
    * North texture: **NO ./path_to_the_north_texture**
        * identifier: NO
        * path to the north texure
    * South texture: **SO ./path_to_the_south_texture**
        * identifier: SO
        * path to the south texure
    * West texture: **WE ./path_to_the_west_texture**
        * identifier: WE
        * path to the west texure
    * East texture: **EA ./path_to_the_east_texture**
        * identifier: EA
        * path to the east texure
    * Floor color: **F 220,100,0**
        * identifier: F
        * R,G,B colors in range [0,255]: 0, 255, 255
    * Ceiling color: **C 225,30,0**
        * identifier: C
        * R,G,B colors in range [0,255]: 0, 255, 255

The buttons that can be pressed on the game are:
* W, A, S and D are used to move the player character;
* Left and Right arrow keys are used to turn the camera;
* ESC can be pressed to close the game. You can also click the X button on the top right of the screen;

<p align="right">(<a href="#top">back to top</a>)</p>


## Prerequisites

This project uses 42s MiniLibX to render the game. Therefore you need to have it installed on your Linux machine. The library can be found [here](https://github.com/42Paris/minilibx-linux).

<p align="right">(<a href="#top">back to top</a>)</p>


<!-- USAGE EXAMPLES -->
## Usage

Clone the repo and make it. Run ```make``` to play the game. A binary will be compiled inside the /bin folder.

<p align="right">(<a href="#top">back to top</a>)</p>


<!-- LICENSE -->
## License

Distributed under the [GNU General Public License version 3 (GPLv3)](https://www.gnu.org/licenses/gpl-3.0.html). 

<p align="right">(<a href="#top">back to top</a>)</p>


<!-- CONTACT -->
## Contact

Christian C. Del Moro - christian.delmoro@protonmail.com

Project Link: [https://github.com/chrisdelmoro/cub3D](https://github.com/chrisdelmoro/cub3D)

<p align="right">(<a href="#top">back to top</a>)</p>


<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->