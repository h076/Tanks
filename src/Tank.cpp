#include "header.h"

#include "Tank.h"

void Tank::virtDraw() {
    getEngine()->drawForegroundOval(
        m_iCurrentScreenX,
        m_iCurrentScreenY,
        m_iCurrentScreenX + m_iDrawWidth - 1,
        m_iCurrentScreenY + m_iDrawHeight - 1,
        0xFFFFFF);
}

/**
 our drawing region is defined by :
 The top left corner has the coordinates:
 X: m_iCurrentScreenX + m_iStartDrawPosX
 Y: m_iCurrentScreenY + m_iStartDrawPosY
 The bottom right corner has the coordinates:
 X: m_iCurrentScreenX + m_iStartDrawPosX + m_iDrawWidth
 Y: m_iCurrentScreenY + m_iStartDrawPosY + m_iDrawHeight
*/

void Tank::virtDoUpdate(int iCurrentTime) {

    // check for all arow key presses
    if(getEngine()->isKeyPressed(SDLK_UP))
        m_iCurrentScreenY -= 2;
    if(getEngine()->isKeyPressed(SDLK_DOWN))
        m_iCurrentScreenY += 2;
    if(getEngine()->isKeyPressed(SDLK_LEFT))
        m_iCurrentScreenX -= 2;
    if(getEngine()->isKeyPressed(SDLK_RIGHT))
        m_iCurrentScreenX += 2;

    // prevent object from moving out of play area using bounds
    if(m_iCurrentScreenX < 0)
        m_iCurrentScreenX = 0;
    if(m_iCurrentScreenX >= getEngine()->getWindowWidth() - m_iDrawWidth)
        m_iCurrentScreenX = getEngine()->getWindowWidth() - m_iDrawWidth;
    if(m_iCurrentScreenY < 0)
        m_iCurrentScreenY = 0;
    if(m_iCurrentScreenY >= getEngine()->getWindowHeight() - m_iDrawHeight)
        m_iCurrentScreenY = getEngine()->getWindowHeight() - m_iDrawHeight;

    this->redrawDisplay();
}
