/*
 * Aurora: https://github.com/pixelmatix/aurora
 * Copyright (c) 2014 Jason Coon
 *
 * Portions of this code are adapted from LedEffects Snake by Robert Atkins: https://bitbucket.org/ratkins/ledeffects/src/26ed3c51912af6fac5f1304629c7b4ab7ac8ca4b/Snake.cpp?at=default
 * Copyright (c) 2013 Robert Atkins
 *
 */

#ifndef PatternAnimatedGIF_H
#define PatternAnimatedGIF_H


class PatternAnimatedGIF : public Drawable {
private:

public:
    PatternAnimatedGIF() {
        name = (char *)"AnimatedGIF";
    }
    unsigned int drawFrame() {
      root = SD.open(gifDir);
      if (root) {
        gifFile = root.openNextFile();
        while (gifFile) {
          memset(filePath, 0x0, sizeof(filePath));                
          strcpy(filePath, gifFile.name());
          ShowGIF(filePath);
          gifFile.close();
          gifFile = root.openNextFile();
          }
         root.close();
      } // root
        return 0;
    }
};

#endif
