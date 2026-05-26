# Gravity Simulation

An interactive **2D gravity sandbox** written in **C++ using OpenGL and GLFW**.

Objects can be spawned with the mouse, given mass, and launched into a simulation where they interact dynamically with each other and the environment.

---

## Demo

![Gravity Simulation Demo](assets/demo_v1.gif)

---

## Features

* Real-time rendering using **OpenGL**
* Window and input management using **GLFW**
* Interactive **mouse-based object spawning**
* Adjustable object **mass during initialization**
* Launch objects with **custom velocity vectors**
* Dynamic object radius based on **mass and density**
* Boundary collision with bounce response
* Basic object-to-object attraction
* Live mouse coordinates displayed in the window title

---

## Controls

| Action           | Description                |
| ---------------- | -------------------------- |
| Left Mouse Press | Spawn a new object         |
| Hold Mouse       | Increase the object's mass |
| Release Mouse    | Launch the object          |

During initialization:

* A line shows the **launch direction**
* Holding the cursor inside the object **increases its mass**

---

## Physics Model

Each object maintains:

* Position
* Velocity
* Mass
* Density
* Radius

Radius is derived from mass and density:

volume = mass / density
radius = ((3 * volume) / (4π))^(1/3)

Objects accelerate toward each other using a simplified attraction model and bounce off window boundaries.

---

## Project Structure

gravity-simulation
│
├── src
│   └── gravity_sim.cpp
│
├── include
│   ├── GL
│   └── GLFW
│
├── assets
│   └── demo_v1.gif
│
├── .vscode
│   ├── settings.json
│   ├── c_cpp_properties.json
│   ├── launch.json
│   └── tasks.json
│
├── glfw3.dll
├── run.bat
├── README.md
└── .gitignore

---

## Requirements

* C++17 compatible compiler
* OpenGL
* GLFW
* Windows environment (MinGW / MSYS2 recommended)
* Visual Studio Code (optional)

---

## Build

Compile using:

g++ src/gravity_sim.cpp -o gravity_sim.exe -lglfw3 -lopengl32 -lgdi32

---

## Run

Run the program:

gravity_sim.exe

or simply double-click:

run.bat

Note: `glfw3.dll` must be present in the same directory as the executable.

---

## Future Improvements

Possible next improvements for this project:

* Implement proper **Newtonian gravity using the inverse-square law**
* Improve **collision response between objects**
* Add **object merging on collision**
* Introduce **simulation pause/reset controls**
* Add **motion trails** to visualize trajectories
* Improve code structure by separating **physics and rendering systems**

---

## Author

Meet Patel
Computer Engineering Student
