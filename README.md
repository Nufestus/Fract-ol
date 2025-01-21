When I started working on Fractol, I knew I wanted to go beyond just rendering the usual Mandelbrot and Julia sets. Most people approach the Julia set by using a fixed complex number c, often predefined or chosen from a set of constants. But I decided to take a different approach—one that makes the visualization more interactive and dynamic.

Instead of using a static value for c, I linked it to the mouse position on the screen. This means that as I move my mouse, the entire Julia fractal morphs in real-time, creating a fluid and evolving pattern. This approach allows for instant feedback and exploration, letting me see how small changes in c drastically affect the fractal structure.

How It Works
The X and Y coordinates of the mouse cursor are mapped to the real and imaginary parts of c.
Whenever the mouse moves, the fractal recalculates with the new c, generating a completely different pattern.
This turns the visualization into an interactive experience rather than just a static image.
Why This Approach?
Most implementations treat c as a constant, requiring users to manually enter values or press keys to switch between preset variations. I wanted something more intuitive and experimental—where the user can directly "feel" the effects of different complex numbers just by moving their mouse.

here is a visual representation :

![ezgif-4-1783e12d77](https://github.com/user-attachments/assets/97285f48-0552-4df3-a458-287957f6c549)

the cursor doesnt appear cuz my recording software is acting weird :p
