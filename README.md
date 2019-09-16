# Digital Timer
 
Include your responses to the bold questions below. Include snippets of code that explain what you did. Deliverables are due next Tuesday. Post your lab reports as README.md pages on your GitHub, and post a link to that on your main class hub page.

## Part A. Solder your LCD panel

**Take a picture of your soldered panel and add it here!**

## Part B. Writing to the LCD
 
**a. What voltage level do you need to power your display?**\
5 V

**b. What voltage level do you need to power the display backlight?**\
3.3 V
   
**c. What was one mistake you made when wiring up the display? How did you fix it?**\
I made a mistake with wiring up the potentiometer and had to refer to the diagram to fix it. I was mistakenly under the impression that the middle pin always had to be connected to ground, and therefore wired it that way first. After looking at the diagram, I realized that pin 3 on the LCD had to be wired to the middle pin of the potentiometer.

**d. What line of code do you need to change to make it flash your name instead of "Hello World"?**\
I changed the below line of code:
```c
lcd.print("hello, world!");
```

to read:
```c
lcd.print("What's up Meera!");
```

[See video here]()
 
**e. Include a copy of your Lowly Multimeter code in your lab write-up.**


## Part C. Using a time-based digital sensor

**Upload a video of your working rotary encoder here.**
[See video here]()


## Part D. Make your Arduino sing!

**a. How would you change the code to make the song play twice as fast?**
I would half the numerator that each value in the note durations array was dividing, i.e. I would change this line of code:
```c
int noteDuration = 1000 / noteDurations[thisNote];
```

to read:
```c
int noteDuration = 500 / noteDurations[thisNote];
```
 
**b. What song is playing?**
Star Wars Main Title - John Williams

## Part E. Make your own timer

Whack-a-MoLED


**a. Make a short video showing how your timer works, and what happens when time is up!**

**b. Post a link to the completed lab report your class hub GitHub repo.**
