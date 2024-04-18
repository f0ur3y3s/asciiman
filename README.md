- [Ascii Stickman](#ascii-stickman)
- [Screen](#screen)
  - [Layers](#layers)
- [Character](#character)
  - [Base](#base)
  - [Right walking first](#right-walking-first)
  - [Right walking second](#right-walking-second)
  - [Left walking first](#left-walking-first)
  - [Left walking second](#left-walking-second)
  - [Jump Prep](#jump-prep)
  - [Mid air jump right](#mid-air-jump-right)
  - [Mid air jump left](#mid-air-jump-left)

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

## Base
```
 O
/|\
/ \
```

## Right walking first

```
 O
/|└
 >\
```

## Right walking second

```
 O
<|\
/ >
```



## Left walking first

```
 O
┘|\
/<
```

## Left walking second

```
 O
/|>
< \
```

## Jump Prep

```
 O
/|\
< >
```

## Mid air jump right

```
 O
v|v
 >>
```

## Mid air jump left

```
 O
v|v
<<
```