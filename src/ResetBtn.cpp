#include "ResetBtn.h"

void ResetBtn::virtDraw() {
    getEngine()->drawForegroundRectangle(m_iCurrentScreenX,
                                         m_iCurrentScreenY,
                                         m_iCurrentScreenX + m_iDrawWidth - 1,
                                         m_iCurrentScreenY + m_iDrawHeight - 1,
                                         0x0012ff);

    getEngine()->drawForegroundString(m_iCurrentScreenX + 10,
                                      m_iCurrentScreenY + 10,
                                      "Reset Tiles", 0xffffff);
}

void ResetBtn::pressed() {
    getEngine()->virtSetupBackgroundBuffer();
    //getTileManager()->newTileLayout(getEngine(), getEngine()->getBackgroundSurface(), 6);
}
