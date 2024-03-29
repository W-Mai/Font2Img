# Font2Img

A Freetype Playground.

# How to build

```shell
meson compile -C build
```

# Features

- [ ] Font loading and rendering.
    - [x] Load bitmap.
    - [ ] Load outline.
    - [ ] Load SVG
- [x] Font rendering in the console.

# Snapshot

### Render 龘 in the console with rotation 30 degrees.

```shell
Width: 29
Height: 30
Advance: 49
               .                                        
               *##.    .                                
                 *@@#. #@#                              
            #*.  .@@ *#@@@                              
             .####@#    *##*                            
                .*##.      *@#*                         
             *@#.  .*##.  .#@#*##*    *.                
             @@**##*   *##@@*        *@#                
            #@@*   *##*   *##*       @@#.               
           .@@..##*   .##*   *##*   #@# *##.            
           #@@*.  .##*   .##*   .   *##.   *##*         
          *@@  *##.  .*#*. #@*     *   .##.   *##*      
          *#*     *##.  .*#@#     #@##*   .##*   .##*   
      #*  **         *##..@@*    .@@*  *#*.  .##*   .## 
       ####@      *#.   .@@#     #@#*#*.  *#*.  .@#.    
    .. @*  *#*.    .#@#.*@@.    *@@#.  *#*.  *##*@@     
     *#@*   ##*. *@*  .*#@#     #@# .##.  *##.  *#*     
    *.  *####    @@#.          *@###.  .##.  .##.       
   .@@#*.  .##  #@# .##.       .@#  .##*  .##*  ..      
   #@#  .##.     .#*   .##       ##*   .*#*  .##*       
  *@#*#*  #@.  #*   .#*.   ##* .#. .##*   .*#*          
  @@#   *#@#  *@#.#*.#@.    *@##@*    .##*.   **        
 #@# *#*.@@   @@#.  .##  ** *@  .*#*     .*#*.  #*      
.@@     #@*  #@# .*#.     .*#@.  ##.*  *#*  .*#@@@.     
  . .*.*@@  .@@.*#.  .   .*   *##@.    #@#.     .       
     .*#@.  #@#*. .*#    #@*#*.  *##  *@# .##.          
            @@  .**.    *@#   .#*.     *#*   .##.       
            .##.   *.   @@.*#* .@@   #*   *#*           
               .##*@#  #@#.   *@@*  #@#*#* .@@.         
                  ..  .@#  *#**@#  .@@#.  .#@#          
                      #@*    .@@.  #@# .*#.             
                          #*.*@#  .@@*#*. .**           
                           .#@@   #@#*  .#*.            
                                 .@@  .**               
                                  .##.   .#             
                                     *#*.*@#            
                                        .*#             

Process finished with exit code 0

```