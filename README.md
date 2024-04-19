- [Ascii Stickman](#ascii-stickman)
- [Screen](#screen)
  - [Layers](#layers)
- [Character](#character)
  - [Idle](#idle)
  - [Right walking](#right-walking)
  - [Left walking](#left-walking)
  - [Jump Prep](#jump-prep)
  - [Mid air jump idle](#mid-air-jump-idle)
  - [Mid air jump right](#mid-air-jump-right)
  - [Mid air jump left](#mid-air-jump-left)
  - [Attack](#attack)
  - [Holding heavy weapon](#holding-heavy-weapon)
- [Future Work](#future-work)
- [Animation format](#animation-format)
- [Character matrix](#character-matrix)
- [Animation format](#animation-format-1)
  - [Frame 1](#frame-1)
  - [Frame 2](#frame-2)

# Ascii Stickman

# Screen

The screen is made in the terminal.

Any update to the screen is made with a position-based update instead of flushing and redrawing the whole screen.

Screen buffering is used between updates to reduce flickering. This system will create a delta between the current screen and the next screen. The delta will be applied to the screen to update the screen.

Proccessing path goes from the top left to the bottom right.
Player representation is passed as a matrix to the screen, then the screen will render the player on the screen.

## Layers

The rendering order is as follows:

- Background
- Player
- Foreground

# Character

## Idle

```
 o
/|\
/ \
```

For the animations, could create a circularly linked list of the different states.

Hold the animation csll in an singly linked list with a key loop function for the walking and idle animations. This allows multiple animation csll to be held by the player

## Right walking

original four

```
 o
/|\
/ \
 o
/|\
 >\
 o
/|\
 |\
 o
/|\
 |>
```

extended ascii with wchar

```
 o
/|\
/ \
 o
/|\
 ┘\
 o
/|\
 |\
 o
/|\
 |┘
```

extended set

```
 o
/|\
/ \
 o
/|\
 >\
 o
/|\
 |\
 o
/|\
/ \
 o
/|\
/ >
 o
/|\
 |>
```

## Left walking

```
 o
/|\
/ \
 o
/|\
/<
 o
/|\
/|
 o
/|\
<|
```
extended ascii

```
 o
/|\
/ \
 o
/|\
/└
 o
/|\
/|
 o
/|\
└|
```

## Jump Prep

```
 o
/|\
/ \

_o_
<'>

\o/
<'>
```

## Mid air jump idle

```
\o/
 |
/ \
```

## Mid air jump right

```
\o/
 )
/┘
```

## Mid air jump left

```
\o/
 (
 └\
```

## Attack

```
 o
`)\
/┘
```

## Holding heavy weapon

```
     /\
    / /
 o_/)/
 \/
/ \
```

# Future Work

- Create file format to allow new icons and animation frames
- Abstract player type to be an entity type

# Animation format

# Character matrix
```
|     |     |     |     |     |     |
| 0,0 | 1,0 | 2,0 | 3,0 | 4,0 | 5,0 |
|_____|_____|_____|_____|_____|_____|
|     |     |     |     |     |     |
| 0,1 | 1,1 | 2,1 | 3,1 | 4,1 | 5,1 |
|_____|_____|_____|_____|_____|_____|
|     |     |     |     |     |     |
| 0,2 | 1,2 | 2,2 | 3,2 | 4,2 | 5,2 |
|_____|_____|_____|_____|_____|_____|
|     |     |     |     |     |     |
| 0,3 | 1,3 | 2,3 | 3,3 | 4,3 | 5,3 |
|_____|_____|_____|_____|_____|_____|
|     |     |     |     |     |     |
| 0,4 | 1,4 | 2,4 | 3,4 | 4,4 | 5,4 |
|_____|_____|_____|_____|_____|_____|
```

# Animation format
## Frame 1
```
TARGET 1,1 - 2,2
|     |     |     |     |     |     |
| 0,0 | 1,0 | 2,0 | 3,0 | 4,0 | 5,0 |
|_____|_____|_____|_____|_____|_____|
|     |     |     |     |     |     |
| 0,1 |  X  |  X  | 3,1 | 4,1 | 5,1 |
|_____|_____|_____|_____|_____|_____|
|     |     |     |     |     |     |
| 0,2 |  X  |  X  | 3,2 | 4,2 | 5,2 |
|_____|_____|_____|_____|_____|_____|
|     |     |     |     |     |     |
| 0,3 | 1,3 | 2,3 | 3,3 | 4,3 | 5,3 |
|_____|_____|_____|_____|_____|_____|
|     |     |     |     |     |     |
| 0,4 | 1,4 | 2,4 | 3,4 | 4,4 | 5,4 |
|_____|_____|_____|_____|_____|_____|
```

## Frame 2
```
TARGET 0,3 - 5,4
|     |     |     |     |     |     |
| 0,0 | 1,0 | 2,0 | 3,0 | 4,0 | 5,0 |
|_____|_____|_____|_____|_____|_____|
|     |     |     |     |     |     |
| 0,1 |  X  |  X  | 3,1 | 4,1 | 5,1 |
|_____|_____|_____|_____|_____|_____|
|     |     |     |     |     |     |
| 0,2 |  X  |  X  | 3,2 | 4,2 | 5,2 |
|_____|_____|_____|_____|_____|_____|
|     |     |     |     |     |     |
|  X  |  X  |  X  |  X  |  X  |  X  |
|_____|_____|_____|_____|_____|_____|
|     |     |     |     |     |     |
|  X  |  X  |  X  |  X  |  X  |  X  |
|_____|_____|_____|_____|_____|_____|
```