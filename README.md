- [Ascii Stickman](#ascii-stickman)
- [Screen](#screen)
  - [Layers](#layers)
- [Character](#character)
  - [Idle](#idle)
  - [Right walking](#right-walking)
  - [Left walking](#left-walking)
  - [Jump Prep](#jump-prep)
  - [Mid air jump right](#mid-air-jump-right)
  - [Mid air jump left](#mid-air-jump-left)
  - [Attack](#attack)
  - [Holding heavy weapon](#holding-heavy-weapon)

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

## Right walking

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
/|
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

## Jump Prep

```
\o/
<'>
```

## Mid air jump right

```
\o/
 )
//
```

## Mid air jump left

```
\o/
 (
 \\
```

## Attack

```
 o
`)\
/>
```

## Holding heavy weapon

```
     /\
    / /
 o_/)/
 \/
/ \
```


