# DroEngine

## Simple 2D Game Engine written in C++ using SDL2 library.

Repository includes the engine and a small demo showing the current capabilities of the engine.

![demonstration of the demo game scene](demo.gif)

## Implemented features

### Components
- Sprite component
- Animator component
  - Uses the position of current animation frame (sprite) on the spritesheet.
- Rigidbody
  - Detects and resolves collisions taking into account weights of colliding objects.
- Collider
  - Represents the physical body of an object. Currently available only as a rectangle.

### Prefabs
- Entity
  - Represents a movable entity. Includes sprite, animator, rigidbody and collider components.
- Tiled Texture
  - Represents a tiled texture. Includes sprite, rigidbody and collider components. By default rigidbody is set to static and collider component is disabled.
- Tiled Wall
  - Represents a tiled texture with a collider.

### Utilities
- Scene builder
  - Basic scene builder that generates a game scene using a symbol map of the scene made with and prefabs representing the symbols.

## Running the demo
To compile the engine with the demo, go to `game` folder of the repository and run `make default`. To clean the repository up after compiling, run `make clean` in the same folder.