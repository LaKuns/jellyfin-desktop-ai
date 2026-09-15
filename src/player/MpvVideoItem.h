#ifndef MPVVIDEOITEM_H
#define MPVVIDEOITEM_H

#include <MpvAbstractItem>

class PlayerComponent;

class MpvVideoItem : public MpvAbstractItem
{
    Q_OBJECT
    QML_ELEMENT

public:
    explicit MpvVideoItem(QQuickItem *parent = nullptr);
    void setPlayerComponent(PlayerComponent* player);

    MpvController* controller() { return mpvController(); }

private:
    PlayerComponent* m_player = nullptr;
    // Guard against connecting the ready() signal more than once per instance.
    // Multiple setPlayerComponent() calls (which can happen across QML reloads)
    // would otherwise stack the lambda and cause initializeMpv() to fire N
    // times per ready() emission.
    bool m_readyConnected = false;
};

#endif // MPVVIDEOITEM_H
