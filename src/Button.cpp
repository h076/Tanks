#include "header.h"

#include "Button.h"
#include <cstdio>

int Button::btnID = 0;

void Button::virtDraw() {
    getEngine()->drawForegroundRectangle(m_iCurrentScreenX,
                                         m_iCurrentScreenY,
                                         m_iCurrentScreenX + m_iDrawWidth -1,
                                         m_iCurrentScreenY + m_iDrawHeight -1,
                                         0x0000ff);
    char buf[128];
    snprintf(buf, 128, "Button %d", btnID);
    getEngine()->drawForegroundString(m_iCurrentScreenX,
                                      m_iCurrentScreenY,
                                      buf, 0xffffff);
}

void Button::virtMouseDown(int iButton, int iX, int iY) {
    //std::cout << "mouse down at " << iX << "," << iY << "\n";
    if(iX >= m_iCurrentScreenX && iX <= m_iCurrentScreenX+m_iDrawWidth)
        if(iY >= m_iCurrentScreenY && iY <= m_iCurrentScreenY+m_iDrawHeight)
            this->pressed();

}

void Button::pressed() {
    std::cout << "Button " << btnID << " pressed\n";
}
