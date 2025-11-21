#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 400
#define HEIGHT 300

int main() {
    Display *display;
    Window window;
    XEvent event;
    GC gc;
    int screen;
    
    printf("X11 Client started via SSH/PuTTY\n");
    
    display = XOpenDisplay(NULL);
    if (!display) {
        fprintf(stderr, "Cannot open X display\n");
        return 1;
    }
    
    screen = DefaultScreen(display);
    window = XCreateSimpleWindow(display, RootWindow(display, screen),
                                100, 100, WIDTH, HEIGHT, 2,
                                BlackPixel(display, screen),
                                WhitePixel(display, screen));
    
    XStoreName(display, window, "SSH X11 Client from Docker");
    
    gc = XCreateGC(display, window, 0, NULL);
    XSetForeground(display, gc, BlackPixel(display, screen));
    
    XSelectInput(display, window, ExposureMask | KeyPressMask | ButtonPressMask);
    XMapWindow(display, window);
    
    int running = 1;
    while (running) {
        XNextEvent(display, &event);
        
        switch (event.type) {
            case Expose:
                XDrawString(display, window, gc, 50, 50, 
                           "X11 over SSH from Docker!", 25);
                XDrawString(display, window, gc, 50, 80, 
                           "Press any key to exit", 21);
                
                // Draw some graphics
                XFillRectangle(display, window, gc, 50, 120, 100, 60);
                XFillArc(display, window, gc, 200, 120, 100, 100, 0, 360*64);
                break;
                
            case KeyPress:
                running = 0;
                break;
                
            case ButtonPress:
                printf("Mouse click at (%d, %d)\n", 
                       event.xbutton.x, event.xbutton.y);
                break;
        }
    }
    
    XFreeGC(display, gc);
    XDestroyWindow(display, window);
    XCloseDisplay(display);
    
    return 0;
}