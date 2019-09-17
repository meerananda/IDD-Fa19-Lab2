# Digital Timer
 
Include your responses to the bold questions below. Include snippets of code that explain what you did. Deliverables are due next Tuesday. Post your lab reports as README.md pages on your GitHub, and post a link to that on your main class hub page.

## Part A. Solder your LCD panel

**Take a picture of your soldered panel and add it here!**
![Soldered LCD Panel](/images/PartA_SolderedLCD.png)

## Part B. Writing to the LCD
 
**a. What voltage level do you need to power your display?**\
5 V

**b. What voltage level do you need to power the display backlight?**\
3.3 V
   
**c. What was one mistake you made when wiring up the display? How did you fix it?**\
I did not connect LCD pin 16 to ground, which resulted in the LCD panel displaying at a very low brightness. After I connected pin 16 to ground, the brightness increased significantly.

**d. What line of code do you need to change to make it flash your name instead of "Hello World"?**\
I changed the below line of code:
```c
lcd.print("hello, world!");
```

to read:
```c
lcd.print("What's up Meera!");
```
[See video here](https://youtu.be/vseEE6dNb3Y)

 
**e. Include a copy of your Lowly Multimeter code in your lab write-up.**

[Lowly Multimeter Code](/code/Whack_A_MoLED.ino)
[Lowly Multimeter Video](https://youtu.be/HCcY8Uw8YME)


## Part C. Using a time-based digital sensor

**Upload a video of your working rotary encoder here.**\
[See video here](https://youtu.be/lghDFxgiDk4)

![Rotary Encoder](/images/PartC_RotaryEncoder.png)


## Part D. Make your Arduino sing!

**a. How would you change the code to make the song play twice as fast?**\
I would half the numerator that each value in the note durations array was dividing, i.e. I would change this line of code:
```c
int noteDuration = 1000 / noteDurations[thisNote];
```

to read:
```c
int noteDuration = 500 / noteDurations[thisNote];
``` 
[See video here](https://youtu.be/-9Km33Kh1CA)

**b. What song is playing?**\
Star Wars Main Title

[See video here](https://youtu.be/9r_bR_2knQE)


## Part E. Make your own timer

Whack-a-MoLED

This game has the following components:
1. 2 "Mole" LEDs
1. 2 Switches
1. Success/Failure indicator LED

The game generates a random number between 0 and 1 to select one of the Mole LEDs to light up. Once one of the lights up, the user has 3 seconds to hit the correct corresponding switch. The countdown can be seen on the LCD panel. If they hit the correct switch, the indicator LED will turn green to indicate success. If they don't hit the correct switch within 3 seconds, the indicator LED will turn red to indicate failure for this round. 

[Whack-a-MoLED Code](/code/Whack_A_MoLED.ino)

**a. Make a short video showing how your timer works, and what happens when time is up!**\
[Whack-a-MoLED Video](https://youtu.be/2LdZr8o1ReI)

**b. Post a link to the completed lab report your class hub GitHub repo.**
