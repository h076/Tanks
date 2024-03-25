#ifndef MAPGENERATION_H
#define MAPGENERATION_H

#include "header.h"

class MapGeneration
{
    public:
        MapGeneration(int w, int h) : m_iMapWidth(w), m_iMapHeight(h)
        {
            m_pMapData = (int *) malloc(m_iMapHeight*m_iMapWidth*sizeof(int));
        }

    // map operations
    private:
        void setBorder() {
            int * p = m_pMapData;
            for(int x=0; x<m_iMapWidth; x++) {
                for(int y=0; y<m_iMapHeight; y++) {
                    if(x==0 || x==m_iMapWidth-1) {
                        *(p+(x + y*m_iMapWidth)) = 1;
                    }else if(y==0 || y==m_iMapHeight-1) {
                        *(p+(x + y*m_iMapWidth)) = 1;
                    }
                }
            }
        }

        void clearMap() {
            memset(m_pMapData, 0, m_iMapHeight*m_iMapWidth*sizeof(int));
        }

    public:

        int * getMapData() const {return m_pMapData;}
        int getMapWidth() const {return m_iMapWidth;}
        int getMapHeight() const {return m_iMapHeight;}

        void setMapTemp1() {
            clearMap();
            setBorder();
            int * p = m_pMapData;
            for(int x=1; x<m_iMapWidth-1; x++) {
                for(int y=1; y<m_iMapHeight-1; y++) {
                    if(y>4 && y<13 && x%3==0) {
                        *(p+(x + y*m_iMapWidth)) = 1;
                    }
                }
            }
        }

    private:
        const int m_iMapWidth;
        const int m_iMapHeight;
        int * m_pMapData;
};

#endif /* MAPGENERATION_H */
