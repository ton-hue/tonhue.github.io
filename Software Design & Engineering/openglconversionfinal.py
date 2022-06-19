#Py file Conversion of OpenGL - Please refer to CPP file for Original 

from OpenGL.GL import *    #libraries used for opengl settings
from OpenGL.GLU import *   #similar libraries to opengl in C++ used for different settings  
from OpenGL.GLUT import *  

import pygame              #imported needed for python art multimedia also used                          
from pygame.locals import * #for WASD conversion from C++

#vertices from the c++ file and connections for my box of toys converted in python
#vertices had similar setup to c++

verticies = (

    (0.5, -0.5, -0.5),
    (0.5, 0.5, -0.5),
    (-0.5, 0.5, -0.5),
    (-0.5, -0.5, -0.5),
    (0.5, -0.5, 0.5),
    (0.5, 0.5, 0.5),
    (-0.5, -0.5, 0.5),
    (-0.5, 0.5, 0.5),

    )

  #edges used instead of normalization in c++
  #this defines the edges of the cube, from one corner to another in the image

edges = (

    (0,1),
    (0,3),
    (0,4),
    (2,1),
    (2,3),
    (2,7),
    (6,3),
    (6,4),
    (6,7),
    (5,1),
    (5,4),
    (5,7)

    )

#made for colors of surfaces on the box using 5 surface spaces as
#there will be an opening on top of the box. each point connects the suface
#that we are filling besides the top. 

surface = (

(0, 1, 2, 3),
(3, 2, 7, 6),
(6, 7, 5, 4),
(4, 5, 1, 0),
(4, 0, 3, 6),

)


#texture of box, I used a brown box texture found on google to give box realism 
#to load texture in python I had to utilize pygame and then loaded width and height

def loadTextures():
    textSurface = pygame.image.load('brownbox.png')
    textData = pygame.image.tostring(textureSurface, "RGBA", 1)
    width = textSurface.get_width()
    height = texSurface.get_height()

    
#defining box verts and edges for vertices to show

def Cube(lines=False):
    
    #added quads for surface colors so opengl can draw
    glBegin(GL_QUADS)
    for surface in surfaces:
        glColor3fv((0.5, 0.35, 0.05)) #selected brown color for box
        for vertex in surface:
            glVertex3f(vertices[vertex])
                glEnd() #ended quads to begin lines

            
    if lines:
    glBegin(GL_Lines) #lines utilized for texture on the box

    for edge in edges:
        glColor3fv((1.0f, 0.5f, 0.0f, 0.0f)) #color set to brown as well
        for vertex in edge:
            glVertex3fv(verticies[vertex])
        else:
        glBegin(GL_QUADS) #used to draw the texture on box using 3 verts as ref
        glTexCoord2f(0.0, 0.0)#attempted texture with 2 dimensional 
        glVertex3f(-0.5, -0.5,  0.5)
        glTexCoord2f(0.5, 0.0)
        glVertex3f(0.5, -0.5,  0.5)
        glTexCoord2f(0.5, 0.5)
        glVertex3f(1.0,  0.5,  0.5)
        glTexCoord2f(1.0, 0.5)
        glVertex3f(-0.5,  0.5,  0.5)
        glTexCoord2f(0.5, 0.0)
        glVertex3f(-0.5, -0.5, -0.5)
        glTexCoord2f(0.5, 0.5)
        glVertex3f(-0.5,  0.5, -0.5)
        glTexCoord2f(0.0, 0.5)
        glVertex3f(0.5,  0.5, -0.5)
        glTexCoord2f(0.0, 0.0)
        glVertex3f(0.5, -0.5, -0.5)
        glTexCoord2f(0.0, 0.5)
        glVertex3f(-0.5,  0.5, -0.5)
        glTexCoord2f(0.0, 0.0)
        glVertex3f(-0.5, 0.5, 0.5)
        glEnd()
        
    glEnd()

#for the main function it has display, buffers, glclear in python similar to cpp file.
#The Doublebuf or Double buffers is utilized to have multiple items in scene
#this also uses pygame to display image

    def main():

        pygame.init()

        display = (800,700) #selected same display size as cpp opengl code

        pygame.display.set_mode(display, DOUBLEBUF|OPENGL) #displaying double duffers for the items

        gluPerspective (50, (display[0]/display[1]), 0.1, 50.0) #zoom for object

        glTranslatef(0.0, 0.0, -3) #the gltraslate is similar to matrix used in c++ using x y z

        glRotatef(0, 0, 0, 0) #no rotation on item, set to 0, will review with lighting and adjust with lighting

        #calling loop using true false statement

        while True:

            for event in pygame.event.get():     #allows viewer to close window
                if event.type == pygame.QUIT:

                    pygame.quit()
                    quit()

            #Here is the movements using a if-else statement 
            #similar to WASD keys from the orginal cpp file
            #for the conversion. I choose the arrow keys on the keyboard using
            #pygame.

            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_LEFT:
                glTranslatef(-2.0, 0.0, 0.0)  #utilizing x axis and pygame here is controls using left and right arrows
                if event.key == pygame.K_RIGHT:
                glTranslatef(2.0, 0.0, 0.0)
                if event.key == pygame.K_DOWN:  
                glTranslatef(0.0, -2.0, 0.0)  #utilizing y axis and pygame here is controls using down and up arrows
                if event.key == pygame.K_UP:
                glTranslatef(0.0, 2.0, 0.0)

            #next using pygame I will convert the mouse controls from the cpp file
                if event.button == 4:
                    glTranslatef(0.0, 0.0, 2.0) #using z axis created mouse controls going fwd.

                if event.button == 5:
                    glTranslatef(0.0, 0.0, -2.0) #using z axis created mouse controls going back.



            glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT) #clears buffers

            Cube()                  #call the cube using flip to avoid errors 
            pygame.display.flip()

            pygame.time.wait(8) #8 miliseconds fps

            main()
            
