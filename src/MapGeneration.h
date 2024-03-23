#ifndef MAPGENERATION_H
#define MAPGENERATION_H

#include "header.h"

class MapGeneration
{
    public:
        MapGeneration(int w, int h)
        {
            m_iMapWidth = w;
            m_iMapHeight = h;
            m_pMapData = (int *) malloc(m_iMapHeight*m_iMapWidth*sizeof(int));
        }

    // map operations
    public:
        void setBorder() {
            int * p = m_pMapData;
            for(int x=0; x<m_iMapWidth; x++) {
                for(int y=0; y<m_iMapHeight; y++) {
                    if(x==0 || x==m_iMapWidth-1) {
                        *(p+(x*y)) = 1;
                    }else if(y==0 || y==m_iMapHeight-1) {
                        *(p+(x*y)) = 1;
                    }
                }
            }
        }

    private:
        int m_iMapWidth;
        int m_iMapHeight;
        int * m_pMapData;
};

#endif /* MAPGENERATION_H */
