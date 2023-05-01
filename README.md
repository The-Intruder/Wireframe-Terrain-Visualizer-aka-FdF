<br/>
<p align="center">
  <a href="https://github.com/The-Intruder/Wireframe-Terrain-Visualizer-aka-FdF">
    <img src="https://i.pinimg.com/originals/f6/2d/e6/f62de6bd66da099c0b7c49bd96de8e81.png" alt="Banner">
  </a>

  <h3 align="center">Wireframe Terrain Visualizer <em>(Fils de Fer)</em></h3>

  <p align="center">
    A graphical representation of a landscape using a wireframe and color gradient to simulate a 3D effect
    <br/>
    <br/>
    <a href="https://github.com/The-Intruder/Wireframe-Terrain-Visualizer-aka-FdF/issues">Report Bug</a>
    .
    <a href="https://github.com/The-Intruder/Wireframe-Terrain-Visualizer-aka-FdF/issues">Request Feature</a>
  </p>
</p>

<div  style="display: flex; justify-content: center;">
<a  href="https://twitter.com/i_am_amine" target="_blank">
  <img  alt="Twitter Follow"  src="https://img.shields.io/twitter/follow/i_am_amine?style=social">
</a>
<img  src="https://img.shields.io/github/repo-size/The-Intruder/Wireframe-Terrain-Visualizer-aka-FdF"  alt="Repo Size">
<img  src="https://img.shields.io/github/last-commit/The-Intruder/Wireframe-Terrain-Visualizer-aka-FdF"  alt="Last Commit">
<img alt="GitHub" src="https://img.shields.io/github/license/The-Intruder/Wireframe-Terrain-Visualizer-aka-FdF">
</div>

## Table Of Contents

* [About the Project](#about-the-project)
* [Built With](#built-with)
* [Getting Started](#getting-started)
  * [Prerequisites](#prerequisites)
  * [Installation](#installation)
* [Usage](#usage)
* [Roadmap](#roadmap)
* [Contributing](#contributing)
* [License](#license)
* [Authors](#authors)
* [Acknowledgements](#acknowledgements)

## About The Project

The FdF (Fil de Fer) project is an intriguing endeavor that aims to create a captivating graphical representation of landscapes. It leverages wireframe rendering and color gradients to simulate a mesmerizing three-dimensional effect. By transforming raw data into visually stunning and interactive landscapes, this project showcases the creativity and technical skills of developers.

#### Features
- Generate visually appealing representations of landscapes.
- Utilize wireframe rendering to create a distinct visual style.
- Implement color gradients to simulate a lifelike three-dimensional effect.
- Interact with the landscapes, exploring different perspectives and angles.
- Navigate the intricacies of transforming data into immersive graphical representations.

## Built With

##### **C Programming Language:**
The FdF project is primarily implemented using the C programming language, providing low-level control and efficiency for graphics rendering and data manipulation.

##### **Minilibx Graphics Library:**
The project utilizes the Minilibx graphics library, which provides functions for window creation, pixel manipulation, and event handling. These libraries offer the necessary tools for rendering and interacting with graphical elements.

##### **Wireframe Rendering Techniques:**
FdF employs wireframe rendering techniques to create a visual representation of landscapes. This involves drawing lines between given points to form a mesh-like structure, simulating the geometry of the landscape.

##### **Data Parsing and Manipulation:**
FdF involves parsing data files that represent the landscapes. The project handles parsing and manipulates the data to extract necessary information such as coordinates, elevations, and colors for rendering.

##### **Interactive User Interface Components:**
The project incorporates interactive user interface components to enable users to navigate and explore the landscapes. This includes controls for rotating, zooming, and panning the rendered scene, providing an interactive and immersive experience.

##### **Matrix Transformations:**
FdF employs matrix transformations such as translation, rotation, and scaling to manipulate the landscape data and transform it into a visually appealing representation. These transformations allow for the positioning and orientation of the rendered elements.

##### **Mathematical Calculations** _(3D Isometric Projection)_**:**
The project utilizes mathematical calculations, including 3D projection techniques like isometric or perspective projection, to convert the landscape data into a 3D representation that can be rendered on a 2D screen.

##### **User Input Handling and Event Processing:**
FdF incorporates user input handling to capture and process events such as keyboard and mouse interactions. This allows users to interact with the rendered scene and perform actions like rotating the view or changing rendering settings.


## Getting Started

This following section provides step-by-step instructions for getting started with the FdF project

### Prerequisites

Prerequisites:
- _**C Compiler:**_ To compile and run the FdF project, you need the `gcc` C compiler installed on your system.

- _**Graphics Library:**_ FdF relies on the MiniLibX graphics library for rendering and interacting with graphical elements. Ensure that you have it installed and set up properly.

- _**Unix-Based Operating System:**_ The project is typically developed and tested on Unix-based operating systems like Linux or macOS. It is recommended to have access to a Unix environment for proper library support and compatibility.

### Installation

Getting Started:
1. Clone the Repository:
   Start by cloning the FdF project repository from the official source using the following command:

```bash
git clone https://github.com/username/fdf.git
```

2. Install Graphics Library:
FdF relies on a graphics library like MiniLibX for rendering. Install the necessary graphics library and set it up according to the provided instructions or documentation.

3. Compile the Project:
Use a C compiler to compile the FdF project source code. Navigate to the project directory and execute the compilation command. For example:

```bash
gcc -o fdf fdf.c -L/path/to/library -lminilibx
```

_**Note:** Replace `/path/to/library` with the path where the graphics library is installed._

## Usage

Usage:
1. Start the Program:
   Run the compiled FdF program using the following command:

```bash
./fdf map_file.fdf
```

_**Note:** Replace `map_file.fdf` with the path to the FdF data file containing the landscape information. The program will read the file and render the corresponding 3D landscape._

2. Navigation Controls:
- Rotate: Use the `x`, `y`, or `z` to rotate the scene horizontally, vertically, and diagonally respectively, and view the landscape from different angles.
- Zoom: Press the `+` and `-` keys or use the mouse scroll wheel to zoom in and out of the scene.

3. Render Modes:
FdF supports different render modes to visualize the landscape in various ways. Use the `P` key to switch between modes:
- Wireframe mode (default), which displays the landscape as a mesh of lines.
- Flat mode, which fills the polygons of the landscape with a flat color.

4. Additional Controls:
- Change Elevation: Press the `PageUp` and `PageDown` keys to increase or decrease the elevation of the landscape.
- Reset View: Press the `R` key to reset the view to the initial position and orientation.
- Quit: Press the `Esc` key or close the application window to exit the program.

5. Customize the Program:
Feel free to modify the FdF source code to add new features, change rendering algorithms, or experiment with different visualization techniques. Recompile the program after making any modifications.

6. Input Data Format:
The FdF program reads input data files in a specific format. Ensure that your map file follows the required format, which typically consists of space-separated values representing the elevation of each point in the landscape. Refer to the project documentation or examples for more details on the input file format.

7. Explore and Analyze:
Use the FdF program to explore and analyze various landscapes. Experiment with different input files, try out different render modes, and observe the visual representation of elevation changes. Use it as a tool to better understand and analyze geographical data.

8. Report Issues and Contribute:
If you encounter any issues or have suggestions for improvement, consider reporting them to the project repository's issue tracker. You can also contribute to the project by submitting bug fixes, enhancements, or new features to the official repository.

## Roadmap

This section outlines a suggested roadmap for the FdF project, highlighting key milestones and features that can be implemented to enhance the functionality and user experience of the program.

1. Basic Functionality:
    - [ ] Implement parsing of the input data file to read and process the landscape data.
    - [ ] Render the 3D landscape using a wireframe representation.
    - [ ] Allow basic navigation controls to rotate, zoom, and pan the view of the landscape.

2. Enhanced Rendering:
    - [ ] Implement additional rendering modes such as flat shading, Gouraud shading, or Phong shading to provide more visually appealing representations of the landscape.
    - [ ] Explore color mapping techniques based on elevation to visualize the terrain more effectively.

3. User Interaction:
    - [ ] Enable user interaction by allowing the modification of individual points in the landscape.
    - [ ] Implement dynamic lighting effects to enhance the visual quality of the landscape representation.

4. Advanced Rendering Techniques:
    - [ ] Explore advanced rendering techniques such as shadow mapping, reflections, or post-processing effects to further improve the visual realism of the landscape.
    - [ ] Implement advanced shading models like per-pixel lighting or physically-based rendering (PBR) for more accurate lighting simulations.

5. Optimization and Performance:
    - [ ] Optimize the rendering pipeline to improve performance and efficiency, allowing for larger and more complex landscapes to be rendered smoothly.
    - [ ] Implement techniques such as level-of-detail (LOD) rendering or geometry instancing to handle high-resolution terrains more efficiently.

6. Additional Features:
    - [ ] Add support for loading and rendering textures to enhance the visual representation of the landscape.
    - [ ] Implement terrain generation algorithms to generate procedurally generated landscapes.
    - [ ] Allow importing and exporting of landscape data in different file formats.

7. User Interface and Configuration:
    - [ ] Design and implement a user-friendly interface to provide intuitive controls and options for the user to customize the rendering and interaction settings.
    - [ ] Provide configuration files or settings to allow users to customize various aspects of the program, such as keybindings, default render modes, or window settings.

8. Documentation and Testing:
    - [ ] Create comprehensive documentation that explains the usage and features of the program.
    - [ ] Perform thorough testing to ensure the program functions correctly and handles different scenarios.

9. Refinement and Polish:
    - [ ] Continuously improve and refine the program based on user feedback and testing.
    - [ ] Address any bugs or issues reported by users and ensure a smooth and stable user experience.

10. Deployment and Distribution:
    - [ ] Prepare the program for deployment by packaging it into an executable or installer.
    - [ ] Distribute the program to the intended audience, whether it be classmates, instructors, or the wider community.


## Contributing

Contributions are what make the open source community such an amazing place to be learn, inspire, and create. Any contributions you make are **greatly appreciated**.
* If you have suggestions for adding or removing projects, feel free to [open an issue](https://github.com/The-Intruder/Wireframe-Terrain-Visualizer-aka-FdF/issues/new) to discuss it, or directly create a pull request after you edit the *README.md* file with necessary changes.
* Please make sure you check your spelling and grammar.
* Create individual PR for each suggestion.
* Please also read through the [Code Of Conduct](https://github.com/The-Intruder/Wireframe-Terrain-Visualizer-aka-FdF/blob/main/CODE_OF_CONDUCT.md) before posting your first idea as well.

### Creating A Pull Request

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## Very useful ressources _(and the base of this README)_

- [42 Minilibx official Repo](https://github.com/42Paris/minilibx-linux)
- [Getting Started with the Minilibx](https://aurelienbrabant.fr/blog/getting-started-with-the-minilibx)
- [Pixel Drawing with the Minilibx](https://aurelienbrabant.fr/blog/pixel-drawing-with-the-minilibx)
- [Managing Events with the Minilibx](https://aurelienbrabant.fr/blog/managing-events-with-the-minilibx)
- [42 UNofficial Documentation of Minilibx](https://harm-smits.github.io/42docs/libs/minilibx)
- [Another 42 UNofficial Documentation of Minilibx](https://gontjarow.github.io/MiniLibX/)
- [FdF CookBook](https://stackoverflow.com/c/42network/questions/164)
- [Interesing GitHub repo with a lot of useful stuff](https://github.com/qst0/ft_libgfx#the-graphics-branch)
- [How to draw in an image instead of directly in the window, and why you should do that.](https://github.com/keuhdall/images_example)

## License

Distributed under the MIT License. See [LICENSE](https://github.com/The-Intruder/Wireframe-Terrain-Visualizer-aka-FdF/blob/main/LICENSE.md) for more information.

## Authors

* **Mohamed Amine Naimi** - *Computer Science Student* - [Mohamed Amine Naimi](https://github.com/The-Intruder/) - *Built the FdF Project*

## Acknowledgements

* [The-Intruder](https://github.com/The-Intruder/)
