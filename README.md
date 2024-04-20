- [Asciiman](#asciiman)
  - [Animations](#animations)
    - [Animation tool](#animation-tool)
      - [Options](#options)
  - [Screen](#screen)
  - [Layers](#layers)
- [Future Work](#future-work)

# Asciiman

Asciiman is a game engine that uses the terminal to render a game.

## Animations

Entities can hold multiple animations, of which can be cycled through.

The internal representation is a circular singly linked list of the different states.

### Animation tool

There is an animation tool that can be used to create animations for entities. The tool is a web-based tool that can be used to create animations for entities.

Prior to running the tool, you must install the Flask library:

```bash
pip3 install flask
```

To run the tool, use the following command from the project root:

```bash
python3 ./src/anim_tool.py
```

The tool will be available at `http://localhost:8000`.

#### Options

```bash
usage: anim_tool.py [-h] [--ip IP] [--port PORT]

Webserver to serve animation tool.

options:
  -h, --help            show this help message and exit
  --ip IP, -i IP        IP the server will listen on (default:localhost)
  --port PORT, -p PORT  Port number of the server (default: 8000)
```

## Screen

The screen is made in the terminal and operates by "cooking" and "uncooking" the terminal to and from raw mode.

Any update to the screen is made with a position-based update instead of flushing and redrawing the whole screen.

Screen buffering is used between updates to reduce flickering. This system will create a delta between the current screen and the next screen. The delta will be applied to the screen to update the screen.

Proccessing path goes from the top left to the bottom right.
Player representation is passed as a matrix to the screen, then the screen will render the player on the screen.

## Layers

Although not implemented yet, I plan on adding layer support to the game "world" and to help rendering.

The rendering order would be as follows:

- Background
- Player
- Foreground


# Future Work

- Create file format to allow new icons and animation frames
- Abstract player type to be an entity type
