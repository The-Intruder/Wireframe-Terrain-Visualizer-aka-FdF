```text
 ______________________________________________________________________________
|______________________________________________________________________________|
|________________/\\\\\\\\\\\\\\\____/\\\____/\\\\\\\\\\\\\\\__________________|
|________________\/\\\///////////____\/\\\___\/\\\///////////__________________|
|_________________\/\\\_______________\/\\\___\/\\\____________________________|
|__________________\/\\\\\\\\\\\_______\/\\\___\/\\\\\\\\\\\___________________|
|___________________\/\\\///////___/\\\\\\\\\___\/\\\///////___________________|
|____________________\/\\\_________/\\\////\\\___\/\\\_________________________|
|_____________________\/\\\________\/\\\__\/\\\___\/\\\________________________|
|______________________\/\\\________\//\\\\\\\/\\__\/\\\_______________________|
|_______________________\///__________\///////\//___\///_________________:)____|
|______________________________________________________________________________|
```
# Preface

> !(I really enjoyed making this project, and it did not give me headache 
AT ALL) _- Ameen_

Nonetheless, this project is quite stressfull, specially for someone who doesn't
remember the basics of Trigonometry _(or math in general)_, so if you REALLY 
want to work on _FdF_ aka **Fils de Fer** _(really dumb name btw)_, prepare 
yourself for some serious headache, unless you're good with VERY BASIC math.

_No seriouslly though, it is not that hard, I'm just really bad when it comes
to maths, so please don't be discouraged, it is really worth your while, 
especially when **good** results start to show up. :)_

# Projet Description

_FdF_ or as they call it **Fils de Fer** is a program that takes `*.fdf` files
as its 1st argument as shown in _Figure 1.1_, and converts them into actual 
graphical maps as shown in _Figure 1.2_

```text
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0
0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10 10 10 10 10  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
```
_**Figure 1.1**_
<br />

![Figure 1.2](#)
_**Figure 1.2**_
<br />

That is basically what you should do, but that's just the _Mandatory Part_, the
_Bonus Part_ requires you to apply some rotations on the map, some zooming, 
some altitude manipulation, as well as toggling between different projections 
_(we'll see what that means in a sec)_, and some other bonus(es) from your 
choice.

## Ummm, what the F%!$ is that S%?£ in Figure 1.1

Behold the power of confusion _(not really)_.

Every number on that—so called—map represents the altitude of a pixel, and if
we were to calculate that map's dimensions, we would get a _19px*11px_ map, 
