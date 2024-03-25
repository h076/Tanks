#ifndef UTILMAPTILES_H
#define UTILMAPTILES_H
#include "ImageManager.h"
#include "SimpleImage.h"
#include "header.h"

class MapTiles
{
    public:
        MapTiles()
        {
            path = "./images/";

            loadWalls();
        }

        void loadWalls() {
            wallImgs[0] = ImageManager::loadImage("wall0.png", false);
            wallImgs[1] = ImageManager::loadImage("wall1.png", false);
            wallImgs[2] = ImageManager::loadImage("wall2.png", false);
            wallImgs[3] = ImageManager::loadImage("wall3.png", false);
            wallImgs[4] = ImageManager::loadImage("wall4.png", false);
            wallImgs[5] = ImageManager::loadImage("wall5.png", false);
            wallImgs[6] = ImageManager::loadImage("wall6.png", false);
            wallImgs[7] = ImageManager::loadImage("wall7.png", false);
        }

        SimpleImage getRandomWall() const {
            return wallImgs[rand() % 8];
        }

    private:
        std::string path;
        SimpleImage wallImgs[8];

};

#endif /* UTILMAPTILES_H */
